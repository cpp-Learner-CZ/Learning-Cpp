#pragma once

namespace verify {
	//If name alredy exist return true, else return false.
	bool nameIsExist(std::string name);

	//If quantity equals zero, return true, else return false.
	bool quantityIs0(int& quantity);

	//If price equals zero, return true, else return false.
	bool priceIs0(double& price);

	//If integer equals bigger than five or zero, return false, else return true.
	bool enumInputIsOK(const int& input);
}