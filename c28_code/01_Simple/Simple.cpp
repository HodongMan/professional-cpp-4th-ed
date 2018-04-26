#include "Simple.h"

int Simple::sStaticInt = 0;   // Initialize static data member

Simple::Simple() : mPublicInteger(40)
{
	// Implementation of constructor
}

void Simple::publicMethod() { /* Implementation of public method */ }

void Simple::protectedMethod() { /* Implementation of protected method */ }

void Simple::privateMethod() { /* Implementation of private method */ }

int main()
{
	Simple mySimple;
	return 0;
}
