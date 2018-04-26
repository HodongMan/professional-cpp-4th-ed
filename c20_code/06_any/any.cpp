#include <any>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	any empty;
	any anInt(3);
	any aString("An std::string."s);

	cout << "empty.has_value = " << empty.has_value() << endl;
	cout << "anInt.has_value = " << anInt.has_value() << endl << endl;

	cout << "anInt wrapped type = " << anInt.type().name() << endl;
	cout << "aString wrapped type = " << aString.type().name() << endl << endl;

	int theInt = any_cast<int>(anInt);
	cout << theInt << endl;
	try {
		int test = any_cast<int>(aString);
		cout << test << endl;
	} catch (const bad_any_cast& ex) {
		cout << "Exception: " << ex.what() << endl;
	}


	any something(3);              // Now it contains an integer.
	something = "An std::string"s; // Now the same instance contains a string.


	vector<any> v;
	v.push_back(any(42));
	v.push_back(any("An std::string"s));

	cout << any_cast<string>(v[1]) << endl;

	return 0;
}
