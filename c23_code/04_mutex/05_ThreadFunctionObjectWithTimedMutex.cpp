#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: mId(id), mNumIterations(numIterations)
	{
	}

	void operator()() const
	{
		for (int i = 0; i < mNumIterations; ++i) {
			//unique_lock lock(sTimedMutex, 200ms);  // C++17
			unique_lock<timed_mutex> lock(sTimedMutex, 200ms);
			if (lock) {
				cout << "Counter " << mId << " has value " << i << endl;
			} else {
				// Lock not acquired in 200ms, skip output.
			}
		}
	}

private:
	int mId;
	int mNumIterations;
	static timed_mutex sTimedMutex;
};

timed_mutex Counter::sTimedMutex;

int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{ 1, 20 } };

	// Using named variable
	Counter c(2, 12);
	thread t2(c);

	// Using temporary
	thread t3(Counter(3, 10));

	// Wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
