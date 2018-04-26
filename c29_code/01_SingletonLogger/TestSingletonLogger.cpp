#include "Logger.h"
#include <vector>
#include <string>

using namespace std;

int main()
{
	// Set log level to Debug.
	Logger::instance().setLogLevel(Logger::LogLevel::Debug);

	// Log some messages.
	Logger::instance().log("test message", Logger::LogLevel::Debug);
	vector<string> items = {"item1", "item2"};
	Logger::instance().log(items, Logger::LogLevel::Error);

	// Set log level to Error.
	Logger::instance().setLogLevel(Logger::LogLevel::Error);
	// Now that the log level is set to Error, logging a Debug
	// message will be ignored.
	Logger::instance().log("A debug message", Logger::LogLevel::Debug);

	return 0;
}
