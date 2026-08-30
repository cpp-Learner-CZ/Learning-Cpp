#include <string>
#include <print>

#include "Patient.hpp"
#include "EnumOperation.hpp"

std::vector<std::string> logList;

int Patient::getID() const {
	return this->ID;
}

std::string Patient::getName() const {
	return this->name;
}

int Patient::getAge() const {
	return this->age;
}

Department Patient::getDepartment() const {
	return this->department;
}

std::string Patient::getDiagnosis() const {
	return this->diagnosis;
}

Status Patient::getStatus() const {
	return this->status;
}

std::string Patient::getDateOfAdmission() const {
	return this->dateOfAdmission;
}

void Patient::showPatientINFO() const {
	std::println("ID: {}", this->ID);
	std::println("Name: {}", this->name);
	std::println("Age: {}", this->age);
	std::println("Department: {}", enumActions::departmentToString(this->department));
	std::println("Diagnosis: {}", this->diagnosis);
	std::println("Status: {}", enumActions::statusToString(this->status));
	std::println("Date of admission: {}", this->dateOfAdmission);
	std::println("------------------------------");
	std::println("= Treatments: ");
	for (size_t i = 0; i < treatments.size(); i++)
	{
		std::println("- {}", treatments[i].treatmentString);
	}
}