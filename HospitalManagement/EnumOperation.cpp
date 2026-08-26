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
}