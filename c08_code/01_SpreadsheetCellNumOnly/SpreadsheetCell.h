#pragma once

class SpreadsheetCell
{
public:
	void setValue(double inValue);
	double getValue() const;

private:
	double mValue;
};
