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

	auto ret = dataMap.insert({ 1, Data(4) });   // Using an initializer_list
	if (ret.second) {
		cout << "Insert succeeded!" << endl;
	} else {
		cout << "Insert failed!" << endl;
	}

	ret = dataMap.insert(make_pair(1, Data(6))); // Using a pair object
	if (ret.second) {
		cout << "Insert succeeded!" << endl;
	} else {
		cout << "Insert failed!" << endl;
	}

	// Using C++17 initializers for if statements
	if (auto result = dataMap.insert({ 1, Data(4) }); result.second) {
		cout << "Insert succeeded!" << endl;
	} else {
		cout << "Insert failed!" << endl;
	}

	// Using C++17 initializers for if statements and structured bindings
	if (auto [iter, success] = dataMap.insert({ 1, Data(4) }); success) {
		cout << "Insert succeeded!" << endl;
	} else {
		cout << "Insert failed!" << endl;
	}

	ret = dataMap.insert_or_assign(1, Data(7));
	if (ret.second) {
		cout << "Inserted." << endl;
	} else {
		cout << "Overwritten." << endl;
	}

	return 0;
}
