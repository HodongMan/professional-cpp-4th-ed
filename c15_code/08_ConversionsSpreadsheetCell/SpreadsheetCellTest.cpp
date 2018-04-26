#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell cell(1.23);
	double d1 = cell;
	cout << d1 << endl;
	string str = cell;
	cout << str << endl;

	return 0;
}
