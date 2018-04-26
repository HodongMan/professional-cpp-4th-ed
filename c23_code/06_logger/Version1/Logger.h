#pragma once

#include <queue>
#include <string>
#include <string_view>
#include <thread>
#include <mutex>
#include <condition_variable>

class Logger
{
public:
	// Starts a background thread writing log entries to a file.
	Logger();
	// Prevent copy construction and assignment.
	Logger(const Logger& src) = delete;
	Logger& operator=(const Logger& rhs) = delete;
	// Add log entry to the queue.
	void log(std::string_view entry);

private:
	// The function running in the background thread.
	void processEntries();
	// Mutex and condition variable to protect access to the queue.
	std::mutex mMutex;
	std::condition_variable mCondVar;
	std::queue<std::string> mQueue;
	// The background thread.
	std::thread mThread;
};
