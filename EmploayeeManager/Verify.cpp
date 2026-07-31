#include <iostream>
#include <limits>

#include "Verify.hpp"
#include "Employee.hpp"

namespace verify {
	//Check if input is 1-4 true, also false
	bool departmentInputIsCompatible(int inputCheck) {
		if (inputCheck != 0 && inputCheck <= 4)
		{
			return true;
		}
		return false;
	}

	//Check if input is 1-3 true, also false
	bool employmentStatusIsCompatible(int inputCheck) {
		if (inputCheck != 0 && inputCheck <= 3)
		{
			return true;
		}
		return false;
	}

	//If employee name and surname is alredy exist, return true, else return false
	bool nameExistVerify(std::string checkFirstName, std::string checkLastName) {
		for (size_t i = 0; i < employees.size(); i++)
		{
			if (employees[i].firstName == checkFirstName && employees[i].lastName == checkLastName)
			{
				return true;
			}
		}
		return false;
	}

	//If age are bigger or equal 18, function return true.
	bool verifyIfAgeBiggerthan18(int verifyAge) {
		if (verifyAge >= 18)
		{
			return true;
		}
		return false;
	}

	//Function returns true, if salary not equals 0.
	bool salaryIs0(int salary) {
		if (salary != 0)
		{
			return true;
		}
		return false;
	}
}