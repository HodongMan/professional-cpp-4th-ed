#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

int main()
{
	// C++17 Boyer-Moore searcher
	string text = "This is the haystack to search a needle in.";
	string toSearchFor = "needle";
	auto searcher = std::boyer_moore_searcher(cbegin(toSearchFor), cend(toSearchFor));
	auto result = search(cbegin(text), cend(text), searcher);
	if (result != cend(text)) {
		cout << "Found the needle." << endl;
	} else {
		cout << "Needle not found." << endl;
	}

	return 0;
}
