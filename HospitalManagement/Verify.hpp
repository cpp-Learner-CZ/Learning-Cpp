#pragma once
#include <string>

namespace writeInput {
	void writeInt(int& input, const std::string& message);
}

namespace verify {
	bool intEqualZero(const int integer);

	bool IDExist(const int checkID, std::vector<Patient>& patients);

	bool nameExist(const std::string& checkName, std::vector<Patient>& patients);

	bool ageExist(const int checkAge, std::vector<Patient>& patients);

	bool departmentValidInt1To4(const int& intValid);
}