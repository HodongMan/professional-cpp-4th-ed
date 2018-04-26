#include <functional>
#include <algorithm>
#include <cctype>
#include <string_view>
#include <iostream>

using namespace std;

bool isNumber(string_view str)
{
    class myIsDigit
    {
    public:
		bool operator()(char c) const { return ::isdigit(c) != 0; }
    };

	auto endIter = end(str);
	auto it = find_if(begin(str), endIter, not_fn(myIsDigit()));
	return (it == endIter);
}

int main()
{

    cout << isNumber("12345") << endl;
    cout << isNumber("hello") << endl;
    cout << isNumber("1234a") << endl;

    return 0;
}
