#pragma once

#include <cstddef>
#include <string>
#include <string_view>

class SpreadsheetApplication; // forward declaration

class Spreadsheet
{
public:

	class Cell
	{
	public:
		Cell() = default;
		Cell(double initialValue);
		Cell(std::string_view initialValue);

		void set(double inValue);
		void set(std::string_view inString);

		double getValue() const { mNumAccesses++; return mValue; }
		std::string getString() const { mNumAccesses++; return doubleToString(mValue); }
		
		static std::string doubleToString(double inValue);
		static double stringToDouble(std::string_view inString);

	private:
		double mValue = 0;
		mutable size_t mNumAccesses = 0;
	};

	Spreadsheet(size_t width, size_t height,
		const SpreadsheetApplication& theApp);
	Spreadsheet(const Spreadsheet& src);
	~Spreadsheet();
	Spreadsheet& operator=(const Spreadsheet& rhs);

	void setCellAt(size_t x, size_t y, const Cell& cell);
	Cell& getCellAt(size_t x, size_t y);

	size_t getId() const;

	friend void swap(Spreadsheet& first, Spreadsheet& second) noexcept;

	static const size_t kMaxHeight = 100;
	static const size_t kMaxWidth = 100;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	size_t mId = 0;
	size_t mWidth = 0;
	size_t mHeight = 0;
	Cell** mCells = nullptr;

	const SpreadsheetApplication& mTheApp;

	static size_t sCounter;
};
