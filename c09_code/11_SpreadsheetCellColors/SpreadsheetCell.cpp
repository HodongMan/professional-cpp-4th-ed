#include "SpreadsheetCell.h"

using namespace std;

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: mValue(initialValue)
{
}

SpreadsheetCell::SpreadsheetCell(string_view initialValue)
	: mValue(stringToDouble(initialValue))
{
}

void SpreadsheetCell::set(double inValue)
{
	mValue = inValue;
}

void SpreadsheetCell::set(string_view inString)
{
	mValue = stringToDouble(inString);
}

string SpreadsheetCell::doubleToString(double inValue)
{
	return to_string(inValue);
}

double SpreadsheetCell::stringToDouble(string_view inString)
{
	return strtod(inString.data(), nullptr);
}

void SpreadsheetCell::setColor(Color color)
{
	mColor = color;
}

SpreadsheetCell::Color SpreadsheetCell::getColor() const
{
	return mColor;
}
