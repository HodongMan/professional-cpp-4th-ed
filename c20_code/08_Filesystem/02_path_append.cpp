#include <filesystem>
#include <iostream>

using namespace std;
using namespace std::filesystem;

int main()
{
	path p(L"D:\\Foo");
	p.append("Bar");
	p /= "Bar";
	cout << p << endl;

	return 0;
}
