#include <cstddef>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	const size_t count = 10;
	int arr[count];     // standard C-style array

	// Initialize each element of the array to the value of its index.
	for (int i = 0; i < count; i++) {
		arr[i] = i;
	}

	// Insert the contents of the array at the end of a vector.
	vector<int> vec;
	vec.insert(end(vec), arr, arr + count);
	// Use std::cbegin() and std::cend()
	//vec.insert(end(vec), cbegin(arr), cend(arr));

	// Print the contents of the vector.
	for (const auto& i : vec) {
		cout << i << " ";
	}

	return 0;
}
