#pragma once

#include "Patient.hpp"

namespace enumActions {
	Department intToDepartment(const int& setDepartment);

	std::string departmentToString(const Department& showDepartment);

	std::string statusToString(const Status& showStatus);
}