#include <type_traits>

using namespace std;

class Base1 {};
class Base1Child : public Base1 {};

class Base2 {};
class Base2Child : public Base2 {};

template<typename T>
void process(const T& /*t*/)
{
	static_assert(is_base_of_v<Base1, T>, "Base1 should be a base for T.");
}

int main()
{
	process(Base1());
	process(Base1Child());
	//process(Base2());      // Error
	//process(Base2Child()); // Error

	return 0;
}
