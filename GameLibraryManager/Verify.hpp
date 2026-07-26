#pragma once

namespace verify {
	//If name exist = return true, else return false
	bool nameExist(std::string names);

	//If enum 1-4 return true, else return false
	bool enumGenreIsCompatible(int input);

	//If enum 1-3 return true, else return false
	bool enumStatusIsCompatible(int input);
}
