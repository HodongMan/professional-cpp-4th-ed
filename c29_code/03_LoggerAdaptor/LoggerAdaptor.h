#pragma once

#include <string>
#include <string_view>

class Logger
{
public:
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	Logger();
	virtual ~Logger() = default;  // Always a virtual destructor!

	void log(LogLevel level, std::string message);

private:
	// Converts a log level to a human readable string.
	std::string_view getLogLevelString(LogLevel level) const;
};

class NewLoggerInterface
{
public:
	virtual ~NewLoggerInterface() = default;  // Always a virtual destructor!
	virtual void log(std::string_view message) = 0;
};

class NewLoggerAdaptor : public NewLoggerInterface
{
public:
	NewLoggerAdaptor();
	virtual void log(std::string_view message) override;

private:
	Logger mLogger;
};
