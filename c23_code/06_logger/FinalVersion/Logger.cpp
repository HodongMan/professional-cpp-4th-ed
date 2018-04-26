#include "Logger.h"
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

Logger::Logger()
{
	// Start background thread.
	mThread = thread{ &Logger::processEntries, this };
}

Logger::~Logger()
{
	{
		//unique_lock lock(mMutex);  // C++17
		unique_lock<mutex> lock(mMutex);
		// Gracefully shut down the thread by setting mExit
		// to true and notifying the thread.
		mExit = true;
		// Notify condition variable to wake up thread.
		mCondVar.notify_all();
	}
	// Wait until thread is shut down. This should be outside the above code
	// block because the lock must be released before calling join()!
	mThread.join();
}

void Logger::log(string_view entry)
{
	// Lock mutex and add entry to the queue.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	mQueue.push(string(entry));

	// Notify condition variable to wake up thread.
	mCondVar.notify_all();
}

void Logger::processEntries()
{
	// Open log file.
	ofstream logFile("log.txt");
	if (logFile.fail()) {
		cerr << "Failed to open logfile." << endl;
		return;
	}

	// Start processing loop.
	//unique_lock lock(mMutex);  // C++17
	unique_lock<mutex> lock(mMutex);
	while (true) {
		
		// You can add artificial delays on specific places in your multithreaded
		// code to trigger certain behavior. Note that such delays should only be
		// added for testing, and should be removed from your final code!
		//
		// For example, in this Logger class, you could add the following delay
		// to test that the race-condition with the destructor as discussed
		// in Chapter 23 is solved.
		//this_thread::sleep_for(1000ms); // Needs #include <chrono>

		if (!mExit) { // Only wait for notifications if we don't have to exit.
			// Wait for a notification.
			mCondVar.wait(lock);
		}

		// Condition variable is notified, so something might be in the queue
		// and/or we need to shut down this thread.
		lock.unlock();
		while (true) {
			lock.lock();
			if (mQueue.empty()) {
				break;
			} else {
				logFile << mQueue.front() << endl;
				mQueue.pop();
			}
			lock.unlock();
		}

		if (mExit) {
			break;
		}
	}
}
