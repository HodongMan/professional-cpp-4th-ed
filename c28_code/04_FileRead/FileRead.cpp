#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile("FileRead.cpp");
	if (inputFile.fail()) {
		cerr << "Unable to open file for reading." << endl;
		return 1;
	}

	string nextToken;
	while (inputFile >> nextToken) {
		cout << "Token: " << nextToken << endl;
	}

	return 0;
}
