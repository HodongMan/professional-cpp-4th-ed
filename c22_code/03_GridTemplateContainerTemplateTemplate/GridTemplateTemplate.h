#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <optional>
#include <utility>

template <typename T,
	template <typename E, typename Allocator = std::allocator<E>> class Container = std::vector>
class Grid
{
public:
	explicit Grid(size_t width = kDefaultWidth, size_t height = kDefaultHeight);
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and assignment operator.
	Grid(const Grid& src) = default;
	Grid<T, Container>& operator=(const Grid& rhs) = default;

	// Explicitly default a move constructor and assignment operator.
	Grid(Grid&& src) = default;
	Grid<T, Container>& operator=(Grid&& rhs) = default;

	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container<std::optional<T>>> mCells;
	size_t mWidth = 0, mHeight = 0;
};

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
const std::optional<T>& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
std::optional<T>& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}
