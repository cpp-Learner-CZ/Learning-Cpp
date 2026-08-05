#include <print>

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
}