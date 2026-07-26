#pragma once;
#include <string>

//Types of errors
namespace error {
	inline const std::string wrongNumber = "ERROR: Write only numbers or valid input!";
	inline const std::string nameExistTrue = "ERROR: This name is alredy exist!";
	inline const std::string wrongInputEnumGenre = "ERROR: Write only numbers from 1 to 4!";
	inline const std::string wrongInputEnumSatus = "ERROR: Write only numbers from 1 to 3!";
	inline const std::string nameIsntExist = "ERROR: Name not found!";
	inline const std::string alredySetGenre = "ERROR: This genre is alredy set this genre for this game!";
	inline const std::string alredySetStatus = "ERROR: This status is alredy set this status for this name!";
	inline const std::string cantOpenFile = "ERROR: Can't open this file!";
}