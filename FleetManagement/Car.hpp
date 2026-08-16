#pragma once
#include <vector>
#include <iostream>
#include <string>

struct logString {
	std::string logStrings;
};

extern std::vector<logString> logList;

enum class FuelType
{
	Petrol = 1, 
	Diesel = 2,
	Hybrid = 3, 
	Electric = 4
};

enum class CarStatus
{
	Available = 1,
	Rented = 2, 
	Service = 3
};

class Car
{
	// For train getter and setter
private:
	std::string brand;
	std::string model;
	float price;
	float mileageInKm;
	int yearOfProduction;
	FuelType fuelType;
	CarStatus carStatus;

public:
	Car(){}

	Car(std::string b, std::string mo, float p, float mi, int y, FuelType f);

	std::string getBrand() const;

	std::string getModel() const;

	float getPrice() const;

	float getMileage() const;

	FuelType getFuelType();

	CarStatus getCarStatus();

	bool setModel(const std::string& searchBrandSet, const std::string newModelSet, std::vector<Car>& carList);

	bool setPrice(const float newPriceSet);

	bool setMileage(const float newMileageSet);

	bool setFuelType(const int newFuelType);

	void showCar(int index, std::vector<Car>& carList);
};

namespace addCar {
	void lobby(std::vector<Car>& carList);
}

namespace searchCar {
	void mainSearch(const std::string& searchBrand, const std::string& searchModel, std::vector<Car>& carList);

	void lobby(std::vector<Car>& carList);
}

void showCars(std::vector<Car>& carList);