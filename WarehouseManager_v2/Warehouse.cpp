#include <print>
#include <string>
#include <iostream>
#include <limits>

#include "Warehouse.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "EnumOperation.hpp"

std::vector<logWarehouse> logAction;
std::vector<Product> productList;

void Product::showProduct(int iterator) {
	std::println("Name: {}", productList[iterator].name);
	std::println("Quantity: {}", productList[iterator].quantity);
	std::println("Price: {}", productList[iterator].price);
	std::println("Category: {}", enumActions::enumToString(productList[iterator].category));
	std::println("----------------------------");
}

bool Product::updateName(std::string& chooseName, std::string& newName) {
	for (size_t i = 0; i < productList.size(); i++)
	{
		if (chooseName == productList[i].name)
		{
			productList[i].name = newName;
			return true;
		}
	}
	return false;
}

bool Product::addStock(std::string& chooseName, int& addStock) {
	for (size_t i = 0; i < productList.size(); i++)
	{
		if (chooseName == productList[i].name)
		{
			if (verify::quantityIs0(addStock))
			{
				std::cerr << error::quantityIs0;
				logAction.emplace_back(logs::logQuantityIs0);
				return false;
			}
			productList[i].quantity += addStock;
			logAction.emplace_back(logs::logAddStockCompleted);
			return true;
		}
	}
	return false;
}

bool Product::removeStock(std::string& chooseName, int& removeStock) {
	for (size_t i = 0; i < productList.size(); i++)
	{
		if (chooseName == productList[i].name)
		{
			if (verify::quantityIs0(removeStock))
			{
				std::cerr << error::quantityIs0;
				logAction.emplace_back(logs::logQuantityIs0);
				return false;
			}

			if (!verify::intIsEqualOrLower(productList[i].quantity, removeStock))
			{
				std::cerr << error::stockRemoveIntBigger;
				logAction.emplace_back(logs::logRemoveStockErrorIntBigger);
				return false;
			}

			productList[i].quantity -= removeStock;
			logAction.emplace_back(logs::logRemoveStockCompleted);
			return true;
		}
	}
	return false;
}

bool Product::changePrice(std::string& chooseName, double& changeDouble) {
	for (size_t i = 0; i < productList.size(); i++)
	{
		if (productList[i].name == chooseName)
		{
			if (verify::priceIs0(changeDouble))
			{
				std::cerr << error::priceIs0;
				logAction.emplace_back(logs::logPriceIs0);
				return false;
			}

			productList[i].price = changeDouble;
			logAction.emplace_back(logs::logPriceChange);
			return true;
		}
	}
	return false;
}

bool Product::deleteProduct(std::string& delName) {
	for (size_t i = 0; i < productList.size(); i++)
	{
		if (productList[i].name == delName)
		{
			productList.erase(productList.begin() + i);
			logAction.emplace_back(logs::logProductDeleted);
			std::println("Product {} deleted.", delName);
			return true;
		}
	}
	return false;
}

namespace add {
	std::string newName;
	int newQuantity;
	double newPrice;
	Category newCategory;

	void save() {
		productList.emplace_back(newName, newQuantity, newPrice, newCategory);
		std::println("Product {} added.", newName);
		logAction.emplace_back(logs::logProductAdded);
	}

	void consentChoose() {
		std::println("=== Add product ===");
		std::println("=== Consent choose ===");
		std::println("Name: {}", newName);
		std::println("Quantity: {}", newQuantity);
		std::println("Price: {}", newPrice);
		std::println("Category: {}", enumActions::enumToString(newCategory));
		std::println("Is this summary truth? Write y else n");
		std::print("Consent: ");
		std::string consentInfo;
		std::getline(std::cin >> std::ws, consentInfo);

		bool boolConsent = (consentInfo == "y" || consentInfo == "Y");

		if (!boolConsent)
		{
			std::println("Adding product canceled.");
			logAction.emplace_back(logs::logAddCanceled);
			return;
		}

		save();
	}

	void setCategory() {
		int newCategory_;
		std::println("\nChoose category");
		std::println("1) Fridge");
		std::println("2) Oven");
		std::println("3) Toaster");
		std::println("4) Iron");
		std::print("5) Electric shawer\nChoose: ");
		while (!(std::cin >> newCategory_))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (!verify::enumInputIsOK(newCategory_))
		{
			std::cerr << error::invalidInputforSetEnum;
			logAction.emplace_back(logs::logInvalidInputEnumSet);
			setCategory();
		}

		newCategory = enumActions::intToCategory(newCategory_);
		std::println("Category set to: {}", enumActions::enumToString(newCategory));
		
		consentChoose();
	}

	void lobby() {
		std::println("=== Add product ===");
		std::print("Name: ");
		std::getline(std::cin >> std::ws, newName);
		if (verify::nameIsExist(newName))
		{
			std::cerr << error::nameAlredyExist;
			logAction.emplace_back(logs::logNameAlredyExist);
			return;
		}

		std::print("Quantity: ");
		while (!(std::cin >> newQuantity))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (verify::quantityIs0(newQuantity))
		{
			std::cerr << error::quantityIs0;
			logAction.emplace_back(logs::logQuantityIs0);
			return;
		}

		std::print("Price: ");
		while (!(std::cin >> newPrice))
		{
			std::cerr << error::wrongNumber;
			logAction.emplace_back(logs::logWrongNumber);
			std::print("\nChoose: ");

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (verify::priceIs0(newPrice))
		{
			std::cerr << error::priceIs0;
			logAction.emplace_back(logs::logPriceIs0);
			return;
		}

		setCategory();
	}
}
namespace deleteProduct {
	std::string deleteName;
	
	void deleter() {
		Product product;
		if (!product.deleteProduct(deleteName))
		{
			std::cerr << error::deleteProductError;
			logAction.emplace_back(logs::logProductDeleteError);
		}
	}

	void consentDelete() {
		std::string consentChoose;
		std::print("Are you sure for delete product {}?\nWrite y or n\nYour choose: ", deleteName);
		std::getline(std::cin >> std::ws, consentChoose);

		bool consentBool = (consentChoose == "y" || consentChoose == "Y");

		if (!consentBool)
		{
			logAction.emplace_back(logs::logDeleteProductCancel);
			std::println("Product deletion canceled.");
			return;
		}
		deleter();
	}

	void lobby() {
		std::println("=== Delete product ===");
		std::print("Remove:(Name) ");
		std::getline(std::cin >> std::ws, deleteName);
		if (!verify::nameIsExist(deleteName))
		{
			std::cerr << error::nameDoesntExist;
			logAction.emplace_back(logs::logNameDoesntExist);
			return;
		}

		consentDelete();
	}
}

void showProductss() {
	std::println("=== Show products ===");
	if (productList.size() == 0)
	{
		std::println("No products added yet.");
	}
	for (size_t i = 0; i < productList.size(); i++)
	{
		Product productss;
		productss.showProduct(i);
	}
}