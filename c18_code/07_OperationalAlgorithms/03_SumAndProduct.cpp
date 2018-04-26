#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

// Function template to populate a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
	int num;

	while (true) {
		cout << "Enter a number (0 to quit): ";
		cin >> num;
		if (num == 0) {
			break;
		}
		cont.push_back(num);
	}
}

class SumAndProduct
{
public:
	void operator()(int value);
	int getSum() const { return mSum; }
	int getProduct() const { return mProduct; }

private:
	int mSum = 0;
	int mProduct = 1;
};

void SumAndProduct::operator()(int value)
{
	mSum += value;
	mProduct *= value;
}

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	SumAndProduct func;
	func = for_each(cbegin(myVector), cend(myVector), func);
	cout << "The sum is " << func.getSum() << endl;
	cout << "The product is " << func.getProduct() << endl;

	return 0;
}
