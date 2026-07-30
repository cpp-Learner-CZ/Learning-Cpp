#include <print>
#include <iostream>
#include <limits>
#include <algorithm>

#include "Sorter.hpp"
#include "Error.hpp"
#include "Employee.hpp"

//Namespace for sort
namespace sorter {
	void sortFirstName() {
		std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
			return a.firstName < b.firstName;
			});
	}

	void sortLastName() {
		std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
			return a.lastName < b.lastName;
			});
	}

	void sortAge() {
		std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
			return a.age < b.age;
			});
	}

	void sortSalary() {
		std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
			return a.salary < b.salary;
			});
	}

	void sortDepartment() {
		std::sort(employees.begin(), employees.end(), [](const Employee& a, const Employee& b) {
			return static_cast<int>(a.department) < static_cast<int>(b.department);
			});
	}

	void sortSwitch(int sortSwitchInput) {
		switch (sortSwitchInput)
		{
		case 1:
			sortFirstName();
			std::println("Sorted.");
			break;

		case 2:
			sortLastName();
			std::println("Sorted.");
			break;

		case 3:
			sortAge();
			std::println("Sorted.");
			break;

		case 4:
			sortSalary();
			std::println("Sorted.");
			break;

		case 5:
			sortDepartment();
			std::println("Sorted.");
			break;

		case 6:
			break;

		default:
			std::cerr << error::wrongNumberOrMistake;
			lobby();
			break;
		}
	}

	//Main enter function for sort
	void lobby() {
		std::println("\n=== Sort ===");
		std::println("1) First name");
		std::println("2) Last name");
		std::println("3) Age");
		std::println("4) Salary");
		std::println("5) Department");
		std::print("6) Back\nChoose: ");
		int sortChoose;
		while (!(std::cin >> sortChoose)) {
			std::cerr << error::wrongNumber;
			std::print("\nPrint: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		sortSwitch(sortChoose);
	}
}