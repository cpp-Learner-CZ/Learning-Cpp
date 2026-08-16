#include <vector>
#include <print>
#include <iostream>

#include "Filter.hpp"
#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

namespace filter {
	namespace action {
		void priceSmaller500000(std::vector<Car>& carList) {
			std::println("=== Price smaller than 500 000 ===");
			Car car;
			for (size_t i = 0; i < carList.size(); i++)
			{
				if (carList[i].getPrice() < 500000)
				{
					car.showCar(i, carList);
					std::println("----------------------------");
				}
			}
		}

		void mileageSmaller100000(std::vector<Car>& carList) {
			std::println("=== Mileage smaller than 100 000 ===");
			Car car;
			for (size_t i = 0; i < carList.size(); i++)
			{
				if (carList[i].getMileage() < 100000)
				{
					car.showCar(i, carList);
					std::println("----------------------------");
				}
			}
		}

		void fuelTypeElectric(std::vector<Car>& carList) {
			std::println("=== Fuel type: electric ===");
			Car car;
			for (size_t i = 0; i < carList.size(); i++)
			{
				if (carList[i].getFuelType() == FuelType::Electric)
				{
					car.showCar(i, carList);
					std::println("----------------------------");
				}
			}
		}

		void statusAvailable(std::vector<Car>& carList) {
			std::println("=== Status: available ===");
			Car car;
			for (size_t i = 0; i < carList.size(); i++)
			{
				if (carList[i].getCarStatus() == CarStatus::Available)
				{
					car.showCar(i, carList);
					std::println("----------------------------");
				}
			}
		}
	}
	
	void switchFilter(const int choose, std::vector<Car>& carList) {
		switch (choose)
		{
		case 1:
			action::priceSmaller500000(carList);
			break;

		case 2:
			action::mileageSmaller100000(carList);
			break;

		case 3:
			action::fuelTypeElectric(carList);
			break;

		case 4:
			action::statusAvailable(carList);
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber1to5;
			logList.emplace_back(logs::logWrongNumber1to5);
			lobby(carList);
		}
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Filter ===");
		std::println("1) Price smaller than 500 000");
		std::println("2) Mileage smaller than 100 000");
		std::println("3) Fuel type: electric");
		std::println("4) Status: available");
		std::print("5) Back\nFilter: ");
		int chooseFilter;
		inputt::intWrite(chooseFilter, "Filter");

		switchFilter(chooseFilter, carList);
	}
}