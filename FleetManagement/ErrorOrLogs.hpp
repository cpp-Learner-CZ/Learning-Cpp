#pragma once
#include <string>

namespace error {
	inline const std::string wrongNumber = "Invalid input: Write only numbers!";
	inline const std::string carIsDuplicit = "Car exist: This car is alredy exist!";
	inline const std::string wrongNumber1to14 = "Wrong number: Write only numbers from one to fourteen!";
}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Write only numbers.";
	inline const std::string logCarIsDuplicit = "[Warning] Entered car name is alredy exist.";
	inline const std::string logWrongNumber1to14 = "[Warning] Write only numbers from one to fourteen.";
}