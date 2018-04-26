#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

void processPath(const path& p)
{
	if (!exists(p)) {
		return;
	}

	auto begin = recursive_directory_iterator(p);
	auto end = recursive_directory_iterator();
	for (auto iter = begin; iter != end; ++iter) {
		const string spacer(iter.depth() * 2, ' ');

		auto& entry = *iter;

		if (is_regular_file(entry)) {
			cout << spacer << "File: " << entry;
			cout << " (" << file_size(entry) << " bytes)" << endl;
		} else if (is_directory(entry)) {
			cout << spacer << "Dir: " << entry << endl;
		}
	}
}

int main()
{
	path p(LR"(D:\Foo\Bar)");
	processPath(p);

	return 0;
}
