#pragma once

#include <cstddef>
#include <vector>

template <typename T, size_t N>
class NDGrid
{
public:
	explicit NDGrid(size_t size = kDefaultSize);
	virtual ~NDGrid() = default;

	NDGrid<T, N-1>& operator[](size_t x);
	const NDGrid<T, N-1>& operator[](size_t x) const;

	void resize(size_t newSize);
	size_t getSize() const { return mElements.size(); }

	static const size_t kDefaultSize = 10;

private:
	std::vector<NDGrid<T, N-1>> mElements;
};

template <typename T>
class NDGrid<T, 1>
{
public:
	explicit NDGrid(size_t size = kDefaultSize);
	virtual ~NDGrid() = default;

	T& operator[](size_t x);
	const T& operator[](size_t x) const;

	void resize(size_t newSize);
	size_t getSize() const { return mElements.size(); }

	static const size_t kDefaultSize = 10;

private:
	std::vector<T> mElements;
};

template <typename T, size_t N>
NDGrid<T, N>::NDGrid(size_t size)
{
	resize(size);
}

template <typename T, size_t N>
void NDGrid<T, N>::resize(size_t newSize)
{
	mElements.resize(newSize);

	// Resizing the vector calls the 0-argument constructor for
	// the NDGrid<T, N-1> elements, which constructs
	// them with the default size. Thus, we must explicitly call
	// resize() on each of the elements to recursively resize all
	// nested Grid elements.
	for (auto& element : mElements) {
		element.resize(newSize);
	}
}

template <typename T, size_t N>
NDGrid<T, N-1>& NDGrid<T, N>::operator[](size_t x)
{
	return mElements[x];
}

template <typename T, size_t N>
const NDGrid<T, N-1>& NDGrid<T, N>::operator[](size_t x) const
{
	return mElements[x];
}


////////////////////////


template <typename T>
NDGrid<T, 1>::NDGrid(size_t size)
{
	resize(size);
}

template <typename T>
void NDGrid<T, 1>::resize(size_t newSize)
{
	mElements.resize(newSize);
}

template <typename T>
T& NDGrid<T, 1>::operator[](size_t x)
{
	return mElements[x];
}

template <typename T>
const T& NDGrid<T, 1>::operator[](size_t x) const
{
	return mElements[x];
}
