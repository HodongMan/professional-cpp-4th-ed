#include <vector>
#include <iostream>

using namespace std;

int main()
{
    // Create a vector of integers
    vector<int> myVector = { 11, 22 };

	// Add some more integers to the vector using push_back()
    myVector.push_back(33);
    myVector.push_back(44);

	// Access elements
	cout << "1st element: " << myVector[0] << endl;
    
	return 0;
}
