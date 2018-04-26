#include "LoggerAdaptor.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Logger::Logger()
{
	cout << "Logger constructor" << endl;
}

void Logger::log(LogLevel level, std::string message)
{
	cout << getLogLevelString(level).data() << ": " << message << endl;
}

string_view Logger::getLogLevelString(LogLevel level) const
{
	switch (level) {
	case LogLevel::Error:
		return "ERROR";
	case LogLevel::Info:
		return "INFO";
	case LogLevel::Debug:
		return "DEBUG";
	}
	throw runtime_error("Invalid log level.");
}

NewLoggerAdaptor::NewLoggerAdaptor()
{
	cout << "NewLoggerAdaptor constructor" << endl;
}

void NewLoggerAdaptor::log(string_view message)
{
	mLogger.log(Logger::LogLevel::Info, message.data());
}
