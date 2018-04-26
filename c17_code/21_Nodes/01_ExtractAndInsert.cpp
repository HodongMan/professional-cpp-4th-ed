#include <map>

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

	map<int, Data> dataMap2;
	dataMap2.insert(dataMap.extract(1));

	return 0;
}
