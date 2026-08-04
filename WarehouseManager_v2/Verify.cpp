#include <string>

#include "Verify.hpp"
#include "Warehouse.hpp"

namespace verify {
    //If name alredy exist return true, else return false.
	bool nameIsExist(std::string name) {
		for (size_t i = 0; i < productList.size(); i++)
		{
			if (productList[i].name == name)
			{
				return true;
			}
		}
		return false;
	}

	//If quantity equals zero, return true, else return false.
	bool quantityIs0(int& quantity) {
		if (quantity == 0)
		{
			return true;
		}
		return false;
	}

	//If price equals zero, return true, else return false.
	bool priceIs0(double& price) {
		if (price == 0)
		{
			return true;
		}
		return false;
	}

	//If integer equals bigger than five or zero, return false, else return true.
	bool enumInputIsOK(const int& input) {
		if (input != 0 && input <= 5)
		{
			return true;
		}
		return false;
	}

	//If integer 'check' equals to 'size' or lower than integer 'size', return true, else return false.
	bool intIsEqualOrLower(const int& size, const int& check) {
		if (size >= check)
		{
			return true;
		}
		return false;
	}
}