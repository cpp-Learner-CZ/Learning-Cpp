#include <print>
#include <iostream>
#include <limits>

#include "Search.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"

namespace search {
	void searchSwitch(int& input) {
		switch (input)
		{	
		case 1:
			break;

		case 2:
			break;

		case 3:
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
		std::println("=== Search product ===");
		std::println("1) By name");
		std::println("2) By price");
		std::println("3) By category");
		std::print("4) Back\nChoose: ");
		int chooseSeachType;
		while (!(std::cin >> chooseSeachType))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		searchSwitch(chooseSeachType);
	}
}