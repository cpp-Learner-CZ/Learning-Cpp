#pragma once

namespace verify {
	//Check if input is 1-4 true, also false
	bool departmentInputIsCompatible(int inputCheck);

	//Check if input is 1-3 true, also false
	bool employmentStatusIsCompatible(int inputCheck);

	//If employee name and surname is alredy exist, return true, else return false
	bool nameExistVerify(std::string checkFirstName, std::string checkLastName);

	//If age are bigger or equal 18, function return true.
	bool verifyIfAgeBiggerthan18(int verifyAge);

	//Function returns true, if salary not equals 0.
	bool salaryIs0(int salary);
}