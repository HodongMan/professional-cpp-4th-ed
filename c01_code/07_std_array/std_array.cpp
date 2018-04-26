#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 3> arr = { 9, 8, 7 };
	cout << "Array size = " << arr.size() << endl;
	cout << "2nd element = " << arr[1] << endl;

	return 0;
}
