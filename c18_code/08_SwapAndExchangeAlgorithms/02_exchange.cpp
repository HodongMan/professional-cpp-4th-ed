#include <utility>
#include <iostream>

using namespace std;

int main()
{
	int a = 11;
	int b = 22;

	cout << "Before exchange(): a = " << a << ", b = " << b << endl;

	int returnedValue = exchange(a, b);

	cout << "After exchange():  a = " << a << ", b = " << b << endl;
	cout << "exchange() returned: " << returnedValue << endl;

	return 0;
}