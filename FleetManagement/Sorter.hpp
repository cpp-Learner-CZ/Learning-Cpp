#pragma once
#include <vector>

#include "Car.hpp"

namespace sorter {
	void sortByBrand(std::vector<Car>& carList);

	void sortByModel(std::vector<Car>& carList);

	void sortByPrice(std::vector<Car>& carList);

	void sortByMileage(std::vector<Car>& carList);

	void lobby(std::vector<Car>& carList);
}