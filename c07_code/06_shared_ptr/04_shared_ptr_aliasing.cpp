#include <memory>

using namespace std;

class Foo
{
public:
	Foo(int value) : mData(value) { }
	int mData;
};

int main()
{
	auto foo = make_shared<Foo>(42);
	auto aliasing = shared_ptr<int>(foo, &foo->mData);

	return 0;
}