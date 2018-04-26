#include <utility>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	// Two-argument constructor and default constructor
	pair<string, int> myPair("hello", 5);
	pair<string, int> myOtherPair;

	// Can assign directly to first and second
	myOtherPair.first = "hello";
	myOtherPair.second = 6;

	// copy constructor
	pair<string, int> myThirdPair(myOtherPair);

	// operator<
	if (myPair < myOtherPair) {
		cout << "myPair is less than myOtherPair" << endl;
	} else {
		cout << "myPair is greater than or equal to myOtherPair" << endl;
	}

	// operator==
	if (myOtherPair == myThirdPair) {
		cout << "myOtherPair is equal to myThirdPair" << endl;
	} else {
		cout << "myOtherPair is not equal to myThirdPair" << endl;
	}

	pair<int, double> aPair = make_pair(5, 10.10);
	auto aSecondPair = make_pair(5, 10.10);
	auto aThirdPair = pair(5, 10.10);

	// Decompose a pair into separate variables using
	// C++17 structured bindings
	auto[theString, theInt] = myPair;
	cout << "theString: " << theString << endl;
	cout << "theInt: " << theInt << endl;

	return 0;
}
