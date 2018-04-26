#include "Spreadsheet.h"
#include <iostream>

using namespace std;

class SpreadsheetApplication {};

int main()
{
	SpreadsheetApplication theApp;
	Spreadsheet s1(5, 6, theApp);

	Spreadsheet::Cell c1(4), c2(5);
	Spreadsheet::Cell c3(c1);
	c2 = c3;

	cout << c1.getValue() << endl;

	return 0;
}
