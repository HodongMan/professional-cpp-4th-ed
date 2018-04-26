#include <random>
#include <functional>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	const unsigned int kStart = 1;
	const unsigned int kEnd = 99;
	const unsigned int kIterations = 1'000'000;

	// Uniform Mersenne Twister
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));
	normal_distribution<double> dist(50, 10);
	auto gen = bind(dist, eng);
	map<int, int> m;
	for (unsigned int i = 0; i < kIterations; ++i) {
		int rnd = static_cast<int>(gen());
		// Search map for a key = rnd. If found, add 1 to the value associated
		// with that key. If not found, add the key to the map with value 1.
		++(m[rnd]);
	}

	// Write to a CSV file
	ofstream of("res.csv");
	for (unsigned int i = kStart; i <= kEnd; ++i) {
		of << i << "," << m[i] << endl;
	}

	return 0;
}
