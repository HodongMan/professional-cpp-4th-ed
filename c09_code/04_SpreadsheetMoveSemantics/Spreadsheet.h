#pragma once

#include <cstddef>
#include "SpreadsheetCell.h"

class Spreadsheet
{
public:
	Spreadsheet(size_t width, size_t height);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet(Spreadsheet&& src) noexcept; // Move constructor
	~Spreadsheet();

	Spreadsheet& operator=(const Spreadsheet& rhs);
	Spreadsheet& operator=(Spreadsheet&& rhs) noexcept;  // Move assignment

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

private:
	void verifyCoordinate(size_t x, size_t y) const;
	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;

	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;
};
