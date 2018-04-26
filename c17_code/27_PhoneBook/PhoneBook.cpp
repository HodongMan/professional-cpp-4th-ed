#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template<class T>
void printMap(const T& m)
{
	for (auto& [key, value] : m) {
		cout << key << " (Phone: " << value << ")" << endl;
	}
	
	// If your compiler doesn't support the C++17 structured bindings
	// yet, then you can use the following for loop.
	//for (auto& p : m) {
	//	cout << p.first << " (Phone: " << p.second << ")" << endl;
	//}

	cout << "-------" << endl;
}

int main()
{
	// Create a hash table.
	unordered_map<string, string> phoneBook = {
		{ "Marc G.", "123-456789" },
		{ "Scott K.", "654-987321" } };
	printMap(phoneBook);

	// Add/remove some phone numbers.
	phoneBook.insert(make_pair("John D.", "321-987654"));
	phoneBook["Johan G."] = "963-258147";
	phoneBook["Freddy K."] = "999-256256";
	phoneBook.erase("Freddy K.");
	printMap(phoneBook);

	// Find the bucket index for a specific key.
	const size_t bucket = phoneBook.bucket("Marc G.");
	cout << "Marc G. is in bucket " << bucket
	     << " which contains the following "
	     << phoneBook.bucket_size(bucket) << " elements:" << endl;
	// Get begin and end iterators for the elements in this bucket.
	// 'auto' is used here. The compiler deduces the type of
	// both as unordered_map<string, string>::const_local_iterator
	auto localBegin = phoneBook.cbegin(bucket);
	auto localEnd = phoneBook.cend(bucket);
	for (auto iter = localBegin; iter != localEnd; ++iter) {
		cout << "\t" << iter->first << " (Phone: "
			<< iter->second << ")" << endl;
	}
	cout << "-------" << endl;

	// Print some statistics about the hash table
	cout << "There are " << phoneBook.bucket_count() << " buckets." << endl;
	cout << "Average number of elements in a bucket is " << phoneBook.load_factor() << endl;

	return 0;
}
