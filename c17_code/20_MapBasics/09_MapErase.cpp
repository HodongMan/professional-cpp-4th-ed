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

	cout << "There are " << dataMap.count(1) << " elements with key 1" << endl;
	dataMap.erase(1);
	cout << "There are " << dataMap.count(1) << " elements with key 1" << endl;

	return 0;
}
