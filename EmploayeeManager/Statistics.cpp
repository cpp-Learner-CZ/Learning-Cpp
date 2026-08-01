#include <print>
#include <iostream>

#include "Statistics.hpp"
#include "Employee.hpp"
#include "Sorter.hpp"

//Namespace for statistics
namespace statistics {
	int employeeCount = 0;

	float averageAge() {
		int sumAge = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			sumAge = sumAge + employees[i].age;
		}
		return sumAge / employeeCount;
	}

	double averageSalary() {
		double sumSalary = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			sumSalary = sumSalary + employees[i].salary;
		}
		return sumSalary / employeeCount;
	}

	namespace employeesInDiferrentDepartures {
		int departmentIT() {
			int totalIT = 0;
			for (size_t i = 0; i < employees.size(); i++)
			{
				if (employees[i].department == Department::IT)
				{
					totalIT++;
				}
			}
			return totalIT;
		}

		int departmentHR() {
			int totalHR = 0;
			for (size_t i = 0; i < employees.size(); i++)
			{
				if (employees[i].department == Department::HR)
				{
					totalHR++;
				}
			}
			return totalHR;
		}

		int departmentFinance() {
			int totalFinance = 0;
			for (size_t i = 0; i < employees.size(); i++)
			{
				if (employees[i].department == Department::Finance)
				{
					totalFinance++;
				}
			}
			return totalFinance;
		}

		int departmentSales() {
			int totalSales = 0;
			for (size_t i = 0; i < employees.size(); i++)
			{
				if (employees[i].department == Department::Sales)
				{
					totalSales++;
				}
			}
			return totalSales;
		}
	}

	int employeeActive() {
		int activeCount = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].employmentStatus == EmploymentStatus::Active)
			{
				activeCount++;
			}
		}
		return activeCount;
	}

	int employeeVacation() {
		int vacationCount = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].employmentStatus == EmploymentStatus::Vacation)
			{
				vacationCount++;
			}
		}
		return vacationCount;
	}

	int employeeSickLeave() {
		int sickLeaveCount = 0;
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].employmentStatus == EmploymentStatus::SickLeave)
			{
				sickLeaveCount++;
			}
		}
		return sickLeaveCount;
	}

	std::string biggerSalary() {
		sorter::sortSalary();

		int biggerSalaryInt = employeeCount - 1;
		std::string biggerSalaryName = employees[biggerSalaryInt].firstName;

		sorter::sortFirstName();

		return biggerSalaryName;
	}

	std::string lowerSalary() {
		sorter::sortSalary();

		std::string lowerSalaryName = employees[0].firstName;

		sorter::sortFirstName();

		return lowerSalaryName;
	}

	//Main enter function for statistics
	void lobby() {
		std::println("=== Statistics ===");
		//This if block checks if the vector is not empty. Without it, the program would crash.
		if (employees.size() == 0)
		{
			logsVector.emplace_back("[Error] Can't load statistics because the employee list is empty.");
			std::cerr << "ERROR: Cannot load statistics because the employee list is empty!";
			return;
		}

		employeeCount = employees.size();
		std::println("Total count employees: {}", employeeCount);
		std::println("Average employee age: {}", averageAge());
		std::println("Average employee salary: {}", averageSalary());
		std::println("\nEmployees in different departures");
		std::println("---------------------------------");
		std::println("IT: {}", employeesInDiferrentDepartures::departmentIT());
		std::println("HR: {}", employeesInDiferrentDepartures::departmentHR());
		std::println("Finance: {}", employeesInDiferrentDepartures::departmentFinance());
		std::println("Sales: {}", employeesInDiferrentDepartures::departmentSales());
		std::println("---------------------------------");
		std::println("Active employees count: {}", employeeActive());
		std::println("Vacation employee count: {}", employeeVacation());
		std::println("Sick leave employee count: {}", employeeSickLeave());
		std::println("Bigger salary employee: {}", biggerSalary());
		std::println("Lower salary employee {}", lowerSalary());
	}
}