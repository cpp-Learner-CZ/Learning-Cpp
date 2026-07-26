#include <string>
#include <iostream>

#include "Verify.hpp"
#include "Data.hpp"

namespace verify {
	//If name exist = return true, else return false
	bool nameExist(std::string names) {
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == names)
			{
				return true;
			}
		}
		return false;
	}

	//If enum 1-4 return true, else return false
	bool enumGenreIsCompatible(int input) {
		if (input != 0 && input <= 4)
		{
			return true;
		}
		return false;
	}

	//If enum 1-3 return true, else return false
	bool enumStatusIsCompatible(int input) {
		if (input != 0 && input <= 3)
		{
			return true;
		}
		return false;
	}

}