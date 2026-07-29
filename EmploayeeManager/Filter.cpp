#include <print>

#include "Filter.hpp"
#include "Error.hpp"

//Namespace for filter
namespace filter {

	//Main enter function for filter
	void lobby() {
		std::println("=== Filter ===");
		std::println("1) Only IT");
		std::println("2) Only HR");
		std::println("3) Only active");
		std::println("4) Only sick leave");
		std::println("5) Salary bigger than 20");
		std::println("6) Age bigger than 18");
		std::print("7) Back\nChoose: ");

	}
}