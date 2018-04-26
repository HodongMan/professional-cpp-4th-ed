#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG_MODE

#ifdef DEBUG_MODE
	class Logger
	{
	public:
		template<typename... Args>
		static void log(const Args&... args)
		{
			ofstream logfile(msDebugFileName, ios_base::app);
			if (logfile.fail()) {
				cerr << "Unable to open debug file!" << endl;
				return;
			}
			// Use a C++17 unary right fold, see Chapter 22.
			((logfile << args), ...);
			logfile << endl;
		}

	private:
		static const string msDebugFileName;
	};
	const string Logger::msDebugFileName = "debugfile.out";

	#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
	#define log(...)
#endif

// WARNING:
//		Be careful not to put any code that must be executed for correct program
//		functioning inside your log() calls. For example, a line as follows is
//		probably asking for trouble:
//		    log("Result: ", myFunctionCall());
//		If DEBUG_MODE is not defined, the preprocessor replaces all log() calls with
//		no-ops, which means that the call to myFunctionCall() is removed as well!

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
			log("received exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef DEBUG_MODE
	// Print the command-line arguments to the trace
	for (int i = 0; i < argc; i++) {
		log(argv[i]);
	}
#endif

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Rest of the function not shown
	return 0;
}
