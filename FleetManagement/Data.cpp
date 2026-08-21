#include <print>
#include <fstream>
#include <string>

#include "Car.hpp"
#include "Data.hpp"
#include "ErrorOrLogs.hpp"

namespace logActions {
	void exportLogs() {
		std::println("Exporting logs...");
		std::ofstream saveLog("logs.log");
		if (!saveLog.is_open())
		{
			saveLog.close();
			std::cerr << error::exportLogFailed;
			logList.emplace_back(logs::logExportLogFailed);
			return;
		}

		for (size_t i = 0; i < logList.size(); i++)
		{
			saveLog << logList[i].logStrings << "\n";
		}

		saveLog.close();
		std::println("Log export completed.");
	}

	void showLogs() {
		std::println("=== Show logs ===");
		if (logList.size() == 0)
		{
			std::println("The log list is empty.");
			return;
		}
		for (size_t i = 0; i < logList.size(); i++)
		{
			std::println("- {}", logList[i].logStrings);
		}
	}
}

namespace fileDataAction {
	const std::string fileName = "file.dat";

	void loadData(std::vector<Car>& carList) {
		std::println("Loading data...");
		std::ifstream loader(fileName);
		if (!loader.is_open())
		{
			loader.close();
			std::cerr << error::fileActionLoadFailed;
			logList.emplace_back(logs::logFileActionLoadFailed);
			return;
		}

		std::string tempBrand;
		std::string tempModel;
		float tempPrice;
		float tempMileageInKm;
		int tempYearOfProduction;
		FuelType tempFuelType;
		CarStatus tempCarStatus;

		int tempFuelTypeInt;
		int tempCarStatusInt;
		while (std::getline(loader, tempBrand))
		{
			std::getline(loader, tempModel);
			loader >> tempPrice;
			loader >> tempMileageInKm;
			loader >> tempYearOfProduction;
			loader >> tempFuelTypeInt;
			loader >> tempCarStatusInt;
			loader.ignore();

			tempFuelType = static_cast<FuelType>(tempFuelTypeInt);
			tempCarStatus = static_cast<CarStatus>(tempCarStatusInt);

			carList.emplace_back(tempBrand, tempModel, tempPrice, tempMileageInKm, tempYearOfProduction, tempFuelType, tempCarStatus);
		}

		loader.close();
		std::println("Load completed, starting menu...");
	}

	void saveData(std::vector<Car>& carList) {
		std::println("Saving data...");
		std::ofstream writer(fileName);
		if (!writer.is_open())
		{
			writer.close();
			std::cerr << error::fileActionSaveFailed;
			logList.emplace_back(logs::logFileActionSaveFailed);
			return;
		}

		for (size_t i = 0; i < carList.size(); i++)
		{
			std::string tempBrand = carList[i].getBrand();
			std::string tempModel = carList[i].getModel();
			float tempPrice = carList[i].getPrice();
			float tempMileageInKm = carList[i].getMileage();
			int tempYearOfProduction = carList[i].getYearOfProduction();
			FuelType tempFuelType = carList[i].getFuelType();
			CarStatus tempCarStatus = carList[i].getCarStatus();

			int tempFuelTypeInt = static_cast<int>(tempFuelType);
			int tempCarStatusInt = static_cast<int>(tempCarStatus);

			writer << tempBrand << "\n";
			writer << tempModel << "\n";
			writer << tempPrice << "\n";
			writer << tempMileageInKm << "\n";
			writer << tempYearOfProduction << "\n";
			writer << tempFuelTypeInt << "\n";
			writer << tempCarStatusInt << "\n";
		}

		writer.close();
		std::println("Save completed, terminating program...");
	}
}