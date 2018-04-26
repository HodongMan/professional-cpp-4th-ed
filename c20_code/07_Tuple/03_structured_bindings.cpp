#include <iostream>
#include <string>
#include <tuple> 

using namespace std;

int main()
{
	tuple<int, string, bool> t1(16, "Test", true);
	//tuple t1(16, "Test"s, true); // C++17 template argument deduction for constructors
	auto[i, str, b] = t1;
	cout << "Decomposed: i = " << i << ", str = \"" << str << "\", b = " << b << endl;


	return 0;
}