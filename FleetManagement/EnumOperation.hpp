#pragma once

#include "Car.hpp"

namespace enumAction {
	FuelType intToFuelType(const int& enumSet);

	std::string enumFuelToString(const FuelType& input);

	CarStatus intToCarStatus(const int& enumSet);

	std::string enumCarToString(const CarStatus& input);
}