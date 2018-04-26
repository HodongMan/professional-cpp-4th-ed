#include <iostream>
#include <string>
#include <tuple> 

using namespace std;

template<typename TupleType, int n>
class tuple_print
{
public:
	tuple_print(const TupleType& t) {
		tuple_print<TupleType, n - 1> tp(t);
		cout << get<n - 1>(t) << endl;
	}
};

template<typename TupleType>
class tuple_print<TupleType, 0>
{
public:
	tuple_print(const TupleType&) { }
};

int main()
{
	using MyTuple = tuple<int, string, bool>;
	MyTuple t1(16, "Test", true);
	tuple_print<MyTuple, tuple_size<MyTuple>::value> tp(t1);

	return 0;
}
