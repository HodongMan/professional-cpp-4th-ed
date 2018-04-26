#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	// Calculate the sum of integers read from the console until the end-of-stream is reached.
	// Note:
	//	On Windows, the end-of-stream is reached when pressing Ctrl+Z followed by Enter.
	//	On Linux, the end-of-stream is reached by pressing enter to get a new line, followed by Ctrl+D.
	cout << "Enter numbers separated by white space." << endl;
	cout << "Press Ctrl+Z followed by Enter to stop." << endl;
	istream_iterator<int> numbersIter(cin);
	istream_iterator<int> endIter;
	int sum = accumulate(numbersIter, endIter, 0);
	cout << "Sum: " << sum << endl;

	return 0;
}
