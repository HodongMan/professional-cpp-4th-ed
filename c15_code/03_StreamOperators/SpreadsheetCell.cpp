#include "SpreadsheetCell.h"
#include <stdexcept>
#include <iostream>

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

SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() + rhs.getValue());
}

SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() - rhs.getValue());
}

SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return SpreadsheetCell(lhs.getValue() * rhs.getValue());
}

SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	return SpreadsheetCell(lhs.getValue() / rhs.getValue());
}

SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs)
{
	set(getValue() + rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs)
{
	set(getValue() - rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs)
{
	set(getValue() * rhs.getValue());
	return *this;
}

SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs)
{
	if (rhs.getValue() == 0) {
		throw invalid_argument("Divide by zero.");
	}
	set(getValue() / rhs.getValue());
	return *this;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() == rhs.getValue());
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() < rhs.getValue());
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() > rhs.getValue());
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() != rhs.getValue());
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() <= rhs.getValue());
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs)
{
	return (lhs.getValue() >= rhs.getValue());
}

SpreadsheetCell SpreadsheetCell::operator-() const
{
	return SpreadsheetCell(-getValue());
}

SpreadsheetCell& SpreadsheetCell::operator++()
{
	set(getValue() + 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator++(int)
{
	auto oldCell(*this); // Save current value
	++(*this);           // Increment using prefix ++
	return oldCell;      // Return the old value
}

SpreadsheetCell& SpreadsheetCell::operator--()
{
	set(getValue() - 1);
	return *this;
}

SpreadsheetCell SpreadsheetCell::operator--(int)
{
	auto oldCell(*this); // Save current value
	--(*this);           // Decrement using prefix --
	return oldCell;      // Return the old value
}

ostream& operator<<(ostream& ostr, const SpreadsheetCell& cell)
{
	ostr << cell.getValue();
	return ostr;
}

istream& operator>>(istream& istr, SpreadsheetCell& cell)
{
	double value;
	istr >> value;
	cell.set(value);
	return istr;
}
