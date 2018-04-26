#include "Grid.h"
#include <vector>

using namespace std;

void processIntGrid(Grid<int>& /*grid*/)
{
	// body omitted for brevity
}

int main()
{
	Grid<int> myIntGrid; // declares a grid that stores ints,
						 // using default arguments for the constructor
	Grid<double> myDoubleGrid(11, 11); // declares an 11x11 Grid of doubles

	myIntGrid.at(0, 0) = 10;
	int x = myIntGrid.at(0, 0).value_or(0);

	Grid<int> grid2(myIntGrid);  // Copy constructor
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;      // Assignment operator

	processIntGrid(myIntGrid);

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	return 0;
}
