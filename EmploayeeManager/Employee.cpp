#include <vector>
#include <print>
#include <iostream>
#include <string>

#include "Employee.hpp"
#include "Verify.hpp"
#include "Error.hpp"
#include "EnumOperation.hpp"

std::vector<Employee> employees;

//Namespace for add empleyee
namespace add {
	std::string newFirstName;
	std::string newLastName;
	int newAge;
	double newSalary;
	Department newDepartment;
	EmploymentStatus newEmploymentStatus;
	
	void save() {
		employees.emplace_back(newFirstName, newLastName, newAge, newSalary, newDepartment, newEmploymentStatus);
		std::println("Employee added.");
	}

	void setEmploymentStatus() {
		std::println("== Set employment status ==");
		std::println("1) Active");
		std::println("2) Vocation");
		std::println("3) Sick Leave");
		std::print("Choose: ");
		int chooseDeploymentStatus;
		while (!(std::cin >> chooseDeploymentStatus))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}

		//Verify if user writed 1-3
		if (!verify::employmentStatusIsCompatible(chooseDeploymentStatus))
		{
			std::cerr << error::errorInputEmploymentStatus;
			return;
		}

		newEmploymentStatus = enumOperation::intToEmploymentStatus(chooseDeploymentStatus);
		save();
	}

	void setDepartment() {
		std::println("== Set department ==");
		std::println("1) IT");
		std::println("2) HR");
		std::println("3) Finance");
		std::println("4) Sales");
		std::print("Choose: ");
		int chooseDepartment;
		while (!(std::cin >> chooseDepartment))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}

		//Verify if user writed 1-4
		if (!verify::departmentInputIsCompatible(chooseDepartment))
		{
			std::cerr << error::errorInputSetDepartment;
			return;
		}

		newDepartment = enumOperation::intToDepartment(chooseDepartment);
		setEmploymentStatus();
	}

	//Main enter for add employees
	void addEmployee() {
		std::println("=== Add employee ===");
		std::print("Write employee first name: ");
		std::getline(std::cin >> std::ws, newFirstName);

		std::print("Write employee last name: ");
		std::getline(std::cin >> std::ws, newLastName);

		std::print("Write employee age: ");
		while (!(std::cin >> newAge))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		
		std::print("Write employee salary: ");
		while (!(std::cin >> newSalary))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		setDepartment();
	}
}

void showEmployees() {
	std::println("=== Show employees ===");
	for (size_t i = 0; i < employees.size(); i++)
	{
		std::println("First name: {}", employees[i].firstName);
		std::println("Last name: {}", employees[i].lastName);
		std::println("Age: {}", employees[i].age);
		std::println("Salary: {}", employees[i].salary);
		std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
		std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
		std::println("----------------------------");
	}
	if (employees.size() == 0)
	{
		std::println("No employees found.");
	}
}