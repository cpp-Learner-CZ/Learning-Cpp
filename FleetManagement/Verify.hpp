#pragma once

#include "Car.hpp"

namespace inputt {
	// Verify input because user can enter wrong number
	void intWrite(int& input, const std::string message);

	// Verify input because user can enter wrong number
	void floatWrite(float& input, const std::string message);
}

namespace verify {
	// Verify input because user can enter duplicate brands
	bool brandIsExist(const std::string& name, std::vector<Car>& carListt);

	// Verify input because user can enter duplicite models
	bool modelIsExist(const std::string& model, std::vector<Car>& carList);

	bool validFuelTypeEnum(const int& input);

	bool validCarStatusEnum(const int& input);

	// Verify if the number is equal to zero
	namespace equalZero {
		bool zeroInt(const int& check);

		bool zeroFloat(const float& check);
	}
}