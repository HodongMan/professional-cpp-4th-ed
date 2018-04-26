#include <vector>
#include <iterator>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template <typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
	typename std::iterator_traits<IteratorType>::value_type temp;
	temp = *it;
	//auto temp = *it;
	cout << temp << endl;
}

int main()
{
	vector<int> v{ 5 };
	iteratorTraitsTest(cbegin(v));

	return 0;
}
