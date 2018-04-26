#pragma once

#include <cstddef>
#include <iostream>
#include <new>
#include <exception>

template <typename T>
class Matrix
{
public:
	Matrix(size_t width, size_t height);
	virtual ~Matrix();

private:
	void cleanup();

	size_t mWidth = 0;
	size_t mHeight = 0;
	T** mMatrix = nullptr;
};

template <typename T>
Matrix<T>::Matrix(size_t width, size_t height)
{
	mMatrix = new T*[width] {};	// Array is zero-initialized!

	// Don't initialize the mWidth and mHeight members in the ctor-
	// initializer. These should only be initialized when the above
	// mMatrix allocation succeeds!
	mWidth = width;
	mHeight = height;

	try {
		for (size_t i = 0; i < width; ++i) {
			mMatrix[i] = new T[height];
		}
	} catch (...) {
		std::cerr << "Exception caught in constructor, cleaning up..." << std::endl;
		cleanup();
		// Nest any caught exception inside a bad_alloc exception.
		std::throw_with_nested(std::bad_alloc());
	}
}

template <typename T>
Matrix<T>::~Matrix()
{
	cleanup();
}

template <typename T>
void Matrix<T>::cleanup()
{
	for (size_t i = 0; i < mWidth; ++i)
		delete[] mMatrix[i];
	delete[] mMatrix;
	mMatrix = nullptr;
	mWidth = mHeight = 0;
}
