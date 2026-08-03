#pragma once
#include "Warehouse.hpp"

namespace enumActions {

	//Convert integer to enum.
	Category intToCategory(const int& input);

	//Print string by enum Category
	std::string enumToString(const Category& categoryInput);
}