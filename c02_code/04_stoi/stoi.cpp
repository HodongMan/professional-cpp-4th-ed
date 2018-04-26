#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

int main()
{
	const string toParse = "   123USD";
	size_t index = 0;
	int value = stoi(toParse, &index);
	cout << "Parsed value: " << value << endl;
	cout << "First non-parsed character: '" << toParse[index] << "'" << endl;

	return 0;
}