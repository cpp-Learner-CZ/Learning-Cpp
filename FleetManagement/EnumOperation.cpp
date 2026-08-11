#include "EnumOperation.hpp"
#include "Car.hpp"

namespace enumAction {
	FuelType intToFuelType(const int& enumSet) {
		switch (enumSet)
		{	
		case 1:
			return FuelType::Petrol;

		case 2:
			return FuelType::Diesel;

		case 3:
			return FuelType::Hybrid;

		case 4:
			return FuelType::Electric;
		}
	}

	std::string enumFuelToString(const FuelType& input) {
		switch (input)
		{
		case FuelType::Petrol:
			return "Petrol";

		case FuelType::Diesel:
			return "Diesel";

		case FuelType::Hybrid:
			return "Hzbrid";

		case FuelType::Electric:
			return "Electric";
		}
	}

	CarStatus intToCarStatus(const int& enumSet) {
		switch (enumSet)
		{
		case 1:
			return CarStatus::Available;

		case 2:
			return CarStatus::Rented;

		case 3:
			return CarStatus::Service;
		}
	}

	std::string enumCarToString(const CarStatus& input) {
		switch (input)
		{
		case CarStatus::Available:
			return "Available";

		case CarStatus::Rented:
			return "Rented";

		case CarStatus::Service:
			return "Service";
		}
	}
}