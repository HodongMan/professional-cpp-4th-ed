#include <string>
#include <iostream>

void printString(const std::string& myString)
{
	std::cout << myString << std::endl;
}

int main()
{
	std::string someString = "Hello World";
	printString(someString);
	printString("Hello World");  // Passing literals works
	return 0;
}
