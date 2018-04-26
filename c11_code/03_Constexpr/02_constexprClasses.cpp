#include <cstddef>
#include <iostream>
#include <array>

using namespace std;

class Rect
{
public:
	constexpr Rect(size_t width, size_t height)
		: mWidth(width), mHeight(height)
	{
	}
	
	constexpr size_t getArea() const
	{
		return mWidth * mHeight;
	}

private:
	size_t mWidth, mHeight;
};

int main()
{
	constexpr Rect r(8, 2);
	int myArray[r.getArea()];
	cout << std::size(myArray) << endl;

	return 0;
}