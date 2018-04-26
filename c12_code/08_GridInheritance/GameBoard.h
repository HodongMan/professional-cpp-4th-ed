#pragma once

#include <cstddef>
#include "Grid.h"

template <typename T>
class GameBoard : public Grid<T>
{
public:
	explicit GameBoard(size_t width = Grid<T>::kDefaultWidth,
		size_t height = Grid<T>::kDefaultHeight);
	void move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest);
};

template <typename T>
GameBoard<T>::GameBoard(size_t width, size_t height)
	: Grid<T>(width, height)
{
}

template <typename T>
void GameBoard<T>::move(size_t xSrc, size_t ySrc, size_t xDest, size_t yDest)
{
	Grid<T>::at(xDest, yDest) = std::move(Grid<T>::at(xSrc, ySrc));
	Grid<T>::at(xSrc, ySrc).reset(); // Reset source cell
	// Or:
	// this->at(xDest, yDest) = std::move(this->at(xSrc, ySrc));
	// this->at(xSrc, ySrc).reset();
}
