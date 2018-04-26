#include <iostream>

using namespace std;

class Foo
{
public:
	Foo(double value);

private:
	double mValue;
};

Foo::Foo(double value) : mValue(value)
{
	cout << "Foo::mValue = " << mValue << endl;
}

class MyClass
{
public:
	MyClass(double value);

private:
	double mValue;
	Foo mFoo;
};

MyClass::MyClass(double value)
	: mValue(value)
	, mFoo(mValue)
{
	cout << "MyClass::mValue = " << mValue << endl;
}

int main()
{
	MyClass instance(1.2);
	return 0;
}