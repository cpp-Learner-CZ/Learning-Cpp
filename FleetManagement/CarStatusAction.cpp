#include <print>
#include <iostream>
#include <string>

#include "CarStatusAction.hpp"
#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

namespace carRent {
	std::string rentBrand;
	std::string rentModel;
	int carSelected;

	void rentAction(std::vector<Car>& carList) {
		carList[carSelected].setCarStatusRent();
		std::println("The car was rented.");
		logList.emplace_back(logs::logCarSetRented);
	}

	void check(std::vector<Car>& carList) {
		if (!(verify::brandIsExist(rentBrand, carList) && verify::modelIsExist(rentModel, carList)))
		{
			std::cerr << error::carDoesntExist;
			logList.emplace_back(logs::logCarDoesntExist);
			return;
		}

		bool carAvailable = false;
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (rentBrand == carList[i].getBrand() && rentModel == carList[i].getModel())
			{
				if (carList[i].carAvailable())
				{
					carSelected = i;
					carAvailable = true;
				}
			}
		}

		if (!carAvailable)
		{
			std::cerr << error::carAvailabilityFalse;
			logList.emplace_back(logs::logCarAvailabilityFalse);
			return;
		}

		rentAction(carList);
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Rent car ===");
		std::print("Enter brand: ");
		std::getline(std::cin >> std::ws, rentBrand);

		std::print("Enter model: ");
		std::getline(std::cin >> std::ws, rentModel);

		check(carList);
	}
}

namespace carReturn {
	std::string returnBrand;
	std::string returnModel;
	int carSelected;

	void returnAction(std::vector<Car>& carList) {
		carList[carSelected].setCarStatusAvailable();
		std::println("The car was returned.");
		logList.emplace_back(logs::logCarSetReturned);
	}

	void check(std::vector<Car>& carList) {
		if (!(verify::brandIsExist(returnBrand, carList) && verify::modelIsExist(returnModel, carList)))
		{
			std::cerr << error::carDoesntExist;
			logList.emplace_back(logs::logCarDoesntExist);
			return;
		}

		bool carRented = false;
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (returnBrand == carList[i].getBrand() && returnModel == carList[i].getModel())
			{
				if (carList[i].carRented())
				{
					carSelected = i;
					carRented = true;
				}
			}
		}

		if (!carRented)
		{
			std::cerr << error::carRentedFalse;
			logList.emplace_back(logs::logCarRentedFalse);
			return;
		}

		returnAction(carList);
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Return car ===");
		std::print("Car brand: ");
		std::getline(std::cin >> std::ws, returnBrand);

		std::print("Car model: ");
		std::getline(std::cin >> std::ws, returnModel);

		check(carList);
	}
}

namespace carService {
	std::string carBrand;
	std::string carModel;
	int carIndex;

	bool writeBrandAndModel(std::vector<Car>& carList) {
		std::print("Brand: ");
		std::getline(std::cin >> std::ws, carBrand);

		std::print("Model: ");
		std::getline(std::cin >> std::ws, carModel);

		for (size_t i = 0; i < carList.size(); i++)
		{
			if (verify::brandIsExist(carBrand, carList) && verify::modelIsExist(carModel, carList))
			{
				carIndex = i;
				return true;
			}
		}
		return false;
	}

	namespace serviceMain {
		void takeCarToService(std::vector<Car>& carList) {
			std::println("\n== Take the car to the service center ==");
			if (!writeBrandAndModel(carList))
			{
				std::cerr << error::carDoesntExist;
				logList.emplace_back(logs::logCarDoesntExist);
				return;
			}

			if (carList[carIndex].carRented())
			{
				std::cerr << error::carAvailabilityFalse;
				logList.emplace_back(logs::logCarAvailabilityFalse);
				return;
			}

			if (carList[carIndex].carInService())
			{
				std::cerr << error::errorCarInService;
				logList.emplace_back(logs::logErrorCarInService);
				return;
			}

			carList[carIndex].setCarStatusService();
			std::println("The car was taken to the service center.");
			logList.emplace_back(logs::logCarTakenToService);
		}

		void collectCarFromService(std::vector<Car>& carList) {
			std::println("\n== Collect the car from the service center ==");
			if (!writeBrandAndModel(carList))
			{
				std::cerr << error::carDoesntExist;
				logList.emplace_back(logs::logCarDoesntExist);
				return;
			}

			if (!carList[carIndex].carInService())
			{
				std::cerr << error::errorCarIsntService;
				logList.emplace_back(logs::logErrorCarIsntService);
				return;
			}

			carList[carIndex].setCarStatusAvailable();
			std::println("The car was collected from the service center.");
			logList.emplace_back(logs::logCarCollectedFromService);
		}
	}

	void switchService(std::vector<Car>& carList, const int& choose) {
		switch (choose)
		{
		case 1:
			serviceMain::takeCarToService(carList);
			break;

		case 2:
			serviceMain::collectCarFromService(carList);
			break;

		case 3:
			break;

		default:
			std::cerr << error::wrongNumber1to3;
			logList.emplace_back(logs::logWrongNumber1to3);
			lobby(carList);
		}
	}

	void lobby(std::vector<Car>& carList) {
		std::println("\n=== Car service center ===");
		std::println("1) Take the car to the service center");
		std::println("2) Collect the car from the service center");
		std::print("3) Back\nChoose: ");
		int choose;
		inputt::intWrite(choose, "Choose");

		switchService(carList, choose);
	}
}