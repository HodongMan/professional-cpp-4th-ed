#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	SpreadsheetCell c1(4);
	SpreadsheetCell c2(6);
	
	cout << (c1 == c2) << endl;
	cout << (c1 < c2) << endl;
	cout << (c1 != c2) << endl;
	cout << (c1 > c2) << endl;
	cout << (c1 <= c2) << endl;
	cout << (c1 >= c2) << endl;

	return 0;
}
