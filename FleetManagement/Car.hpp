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

	Car(std::string b, std::string mo, float p, float mi, int y, FuelType f, CarStatus c)
	{
		// A new car is always available
		c = CarStatus::Available;

		brand = b;
		model = mo;
		price = p;
		mileageInKm = mi;
		yearOfProduction = y;
		fuelType = f;
		carStatus = c;
	}

	std::string getBrand();

	std::string getModel();
};

namespace addCar {
	void lobby(std::vector<Car>& carList);
}