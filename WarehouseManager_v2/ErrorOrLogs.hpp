#pragma once
#include <string>

namespace error {
	inline const std::string wrongNumber = "Wrong number: Write only numbers!";
	inline const std::string nameAlredyExist = "Wrong name: This name is alredy exist!";
	inline const std::string wrongNumber1to11 = "Wrong number: Write only numbers from one to eleven!";
	inline const std::string wrongNumber1to5 = "Wrong number: Write only numbers from one to five!";
	inline const std::string quantityIs0 = "Wrong quantity: Quantity can't be zero!";
	inline const std::string invalidInputforSetEnum = "Invalid input: Please write only numbers from one to five!";
	inline const std::string nameDoesntExist = "Wrong name: Entered name does not exist!";
	inline const std::string nameEditError = "\nUnexpected error: Can't update name!";
	inline const std::string stockUpdateError = "\nUnexpected error: Can't update quantity!";
	inline const std::string stockRemoveIntBigger = "Invalid input: Value exceeds available quantity!";
}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Wrote a letter instead of a number.";
	inline const std::string wrongNumber1to11 = "[Warning] Write only numbers from one to eleven.";
	inline const std::string logWrongNumber1to5 = "[Warning] Write only numbers from one to five.";
	inline const std::string logNameAlredyExist = "[Warning] Wrote name is alredy exist.";
	inline const std::string logQuantityIs0 = "[Warning] The written quantity was zero.";
	inline const std::string logInvalidInputEnumSet = "[Warning] Wrote number zero or number bigger than five.";
	inline const std::string logAddCanceled = "[INFO] Adding product canceled.";
	inline const std::string logProductAdded = "[INFO] Product added.";
	inline const std::string logNameDoesntExist = "[Warning] Entered name does not exist.";
	inline const std::string logEditNameCompleted = "[INFO] Name updated.";
	inline const std::string logEditNameError = "[Warning] Can't update name.";
	inline const std::string logEditQuantityError = "[Warning] Can't update quantity.";
	inline const std::string logEditQuantityCompleted = "[INFO] Quantity updated.";
	inline const std::string logAddStockCompleted = "[INFO] Stock added.";
	inline const std::string logRemoveStockCompleted = "[INFO] Stock removed.";
	inline const std::string logRemoveStockErrorIntBigger = "[Warning] Value exceeds available quantity.";
}