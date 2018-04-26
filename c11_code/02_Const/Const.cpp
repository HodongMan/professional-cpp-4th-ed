#include <cstdlib>

const double PI = 3.141592653589793238462;

void func(const int /*param*/)
{
	// Not allowed to change param...
}

void constIntOne()
{
	const int* ip;
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constIntTwo()
{
	int const* ip;
	ip = new int[10];
	//  ip[4] = 5; // DOES NOT COMPILE!
}

void constPtrOne()
{
	int* const ip = nullptr;
	//  ip = new int[10]; // DOES NOT COMPILE!
	ip[4] = 5;	// Error: dereferencing a null pointer
}

void constPtrTwo()
{
	int* const ip = new int[10];
	ip[4] = 5;
}

void constIntPtrOne()
{
	int const* const ip = nullptr;
}

void constIntPtrTwo()
{
	const int* const ip = nullptr;
}

void manyLevelConst()
{
	const int * const * const * const ip = nullptr;
}

class BigClass;
void doSomething(const BigClass& /*arg*/)
{
	// implementation here
}

int main()
{
	int* ip;
	ip = new int[10];
	ip[4] = 5;

	int z;
	const int& zRef = z;
	//  zRef = 4; // DOES NOT COMPILE

	return 0;
}
