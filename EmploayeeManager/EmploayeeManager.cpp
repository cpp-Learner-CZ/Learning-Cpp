#include <iostream>
#include <print>
#include <cstdlib>

#include "Error.hpp"
#include "Version.hpp"
#include "Employee.hpp"
#include "Verify.hpp"
#include "Search.hpp"
#include "Filter.hpp"
#include "Sorter.hpp"
#include "Statistics.hpp"
#include "Data.hpp"

bool programRun = true;

//Main switch for selection of functions
void mainSwitch(int switchChoose) {
	switch (switchChoose)
	{
	case 1:
		add::addEmployee();
		break;

	case 2:
		showEmployees();
		break;

	case 3:
		edit::lobby();
		break;

	case 4:
		remover::lobby();
		break;

	case 5:
		search::lobby();
		break;

	case 6:
		filter::lobby();
		break;

	case 7:
		sorter::lobby();
		break;

	case 8:
		statistics::lobby();
		break;

	case 9: {
		Employee employee;
		employee.showLogs();
		break;
	    }

	case 10:
		std::println("Program terminated.");
		programRun = false;
		fileActions::saveData();
		exit(0);

	default:
		std::cerr << error::wrongNumberOrMistake;
		logsVector.emplace_back("[Warning] Wrote number zero or number bigger than ten.");
		break;
	}
}

int main()
{
	fileActions::loadData();
	while (programRun)
	{
		std::println("\n==== Emploayee manager v{} ====", actualVersion);
		std::println("1) Add employee");
		std::println("2) Show employees");
		std::println("3) Edit employee");
		std::println("4) Remove employee");
		std::println("5) Search employee");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::println("9) Export report");
		std::print("10) Terminate\nChoose: ");
		int choose;
		while (!(std::cin >> choose))
		{
			logsVector.emplace_back("[Warning] Wrote a letter instead of a number.");
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		mainSwitch(choose);
	}
}