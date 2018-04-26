#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>

using namespace std;

vector<int> readIntegerFile(string_view fileName) noexcept;

vector<int> readIntegerFile(string_view fileName) noexcept
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception
		throw invalid_argument("");
	}

	// Read the integers one-by-one and add them to a vector
	vector<int> integers;
	int temp;
	while (inputStream >> temp) {
		integers.push_back(temp);
	}

	if (!inputStream.eof()) {
		// We did not reach the end-of-file.
		// This means that some error occurred while reading the file.
		// Throw an exception.
		throw runtime_error(""); 
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const invalid_argument& /* e */) {
		cerr << "Unable to open file " << fileName << endl;
		return 1;
	} catch (const runtime_error& /* e */) {
		cerr << "Error reading file " << fileName << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
