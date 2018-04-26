#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	int a = 11;
	int b = 22;

	cout << "Before swap(): a = " << a << ", b = " << b << endl;

	swap(a, b);

	cout << "After swap():  a = " << a << ", b = " << b << endl;

	return 0;
}