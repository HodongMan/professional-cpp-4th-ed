#include <tuple>
#include <string>
#include <iostream>

using namespace std;

struct Foo
{
	int mInt;
	string mStr;
	bool mBool;
};

bool operator<(const Foo& f1, const Foo& f2)
{
	return tie(f1.mInt, f1.mStr, f1.mBool) <
		tie(f2.mInt, f2.mStr, f2.mBool);
}

int main()
{
	Foo f1{ 42, "Hello", 0 };
	Foo f2{ 32, "World", 0 };
	cout << (f1 < f2) << endl;
	cout << (f2 < f1) << endl;

	return 0;
}
