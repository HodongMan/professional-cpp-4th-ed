#include <cstddef> 
#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void processPath(const path& p, size_t level = 0)
{
	if (!exists(p)) {
		return;
	}

	const string spacer(level * 2, ' ');

	if (is_regular_file(p)) {
		cout << spacer << "File: " << p;
		cout << " (" << file_size(p) << " bytes)" << endl;
	} else if (is_directory(p)) {
		std::cout << spacer << "Dir: " << p << endl;
		for (auto& entry : directory_iterator(p)) {
			processPath(entry, level + 1);
		}
	}
}

int main()
{
	path p(LR"(D:\Foo\Bar)");
	processPath(p);

	return 0;
}
