#include <iostream>
#include <thread>
#include <future>

using namespace std;

void DoWork(promise<int> thePromise)
{
	// ... Do some work ...
	// And ultimately store the result in the promise.
	thePromise.set_value(42);
}

int main()
{
	// Create a promise to pass to the thread.
	promise<int> myPromise;
	// Get the future of the promise.
	auto theFuture = myPromise.get_future();
	// Create a thread and move the promise into it.
	thread theThread{ DoWork, std::move(myPromise) };

	// Do some more work...

	// Get the result.
	int result = theFuture.get();
	cout << "Result: " << result << endl;

	// Make sure to join the thread.
	theThread.join();

	return 0;
}
