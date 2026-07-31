#include <string>

namespace error {
	inline const std::string wrongNumber = "Write only numbers!";
	inline const std::string errorInputSetDepartment = "ERROR: Write numbers from 1 to 4!";
	inline const std::string errorInputEmploymentStatus = "ERROR: Write numbers from 1 to 3!";
	inline const std::string wrongNumberOrMistake = "ERROR: Write only numbers or write only from 1 to 10!";
	inline const std::string nameIsExist = "ERROR: This name is alredy exist!";
	inline const std::string nameIsntExist = "ERROR: This name isn't exist!";
	inline const std::string mistakeNumberEdit = "ERROR: Write only numbers from 1 to 5!";
	inline const std::string fileWriteError = "File write error: unexpected error.";
	inline const std::string fileLoadError = "File load error: file employeeSave.dat doesn't exist.\nThe file will be created after the program ends.";
	inline const std::string wrongAge = "Wrong age: age must be bigger or equal than 18.";
	inline const std::string wrongSalary = "Wrong salary: salary mustn't be 0.";
}