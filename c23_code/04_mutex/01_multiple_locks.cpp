#include <mutex>

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	//unique_lock lock1(mut1, defer_lock);  // C++17
	//unique_lock lock2(mut2, defer_lock);  // C++17
	unique_lock<mutex> lock1(mut1, defer_lock);
	unique_lock<mutex> lock2(mut2, defer_lock);
	lock(lock1, lock2);
	// Locks acquired
} // Locks automatically released

int main()
{
	process();
	
	return 0;
}
