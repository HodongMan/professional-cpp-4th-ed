#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

class SubObject
{
	public:
		SubObject(int i);
};

SubObject::SubObject(int /*i*/)
{
	throw runtime_error("Exception by SubObject ctor");
}

class MyClass
{
	public:
		MyClass();
	private:
		int* mData = nullptr;
		SubObject mSubObject;
};

MyClass::MyClass()
try
	: mData(new int[42]{ 1, 2, 3 }), mSubObject(42)
{
	/* ... constructor body ... */
}
catch (const exception& e)
{
	// Cleanup memory.
	delete[] mData;
	mData = nullptr;
	cout << "function-try-block caught: '" << e.what() << "'" << endl;
}

int main()
{
	try {
		MyClass m;
	} catch (const exception& e) {
		cout << "main() caught: '" << e.what() << "'" << endl;
	}
	return 0;
}
