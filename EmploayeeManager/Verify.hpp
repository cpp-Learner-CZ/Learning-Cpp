#pragma once

namespace verify {
	//Check if input is 1-4 true, also false
	bool departmentInputIsCompatible(int inputCheck);

	//Check if input is 1-3 true, also false
	bool employmentStatusIsCompatible(int inputCheck);

	//If employee name and surname is alredy exist, return true, else return false
	bool nameExistVerify(std::string checkFirstName, std::string checkLastName);
}