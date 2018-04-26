#include "SpreadsheetCell.h"
#include <iostream>
#include <memory>

using namespace std;

int main()
{
	auto myCellp = make_unique<SpreadsheetCell>();
	// Equivalent to:
	// unique_ptr<SpreadsheetCell> myCellp(new SpreadsheetCell());
	
	myCellp->setValue(3.7);
	cout << "cell 1: " << myCellp->getValue() <<
		" " << myCellp->getString() << endl;

	return 0;
}
