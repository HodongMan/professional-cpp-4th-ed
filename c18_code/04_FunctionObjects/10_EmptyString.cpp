#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void findEmptyString(const vector<string>& strings)
{
	auto endIter = end(strings);

	// mem_fn()
	auto it = find_if(begin(strings), endIter, mem_fn(&string::empty));

	// Lambda expression
	//auto it = find_if(begin(strings), endIter,
	//	[](const string& str){ return str.empty(); });

	if (it == endIter) {
		cout << "No empty strings!" << endl;
	} else {
		cout << "Empty string at position: "
			<< static_cast<int>(it - begin(strings)) << endl;
	}
}

int main()
{
	vector<string> myVector;

	string one = "blah";
	string two = "";
	myVector.push_back(one);
	myVector.push_back(one);
	myVector.push_back(two);
	myVector.push_back(one);

	findEmptyString(myVector);

	return 0;
}
