#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename T1, typename T2>
void same(const T1& t1, const T2& t2)
{
	bool areTypesTheSame = is_same_v<T1, T2>;
	// Pre-C++17:
	//bool areTypesTheSame = is_same<T1, T2>::value;
	cout << "'" << t1 << "' and '" << t2 << "' are ";
	cout << (areTypesTheSame ? "the same types." : "different types.") << endl;
}

int main()
{
	same(1, 32);
	same(1, 3.01);
	same(3.01, "Test"s);

	return 0;
}
