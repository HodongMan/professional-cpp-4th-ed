#include "RoundRobin.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

// Simple Process class.
class Process final
{
public:
	// Constructor accepting the name of the process.
	Process(string_view name) : mName(name) {}

	// Implementation of doWorkDuringTimeSlice() would let the process
	// perform its work for the duration of a time slice.
	// Actual implementation omitted.
	void doWorkDuringTimeSlice() {
		cout << "Process " << mName
			<< " performing work during time slice." << endl;
	}

	// Needed for the RoundRobin::remove() method to work.
	bool operator==(const Process& rhs) {
		return mName == rhs.mName;
	}

private:
	string mName;
};

// Simple round-robin based process scheduler.
class Scheduler final
{
public:
	// Constructor takes a vector of processes.
	Scheduler(const vector<Process>& processes);

	// Selects the next process using a round-robin scheduling
	// algorithm and allows it to perform some work during
	// this time slice.
	void scheduleTimeSlice();

	// Removes the given process from the list of processes.
	void removeProcess(const Process& process);

private:
	RoundRobin<Process> mProcesses;
};

Scheduler::Scheduler(const vector<Process>& processes)
{
	// Add the processes
	for (auto& process : processes) {
		mProcesses.add(process);
	}
}

void Scheduler::scheduleTimeSlice()
{
	try {
		mProcesses.getNext().doWorkDuringTimeSlice();
	} catch (const out_of_range&) {
		cerr << "No more processes to schedule." << endl;
	}
}

void Scheduler::removeProcess(const Process& process)
{
	mProcesses.remove(process);
}

int main()
{
	vector<Process> processes = { Process("1"), Process("2"), Process("3") };

	Scheduler scheduler(processes);
	for (int i = 0; i < 4; ++i)
		scheduler.scheduleTimeSlice();

	scheduler.removeProcess(processes[1]);
	cout << "Removed second process" << endl;

	for (int i = 0; i < 4; ++i)
		scheduler.scheduleTimeSlice();

	return 0;
}
