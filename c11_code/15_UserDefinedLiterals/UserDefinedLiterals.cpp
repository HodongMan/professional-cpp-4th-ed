#include <cstddef>
#include <complex>

// Cooked _i literal
std::complex<long double> operator"" _i(long double d)
{  
	return std::complex<long double>(0, d);  
}

// Raw _i literal
//std::complex<long double> operator"" _i(const char* p)
//{
//    // Implementation omitted; it requires parsing the C-style
//    // string and converting it to a complex number.
//}


// Cooked _s literal
std::string operator"" _s(const char* str, size_t len)
{
	return std::string(str, len);
}

int main()
{
	// Cooked _i literal
	std::complex<long double> c1 = 9.634_i;
	auto c2 = 1.23_i;         // c2 has as type std::complex<long double>

	// Cooked _s literal
	std::string str1 = "Hello World"_s;
	auto str2 = "Hello World"_s;   // str2 has as type std::string
	auto str3 = "Hello World";     // str3 has as type const char*;

	return 0;
}
