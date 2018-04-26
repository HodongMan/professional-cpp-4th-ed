#include "SpreadsheetCell.h"

using namespace std;

void SpreadsheetCell::setValue(double value)
{
	value = value; // Ambiguous!
}

double SpreadsheetCell::getValue() const
{
	return value;
}

void SpreadsheetCell::setString(string_view inString)
{
	value = stringToDouble(inString);
}

string SpreadsheetCell::getString() const
{
	return doubleToString(value);
}

string SpreadsheetCell::doubleToString(double inValue) const
{
	return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(string_view inString) const
{
	return strtod(inString.data(), nullptr);
}
