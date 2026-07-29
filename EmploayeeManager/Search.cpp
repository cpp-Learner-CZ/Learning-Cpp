#include <print>
#include <iostream>
#include <limits>

#include "Search.hpp"
#include "Error.hpp"
#include "Employee.hpp"
#include "EnumOperation.hpp"
#include "Verify.hpp"

//Namespace for search employees
namespace search {
	void firstNameSearch() {
		std::println("=== Search by first name ===");
		std::print("First name: ");
		std::string searchFirstName;
		std::getline(std::cin >> std::ws, searchFirstName);
		bool founded = false;
		
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == searchFirstName)
			{
				founded = true;
				std::println("\nFirst name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println();
			}
		}
		if (!founded)
		{
			std::cerr << error::nameIsntExist;
		}
	}

	void lastNameSearch() {
		std::println("=== Search by last name ===");
		std::print("Last name: ");
		std::string searchLastName;
		std::getline(std::cin >> std::ws, searchLastName);
		bool founded = false;

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].lastName == searchLastName)
			{
				founded = true;
				std::println("\nFirst name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println();
			}
		}
		if (!founded)
		{
			std::cerr << error::nameIsntExist;
		}
	}

	void departmentSearch() {
		std::println("=== Search by department ===");
		std::println("1) IT");
	    std::println("2) HR");
		std::println("3) Finance");
		std::println("4) Sales");
		std::print("Choose: ");
		int chooseSearchDepartment;
		while (!(std::cin >> chooseSearchDepartment))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (!verify::departmentInputIsCompatible(chooseSearchDepartment))
		{
			std::cerr << error::errorInputSetDepartment;
			return;
		}

		Department searchDepartment = enumOperation::intToDepartment(chooseSearchDepartment);
		bool founded = false;

		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].department == searchDepartment)
			{
				founded = true;
				std::println("\nFirst name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println();
			}
		}
		if (!founded)
		{
			std::cerr << error::nameIsntExist;
		}
	}

	void searchChoose(int chooseSearch) {
		switch (chooseSearch)
		{
		case 1:
			firstNameSearch();
			break;

		case 2:
			lastNameSearch();
			break;

		case 3:
			departmentSearch();
			break;

		case 4:
			break;

		default:
			std::cerr << error::wrongNumberOrMistake;
			break;
		}
	}

	//Main enter function for search
	void lobby() {
		int chooseSearch_;
		std::println("=== Search employee ===");
		std::println("1) By first name");
		std::println("2) By last name");
		std::println("3) By department");
		std::print("4) Back\nChoose: ");

		while (!(std::cin >> chooseSearch_))
		{
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		searchChoose(chooseSearch_);
	}
}