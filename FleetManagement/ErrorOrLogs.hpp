#pragma once
#include <string>

namespace error {
	inline const std::string wrongNumber = "Invalid input: Write only numbers!";
	inline const std::string carIsDuplicit = "Car exist: This car is alredy exist!";
	inline const std::string carModelAlredyExist = "Car model: This car model already exists!";
	inline const std::string carDoesntExist = "Car doesn't exist: This car doesn't exist!";
	inline const std::string wrongNumber1to3 = "Wrong number: Write only numbers from one to three!";
	inline const std::string wrongNumber1to4 = "Wrong number: Write only numbers from one to four!";
	inline const std::string wrongNumber1to5 = "Wrong number: Write only numbers from one to five!";
	inline const std::string wrongNumber1to14 = "Wrong number: Write only numbers from one to fourteen!";
	inline const std::string priceEqualZero = "Invalid price: Price can't be zero!";
	inline const std::string yearEqualZero = "Invalid year: Year can't be zero!";
	inline const std::string priceEnteredEqualCurrent = "Invalid price: The entered price is the same as the current price!";
	inline const std::string mileageEnteredEqualCurrent = "Invalid mileage: The entered mileage is the same as the current mileage!";
	inline const std::string fuelTypeEnteredEqualCurrent = "Invalid fuel type: The entered fuel type is the same as the current fuel type!";
	inline const std::string removeCarRented = "Car rented: Can't remove the car because it is already rented!";
	inline const std::string carAvailabilityFalse = "Invalid status: The car is not available!";
	inline const std::string carRentedFalse = "Invalid status: The car is not rented!";
	inline const std::string errorCarInService = "Invalid status: The car is in service center!";
	inline const std::string errorCarIsntService = "Invalid status: The car is not in service center!";
}

namespace logs {
	inline const std::string logWrongNumber = "[Warning] Write only numbers.";
	inline const std::string logCarIsDuplicit = "[Warning] Entered car name is alredy exist.";
	inline const std::string logCarModelAlredyExist = "[Warning] This car model already exists.";
	inline const std::string logCarDoesntExist = "[Warning] This car doesn't exist.";
	inline const std::string logWrongNumber1to3 = "[Warning] Write only numbers from one to three.";
	inline const std::string logWrongNumber1to4 = "[Wrning] Write only numbers from one to four.";
	inline const std::string logWrongNumber1to5 = "Wrong number: Write only numbers from one to five.";
	inline const std::string logWrongNumber1to14 = "[Warning] Write only numbers from one to fourteen.";
	inline const std::string logPriceEqualZero = "[Warning] Price can't be zero.";
	inline const std::string logYearEqualZero = "[Warning] Year can't be zero!";
	inline const std::string logCarAddComplete = "[INFO] Car added.";
	inline const std::string logCarAdditionCancel = "[INFO] Car addition canceled.";
	inline const std::string logEditModelError = "[Warning] Unable to edit car model.";
	inline const std::string logEditPriceError = "[Warning] Unable to edit price.";
	inline const std::string logEditMileageError = "[Warning] Unable to edit mileage.";
	inline const std::string logEditFuelTypeError = "[Warning] Unable to edit fuel type.";
	inline const std::string logEditModelCompleted = "[INFO] Car model updated.";
	inline const std::string logEditPriceCompleted = "[INFO] Car price updated.";
	inline const std::string logEditMileageCompleted = "[INFO] Car mileage updated.";
	inline const std::string logEditFuelTypeCompleted = "[INFO] Car fuel type updated.";
	inline const std::string logPriceEnteredEqualCurrent = "[Warning] The entered price is the same as the current price.";
	inline const std::string logMileageEnteredEqualCurrent = "[Warning] The entered mileage is the same as the current mileage.";
	inline const std::string logFuelTypeEnteredEqualCurrent = "[Warning] The entered fuel type is the same as the current fuel type.";
	inline const std::string logRemoveCarRented = "[Warning] Can't remove the car because it is already rented.";
	inline const std::string logRemoveCanceled = "[INFO] Car removal canceled.";
	inline const std::string logRemoveCompleted = "[INFO] Car removed.";
	inline const std::string logSortBrand = "[INFO] Sorted by brand.";
	inline const std::string logSortModel = "[INFO] Sorted by model.";
	inline const std::string logSortPRice = "[INFO] Sorted by price.";
	inline const std::string logSortMileage = "[INFO] Sorted by mileage.";
	inline const std::string logCarAvailabilityFalse = "[Warning] The car is not available.";
	inline const std::string logCarRentedFalse = "[Warning] The car is not rented.";
	inline const std::string logCarSetRented = "[INFO] The car was rented.";
	inline const std::string logCarSetReturned = "[INFO] The car was returned.";
	inline const std::string logErrorCarInService = "[Warning] The car is in service center.";
	inline const std::string logErrorCarIsntService = "[Warning] The car is not in service center.";
	inline const std::string logCarTakenToService = "[INFO] The car was taken to the service center.";
	inline const std::string logCarCollectedFromService = "[INFO] The car was collected from the service center.";
}