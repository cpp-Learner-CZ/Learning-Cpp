#include <vector>
#include <print>
#include <string>

#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "EnumOperation.hpp"

std::vector<logString> logList;

std::string Car::getBrand() {
	return this->brand = brand;
}

std::string Car::getModel() {
	return this->model = model;
}

Car::Car(std::string b, std::string mo, float p, float mi, int y, FuelType f) {
	brand = b;
	model = mo;
	price = p;
	mileageInKm = mi;
	yearOfProduction = y;
	fuelType = f;

	// A new car is always available
	carStatus = CarStatus::Available;
}

void Car::showCar(int index, std::vector<Car>& carList) {
	std::println("Brand: {}", carList[index].brand);
	std::println("Model: {}", carList[index].model);
	std::println("Price: {}", carList[index].price);
	std::println("Mileage in KM: {}", carList[index].mileageInKm);
	std::println("Year of production: {}", carList[index].yearOfProduction);
	std::println("Fuel type: {}", enumAction::enumFuelToString(carList[index].fuelType));
	std::println("Car status: {}", enumAction::enumCarToString(carList[index].carStatus));
	std::println("----------------------------");
}

namespace addCar {
	std::string addBrand;
	std::string addModel;
	float addPrice;
	float addMileageInKm;
	int addYearOfProduction;
	FuelType addFuelType;

	int newFuelType;

	void save(std::vector<Car>& carList) {
		carList.emplace_back(addBrand, addModel, addPrice, addMileageInKm, addYearOfProduction, addFuelType);
		std::println("Car added.");
		logList.emplace_back(logs::logCarAddComplete);
	}

	void consentAdd(std::vector<Car>& carList) {
		std::println("== Add car: consent ==");
		std::println("Brand: {}", addBrand);
		std::println("Model: {}", addModel);
		std::println("Price: {}", addPrice);
		std::println("Mileage in KM: {}", addMileageInKm);
		std::println("Year of production: {}", addYearOfProduction);
		std::println("Fuel type: {}", enumAction::enumFuelToString(addFuelType));
		std::println("Car status: Available");
		std::println("----------------------------");

		std::print("Do you want to add a car? (y/n)\nChoose: ");
		std::string chooseConsent;
		std::getline(std::cin >> std::ws, chooseConsent);
		bool consent = (chooseConsent == "y" || chooseConsent == "Y");
		if (!consent)
		{
			std::println("Car addition canceled.");
			logList.emplace_back(logs::logCarAdditionCancel);
			return;
		}
		
		save(carList);
	}

	void setFuelType(std::vector<Car>& carList) {
		std::println("== Set Fuel type ==");
		std::println("1) Petrol");
		std::println("2) Diesel");
		std::println("3) Hybrid");
		std::print("4) Electric\nFuel type: ");
		inputt::intWrite(newFuelType, "Fuel type");

		if (verify::validFuelTypeEnum(newFuelType))
		{
			std::cerr << error::wrongNumber1to4;
			logList.emplace_back(logs::logWrongNumber1to4);
			return;
		}

		addFuelType = enumAction::intToFuelType(newFuelType);

		consentAdd(carList);
	}

	void setYearOfProduction(std::vector<Car>& carList) {
		std::print("Year of production: ");
		inputt::intWrite(addYearOfProduction, "Year of production");

		if (verify::equalZero::zeroInt(addYearOfProduction))
		{
			std::cerr << error::yearEqualZero;
			logList.emplace_back(logs::logYearEqualZero);
			return;
		}

		setFuelType(carList);
	}

	void setMileageInKm(std::vector<Car>& carList) {
		std::print("Mileage in KM: ");
		inputt::floatWrite(addMileageInKm, "Mileage in KM");

		setYearOfProduction(carList);
	}

	void setPrice(std::vector<Car>& carList) {
		std::print("Price: ");
		inputt::floatWrite(addPrice, "Price");

		if (verify::equalZero::zeroInt(addPrice))
		{
			std::cerr << error::priceEqualZero;
			logList.emplace_back(logs::logPriceEqualZero);
			return;
		}

		setMileageInKm(carList);
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Add car ===");
		std::print("Brand: ");
		std::getline(std::cin >> std::ws, addBrand);

		std::print("Model: ");
		std::getline(std::cin >> std::ws, addModel);

		if (verify::brandIsExist(addBrand, carList) && verify::modelIsExist(addModel, carList))
		{
			std::cerr << error::carIsDuplicit;
			logList.emplace_back(logs::logCarIsDuplicit);
			return;
		}
		
		setPrice(carList);
	}
}

void showCars(std::vector<Car>& carList) {
	std::println("=== Show cars ===");
	if (carList.size() == 0)
	{
		std::println("No cars available.");
		return;
	}

	Car car;
	for (size_t i = 0; i < carList.size(); i++)
	{
		car.showCar(i, carList);
	}
}