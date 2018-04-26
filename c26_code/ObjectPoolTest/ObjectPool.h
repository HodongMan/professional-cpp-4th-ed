#pragma once

#include <queue>
#include <memory>

// Provides an object pool that can be used with any class that provides a
// default constructor.
//
// acquireObject() returns an object from the list of free objects. If
// there are no more free objects, acquireObject() creates a new instance.
// The pool only grows: objects are never removed from the pool (freed),
// until the pool is destroyed.
// acquireObject() returns an Object which is an std::shared_ptr with a
// custom deleter that automatically puts the object back into the object
// pool when the shared_ptr is destroyed and its reference reaches 0.
//
// The constructor and destructor on each object in the pool will be called
// only once each for the lifetime of the object pool, not once per
// acquisition and release.
//
// The primary use of an object pool is to avoid creating and deleting
// objects repeatedly. This object pool is most suited to applications that
// use large numbers of objects with expensive constructors for short
// periods of time, and if a profiler tells you that allocating and
// deallocating these objects is a bottleneck.
template <typename T>
class ObjectPool
{
public:
	ObjectPool() = default;
	virtual ~ObjectPool() = default;

	// Prevent assignment and pass-by-value
	ObjectPool(const ObjectPool<T>& src) = delete;
	ObjectPool<T>& operator=(const ObjectPool<T>& rhs) = delete;

	// The type of smart pointer returned by acquireObject().
	using Object = std::shared_ptr<T>;

	// Reserves and returns an object for use.
	Object acquireObject();

private:
	// Stores the objects that are not currently in use by clients.
	std::queue<std::unique_ptr<T>> mFreeList;
};

template <typename T>
typename ObjectPool<T>::Object ObjectPool<T>::acquireObject()
{
	if (mFreeList.empty()) {
		mFreeList.emplace(std::make_unique<T>());
	}

	// Move next free object from the queue to a local unique_ptr.
	std::unique_ptr<T> obj(std::move(mFreeList.front()));
	mFreeList.pop();

	// Convert the object pointer to an Object (a shared_ptr with
	// a custom deleter).
	Object smartObject(obj.release(), [this](T* t){
		// The custom deleter doesn't actually deallocate the
		// memory, but simply puts the object back on the free list.
		mFreeList.emplace(t);
	});

	// Return the Object.
	return smartObject;
}
