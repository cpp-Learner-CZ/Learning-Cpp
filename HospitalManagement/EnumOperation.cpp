#include "EnumOperation.hpp"
#include "Patient.hpp"

namespace enumActions {
	Department intToDepartment(const int& setDepartment) {
		switch (setDepartment)
		{
		case 1:
			return Department::Surgery;

		case 2:
			return Department::Cardiology;

		case 3:
			return Department::Neurology;

		case 4:
			return Department::Emergency;
		}
	}

	std::string departmentToString(const Department& showDepartment) {
		switch (showDepartment)
		{	
		case Department::Surgery:
			return "Surgery";

		case Department::Cardiology:
			return "Cardiology";

		case Department::Neurology:
			return "Neurology";

		case Department::Emergency:
			return "Emergency";
		}
	}

	std::string statusToString(const Status& showStatus) {
		switch (showStatus)
		{
		case Status::New:
			return "New";

		case Status::Admitted:
			return "Admitted";

		case Status::Treatment:
			return "Treatment";

		case Status::Discharged:
			return "Discharged";
		
		case Status::Critical:
			return "Critical";
		}
	}
}