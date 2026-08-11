#pragma once
#include <string>

namespace error {
	inline const std::string wrongNumber = "Invalid input: Write only numbers!";
	inline const std::string carIsDuplicit = "Car exist: This car is alredy exist!";
	inline const std::string wrongNumber1to3 = "Wrong number: Write only numbers from one to three!";
	inline const std::string wrongNumber1to4 = "Wrong number: Write only numbers from one to four!";
	inline const std::string wrongNumber1to14 = "Wrong number: Write only numbers from one to fourteen!";
	inline const std::string priceEqualZero = "Invalid price: Price can't be zero!";
	inline const std::string yearEqualZero = "Invalid year: Year can't be zero!";
}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Write only numbers.";
	inline const std::string logCarIsDuplicit = "[Warning] Entered car name is alredy exist.";
	inline const std::string logWrongNumber1to3 = "[Warning] Write only numbers from one to three.";
	inline const std::string logWrongNumber1to4 = "[Wrning] Write only numbers from one to four.";
	inline const std::string logWrongNumber1to14 = "[Warning] Write only numbers from one to fourteen.";
	inline const std::string logPriceEqualZero = "[Warning] Price can't be zero.";
	inline const std::string logYearEqualZero = "[Warning] Year can't be zero!";
	inline const std::string logCarAddComplete = "[INFO] Car added.";
	inline const std::string logCarAdditionCancel = "[INFO] Car addition canceled.";
}