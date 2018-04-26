#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	// double d2 = cell + 3.3; // DOES NOT COMPILE IF YOU DEFINE operator double()

	// Explicit operator double() demonstration
	SpreadsheetCell cell = 6.6;
	string str = cell;
	double d1 = static_cast<double>(cell);
	double d2 = static_cast<double>(cell + 3.3);
	cout << str << endl;
	cout << d1 << endl;
	cout << d2 << endl;

	return 0;
}
