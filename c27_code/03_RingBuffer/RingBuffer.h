#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <ostream>
#include <sstream>

// Provides a simple debug ring buffer. The client specifies the number
// of entries in the constructor, and adds messages with the addEntry()
// method. Once the number of entries exceeds the number allowed, new
// entries overwrite the oldest entries in the buffer.
//
// The buffer also provides the option to output entries to a stream as
// they are added to the buffer. The client can specify an output stream
// in the constructor, and can reset it with the setOutput() method.
// 
// Finally, the operator<< streams the entire buffer to an output stream.
class RingBuffer
{
public:
	// Constructs a ring buffer with space for numEntries.
	// Entries are written to *ostr as they are queued (optional).
	explicit RingBuffer(size_t numEntries = kDefaultNumEntries, std::ostream* ostr = nullptr);
	virtual ~RingBuffer() = default;

	// Adds an entry to the ring buffer, possibly overwriting the
	// oldest entry in the buffer (if the buffer is full).
	template<typename... Args>
	void addEntry(const Args&... args)
	{
		std::ostringstream os;
		// Use a C++17 unary right fold, see Chapter 22.
		((os << args), ...);
		addStringEntry(os.str());
	}

	// Streams the buffer entries, separated by newlines, to ostr.
	friend std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb);

	// Streams entries as they are added to the given stream.
	// Specify nullptr to disable this feature.
	// Returns the old output stream.
	std::ostream* setOutput(std::ostream* newOstr);

private:
	std::vector<std::string> mEntries;
	std::vector<std::string>::iterator mNext;

	std::ostream* mOstr;
	bool mWrapped;

	static const size_t kDefaultNumEntries = 500;

	void addStringEntry(std::string&& entry);
};
