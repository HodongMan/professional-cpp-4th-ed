#pragma once

#include <cstddef>
#include <stdexcept>
#include <memory>

template <typename T>
class Array
{
public:
	// Creates an array with a default size that will grow as needed.
	Array();
	virtual ~Array();

	// Disallow assignment and pass-by-value
	Array<T>& operator=(const Array<T>& rhs) = delete;
	Array(const Array<T>& src) = delete;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	// Returns the value at index x. Throws an exception of type
	// out_of_range if index x does not exist in the array.
	const T& getElementAt(size_t x) const;

	// Sets the value at index x. If index x is out of range,
	// allocates more space to make it in range.
	void setElementAt(size_t x, const T& value);

	size_t getSize() const;

private:
	static const size_t kAllocSize = 4;
	void resize(size_t newSize);
	T* mElements = nullptr;
	size_t mSize = 0;
};

template <typename T>
Array<T>::Array()
{
	mSize = kAllocSize;
	mElements = new T[mSize] {}; // Elements are zero-initialized!
}

template <typename T>
Array<T>::~Array()
{
	delete [] mElements;
	mElements = nullptr;
}

template <typename T>
void Array<T>::resize(size_t newSize)
{
	// Create new bigger array with zero-initialized elements.
	auto newArray = std::make_unique<T[]>(newSize);

	// The new size is always bigger than the old size (mSize)
	for (size_t i = 0; i < mSize; i++) {
		// Copy the elements from the old array to the new one
		newArray[i] = mElements[i];
	}

	// Delete the old array, and set the new array
	delete[] mElements;
	mSize = newSize;
	mElements = newArray.release();
}

template <typename T>
T& Array<T>::operator[](size_t x)
{
	if (x >= mSize) {
		// Allocate kAllocSize past the element the client wants
		resize(x + kAllocSize);
	}
	return mElements[x];
}

template <typename T>
const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize) {
		throw std::out_of_range("");
	}
	return mElements[x];
}

/*
template <typename T>
const T& Array<T>::operator[](size_t x) const
{
	if (x >= mSize) {
		static T nullValue = T();
		return nullValue;
	}
	return mElements[x];
}
*/

template <typename T>
const T& Array<T>::getElementAt(size_t x) const
{
	if (x >= mSize) {
		throw std::out_of_range("");
	}
	return mElements[x];
}

template <typename T>
void Array<T>::setElementAt(size_t x, const T& val)
{
	if (x >= mSize) {
		// Allocate kAllocSize past the element the client wants
		resize(x + kAllocSize);
	}
	mElements[x] = val;
}

template <typename T>
size_t Array<T>::getSize() const
{
	return mSize;
}
