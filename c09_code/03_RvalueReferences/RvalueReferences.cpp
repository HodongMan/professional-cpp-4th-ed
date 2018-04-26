#include <iostream>
#include <string>

using namespace std;

void helper(std::string&& message)
{
}

// lvalue reference parameter
void handleMessage(std::string& message)
{
	cout << "handleMessage with lvalue reference: " << message << endl;
}

// rvalue reference parameter
void handleMessage(std::string&& message)
{
	cout << "handleMessage with rvalue reference: " << message << endl;
	helper(std::move(message));
}

int main()
{
	std::string a = "Hello ";
	std::string b = "World";

	// Handle a named variable
	handleMessage(a);             // Calls handleMessage(string& value)

	// Handle an expression
	handleMessage(a + b);         // Calls handleMessage(string&& value)

	// Handle a literal
	handleMessage("Hello World"); // Calls handleMessage(string&& value)

	// Handle a named variable and force to use rvalue reference method
	handleMessage(std::move(b));  // Calls handleMessage(string&& value)

	return 0;
}
