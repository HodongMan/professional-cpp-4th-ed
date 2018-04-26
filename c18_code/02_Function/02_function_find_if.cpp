#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool isEven(int num)
{
	return num % 2 == 0;
}

int main()
{
	vector<int> vec{ 1,2,3,4,5,6,7,8,9 };

	function<bool(int)> fcn = isEven;
	auto result = find_if(cbegin(vec), cend(vec), fcn);
	if (result != cend(vec)) {
		cout << "First even number: " << *result << endl;
	} else {
		cout << "No even number found." << endl;
	}

	return 0;
}

