#include <iostream>
#include <vector>
#include <memory>

#include "DoubleSpreadsheetCell.h"
#include "StringSpreadsheetCell.h"

using namespace std;

StringSpreadsheetCell operator+(const StringSpreadsheetCell& lhs,
	const StringSpreadsheetCell& rhs)
{
	StringSpreadsheetCell newCell;
	newCell.set(lhs.getString() + rhs.getString());
	return newCell;
}

int main()
{
	vector<unique_ptr<SpreadsheetCell>> cellArray;

	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<StringSpreadsheetCell>());
	cellArray.push_back(make_unique<DoubleSpreadsheetCell>());

	cellArray[0]->set("hello");
	cellArray[1]->set("10");
	cellArray[2]->set("18");

	cout << "Vector values are [" << cellArray[0]->getString() << "," <<
		cellArray[1]->getString() << "," <<
		cellArray[2]->getString() << "]" << endl;

	DoubleSpreadsheetCell myDbl;
	myDbl.set(8.4);
	StringSpreadsheetCell result = myDbl + myDbl;
	cout << endl << result.getString() << endl;
	
	return 0;
}
