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

	// Using C++11 auto keyword
	for (auto iter = cbegin(dataMap); iter != cend(dataMap); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	// Using C++11 range-based for loop
	for (const auto& p : dataMap) {
		cout << p.second.getValue() << endl;
	}

	// Using range-based for loop + C++17 structured bindings
	for (const auto& [key, data] : dataMap) {
		cout << data.getValue() << endl;
	}

	// If your compiler does not support the above C++11 versions
	for (map<int, Data>::const_iterator iter = dataMap.begin();
		iter != dataMap.end(); ++iter) {
		cout << iter->second.getValue() << endl;
	}

	return 0;
}
