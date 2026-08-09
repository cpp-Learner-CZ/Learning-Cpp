#include <string>
#include <iostream>
#include <limits>
#include <print>

#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "Car.hpp"

namespace inputt {
	// Verify input because user can enter wrong number
	void intWrite(int& input, const std::string message) {
		while (!(std::cin >> input))
		{
			std::cerr << error::wrongNumber;
			logList.emplace_back(logs::logWrongNumber);
			std::print("\n{}: ", message);

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	// Verify input because user can enter wrong number
	void floatWrite(float& input, const std::string message) {
		while (!(std::cin >> input))
		{
			std::cerr << error::wrongNumber;
			logList.emplace_back(logs::logWrongNumber);
			std::print("\n{}: ", message);

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

namespace verify {
	// Verify input because user can enter duplicate brands
	bool brandIsExist(const std::string& brand, std::vector<Car>& carList) {
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (brand == carList[i].getBrand())
			{
				return true;
			}
		}
		return false;
	}

	// Verify input because user can enter duplicite models
	bool modelIsExist(const std::string& model, std::vector<Car>& carList) {
		for (size_t i = 0; i < carList.size(); i++)
		{
			if (model == carList[i].getModel())
			{
				return true;
			}
		}
		return false;
	}

	// Verify if the number is equal to zero 
	namespace equalZero {
		bool zeroInt(int& check) {
			if (check == 0)	return true;
			return false;
		}

		bool zeroFloat(float& check) {
			if (check == 0)	return true;
			return false;
		}
	}
}