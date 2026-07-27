#include <iostream>
#include <limits>

#include "Verify.hpp"

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
}