#include <iostream>
#include <string>
#include <string_view>
#include <functional>

using namespace std;

void func(int num, string_view str)
{
	cout << "func(" << num << ", " << str << ")" << endl;
}

int main()
{
	// Bind second argument to a fixed value.
	string myString = "abc";
	auto f1 = bind(func, placeholders::_1, myString);
	f1(16);

	// Rearrange arguments
	auto f2 = bind(func, placeholders::_2, placeholders::_1);
	f2("Test", 32);
	
	return 0;
}

