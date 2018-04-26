#pragma once

class SpreadsheetCell
{
	void setValue(double inValue);
public:
	double getValue() const;

private:
	double mValue;
};
