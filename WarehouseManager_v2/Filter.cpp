#include <print>
#include <iostream>
#include <limits>

#include "Filter.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"

namespace filter {
	void filterBiggerThan25() {
		std::println("== Filter price bigger than 25 ==");
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].price > 25)
			{
				Product product;
				product.showProduct(i);
			}
		}
	}

	void filterLowerThan100() {
		std::println("== Filter quantity lower than 100 ==");
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].quantity < 100)
			{
				Product	product;
				product.showProduct(i);
			}
		}
	}

	namespace categoryFilter {
		void categoryFridge() {
			std::println("= Sort by fridge category =");
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Fridge)
				{
					Product product;
					product.showProduct(i);
				}
			}
		}

		void categoryOven() {
			std::println("= Sort by oven category =");
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Oven)
				{
					Product product;
					product.showProduct(i);
				}
			}
		}

		void categoryToaster() {
			std::println("= Sort by toaster category =");
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Toaster)
				{
					Product product;
					product.showProduct(i);
				}
			}
		}

		void categoryIron() {
			std::println("= Sort by iron category =");
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Iron)
				{
					Product product;
					product.showProduct(i);
				}
			}
		}

		void categoryElectricShaver() {
			std::println("= Sort by elictric shaver category =");
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::ElectricShaver)
				{
					Product product;
					product.showProduct(i);
				}
			}
		}

		void filterCategorySwitch(const int& input) {
			switch (input)
			{
			case 1:
				categoryFridge();
				break;

			case 2:
				categoryOven();
				break;

			case 3:
				categoryToaster();
				break;

			case 4:
				categoryIron();
				break;

			case 5:
				categoryElectricShaver();
				break;

			case 6:
				lobby();
				break;

			default:
				std::cerr << error::wrongNumber1to6;
				logAction.emplace_back(logs::logWrongNumber1to6);
				filterCategoryMenu();
			}
		}
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

		categoryFilter::filterCategorySwitch(chooseCategory);
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