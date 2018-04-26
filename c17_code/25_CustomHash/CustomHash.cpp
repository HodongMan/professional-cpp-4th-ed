#include <cstddef>
#include <unordered_set>
#include <functional>
#include <iostream>

using namespace std;

class IntWrapper
{
public:
	IntWrapper(int i) : mWrappedInt(i) {}
	int getValue() const { return mWrappedInt; }

private:
	int mWrappedInt;
};

bool operator==(const IntWrapper& lhs, const IntWrapper& rhs)
{
	return lhs.getValue() == rhs.getValue();
}

namespace std
{
	template<> struct hash<IntWrapper>
	{
		using argument_type = IntWrapper;
		using result_type = size_t;

		result_type operator()(const argument_type& f) const {
			return std::hash<int>()(f.getValue());
		}
	};
}

int main()
{
	unordered_set<IntWrapper> s;
	s.insert(IntWrapper(1));
	s.insert(IntWrapper(2));

	for (const auto& element : s) {
		cout << element.getValue() << endl;
	}

	return 0;
}
