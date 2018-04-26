#include <vector>
#include <string>

//void processVector(const std::vector<std::string>& vec)
//{
//    // Body omitted
//}

using StringVector = std::vector<std::string>;

void processVector(const StringVector& vec)
{
	// Body omitted
}

int main()
{
	//std::vector<std::string> myVector;
	StringVector myVector;
	processVector(myVector);
	// Rest of the program ...
	return 0;
}
