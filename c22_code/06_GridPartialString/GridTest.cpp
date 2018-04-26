#include "Grid.h"
#include <iostream>

using namespace std;

int main()
{
	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;

	myGrid.at(2, 3) = 45;
	anotherGrid = myGrid;

	cout << anotherGrid.at(2, 3).value_or(0) << endl;

	return 0;
}
