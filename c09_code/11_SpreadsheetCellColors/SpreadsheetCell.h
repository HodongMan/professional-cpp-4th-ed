#pragma once

#include <cstddef>
#include <string>
#include <string_view>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);

	void set(double inValue);
	void set(std::string_view inString);

	double getValue() const { mNumAccesses++; return mValue; }
	std::string getString() const { mNumAccesses++; return doubleToString(mValue); }

	static std::string doubleToString(double inValue);
	static double stringToDouble(std::string_view inString);

	enum class Color { Red = 1, Green, Blue, Yellow };
	void setColor(Color color);
	Color getColor() const;

private:
	double mValue = 0;
	mutable size_t mNumAccesses = 0;
	Color mColor = Color::Red;
};
