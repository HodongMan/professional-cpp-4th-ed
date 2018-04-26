#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

void process(const vector<int>& vec, function<void(int)> f)
{
	for (auto& i : vec) {
		f(i);
	}
}

template <typename F>
void processTemplate(const vector<int>& vec, F f)
{
	for (auto& i : vec) {
		f(i);
	}
}

void print(int num)
{
	cout << num << "  ";
}

int main()
{
	vector<int> vec{ 0,1,2,3,4,5,6,7,8,9 };

	process(vec, print);
	cout << endl;

	int sum = 0;
	process(vec, [&sum](int num){ sum += num; });
	cout << "sum = " << sum << endl;

	// processTemplate:
	processTemplate(vec, print);
	cout << endl;

	int sum2 = 0;
	processTemplate(vec, [&sum2](int num) { sum2 += num; });
	cout << "sum = " << sum2 << endl;

	return 0;
}

