#include <iostream>
#include <locale>

using namespace std;

int main()
{
	// User locale
	wcout.imbue(locale(""));
	wcout << 32767 << endl;

	// Classic/neutral locale
	wcout.imbue(locale("C"));
	wcout << 32767 << endl;

	// U.S. English locale
	wcout.imbue(locale("en-US")); // "en_US" for POSIX
	wcout << 32767 << endl;

	return 0;
}
