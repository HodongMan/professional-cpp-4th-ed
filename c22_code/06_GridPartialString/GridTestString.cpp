#include "GridString.h"
#include <iostream>

using namespace std;

int main()
{
	Grid<int, 2, 2> myIntGrid;				// Uses the original Grid
	Grid<const char*, 2, 2> myStringGrid;	// Uses the partial specialization
	//  Grid<2, 3> test;					// DOES NOT COMPILE! No type specified.

	myStringGrid.at(1, 1) = "Hello";
	Grid<const char*, 2, 2> myStringGridCopy(myStringGrid);
	myStringGridCopy.at(1, 1) = "World.";

	cout << myStringGrid.at(1, 1).value_or("") << endl;
	cout << myStringGridCopy.at(1, 1).value_or("") << endl;

	return 0;
}
