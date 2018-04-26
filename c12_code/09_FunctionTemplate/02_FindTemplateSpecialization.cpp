#include <cstddef>
#include <iostream>
#include <cstring>
#include <array>

using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

template <typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

template<>
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // found it; return the index
		}
	}
	return NOT_FOUND; // failed to find it; return NOT_FOUND
}

int main()
{
	const char* word = "two";
	const char* words[] = { "one", "two", "three", "four" };
	const size_t sizeWords = std::size(words);
	size_t res;
	res = Find<const char*>(word, words, sizeWords);// Calls const char* specialization
	res = Find(word, words, sizeWords);             // Calls const char* specialization
	res = Find(word, words);						// Calls const char* specialization
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	return 0;
}
