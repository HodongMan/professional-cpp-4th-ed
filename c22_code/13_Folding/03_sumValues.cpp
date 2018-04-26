#include <iostream>

using namespace std;

template<typename T, typename... Values>
double sumValues(const T& init, const Values&... values)
{
	return (init + ... + values);
}

int main()
{
	cout << sumValues(1, 2, 3.3) << endl;
	cout << sumValues(1) << endl;

	return 0;
}
