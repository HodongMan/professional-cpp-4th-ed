#include "DerivedSimple.h"

DerivedSimple::DerivedSimple() : Simple() 
{
	// Implementation of constructor
}

void DerivedSimple::publicMethod()
{
	// Implementation of overridden method
	Simple::publicMethod(); // You can access base class implementations.
}

void DerivedSimple::anotherMethod()
{
	// Implementation of added method
}
