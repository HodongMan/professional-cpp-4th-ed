#pragma once

#include "Simple.h"

// A derived class of the Simple class.
class DerivedSimple : public Simple
{
public:
	DerivedSimple();                      // Constructor

	virtual void publicMethod() override; // Overridden method
	virtual void anotherMethod();         // Added method
};
