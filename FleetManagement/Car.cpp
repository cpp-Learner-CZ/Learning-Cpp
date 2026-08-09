#include <vector>
#include <print>
#include <string>

#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

std::vector<logString> logList;

std::string Car::getBrand() {
	return this->brand = brand;
}

std::string Car::getModel() {
	return this->model = model;
}

namespace addCar {
	std::string addBrand;
	std::string addModel;
	float addPrice;

	void setPrice(std::vector<Car> carList) {
		std::print("Price: ");
		inputt::floatWrite(addPrice, "Price");

		

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