#include <string>
#include <vector>

#pragma once

struct logWarehouse {
	std::string errorOrLogs;
};

extern std::vector<logWarehouse> logAction;

enum class Category
{
	Fridge = 1, 
	Oven = 2,
	Toaster = 3,
	Iron = 4,
	ElectricShaver = 5
};

class Product {
public:
	std::string name;
	int quantity;
	double price;
	Category category;

	Product() {}

	Product(std::string n, int q, double p, Category c) {
		name = n;
		quantity = q;
		price = p;
		category = c;
	}

	void showProduct(int iterator);

	bool updateName(std::string& chooseName, std::string& newName);

	bool addStock(std::string& chooseName, int& addStock);

	bool removeStock(std::string& chooseName, int& removeStock);

	bool changePrice(std::string& chooseName, double& changeDouble);

	bool deleteProduct(std::string& delName);
};

extern std::vector<Product> productList;

namespace add {
	void lobby();
}
namespace deleteProduct {
	void lobby();
}

void showProductss();