#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

// Class template RoundRobin
// Provides simple round-robin semantics for a list of elements.
template <typename T>
class RoundRobin
{
public:
	// Client can give a hint as to the number of expected elements for
	// increased efficiency.
	RoundRobin(size_t numExpected = 0);
	virtual ~RoundRobin() = default;

	// Prevent assignment and pass-by-value
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	// Explicitly default a move constructor and move assignment operator
	RoundRobin(RoundRobin&& src) = default;
	RoundRobin& operator=(RoundRobin&& rhs) = default;

	// Appends element to the end of the list. May be called
	// between calls to getNext().
	void add(const T& element);

	// Removes the first (and only the first) element
	// in the list that is equal (with operator==) to element.
	// May be called between calls to getNext().
	void remove(const T& element);

	// Returns the next element in the list, starting with the first,
	// and cycling back to the first when the end of the list is
	// reached, taking into account elements that are added or removed.
	T& getNext();

private:
	std::vector<T> mElements;
	typename std::vector<T>::iterator mCurrentElement;
};

template <typename T>
RoundRobin<T>::RoundRobin(size_t numExpected)
{
	// If the client gave a guideline, reserve that much space.
	mElements.reserve(numExpected);

	// Initialize mCurrentElement even though it isn't used until
	// there's at least one element.
	mCurrentElement = begin(mElements);
}

// Always add the new element at the end
template <typename T>
void RoundRobin<T>::add(const T& element)
{
	// Even though we add the element at the end, the vector could
	// reallocate and invalidate the mCurrentElement iterator with
	// the push_back() call. Take advantage of the random-access
	// iterator features to save our spot.
	int pos = mCurrentElement - begin(mElements);

	// Add the element.
	mElements.push_back(element);
	
	// Reset our iterator to make sure it is valid.
	mCurrentElement = begin(mElements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
	for (auto it = begin(mElements); it != end(mElements); ++it) {
		if (*it == element) {
			// Removing an element invalidates the mCurrentElement iterator
			// if it refers to an element past the point of the removal.
			// Take advantage of the random-access features of the iterator
			// to track the position of the current element after removal.
			int newPos;

			if (mCurrentElement == end(mElements) - 1 &&
				mCurrentElement == it) {
				// mCurrentElement refers to the last element in the list,
				// and we are removing that last element, so wrap back to
				// the beginning.
				newPos = 0;
			} else if (mCurrentElement <= it) {
				// Otherwise, if mCurrentElement is before or at the one
				// we're removing, the new position is the same as before.
				newPos = mCurrentElement - begin(mElements);
			} else {
				// Otherwise, it's one less than before.
				newPos = mCurrentElement - begin(mElements) - 1;
			}

			// Erase the element (and ignore the return value).
			mElements.erase(it);

			// Now reset our iterator to make sure it is valid.
			mCurrentElement = begin(mElements) + newPos;

			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::getNext()
{
	// First, make sure there are elements.
	if (mElements.empty()) {
		throw std::out_of_range("No elements in the list");
	}

	// Store the current element which we need to return.
	auto& toReturn = *mCurrentElement;

	// Increment the iterator modulo the number of elements.
	++mCurrentElement;
	if (mCurrentElement == end(mElements)) {
		mCurrentElement = begin(mElements);
	}

	// Return a reference to the element.
	return toReturn;
}
