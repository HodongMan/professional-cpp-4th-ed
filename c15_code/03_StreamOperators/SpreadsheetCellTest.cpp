#include "SpreadsheetCell.h"
#include <iostream>

using namespace std;

int main()
{
	int number = 10;
	cout << "The number is " << number << endl;
	string str;
	cin >> number >> str;

	SpreadsheetCell myCell, anotherCell, aThirdCell;

	cout << "Input 3 spreadsheetcells:" << endl;
	cin >> myCell >> anotherCell >> aThirdCell;
	cout << myCell << " " << anotherCell << " " << aThirdCell << endl;

	cout << "Input 3 spreadsheetcells:" << endl;
	operator>>(operator>>(operator>>(cin, myCell), anotherCell), aThirdCell);

	return 0;
}
