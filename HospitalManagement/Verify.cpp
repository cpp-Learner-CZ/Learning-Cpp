#include <string>
#include <iostream>
#include <print>
#include <limits>

#include "ErrorOrLogs.hpp"
#include "Patient.hpp"

namespace writeInput {
	void writeInt(int& input, const std::string& message) {
		while (!(std::cin >> input))
		{
			std::cerr << errors::wrongNumber;
			logList.emplace_back(logs::logWrongNumber);
			std::print("\n{}: ", message);

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

namespace verify {
	bool intEqualZero(const int integer) {
		if (integer == 0)
		{
			return true;
		}
		return false;
	}

	bool IDExist(const int checkID, std::vector<Patient>& patients) {
		for (size_t i = 0; i < patients.size(); i++)
		{
			if (checkID == patients[i].getID())
			{
				return true;
			}
		}
		return false;
	}

	bool nameExist(const std::string& checkName, std::vector<Patient>& patients) {
		for (size_t i = 0; i < patients.size(); i++)
		{
			if (checkName == patients[i].getName())
			{
				return true;
			}
		}
		return false;
	}

	bool ageExist(const int checkAge, std::vector<Patient>& patients) {
		for (size_t i = 0; i < patients.size(); i++)
		{
			if (checkAge == patients[i].getAge())
			{
				return true;
			}
		}
		return false;
	}

	bool departmentValidInt1To4(const int& intValid) {
		if (intValid != 0 && intValid <= 4)
		{
			return true;
		}
		return false;
	}
}