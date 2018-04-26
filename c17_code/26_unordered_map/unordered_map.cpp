#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<int, string> m = {
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"},
    };

	// Using C++17 structured bindings.
	for (const auto&[key, value] : m) {
		cout << key << " = " << value << endl;
	}

	// Without structured bindings.
	for (const auto& p : m) {
		cout << p.first << " = " << p.second << endl;
	}
    
    return 0;
}
