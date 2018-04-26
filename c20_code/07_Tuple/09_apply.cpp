#include <tuple>
#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	cout << apply(add, std::make_tuple(39, 3)) << endl;

	return 0;
}