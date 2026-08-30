#pragma once
#include <vector>

#include "Patient.hpp"

namespace addPatient {
	void lobby(std::vector<Patient>& patients);
}

namespace editPatient {
	void lobby(std::vector<Patient>& patients);
}

void showPatients(std::vector<Patient>& patients);