#pragma once

class SpreadsheetCell
{
public:
	void setValue(double inValue);

private:
	double mValue;

public:
	double getValue() const;
};
