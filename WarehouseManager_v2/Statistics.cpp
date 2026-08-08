#include <print>
#include <iostream>

#include "Statistics.hpp"
#include "Warehouse.hpp"
#include "ErrorOrLogs.hpp"

namespace statistics {
	int productSize;

	float averageQuantity() {
		int average_ = 0;
		for (size_t i = 0; i < productList.size(); i++)
		{
			average_ += productList[i].quantity;
		}
		return average_ / productSize;
	}

	double averagePrice() {
		double average = 0;
		for (size_t i = 0; i < productList.size(); i++)
		{
			average += productList[i].price;
		}
		return average / productSize;
	}

	double totalWarehouseValue() {
		double total = 0;
		for (size_t i = 0; i < productList.size(); i++)
		{
			Product product;
			total += product.productValue(i);
		}
		return total;
	}

	namespace totalProducts {
		int fridge() {
			int total = 0;
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Fridge)
				{
					total++;
				}
			}
			return total;
		}

		int oven() {
			int total = 0;
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Oven)
				{
					total++;
				}
			}
			return total;
		}

		int toaster() {
			int total = 0;
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Toaster)
				{
					total++;
				}
			}
			return total;
		}

		int iron() {
			int total = 0;
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::Iron)
				{
					total++;
				}
			}
			return total;
		}

		int electricShaver() {
			int total = 0;
			for (size_t i = 0; i < productList.size(); i++)
			{
				if (productList[i].category == Category::ElectricShaver)
				{
					total++;
				}
			}
			return total;
		}
	}

	void lobby() {
		std::println("=== Statistics ===");
		//This if block checks if the vector is not empty. Without it, the program would crash.
		if (productList.size() == 0)
		{
			logAction.emplace_back("[Error] Can't load statistics because the product list is empty.");
			std::cerr << "Unexpected error: Cannot load statistics because the product list is empty!";
			return;
		}

		productSize = productList.size();
		std::println("Total count product types: {}", productSize);
		std::println("Average product quantity: {}", averageQuantity());
		std::println("Average product price: {}", averagePrice());
		std::println("Total warehouse value: {}", totalWarehouseValue());
		std::println("\nProducts in different categoryes");
		std::println("---------------------------------");
		std::println("Fridge: {}", totalProducts::fridge());
		std::println("Oven: {}", totalProducts::oven());
		std::println("Toaster: {}", totalProducts::toaster());
		std::println("Iron: {}", totalProducts::iron());
		std::println("Electric shaver: {}", totalProducts::electricShaver());
		std::println("---------------------------------");
	}
}