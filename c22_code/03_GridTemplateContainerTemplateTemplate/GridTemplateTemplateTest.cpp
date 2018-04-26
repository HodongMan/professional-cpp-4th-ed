#include "GridTemplateTemplate.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{
	Grid<int, vector> myGrid;
	myGrid.at(1, 2) = 3;
	cout << myGrid.at(1, 2).value_or(0) << endl;

	Grid<int, vector> myGrid2(myGrid);

	return 0;
}
