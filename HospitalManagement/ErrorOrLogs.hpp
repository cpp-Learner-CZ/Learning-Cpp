#pragma once
#include <string>

namespace errors {
	inline const std::string wrongNumber = "Wrong number: Write only numbers.";
	inline const std::string wrongNumber1to4 = "Wrong number: Write only numbers from one to four.";
	inline const std::string wrongNumber1to15 = "Wrong number: Write only numbers from one to fifteen.";
	inline const std::string IDIsZero = "Invalid ID: ID cannot be zero.";
	inline const std::string ageIsZero = "Invalid age: Age cannot be zero.";
	inline const std::string nameAlredyExist = "Invalid name: The name already exists.";
	inline const std::string duplicateID = "Duplicate ID: This ID is already in use.";
}

namespace logs {
	inline const std::string logWrongNumber = "[WARNING] Write only numbers.";
	inline const std::string logWrongNumber1to4 = "[WARNING] Write only numbers from one to four.";
	inline const std::string logWrongNumber1to15 = "[WARNING] Write only numbers from one to fifteen.";
	inline const std::string logIDIsZero = "[WARNING] ID cannot be zero.";
	inline const std::string logAgeIsZero = "[WARNING] Age cannot be zero.";
	inline const std::string logNameAlredyExist = "WARNING] The name already exists.";
	inline const std::string logDuplicateID = "[WARNING] This ID is alredy in use.";
	inline const std::string logPatientAdditionCanceled = "[INFO] The patient addition was canceled.";
	inline const std::string logPatientAdded = "[INFO] The patient has been added.";
}