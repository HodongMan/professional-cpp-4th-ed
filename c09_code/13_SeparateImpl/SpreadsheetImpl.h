#pragma once

#include <cstddef>
#include "Spreadsheet.h"
#include "SpreadsheetCell.h"

class Spreadsheet::Impl
{
public:
	Impl(const SpreadsheetApplication& theApp,
		size_t width, size_t height);
	Impl(const Impl& src);
	~Impl();
	Impl& operator=(const Impl& rhs);

	void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
	SpreadsheetCell& getCellAt(size_t x, size_t y);

	size_t getId() const;

private:
	void verifyCoordinate(size_t x, size_t y) const;
	void swap(Impl& other) noexcept;

	size_t mId = 0;
	size_t mWidth = 0;
	size_t mHeight = 0;
	SpreadsheetCell** mCells = nullptr;

	const SpreadsheetApplication& mTheApp;

	static size_t sCounter;
};
