#include <iostream>
#include <tuple>
#include <string>

using namespace std;

template<typename TupleType, int n>
class tuple_print_helper
{
public:
	tuple_print_helper(const TupleType& t) {
		if constexpr(n > 1) {
			tuple_print_helper<TupleType, n - 1> tp(t);
		}
		cout << get<n - 1>(t) << endl;
	}
};

template<typename T>
void tuple_print(const T& t)
{
	tuple_print_helper<T, tuple_size<T>::value> tph(t);
}

int main()
{
	auto t1 = make_tuple(167, "Testing", false, 2.3);
	tuple_print(t1);
}
