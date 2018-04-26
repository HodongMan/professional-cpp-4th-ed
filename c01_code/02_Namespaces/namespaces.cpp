#include <iostream>
#include "namespaces.h"

//namespace mycode {
//	void foo()
//  {
//		std::cout << "foo() called in the mycode namespace" << std::endl;
//	}
//}


void mycode::foo()
{
	std::cout << "foo() called in the mycode namespace" << std::endl;
}
