#include <print>
#include <iostream>
#include <limits>

#include "Filter.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"

namespace filter {
	void filterBiggerThan25() {
		// Later
	}

	void filterLowerThan100() {
		// Later
	}

	void filterCategoryMenu() {
		std::println("== Filter category menu ==");
		std::println("1) Fridge");
		std::println("2) Oven");
		std::println("3) Toaster");
		std::println("4) Iron");
		std::println("5) Electric shaver");
		std::print("6) Back\nChoose: ");
		int chooseCategory;
		while (!(std::cin >> chooseCategory))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// Later
	}

	void filterSwitch(const int& input) {
		switch (input)
		{
		case 1:
			filterBiggerThan25();
			break;

		case 2:
			filterLowerThan100();
			break;

		case 3:
			filterCategoryMenu();
			break;

		case 4:
			break;

		default:
			std::cerr << error::wrongNumber1to4;
			logAction.emplace_back(logs::logWrongNumber1to4);
			lobby();
		}
	}

	void lobby() {
		std::println("=== Filter ===");
		std::println("1) Price bigger than 25");
		std::println("2) Quantity lower than 100");
		std::println("3) Category filter menu");
		std::print("4) Back\nChoose filter: ");
		int chooseFilter;
		while (!(std::cin >> chooseFilter))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose filter: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		filterSwitch(chooseFilter);
	}
}