#include <memory>

using namespace std;

class Foo
{
public:
	Foo(unique_ptr<int> data) : mData(move(data)) { }

private:
	unique_ptr<int> mData;
};

int main()
{
	auto myIntSmartPtr = make_unique<int>(42);
	Foo f(move(myIntSmartPtr));

    return 0;
}
