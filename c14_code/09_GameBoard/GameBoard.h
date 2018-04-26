#pragma once

#include <cstddef>

class GamePiece {};

class GameBoard
{
public:
	// general-purpose GameBoard allows user to specify its dimensions
	explicit GameBoard(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	GameBoard(const GameBoard& src); // Copy constructor
	virtual ~GameBoard() noexcept;
	GameBoard& operator=(const GameBoard& rhs); // Assignment operator

	GamePiece& at(size_t x, size_t y);
	const GamePiece& at(size_t x, size_t y) const;

	size_t getHeight() const noexcept { return mHeight; }
	size_t getWidth() const noexcept { return mWidth; }

	static const size_t kDefaultWidth = 100;
	static const size_t kDefaultHeight = 100;

	friend void swap(GameBoard& first, GameBoard& second) noexcept;

private:
	void cleanup() noexcept;
	void verifyCoordinate(size_t x, size_t y) const;

	// Objects dynamically allocate space for the game pieces.
	GamePiece** mCells = nullptr;
	size_t mWidth = 0, mHeight = 0;
};
