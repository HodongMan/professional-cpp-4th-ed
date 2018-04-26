#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell myCell1(4);
	SpreadsheetCell myCell2(myCell1);
	// myCell2 has the same values as myCell1

	cout << "Cell 1: " << myCell1.getValue() << endl;
	cout << "Cell 2: " << myCell2.getValue() << endl;

	return 0;
}
