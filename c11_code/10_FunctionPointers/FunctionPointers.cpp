#include <cstddef>
#include <iostream>
#include <array>

using namespace std;

using MatchFunction = bool(*)(int, int); 
// typedef bool(*MatchFunction)(int, int);

bool intEqual(int item1, int item2);
bool bothOdd(int item1, int item2);
void findMatches(int values1[], int values2[], size_t numValues, MatchFunction matcher);

void findMatches(int values1[], int values2[], size_t numValues, MatchFunction matcher)
{
	for (size_t i = 0; i < numValues; i++) {
		if (matcher(values1[i], values2[i])) {
			cout << "Match found at position " << i << " (" << values1[i] << ", " << values2[i] << ")" << endl;
		}
	}
}

bool intEqual(int item1, int item2)
{
	return item1 == item2;
}

bool bothOdd(int item1, int item2)
{
	return item1 % 2 == 1 && item2 % 2 == 1;
}

int main()
{
	int arr1[] = { 2, 5, 6, 9, 10, 1, 1 };
	int arr2[] = { 4, 4, 2, 9, 0, 3, 4 };
	size_t arrSize = std::size(arr1); // Pre-C++17: sizeof(arr1) / sizeof(arr1[0]);

	cout << "Calling findMatches() using intEqual():" << endl;
	findMatches(arr1, arr2, arrSize, &intEqual);

	cout << endl;

	cout << "Calling findMatches() using bothOdd():" << endl;
	findMatches(arr1, arr2, arrSize, &bothOdd);

	return 0;
}


