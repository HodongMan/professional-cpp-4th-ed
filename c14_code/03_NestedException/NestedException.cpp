#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include <string_view>

using namespace std;

class MyException : public exception
{
public:
	MyException(string_view message) : mMessage(message) {}
	virtual const char* what() const noexcept override { return mMessage.c_str(); }

private:
	string mMessage;
};

void doSomething()
{
	try {
		throw runtime_error("Throwing a runtime_error exception");
	} catch (const runtime_error& /*e*/) {
		cout << __func__ << " caught a runtime_error" << endl;
		cout << __func__ << " throwing MyException" << endl;
		throw_with_nested(MyException("MyException with nested runtime_error"));
	}
}

int main()
{
	try {
		doSomething();
	} catch (const MyException& e) {
		cout << __func__ << " caught MyException: " << e.what() << endl;
/*
		const auto* pNested = dynamic_cast<const nested_exception*>(&e);
		if (pNested) {
			try {
				pNested->rethrow_nested();
			} catch (const runtime_error& e) {
				// Handle nested exception
				cout << "  Nested exception: " << e.what() << endl;
			}
		}
*/
		try {
			rethrow_if_nested(e);
		} catch (const runtime_error& e) {
			// Handle nested exception
			cout << "  Nested exception: " << e.what() << endl;
		}
	}

	return 0;
}
