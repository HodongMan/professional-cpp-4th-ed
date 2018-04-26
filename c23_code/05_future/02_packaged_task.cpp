#include <iostream>
#include <thread>
#include <future>

using namespace std;

int CalculateSum(int a, int b)
{
	return a + b;
}

int main()
{
	// Create a packaged task to run CalculateSum.
	packaged_task<int(int, int)> task(CalculateSum);
	// Get the future for the result of the packaged task.
	auto theFuture = task.get_future();
	// Create a thread, move the packaged task into it, and
	// execute the packaged task with the given arguments.
	thread theThread{ std::move(task), 39, 3 };
	
	// Do some more work...

	// Get the result.
	int result = theFuture.get();
	cout << result << endl;

	// Make sure to join the thread.
	theThread.join();

	return 0;
}
