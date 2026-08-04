#include <print>
#include <string>
#include <iostream>
#include <limits>

#include "Editor.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "Warehouse.hpp"

namespace editProduct {
	std::string editName_;

	void editName() {
		std::println("== Edit name ==");
		std::print("Write new name: ");
		std::string newName;
		std::getline(std::cin >> std::ws, newName);

		if (verify::nameIsExist(newName))
		{
			logAction.emplace_back(logs::logNameAlredyExist);
			std::cerr << error::nameAlredyExist;
			std::println("\nOperation canceled.");
			return;
		}

		Product product;
		if (product.updateName(editName_, newName))
		{
			logAction.emplace_back(logs::logEditNameCompleted);
			std::println("Name updated.");
			return;
		} 

		std::cerr << error::nameEditError;
		logAction.emplace_back(logs::logEditNameCompleted);
	}

	void editAddStock() {
		std::println("== Add stock ==");
		std::print("Add: ");
		int addStock_;
		while (!(std::cin >> addStock_)) {
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nAdd: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		Product product;
		if (product.addStock(editName_, addStock_))
		{
			logAction.emplace_back(logs::logEditQuantityCompleted);
			std::println("Quantity updated.");
			return;
		}

		std::cerr << error::stockUpdateError;
		logAction.emplace_back(logs::logEditQuantityError);
	}

	void editRemoveStock() {
		std::println("== Remove stock ==");
		std::print("Remove: ");
		int removeStock_;
		while (!(std::cin >> removeStock_))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nRemove: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		Product product;
		if (product.removeStock(editName_, removeStock_))
		{
			logAction.emplace_back(logs::logEditQuantityCompleted);
			std::println("Quantity updated.");
			return;
		}

		std::cerr << error::stockUpdateError;
		logAction.emplace_back(logs::logEditQuantityError);
	}

	void editChangePrice() {
		std::cerr << "\n== This function will be added later. ==";
	}

	void editSwitch(int& input) {
		switch (input)
		{
		case 1:
			editName();
			break;

		case 2:
			editAddStock();
			break;

		case 3:
			editRemoveStock();
			break;

		case 4:
			editChangePrice();
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber1to5;
			logAction.emplace_back(logs::logWrongNumber1to5);
			editProductMenuShow();
		}
	}

	void editProductMenu() {
		std::println("1) Name");
		std::println("2) Add stock");
		std::println("3) Remove stock");
		std::println("4) Change price");
		std::print("5) Back\nChoose: ");
		int chooseEdit;
		while (!(std::cin >> chooseEdit))
		{
			logAction.emplace_back(logs::logWrongNumber);
			std::cerr << error::wrongNumber;
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		editSwitch(chooseEdit);
	}

	void editProductMenuShow() {
		std::println("=== Edit product ===");
		std::println("Selected name: [{}]", editName_);
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].name == editName_)
			{
				Product product;
				product.showProduct(i);
			}
		}

		std::println("----------------------");
		editProductMenu();
	}

	void lobby() {
		std::println("\n=== Edit product ===");
		std::print("Enter product name: ");
		std::getline(std::cin >> std::ws, editName_);
		if (!verify::nameIsExist(editName_))
		{
			logAction.emplace_back(logs::logNameDoesntExist);
			std::cerr << error::nameDoesntExist;
			return;
		}

		editProductMenuShow();
	}
}