#include <map>
#include <iostream>

using namespace std;

class Data final
{
public:
	explicit Data(int value = 0) : mValue(value) { }
	int getValue() const { return mValue; }
	void setValue(int value) { mValue = value; }

private:
	int mValue;
};

int main()
{
	map<int, Data> dataMap;
	dataMap[1] = Data(4);
	dataMap[1] = Data(6); // Replaces the element with key 1

	return 0;
}
