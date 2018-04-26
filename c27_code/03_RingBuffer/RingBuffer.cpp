#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <stdexcept>
#include "RingBuffer.h"

using namespace std;

// Initialize the vector to hold exactly numEntries. The vector size
// does not need to change during the lifetime of the object.
// Initialize the other members.
RingBuffer::RingBuffer(size_t numEntries, ostream* ostr)
	: mEntries(numEntries)
	, mOstr(ostr)
	, mWrapped(false)
{
	if (numEntries == 0)
		throw invalid_argument("Number of entries must be > 0.");
	mNext = begin(mEntries);
}

// The addStringEntry algorithm is pretty simple: add the entry to the next
// free spot, then reset mNext to indicate the free spot after
// that. If mNext reaches the end of the vector, it starts over at 0.
//
// The buffer needs to know if the buffer has wrapped or not so
// that it knows whether to print the entries past mNext in operator<<.
void RingBuffer::addStringEntry(string&& entry)
{
	// If there is a valid ostream, write this entry to it.
	if (mOstr) {
		*mOstr << entry << endl;
	}

	// Move the entry to the next free spot and increment
	// mNext to point to the free spot after that.
	*mNext = std::move(entry);
	++mNext;

	// Check if we've reached the end of the buffer. If so, we need to wrap.
	if (mNext == end(mEntries)) {
		mNext = begin(mEntries);
		mWrapped = true;
	}
}

// Set the output stream.
ostream* RingBuffer::setOutput(ostream* newOstr)
{
	return std::exchange(mOstr, newOstr);
}

// operator<< uses an ostream_iterator to "copy" entries directly
// from the vector to the output stream.
//
// operator<< must print the entries in order. If the buffer has wrapped,
// the earliest entry is one past the most recent entry, which is the entry
// indicated by mNext. So, first print from entry mNext to the end.
//
// Then (even if the buffer hasn't wrapped) print from beginning to mNext-1.
ostream& operator<<(ostream& ostr, RingBuffer& rb)
{
	if (rb.mWrapped) {
		// If the buffer has wrapped, print the elements from
		// the earliest entry to the end.
		copy(rb.mNext, end(rb.mEntries), ostream_iterator<string>(ostr, "\n"));
	}

	// Now, print up to the most recent entry.
	// Go up to mNext because the range is not inclusive on the right side.
	copy(begin(rb.mEntries), rb.mNext, ostream_iterator<string>(ostr, "\n"));

	return ostr;
}
