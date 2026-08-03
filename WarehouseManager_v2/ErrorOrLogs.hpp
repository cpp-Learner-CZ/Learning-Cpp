#pragma once
#include <string>

namespace error {
	inline const std::string wrongNumber = "Wrong number: Write only numbers!";
	inline const std::string nameAlredyExist = "Wrong name: This name is alredy exist!";
	inline const std::string wrongNumber1to11 = "Wrong number: Write only numbers from one to eleven!";
	inline const std::string quantityIs0 = "Wrong quantity: Quantity can't be zero!";
	inline const std::string invalidInputforSetEnum = "Invalid input: Please write only numbers from one to five!";

}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Wrote a letter instead of a number.";
	inline const std::string wrongNumber1to11 = "[Warning] Write only numbers from one to eleven.";
	inline const std::string logNameAlredyExist = "[Warning] Wrote name is alredy exist.";
	inline const std::string logQuantityIs0 = "[Warning] The written quantity was zero.";
	inline const std::string logInvalidInputEnumSet = "[Warning] Wrote number zero or number bigger than five.";
	inline const std::string logAddCanceled = "[INFO] Adding product canceled.";
	inline const std::string logProductAdded = "[INFO] Product added.";
}