#include <vector>
#include <print>
#include <iostream>
#include <string>

#include "Employee.hpp"
#include "Verify.hpp"
#include "Error.hpp"
#include "EnumOperation.hpp"

std::vector<Employee> employees;

//Namespace for add empleyees
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

		if (verify::nameExistVerify(newFirstName, newLastName))
		{
			std::cerr << error::nameIsExist;
			return;
		}

		setDepartment();
	}
}

//Namespace for edit employees
namespace edit {
	std::string chooseFirstName;
	std::string chooseLastName;

	void editAge() {
		int newAge;
		std::println("== Edit age ==");
		std::print("New age: ");
		while (!(std::cin >> newAge))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == chooseFirstName && employees[i].lastName == chooseLastName)
			{
				employees[i].age = newAge;
				std::println("Age updated.");
			}
		}
	}

	void editSalary() {
		double newSalary;
		std::println("== Edit salary ==");
		std::print("New salary: ");
		while (!(std::cin >> newSalary))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == chooseFirstName && employees[i].lastName == chooseLastName)
			{
				employees[i].salary = newSalary;
				std::println("Salary updated.");
			}
		}
	}

	void editDepartment() {
		int newDepartment;
		std::println("== Edit department ==");
		std::println("1) IT");
		std::println("2) HR");
		std::println("3) Finance");
		std::print("4) Sales\nChoose: ");
		while (!(std::cin >> newDepartment))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		//Verify if user writed 1-4
		if (!verify::departmentInputIsCompatible(newDepartment))
		{
			std::cerr << error::errorInputSetDepartment;
			return;
		}

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == chooseFirstName && employees[i].lastName == chooseLastName)
			{
				employees[i].department = enumOperation::intToDepartment(newDepartment);
				std::println("Department updated.");
			}
		}
	}

	void editEploymentStatus() {
		int newEploymentStatus;
		std::println("== Edit eployment statsu ==");
		std::println("1) Active");
		std::println("2) Vacation");
		std::print("3) Sick leave\nChoose: ");
		while (!(std::cin >> newEploymentStatus))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		//Verify if user writed 1-3
		if (!verify::employmentStatusIsCompatible(newEploymentStatus))
		{
			std::cerr << error::errorInputEmploymentStatus;
			return;
		}

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == chooseFirstName && employees[i].lastName == chooseLastName)
			{
				employees[i].employmentStatus = enumOperation::intToEmploymentStatus(newEploymentStatus);
				std::println("Employment status updated.");
			}
		}
	}

	void chooseEditOperation(int chooseEdit) {
		switch (chooseEdit)
		{
		case 1:
			editAge();
			break;

		case 2:
			editSalary();
			break;

		case 3:
			editDepartment();
			break;

		case 4:
			editEploymentStatus();
			break;

		case 5:
			break;

		default:
			std::cerr << error::mistakeNumberEdit;
			break;
		}
	}

	//Main enter for edit employees
	void editMainChoose() {
		int editChoose;
		std::println("=== Edit employee ===");
		std::println("1) Age");
		std::println("2) Salary");
		std::println("3) Department");
		std::println("4) Employment status");
		std::print("5) Back\nChoose: ");
		while (!(std::cin >> editChoose))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		chooseEditOperation(editChoose);
	}

	void lobby() {
		std::println("=== Edit employee ===");
		std::print("Write first name for edit: ");
		std::getline(std::cin >> std::ws, chooseFirstName);

		std::print("Write last name for edit: ");
		std::getline(std::cin >> std::ws, chooseLastName);

		if (!verify::nameExistVerify(chooseFirstName, chooseLastName))
		{
			std::cerr << error::nameIsntExist;
			return;
		}

		editMainChoose();
	}
}

//Namespace for remove employees
namespace remover {
	std::string remFirstName;
	std::string remLastName;

	void removed() {
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == remFirstName && employees[i].lastName == remLastName)
			{
				employees.erase(employees.begin() + i);
				std::println("Employee removed.");
			}
		}
	}

	void consentRemove() {
		std::print("Are you sure for remove employee with:\n-first name: {}\n-last name: {}\nWrite y or n: ", remFirstName, remLastName);
		std::string constentYesNo;
		std::getline(std::cin >> std::ws, constentYesNo);
		bool consentBool = (constentYesNo == "y" || constentYesNo == "Y");

		if (!consentBool)
		{
			std::println("Remove canceled.");
			return;
		}
		removed();
	}

	//Main enter function for remove
	void lobby() {
		std::println("=== Remove employee ===");
		std::print("Write first name for remove: ");
		std::getline(std::cin >> std::ws, remFirstName);
		
		std::print("Write last name for remove: ");
		std::getline(std::cin >> std::ws, remLastName);

		if (!verify::nameExistVerify(remFirstName, remLastName))
		{
			std::cerr << error::nameIsntExist;
			return;
		}
		consentRemove();
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