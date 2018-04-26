#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

// Returns false on error
bool changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");

	return 0;
}

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData(filename.data());
	if (!ioData) {
		cerr << "Error while opening file " << filename << endl;
		return false;
	}

	// Loop until the end of file
	while (ioData) {
		int idRead;
		string number;

		// Read the next ID.
		ioData >> idRead;
		if (!ioData)
			break;

		// Check to see if the current record is the one being changed.
		if (idRead == id) {
			// Seek the write position to the current read position
			ioData.seekp(ioData.tellg());
			// Output a space, then the new number.
			ioData << " " << newNumber;
			break;
		}

		// Read the current number to advance the stream.
		ioData >> number;
	}
	return true;
}