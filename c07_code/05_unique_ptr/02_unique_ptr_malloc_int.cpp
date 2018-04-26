#include <cstdlib>
#include <memory>

using namespace std;

int* malloc_int(int value)
{
	int* p = (int*)malloc(sizeof(int));
	*p = value;
	return p;
}

int main()
{
	unique_ptr<int, decltype(free)*> myIntSmartPtr(malloc_int(42), free);
	return 0;
}
