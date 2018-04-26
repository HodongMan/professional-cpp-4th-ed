#include "namespaces.h"

using namespace mycode;

int main()
{
	mycode::foo();	// Calls the "foo" function in the "mycode" namespace
	foo();			// implies mycode::foo();
	return 0;
}
