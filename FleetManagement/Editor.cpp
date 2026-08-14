#include <vector>
#include <print>
#include <iostream>
#include <string>

#include "Editor.hpp"
#include "Car.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

namespace editor {

	std::string searchBrand;
	std::string searchModel;

	namespace editFunctions {
		void lobbyModel(std::vector<Car>& carList) {
			std::println("== Edit model ==");
			std::print("Enter new model: ");
			std::string newModel;
			std::getline(std::cin >> std::ws, newModel);

			for (size_t i = 0; i < carList.size(); i++)
			{
				if (searchBrand == carList[i].getBrand() && searchModel == carList[i].getModel())
				{
					if (!carList[i].setModel(searchBrand, newModel, carList))
					{
						logList.emplace_back(logs::logEditModelError);
						return;
					}
				}
			}

			std::println("The car model has been updated.");
			logList.emplace_back(logs::logEditModelCompleted);
		}

		void lobbyPrice(std::vector<Car>& carList) {
			std::println("== Edit price ==");
			std::print("Enter new price: ");
			float newPrice;
			inputt::floatWrite(newPrice, "Enter new price");

			for (size_t i = 0; i < carList.size(); i++)
			{
				if (searchBrand == carList[i].getBrand() && searchModel == carList[i].getModel())
				{
					if (!carList[i].setPrice(newPrice))
					{
						logList.emplace_back(logs::logEditPriceError);
						return;
					}
				}
			}

			std::println("The car price has been updated.");
			logList.emplace_back(logs::logEditPriceCompleted);
		}

		void lobbyMileageInKm(std::vector<Car>& carList) {
			std::println("== Edit mileage in KM ==");
			std::print("Enter new mileage: ");
			float newMileage;
			inputt::floatWrite(newMileage, "Enter new mileage");

			for (size_t i = 0; i < carList.size(); i++)
			{
				if (searchBrand == carList[i].getBrand() && searchModel == carList[i].getModel())
				{
					if (!carList[i].setMileage(newMileage))
					{
						logList.emplace_back(logs::logEditMileageError);
						return;
					}
				}
			}

			std::println("The car mileage has been updated.");
			logList.emplace_back(logs::logEditMileageCompleted);
		}

		void lobbyFuelType(std::vector<Car>& carList) {
			std::println("== Edit fuel type ==");
			std::println("1) Petrol");
			std::println("2) Diesel");
			std::println("3) Hybrid");
			std::println("4) Electric");
			std::print("Fuel type: ");
			int chooseEnum;
			inputt::intWrite(chooseEnum, "Fuel type");

			for (size_t i = 0; i < carList.size(); i++)
			{
				if (searchBrand == carList[i].getBrand() && searchModel == carList[i].getModel())
				{
					if (!carList[i].setFuelType(chooseEnum))
					{
						logList.emplace_back(logs::logEditFuelTypeError);
						return;
					}
				}
			}

			std::println("The car fuel type has been updated.");
			logList.emplace_back(logs::logEditFuelTypeCompleted);
		}
	}

	void editSwitch(const int& editChoose, std::vector<Car>& carList) {
		switch (editChoose)
		{
		case 1:
			editFunctions::lobbyModel(carList);
			break;

		case 2:
			editFunctions::lobbyPrice(carList);
			break;

		case 3:
			editFunctions::lobbyMileageInKm(carList);
			break;

		case 4:
			editFunctions::lobbyFuelType(carList);
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber1to5;
			logList.emplace_back(logs::logWrongNumber1to5);
			lobby(carList);
		}
	}

	void lobby(std::vector<Car>&  carList) {
		std::println("\n=== Edit car ===");
		std::print("Car brand: ");
		std::getline(std::cin >> std::ws, searchBrand);	

		std::print("Car model: ");
		std::getline(std::cin >> std::ws, searchModel);
		
		// Check if car is alredy exist
		if (!(verify::brandIsExist(searchBrand, carList) && verify::modelIsExist(searchModel, carList)))
		{
			std::cerr << error::carDoesntExist;
			logList.emplace_back(logs::logCarDoesntExist);
			return;
		}
		
		std::println("=== Selected car ===");
		searchCar::mainSearch(searchBrand, searchModel, carList);

		std::println("\n=== Edit car ===");
		std::println("1) Model");
		std::println("2) Price");
		std::println("3) MileageInKm");
	    std::println("4) Fuel type");
		std::print("5) Back\nChoose: ");
		int editChoose;
		inputt::intWrite(editChoose, "Choose");

		editSwitch(editChoose, carList);
	}
}