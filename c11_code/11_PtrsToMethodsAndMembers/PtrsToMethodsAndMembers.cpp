#include <iostream>
#include "Employee.h"

using namespace std;
using namespace Records;

int main()
{
	Employee employee;
	
	// Old style:
	//int (Employee::*methodPtr) () const = &Employee::getSalary;

	// Using a type alias:
	//using PtrToGet = int (Employee::*) () const;
	//PtrToGet methodPtr = &Employee::getSalary;

	// Using auto:
	auto methodPtr = &Employee::getSalary;

	cout << (employee.*methodPtr)() << endl;

	return 0;
}