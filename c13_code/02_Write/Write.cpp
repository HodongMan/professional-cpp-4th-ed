#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char* test = "hello there\n";
	cout.write(test, strlen(test));

	return 0;
}
