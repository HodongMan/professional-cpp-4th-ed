#include <algorithm>
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

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	int sum = 0;
	int product = 1;
	for_each(cbegin(myVector), cend(myVector),
		[&sum, &product](int i){
			sum += i;
			product *= i;
	});
	cout << "The sum is " << sum << endl;
	cout << "The product is " << product << endl;

	return 0;
}
