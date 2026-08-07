#include <print>
#include <iostream>
#include <limits>
#include <algorithm>

#include "Sorter.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"

namespace sorter {
	void sortName() {
		std::sort(productList.begin(), productList.end(), [](const Product& a, const Product& b) {
			return a.name < b.name;
			});
	}

	void sortQuantity() {
		std::sort(productList.begin(), productList.end(), [](const Product& a, const Product& b) {
			return a.quantity < b.quantity;
			});
	}

	void sortPrice() {
		std::sort(productList.begin(), productList.end(), [](const Product& a, const Product& b) {
			return a.price < b.price;
			});
	}

	void sortSwitch(const int& input) {
		switch (input)
		{
		case 1:
			sortName();
			std::println("Sorted.");
			break;
			
		case 2:
			sortQuantity();
			std::println("Sorted.");
			break;

		case 3:
			sortPrice();
			std::println("Sorted.");
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
		std::println("=== Sort ===");
		std::println("1) By name");
		std::println("2) By quantity");
		std::println("3) By price");
		std::print("4) Back\nChoose: ");
		int chooseSort;
		while (!(std::cin >> chooseSort))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		sortSwitch(chooseSort);
	}
}