#include "Logger.h"
#include <fstream>
#include <iostream>

using namespace std;

Logger::Logger()
{
	// Start background thread.
	mThread = thread{ &Logger::processEntries, this };
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
		// Wait for a notification.
		mCondVar.wait(lock);

		// Condition variable notified, something might be in the queue.
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
	}
}
