#include <print>
#include <iostream>
#include <algorithm>

#include "Sorter.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "Car.hpp"

namespace sorter {
	void sortByBrand(std::vector<Car>& carList) {
		std::sort(carList.begin(), carList.end(), [](const Car& a, const Car& b) {
			return a.getBrand() < b.getBrand();
			});
	}

	void sortByModel(std::vector<Car>& carList) {
		std::sort(carList.begin(), carList.end(), [](const Car& a, const Car& b) {
			return a.getModel() < b.getModel();
			});
	}

	void sortByPrice(std::vector<Car>& carList) {
		std::sort(carList.begin(), carList.end(), [](const Car& a, const Car& b) {
			return a.getPrice() < b.getPrice();
			});
	}

	void sortByMileage(std::vector<Car>& carList) {
		std::sort(carList.begin(), carList.end(), [](const Car& a, const Car& b) {
			return a.getMileage() < b.getMileage();
			});
	}

	void sortSwitch(const int& choose, std::vector<Car>& carList) {
		switch (choose)
		{
		case 1:
			sortByBrand(carList);
			std::println("Sorted by brand.");
			logList.emplace_back(logs::sortBrand);
			break;

		case 2:
			sortByModel(carList);
			std::println("Sorted by model.");
			logList.emplace_back(logs::sortModel);
			break;

		case 3:
			sortByPrice(carList);
			std::println("Sorted by price.");
			logList.emplace_back(logs::sortPRice);
			break;

		case 4:
			sortByMileage(carList);
			std::println("Sorted by mileage.");
			logList.emplace_back(logs::sortMileage);
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber1to5;
			logList.emplace_back(logs::logWrongNumber1to5);
			break;
		}
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Sort ===");
		std::println("1) By brand");
		std::println("2) By model");
		std::println("3) By price");
		std::println("4) By mileage");
		std::print("5) Back\nSort: ");
		int sortChosse;
		inputt::intWrite(sortChosse, "Sort");

		sortSwitch(sortChosse, carList);
	}
}