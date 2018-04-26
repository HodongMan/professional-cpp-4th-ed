#include "CopyAndSwap.h"
#include <utility>

CopyAndSwap::~CopyAndSwap()
{
	// Implementation of destructor
}

CopyAndSwap::CopyAndSwap(const CopyAndSwap& src)
{
	// This copy constructor can first delegate to a non-copy constructor
	// if any resource allocations have to be done. See the Spreadsheet
	// implementation in Chapter 9 for an example.

	// Make a copy of all data members
}

void swap(CopyAndSwap& first, CopyAndSwap& second) noexcept
{
	using std::swap;  // Requires <utility>

	// Swap each data member, for example:
	// swap(first.mData, second.mData);
}

CopyAndSwap& CopyAndSwap::operator=(const CopyAndSwap& rhs)
{
	// Check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	auto copy(rhs);  // Do all the work in a temporary instance
	swap(*this, copy); // Commit the work with only non-throwing operations
	return *this;
}


int main()
{
	CopyAndSwap myFirstInstance;
	CopyAndSwap mySecondInstance;
	mySecondInstance = myFirstInstance;

	return 0;
}
