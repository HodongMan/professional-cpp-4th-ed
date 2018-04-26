#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <sstream>
#include <cstddef>

using namespace std;

class FileError : public exception
{
public:
	FileError(string_view fileName) : mFileName(fileName) {}
	virtual const char* what() const noexcept override { return mMessage.c_str(); }
	string_view getFileName() const noexcept { return mFileName; }

protected:
	void setMessage(string_view message) { mMessage = message; }

private:
	string mFileName;
	string mMessage;
};

class FileOpenError : public FileError
{
public:
	FileOpenError(string_view fileName)
		: FileError(fileName)
	{
		setMessage("Unable to open "s + fileName.data());
	}
};

class FileReadError : public FileError
{
public:
	FileReadError(string_view fileName, size_t lineNumber)
		: FileError(fileName), mLineNumber(lineNumber)
	{
		ostringstream ostr;
		ostr << "Error reading " << fileName << " at line " << lineNumber;
		setMessage(ostr.str());
	}

	size_t getLineNumber() const noexcept { return mLineNumber; }

private:
	size_t mLineNumber;
};


vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	if (inputStream.fail()) {
		// We failed to open the file: throw an exception
		throw FileOpenError(fileName);
	}

	vector<int> integers;
	size_t lineNumber = 0;
	while (!inputStream.eof()) {
		// Read one line from the file
		string line;
		getline(inputStream, line);
		++lineNumber;

		// Create a string stream out of the line
		istringstream lineStream(line);

		// Read the integers one-by-one and add them to a vector
		int temp;
		while (lineStream >> temp) {
			integers.push_back(temp);
		}

		if (!lineStream.eof()) {
			// We did not reach the end of the string stream.
			// This means that some error occurred while reading this line.
			// Throw an exception.
			throw FileReadError(fileName, lineNumber);
		}
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try {
		myInts = readIntegerFile(fileName);
	} catch (const FileError& e) {
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInts) {
		cout << element << " ";
	}
	cout << endl;

	return 0;
}
