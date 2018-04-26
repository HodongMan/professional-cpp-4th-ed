#include <iostream>
#include <random>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>

using namespace std;

void fillVector(vector<int>& vec, const std::function<int()>& generator)
{
	generate(begin(vec), end(vec), generator);
}

//template<typename T>
//void fillVector(vector<int>& vec, const T& generator)
//{
//	generate(begin(vec), end(vec), generator);
//}

int main()
{
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));
	uniform_int_distribution<int> dist(1, 99);

	auto gen = std::bind(dist, eng);

	vector<int> vec(10);
	fillVector(vec, gen);

	for (auto i : vec) {
		cout << i << "  ";
	}
	cout << endl;

	return 0;
}

