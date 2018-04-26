#include <iostream>
#include <utility>
#include <tuple>
#include <cstddef>

using namespace std;

template<typename Tuple, size_t... Indices>
void tuple_print_helper(const Tuple& t, index_sequence<Indices...>)
{
	((cout << get<Indices>(t) << endl), ...);
}

template<typename... Args>
void tuple_print(const tuple<Args...>& t)
{
	tuple_print_helper(t, index_sequence_for<Args...>());
}

int main()
{
	auto t1 = make_tuple(167, "Testing", false, 2.3);
	tuple_print(t1);
}