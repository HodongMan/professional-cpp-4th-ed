#include "hash_map.h"
#include <iostream>
#include <map>

using namespace ProCpp;
using namespace std;

int main()
{
	//hash_map<string, int> myHash;
	//myHash.insert(make_pair("KeyOne", 100));
	//myHash.insert(make_pair("KeyTwo", 200));
	//myHash.insert(make_pair("KeyThree", 300));

	hash_map<string, int> myHash{
			{ "KeyOne", 100 },
			{ "KeyTwo", 200 } };

	myHash.insert({
			{ "KeyThree", 300 },
			{ "KeyFour", 400 } });

	for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
		// Use both -> and * to test the operations
		cout << it->first << " maps to " << (*it).second << endl;
	}

	cout << "----" << endl;

	// Print elements using range-based for loop
	for (auto& p : myHash) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	// Print elements using a range-based for loop and C++17 structured bindings
	for (auto&[key, value] : myHash) {
		cout << key << " maps to " << value << endl;
	}

	cout << "----" << endl;

	// Create an std::map with all the elements in the hashmap
	map<string, int> myMap(cbegin(myHash), cend(myHash));
	for (auto& p : myMap) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	auto found = myHash.find("KeyThree");
	if (found != end(myHash))
	{
		cout << "Found KeyThree: value = " << found->second << endl;
	}


	map<string, int> someMap{ {"One", 1},{"Two", 2} };
	hash_map<string, int> hashMapFromMap(cbegin(someMap), cend(someMap));

	hash_map<string, int> myHash2;
	myHash.swap(myHash2);

	hash_map<string, int> myHash3(std::move(myHash2));

	cout << myHash3.size() << endl;
	cout << myHash3.max_size() << endl;

	return 0;
}
