#pragma once

#include <ostream>
#include <string>
#include <string_view>
#include <stack>

// Sample Error class with just a priority and a string error description.
class Error final
{
public:
	Error(int priority, std::string_view errorString) : mPriority(priority), mErrorString(errorString) {}
	int getPriority() const { return mPriority; }
	std::string_view getErrorString() const { return mErrorString; }

private:
	int mPriority;
	std::string mErrorString;
};

bool operator<(const Error& lhs, const Error& rhs);
std::ostream& operator<<(std::ostream& os, const Error& err);

// Simple ErrorCorrelator class that returns most recent errors first.
class ErrorCorrelator final
{
public:
	// Add an error to be correlated.
	void addError(const Error& error);

	// Retrieve the next error to be processed.
	Error getError();

private:
	std::stack<Error> mErrors;
};
