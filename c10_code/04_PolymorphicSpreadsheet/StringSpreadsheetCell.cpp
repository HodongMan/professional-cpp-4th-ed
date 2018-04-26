#include "StringSpreadsheetCell.h"

using namespace std;

StringSpreadsheetCell::StringSpreadsheetCell(const DoubleSpreadsheetCell& inDoubleCell)
{
	mValue = inDoubleCell.getString();
}

void StringSpreadsheetCell::set(string_view inString)
{
	mValue = inString;
}

string StringSpreadsheetCell::getString() const
{
	return mValue.value_or("");
}
