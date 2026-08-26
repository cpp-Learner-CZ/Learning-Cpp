#pragma once
#include <string>

namespace errors {
	inline const std::string wrongNumber = "Wrong number: Write only numbers.";
	inline const std::string wrongNumber1to15 = "Wrong number: Write only numbers from one to fifteen.";
	inline const std::string IDIsZero = "Invalid ID: ID cannot be zero.";
	inline const std::string ageIsZero = "Invalid age: Age cannot be zero.";
	inline const std::string nameAlredyExist = "Invalid name: The name already exists.";
	inline const std::string duplicateID = "Duplicate ID: This ID is already in use.";
}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Write only numbers.";
	inline const std::string logWrongNumber1to15 = "[Warning] Write only numbers from one to fifteen.";
	inline const std::string logIDIsZero = "[Warning] ID cannot be zero.";
	inline const std::string logAgeIsZero = "[Warning] Age cannot be zero.";
	inline const std::string logNameAlredyExist = "[Warning] The name already exists.";
	inline const std::string logDuplicateID = "[Warning] This ID is alredy in use.";
}