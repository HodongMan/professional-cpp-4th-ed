#include <iostream>

using namespace std;

constexpr unsigned long long factorial(unsigned char f)
{
	if (f == 0) {
		return 1;
	} else {
		return f * factorial(f - 1);
	}
}

int main()
{
	constexpr auto f1 = factorial(6);
	cout << f1 << endl;

	return 0;
}
