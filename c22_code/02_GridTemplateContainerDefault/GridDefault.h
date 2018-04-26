#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>
#include <utility>
#include <optional>

template <typename T, typename Container = std::vector<std::optional<T>>>
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

	typename Container::value_type& at(size_t x, size_t y);
	const typename Container::value_type& at(size_t x, size_t y) const;

	size_t getHeight() const { return mHeight; }
	size_t getWidth() const { return mWidth; }

	static const size_t kDefaultWidth = 10;
	static const size_t kDefaultHeight = 10;

private:
	void verifyCoordinate(size_t x, size_t y) const;

	std::vector<Container> mCells;
	size_t mWidth = 0, mHeight = 0;
};

template <typename T, typename Container>
Grid<T, Container>::Grid(size_t width, size_t height)
	: mWidth(width)
	, mHeight(height)
{
	mCells.resize(mWidth);
	for (auto& column : mCells) {
		column.resize(mHeight);
	}
}

template <typename T, typename Container>
void Grid<T, Container>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= mWidth || y >= mHeight) {
		throw std::out_of_range("");
	}
}

template <typename T, typename Container>
const typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return mCells[x][y];
}

template <typename T, typename Container>
typename Container::value_type& Grid<T, Container>::at(size_t x, size_t y)
{
	return const_cast<typename Container::value_type&>(
		std::as_const(*this).at(x, y));
}
