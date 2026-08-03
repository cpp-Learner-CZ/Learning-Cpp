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
	ElectricShawer = 5
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

};

extern std::vector<Product> productList;

namespace add {
	void lobby();
}

void showProductss();