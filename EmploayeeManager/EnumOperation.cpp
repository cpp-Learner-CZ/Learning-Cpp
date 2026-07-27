#include "EnumOperation.hpp"
#include "Employee.hpp"

namespace enumOperation {
	Department intToDepartment(int input) {
		switch (input)
		{
		case 1:
			return Department::IT;

		case 2:
			return Department::HR;

		case 3:
			return Department::Finance;

		case 4:
			return Department::Sales;
		}
	}

	EmploymentStatus intToEmploymentStatus(int input) {
		switch (input)
		{
		case 1:
			return EmploymentStatus::Active;

		case 2:
			return EmploymentStatus::Vacation;

		case 3:
			return EmploymentStatus::SickLeave;
		}
	}

	//enum -> string
	std::string enumDepartmentToString(Department enumDepartment) {
		switch (enumDepartment)
		{
		case Department::IT:
			return "IT";

		case Department::HR:
			return "HR";

		case Department::Finance:
			return "Finance";

		case Department::Sales:
			return "Sales";
		}
	}

	//enum -> string
	std::string enumEmploymentStatusToString(EmploymentStatus enumEmploymentStatus) {
		switch (enumEmploymentStatus)
		{
		case EmploymentStatus::Active:
			return "Active";

		case EmploymentStatus::Vacation:
			return "Vacation";

		case EmploymentStatus::SickLeave:
			return "Sick leave";
		}
	}
}