#include <execution>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec{ 1,3,6,4,6,9 };
	double result1 = std::accumulate(cbegin(vec), cend(vec), 0.0);
	double result2 = std::reduce(std::execution::par_unseq, cbegin(vec), cend(vec));

	return 0;
}
