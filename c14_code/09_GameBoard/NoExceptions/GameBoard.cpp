#include "GameBoard.h"
#include <utility>

GameBoard::GameBoard(size_t width, size_t height)
	: mWidth(width), mHeight(height)
{
	mCells = new GamePiece*[mWidth];
	for (size_t i = 0; i < mWidth; i++) {
		mCells[i] = new GamePiece[mHeight];
	}
}

GameBoard::GameBoard(const GameBoard& src)
	: GameBoard(src.mWidth, src.mHeight)
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (size_t i = 0; i < mWidth; i++) {
		for (size_t j = 0; j < mHeight; j++) {
			mCells[i][j] = src.mCells[i][j];
		}
	}
}

GameBoard::~GameBoard()
{
	for (size_t i = 0; i < mWidth; i++) {
		delete[] mCells[i];
	}
	delete[] mCells;
	mCells = nullptr;
	mWidth = mHeight = 0;
}

void swap(GameBoard& first, GameBoard& second) noexcept
{
	using std::swap;

	swap(first.mWidth, second.mWidth);
	swap(first.mHeight, second.mHeight);
	swap(first.mCells, second.mCells);
}

GameBoard& GameBoard::operator=(const GameBoard& rhs)
{
	// Check for self-assignment
	if (this == &rhs) {
		return *this;
	}

	// Copy-and-swap idiom
	GameBoard temp(rhs); // Do all the work in a temporary instance
	swap(*this, temp);   // Commit the work with only non-throwing operations
	return *this;
}

const GamePiece& GameBoard::at(size_t x, size_t y) const
{
	return mCells[x][y];
}

GamePiece& GameBoard::at(size_t x, size_t y)
{
	return const_cast<GamePiece&>(std::as_const(*this).at(x, y));
}