#include <iostream>
#include <string>
#include <string_view>
#include <cstddef>

using namespace std;

string_view extractExtension(string_view fileName)
{
	return fileName.substr(fileName.rfind('.'));
}

int main()
{
	// C++ std::string.
	string fileName = R"(c:\temp\my file.ext)";
	cout << "C++ string: " << extractExtension(fileName) << endl;

	// C-style string.
	const char* cString = R"(c:\temp\my file.ext)";
	cout << "C string: " << extractExtension(cString) << endl;

	// String literal.
	cout << "Literal: " << extractExtension(R"(c:\temp\my file.ext)") << endl;

	// Raw string buffer with given length.
	const char* raw = "test.ext";
	size_t length = 8;
	cout << "Raw: " << extractExtension(string_view(raw, length)) << endl;

	// Assigning the result to a std::string.
	string extension = extractExtension(fileName).data();

	return 0;
}
