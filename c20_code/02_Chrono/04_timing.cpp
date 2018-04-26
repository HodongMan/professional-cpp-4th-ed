#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

int main()
{
	// Get the start time
	auto start = high_resolution_clock::now();
	// Execute code that you want to time
	double d = 0;
	for (int i = 0; i < 1000000; ++i) {
		d += sqrt(sin(i) * cos(i));
	}
	// Get the end time and calculate the difference
	auto end = high_resolution_clock::now();
	auto diff = end - start;
	// Convert the difference into milliseconds and output to the console
	cout << duration<double, milli>(diff).count() << "ms" << endl;

	// Output d, because otherwise a compiler might optimize away the whole loop above.
	cout << d << endl;

	return 0;
}
