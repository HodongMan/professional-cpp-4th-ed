#include <iostream>
#include <type_traits>

using namespace std;

class IsDoable
{
public:
	void doit() const { cout << "IsDoable::doit()" << endl; }
};

class Derived : public IsDoable
{
};

template<typename T>
enable_if_t<is_base_of_v<IsDoable, T>, void>
	call_doit(const T& t)
{
	t.doit();
}

template<typename T>
enable_if_t<!is_base_of_v<IsDoable, T>, void>
	call_doit(const T&)
{
	cout << "Cannot call doit()!" << endl;
}

int main()
{
	Derived d;
	call_doit(d);
	call_doit(123);

	return 0;
}
