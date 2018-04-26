#include <algorithm>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

bool perfectScore(int num)
{
	return (num >= 100);
}

int main()
{
	int num;

	vector<int> myVector;
	while (true) {
		cout << "Enter a test score to add (0 to stop): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		myVector.push_back(num);
	}

	auto endIter = end(myVector);
	
	// Using C++17 std::not_fn()
	auto it = find_if(begin(myVector), endIter, not_fn(perfectScore));

	// Using lambda expression
	// auto it = find_if(begin(myVector), endIter, [](int i){ return i < 100; });

	// Using pre-C++17 std::not1()
	// function<bool(int)> f = perfectScore;
	// auto it = find_if(begin(myVector), endIter, not1(f));

	if (it == endIter) {
		cout << "All perfect scores" << endl;
	} else {
		cout << "Found a \"less-than-perfect\" score of " << *it << endl;
	}

	return 0;
}
