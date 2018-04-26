#include <iostream>
#include <memory>

using namespace std;

struct Employee {
	char firstInitial = 'M';
	char lastInitial = 'G';
	int  employeeNumber = 42;
	int  salary = 80'000;
};

int main()
{
	{
		// Using a unique_ptr
		auto anEmployee = make_unique<Employee>();
		if (anEmployee) {
			cout << "Salary: " << anEmployee->salary << endl;
		}
	}

	{
		// Storing an array in a unique_ptr
		auto employees = make_unique<Employee[]>(10);
		cout << "Salary: " << employees[0].salary << endl;
	}

	{
		// Using a shared_ptr
		auto anEmployee = make_shared<Employee>();
		if (anEmployee) {
			cout << "Salary: " << anEmployee->salary << endl;
		}
	}

	{
		// Storing an array in a shared_ptr (C++17)
		shared_ptr<Employee[]> employees(new Employee[10]);
		cout << "Salary: " << employees[0].salary << endl;
	}
}
