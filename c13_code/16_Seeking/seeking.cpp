#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream fout("test.out");
	if (!fout) {
		cerr << "Error opening test.out for writing" << endl;
		return 1;
	}

	// 1. Output the string "12345".
	fout << "12345";

	// 2. Verify that the marker is at position 5.
	streampos curPos = fout.tellp();
	if (5 == curPos) {
		cout << "Test passed: Currently at position 5" << endl;
	} else {
		cout << "Test failed: Not at position 5" << endl;
	}

	// 3. Move to position 2 in the stream.
	fout.seekp(2, ios_base::beg);

	// 4. Output a 0 in position 2 and close the stream.
	fout << 0;
	fout.close();

	// 5. Open an input stream on test.out.
	ifstream fin("test.out");
	if (!fin) {
		cerr << "Error opening test.out for reading" << endl;
		return 1;
	}

	// 6. Read the first token as an integer.
	int testVal;
	fin >> testVal;
	if (!fin) {
		cerr << "Error reading from file" << endl;
		return 1;
	}

	// 7. Confirm that the value is 12045.
	const int expected = 12045;
	if (testVal == expected) {
		cout << "Test passed: Value is " << expected << endl;
	} else {
		cout << "Test failed: Value is not " << expected
			<< " (it was " << testVal << ")" << endl;
	}

	return 0;
}
