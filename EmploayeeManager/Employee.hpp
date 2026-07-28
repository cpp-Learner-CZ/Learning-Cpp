#pragma once
#include <string>
#include <vector>

//Use enum class to avoid user errors
enum class Department
{
	IT = 1,
	HR = 2,
	Finance = 3,
	Sales = 4
};
enum class EmploymentStatus
{
	Active = 1,
	Vacation = 2,
	SickLeave = 3
};

//Main class definition for easy use with vector
class Employee {
public:
	std::string firstName;
	std::string lastName;
	int age;
	double salary;
	Department department;
	EmploymentStatus employmentStatus;

	Employee(std::string f, std::string l, int a, double s, Department d, EmploymentStatus e) {
		firstName = f;
		lastName = l;
		age = a;
		salary = s;
		department = d;
		employmentStatus = e;
	}
};

extern std::vector<Employee> employees;

//Namespace for add empleyees
namespace add {
	void addEmployee();
}

//Namespace for edit employees
namespace edit {
	void lobby();
}

//Namespace for remove employees
namespace remover {
	void lobby();
}

void showEmployees();