#include <atomic>
#include <iostream>
#include <type_traits>

using namespace std;

class Foo { private: int mArray[123]; };
class Bar { private: int mInt; };

int main()
{
	atomic<Foo> f;
	cout << is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << endl;

	atomic<Bar> b;
	cout << is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << endl;
}
