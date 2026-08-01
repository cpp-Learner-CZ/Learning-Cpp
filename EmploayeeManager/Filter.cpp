#include <print>
#include <iostream>
#include <limits>

#include "Filter.hpp"
#include "Error.hpp"
#include "Employee.hpp"
#include "EnumOperation.hpp"

//Namespace for filter
namespace filter {
	void onlyIT() {
		std::println("== Filter only IT ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].department == Department::IT)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void onlyHR() {
		std::println("== Filter only HR ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].department == Department::HR)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void onlyActive() {
		std::println("== Filter only active ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].employmentStatus == EmploymentStatus::Active)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void onlySickLeave() {
		std::println("== Filter only sick leave ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].employmentStatus == EmploymentStatus::SickLeave)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void salaryBiggerThan20() {
		std::println("== Filter salary bigger than 20 ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].salary > 20)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void ageBiggerThan18() {
		std::println("== Filter age bigger than 18 ==");
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].age > 18)
			{
				std::println("First name: {}", employees[i].firstName);
				std::println("Last name: {}", employees[i].lastName);
				std::println("Age: {}", employees[i].age);
				std::println("Salary: {}", employees[i].salary);
				std::println("Department: {}", enumOperation::enumDepartmentToString(employees[i].department));
				std::println("Employment satus: {}", enumOperation::enumEmploymentStatusToString(employees[i].employmentStatus));
				std::println("----------------------------");
			}
		}
	}

	void filterChooseSwitch(int chooseFilterInput) {
		switch (chooseFilterInput)
		{
		case 1:
			onlyIT();
			break;

		case 2:
			onlyHR();
			break;

		case 3:
			onlyActive();
			break;

		case 4:
			onlySickLeave();
			break;

		case 5:
			salaryBiggerThan20();
			break;

		case 6:
			ageBiggerThan18();
			break;

		case 7:
			break;

		default:
			logsVector.emplace_back("[Warning] Wrote the number zero or a number bigger than seven.");
			std::cerr << error::wrongNumberOrMistake;
			lobby();
			break;
		}
	}

	//Main enter function for filter
	void lobby() {
		std::println("\n=== Filter ===");
		std::println("1) Only IT");
		std::println("2) Only HR");
		std::println("3) Only active");
		std::println("4) Only sick leave");
		std::println("5) Salary bigger than 20");
		std::println("6) Age bigger than 18");
		std::print("7) Back\nChoose: ");
		int chooseFilter;
		while (!(std::cin >> chooseFilter))
		{
			logsVector.emplace_back("[Warning] Wrote a letter instead of a number.");
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		filterChooseSwitch(chooseFilter);
	}
}