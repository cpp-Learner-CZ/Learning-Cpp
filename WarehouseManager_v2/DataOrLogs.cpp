#include <print>
#include <fstream>
#include <iostream>
#include <string>

#include "DataOrLogs.hpp"
#include "Warehouse.hpp"

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
	void saveData() {
		std::println("Function to save data will be added later.");
	}

	void loadData() {
		std::println("Function to load data will be added later.");
	}
}