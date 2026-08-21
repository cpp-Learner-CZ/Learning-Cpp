#include <print>
#include <string>
#include <iostream>

#include "Remove.hpp"
#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

namespace remover {
	std::string removeBrand;
	std::string removeModel;
	
	void removeAction(std::vector<Car>& carList) {
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (removeBrand == carList[i].getBrand() && removeModel == carList[i].getModel())
			{
				carList.erase(carList.begin() + i);
			}
		}
		std::println("Car removed.");
		logList.emplace_back(logs::logRemoveCompleted);
	}

	void consentRemove(std::vector<Car>& carList) {
		std::println("\n== Consent remove ==");
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (removeBrand == carList[i].getBrand() && removeModel == carList[i].getModel())
			{
				Car car;
				car.showCar(i, carList);
			}
		}

		std::print("= Do you want remove this car?\nWrite y or n: ");
		std::string stringConstent;
		std::getline(std::cin >> std::ws, stringConstent);

		bool boolConsent = (stringConstent == "y" || stringConstent == "Y");

		if (!boolConsent)
		{
			std::println("Car removal canceled.");
			logList.emplace_back(logs::logRemoveCanceled);
			return;
		}

		removeAction(carList);
	}

	// Check if the car is not rented
	void verifyRented(std::vector<Car>& carList) {
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (removeBrand == carList[i].getBrand() && removeModel == carList[i].getModel())
			{
				if (carList[i].getCarStatus() == CarStatus::Rented)
				{
					std::cerr << error::removeCarRented;
					logList.emplace_back(logs::logRemoveCarRented);
					return;
				}
			}
		}

		consentRemove(carList);
	}

	// Check if the entered brand and model are valid
	void verifyCar(std::vector<Car>& carList) {
		if (!(verify::brandIsExist(removeBrand, carList) && verify::modelIsExist(removeModel, carList)))
		{
			std::cerr << error::carDoesntExist;
			logList.emplace_back(logs::logCarDoesntExist);
			return;
		}

		verifyRented(carList);
	}

	void lobby(std::vector<Car>& carList) {
		std::println("=== Remove car ===");
		std::print("Brand: ");
		std::getline(std::cin >> std::ws, removeBrand);

		std::print("Model: ");
		std::getline(std::cin >> std::ws, removeModel);

		verifyCar(carList);
	}
}