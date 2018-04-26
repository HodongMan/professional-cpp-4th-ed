#pragma once

// A simple class that illustrates the copy-and-swap idiom.
class CopyAndSwap
{
public:
	CopyAndSwap() = default;
	virtual ~CopyAndSwap();                         // Virtual destructor

	CopyAndSwap(const CopyAndSwap& src);            // Copy constructor
	CopyAndSwap& operator=(const CopyAndSwap& rhs); // Assignment operator

	friend void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept;

private:
	// Private data members...
};
