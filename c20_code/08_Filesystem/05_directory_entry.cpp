#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main()
{
	path myPath(L"c:/windows/win.ini");
	directory_entry dirEntry(myPath);
	if (dirEntry.exists() && dirEntry.is_regular_file()) {
		cout << "File size: " << dirEntry.file_size() << endl;
	}

	return 0;
}
