#include <print>
#include <fstream>
#include <iostream>
#include <string>

#include "DataOrLogs.hpp"
#include "Warehouse.hpp"
#include "ErrorOrLogs.hpp"

namespace logWork {
	void show() {
		std::println("=== Logs ===");
		if (logAction.size() == 0)
		{
			std::println("Log list is empty.");
			return;
		}
		for (size_t i = 0; i < logAction.size(); i++)
		{
			std::println("- {}", logAction[i].errorOrLogs);
		}
	}

	void exportLog() {
		std::println("Exporting logs...");
		std::ofstream exportLog("Logs.log");
		if (!exportLog.is_open())
		{
			std::cerr << "Unexpected error: Can't export logs.";
			exportLog.close();
			return;
		}

		for (size_t i = 0; i < logAction.size(); i++)
		{
			exportLog << logAction[i].errorOrLogs << " \n";
		}
		
		exportLog.close();
		std::println("Logs exported.");
	}
}

namespace data {
	const std::string fileName = "file.dat";

	void saveData() {
		std::println("Saving data...");
		std::ofstream writer(fileName);
		if (!writer.is_open())
		{
			writer.close();
			std::cerr << error::errorWriteData;
			logAction.emplace_back(logs::logErrorWriteData);
			return;
		}

		int tempCategory;
		for (size_t i = 0; i < productList.size(); i++)
		{
			writer << productList[i].name << "\n";
			writer << productList[i].quantity << "\n";
			writer << productList[i].price << "\n";

			tempCategory = static_cast<int>(productList[i].category);
			writer << tempCategory;
		}

		writer.close();
		std::println("Save completed, terminating program...");
	}

	void loadData() {
		std::println("Loading data...");
		std::ifstream loader(fileName);
		if (!loader.is_open())
		{
			loader.close();
			std::cerr << error::errorLoadData;
			logAction.emplace_back(logs::logErrorLoadData);
			return;
		}

		std::string tempName;
		int tempQuantity;
		double tempPrice;
		Category tempCategory;

		int tempCategoryInt;

		while (std::getline(loader, tempName))
		{
			loader >> tempQuantity;
			loader >> tempPrice;
			loader >> tempCategoryInt;

			tempCategory = static_cast<Category>(tempCategoryInt);

			loader.ignore();
			productList.emplace_back(tempName, tempQuantity, tempPrice, tempCategory);
		}

		loader.close();
		std::println("Load completed, starting menu...");
	}
}