#include <iostream>
#include <memory>

using namespace std;

int main()
{
	{
		double pi = 3.1415;
		auto myLambda = [myCapture = "Pi: ", pi]{ cout << myCapture << pi; };
		myLambda();
	}

	cout << endl;

	{
		auto myPtr = std::make_unique<double>(3.1415);
		auto myLambda = [p = std::move(myPtr)]{ cout << *p; };
		myLambda();
	}

	cout << endl;

	{
		auto myPtr = std::make_unique<double>(3.1415);
		auto myLambda = [myPtr = std::move(myPtr)]{ cout << *myPtr; };
		myLambda();
	}

	cout << endl;

	return 0;
}
