#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));

	uniform_int_distribution<int> dist(1, 99);
	cout << dist(eng) << endl;

	return 0;
}

