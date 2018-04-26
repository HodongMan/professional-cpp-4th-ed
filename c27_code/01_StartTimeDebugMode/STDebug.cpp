#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Logger
{
public:
	static void enableLogging(bool enable) { msLoggingEnabled = enable; }
	static bool isLoggingEnabled() { return msLoggingEnabled; }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!msLoggingEnabled)
			return;

		ofstream logfile(msDebugFileName, ios_base::app);
		if (logfile.fail()) {
			cerr << "Unable to open debug file!" << endl;
			return;
		}
		// Use a C++17 unary right fold, see Chapter 22.
		((logfile << args),...);
		logfile << endl;
	}

private:
	static const string msDebugFileName;
	static bool msLoggingEnabled;
};

const string Logger::msDebugFileName = "debugfile.out";
bool Logger::msLoggingEnabled = false;



#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)



bool isDebugSet(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			return true;
		}
	}
	return false;
}



class ComplicatedClass
{
	// class details omitted for brevity
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& /* src */)
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
	// class details not shown for brevity
};
ostream& operator<<(ostream& ostr, const UserCommand& /* src */)
{
	ostr << "UserCommand";
	return ostr;
}



UserCommand getNextCommand(ComplicatedClass* /* obj */)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand& /* cmd */)
{
	// details omitted for brevity
}

void trickyFunction(ComplicatedClass* obj)
{
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled()) {
		// Print the command-line arguments to the trace
		for (int i = 0; i < argc; i++) {
			log(argv[i]);
		}
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Rest of the function not shown
	return 0;
}
