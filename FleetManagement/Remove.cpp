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
	
	void consentRemove(std::vector<Car>& carLIst) {

	}

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