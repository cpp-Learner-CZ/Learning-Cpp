#pragma once
#include "Employee.hpp"

namespace enumOperation {
	Department intToDepartment(int input);
	EmploymentStatus intToEmploymentStatus(int input);

	//enum -> string
	std::string enumDepartmentToString(Department enumDepartment);

	//enum -> string
	std::string enumEmploymentStatusToString(EmploymentStatus enumEmploymentStatus);
}