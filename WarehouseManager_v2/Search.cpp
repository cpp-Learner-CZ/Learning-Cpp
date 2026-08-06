#include <print>
#include <iostream>
#include <limits>
#include <string>

#include "Search.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"
#include "Verify.hpp"
#include "EnumOperation.hpp"

namespace search {
	void nameSearch() {
		std::println("=== Search by name ===");
		std::print("Name: ");
		std::string searchName_;
		std::getline(std::cin >> std::ws, searchName_);
		
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].name == searchName_)
			{
				Product product;
				product.showProduct(i);
				return;
			}
		}

		std::println("{}", error::nameDoesntExist);
	}

	void priceSearch() {
		std::println("=== Search by price ===");
		std::print("Price: ");
		double searchPrice_;
		while (!(std::cin >> searchPrice_))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nPrice: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		bool found = false;
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].price == searchPrice_)
			{
				Product product;
				product.showProduct(i);
				found = true;
			}
		}

		if (found) return;
		std::println("Can't find product with price {}.", searchPrice_);
	}

	void categorySearch() {
		std::println("=== Search by category ===");
		std::println("1) Fridge");
		std::println("2) Oven");
		std::println("3) Toaster");
		std::println("4) Iron");
		std::print("5) Electric shaver\nCategory: ");
		int chooseSearchCategory;
		while (!(std::cin >> chooseSearchCategory))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nCategory: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		if (!verify::enumInputIsOK(chooseSearchCategory))
		{
			std::cerr << error::invalidInputforSetEnum;
			logAction.emplace_back(logs::logInvalidInputEnumSet);
			return;
		}

		Category enumSearch = enumActions::intToCategory(chooseSearchCategory);

		bool found = false;
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].category == enumSearch)
			{
				Product product;
				product.showProduct(i);
				found = true;
			}
		}

		if (found) return;
		std::println("Can't find product with category {}.", enumActions::enumToString(enumSearch));
	}

	void searchSwitch(int& input) {
		switch (input)
		{	
		case 1:
			nameSearch();
			break;

		case 2:
			priceSearch();
			break;

		case 3:
			categorySearch();
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