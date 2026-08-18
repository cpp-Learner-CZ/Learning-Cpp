#pragma once
#include <vector>

#include "Car.hpp"

namespace carRent {
	void lobby(std::vector<Car>& carList);
}

namespace carReturn {
	void lobby(std::vector<Car>& carList);
}

namespace carService {
	void lobby(std::vector<Car>& carList);
}