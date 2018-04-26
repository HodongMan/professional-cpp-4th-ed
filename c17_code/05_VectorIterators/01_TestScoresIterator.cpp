#include <cstddef>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

int main()
{
	vector<double> doubleVector;
	// Initialize max to smallest number
	double max = -numeric_limits<double>::infinity();

	for (size_t i = 1; true; i++) {
		double temp;
		cout << "Enter score " << i << " (-1 to stop): ";
		cin >> temp;
		if (temp == -1) {
			break;
		}
		doubleVector.push_back(temp);
		if (temp > max) {
			max = temp;
		}
	}

	max /= 100.0;

	for (vector<double>::iterator iter = begin(doubleVector);
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;

/*
	// Using auto keyword
	for (auto iter = begin(doubleVector);
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		cout << *iter << " ";
	}
	cout << endl;
*/

	return 0;
}
