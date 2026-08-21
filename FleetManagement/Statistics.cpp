#include <vector>
#include <print>

#include "Statistics.hpp"
#include "Car.hpp"
#include "Sorter.hpp"
#include "ErrorOrLogs.hpp"

namespace statistics {
	int totalCars;

	int availableCars(std::vector<Car>& carList) {
		int availableCount = 0;
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (carList[i].getCarStatus() == CarStatus::Available)
			{
				availableCount++;
			}
		}
		return availableCount;
	}

	int rentedCars(std::vector<Car>& carList) {
		int rentedCount = 0;
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (carList[i].getCarStatus() == CarStatus::Rented)
			{
				rentedCount++;
			}
		}
		return rentedCount;
	}

	int serviceCenterCars(std::vector<Car>& carList) {
		int serviceCenterCount = 0;
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (carList[i].getCarStatus() == CarStatus::Service)
			{
				serviceCenterCount++;
			}
		}
		return serviceCenterCount;
	}

	std::string biggestPriceBrand(std::vector<Car>& carList) {
		sorter::sortByPrice(carList);
		int index = totalCars - 1;
		std::string carWithBiggestPrice = carList[index].getBrand();
		sorter::sortByBrand(carList);
		return carWithBiggestPrice;
	}

	std::string biggestPriceModel(std::vector<Car>& carList) {
		sorter::sortByPrice(carList);
		int index = totalCars - 1;
		std::string carWithBiggestPrice = carList[index].getModel();
		sorter::sortByBrand(carList);
		return carWithBiggestPrice;
	}

	std::string lowestPriceBrand(std::vector<Car>& carList) {
		sorter::sortByPrice(carList);
		std::string carWithLowestPrice = carList[0].getBrand();
		sorter::sortByBrand(carList);
		return carWithLowestPrice;
	}

	std::string lowestPriceModel(std::vector<Car>& carList) {
		sorter::sortByPrice(carList);
		std::string carWithLowestPrice = carList[0].getModel();
		sorter::sortByBrand(carList);
		return carWithLowestPrice;
	}

	float warehouseValue(std::vector<Car>& carList) {
		float totalValue = 0;

		for (size_t i = 0; i < carList.size(); i++)
		{
			totalValue += carList[i].getPrice();
		}

		return totalValue;
	}

	float averagePrice(std::vector<Car>& carList) {
		float total = warehouseValue(carList);
		float averagePrice = total / totalCars;
		return averagePrice;
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Statistics ===");
		totalCars = carList.size();
		if (totalCars == 0)
		{
			std::cerr << error::carListEmpty;
			logList.emplace_back(logs::logCarListEmpty);
			return;
		}
		std::println("Total cars: {}", totalCars);
		std::println("Total warehouse value: {}", warehouseValue(carList));
		std::println("Available cars: {}", availableCars(carList));
		std::println("Rented cars: {}", rentedCars(carList));
		std::println("Number of cars in the service center: {}", serviceCenterCars(carList));
		std::println("The most expensive car: Brand {}, Model {}", biggestPriceBrand(carList), biggestPriceModel(carList));// Error
		std::println("The cheapest car: Brand {}, Model {}", lowestPriceBrand(carList), lowestPriceModel(carList));
		std::println("Average price: {}", averagePrice(carList));
	}
}