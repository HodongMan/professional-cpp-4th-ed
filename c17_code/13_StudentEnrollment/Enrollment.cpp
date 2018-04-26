#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// courseStudents is a vector of lists, one for each course. The lists
// contain the students enrolled in those courses. They are not sorted.
//
// droppedStudents is a list of students who failed to pay their
// tuition and so were dropped from their courses.
//
// The function returns a list of every enrolled (non-dropped) student in
// all the courses.
list<string> getTotalEnrollment(const vector<list<string>>& courseStudents,
								const list<string>& droppedStudents)
{
	list<string> allStudents;

	// Concatenate all the course lists onto the master list
	for (auto& lst : courseStudents) {
		allStudents.insert(cend(allStudents), cbegin(lst), cend(lst));
	}

	// Sort the master list
	allStudents.sort();

	// Remove duplicate student names (those who are in multiple courses).
	allStudents.unique();

	// Remove students who are on the dropped list.
	// Iterate through the dropped list, calling remove on the
	// master list for each student in the dropped list.
	for (auto& str : droppedStudents) {
		allStudents.remove(str);
	}

	// done!
	return allStudents;
}

list<string> readStudentList(ifstream& istr)
{
	list<string> students;
	string name;
	while (getline(istr, name)) {
		cout << "Read name " << name << endl;
		students.push_back(name);
	}
	return students;
}

vector<list<string>> readCourseLists()
{
	vector<list<string>> lists;
	for (int i = 1;; i++) {
		ostringstream ostr;
		ostr << "course" << i << ".txt";

		ifstream istr(ostr.str().c_str());
		if (!istr) {
			cout << "Failed to open " << ostr.str() << endl;
			break;
		}
		lists.push_back(readStudentList(istr));
	}
	return lists;
}

list<string> readDroppedStudents()
{
	ifstream istr("dropped.txt");
	return readStudentList(istr);
}

int main()
{
	vector<list<string>> courseStudents = readCourseLists();
	list<string> droppedStudents = readDroppedStudents();

	list<string> finalList = getTotalEnrollment(courseStudents, droppedStudents);

	for (const auto& name : finalList) {
		cout << name << endl;
	}

	return 0;
}
