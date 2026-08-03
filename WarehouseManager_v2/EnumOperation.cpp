#include <iostream>

#include "EnumOperation.hpp"
#include "Warehouse.hpp"

namespace enumActions {

	//Convert integer to enum.
	Category intToCategory(const int& input) {
		switch (input) {
		case 1:
			return Category::Fridge;

		case 2:
			return Category::Oven;

		case 3:
			return Category::Toaster;

		case 4:
			return Category::Iron;

		case 5:
			return Category::ElectricShawer;
		}
	}

	//Print string by enum Category
	std::string enumToString(const Category& categoryInput) {
		switch (categoryInput)
		{
		case Category::Fridge:	
			return "Fridge";

		case Category::Oven:
			return "Oven";

		case Category::Toaster:
			return "Toaster";

		case Category::Iron:
			return "Iron";

		case Category::ElectricShawer:
			return "Electric shawer";
		}
	}
}