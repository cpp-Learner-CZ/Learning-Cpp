#include <string>

#include "Patient.hpp"

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