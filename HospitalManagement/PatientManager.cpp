#include <print>
#include <iostream>
#include <string>

#include "Patient.hpp"
#include "PatientManager.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"

namespace addPatient {
	int addID;
	std::string addName;
	int addAge;
	Department addDepartment;

	int intDepartment;

	void setDepartment(std::vector<Patient> patients) {
		std::println("== Set department ==");
		std::println("1) Surgery");
		std::println("2) Cardiology");
		std::println("3) Neurology");
		std::println("4) Emergency");
		std::print("Department: ");
		writeInput::writeInt(intDepartment, "Department");




	}

	void lobby(std::vector<Patient>& patients) {
		std::println("=== Add patient ===");
		std::print("ID: ");
		writeInput::writeInt(addID, "ID");

		if (verify::intEqualZero(addID))
		{
			std::cerr << errors::IDIsZero;
			logList.emplace_back(logs::logIDIsZero);
			return;
		}

		if (verify::IDExist(addID, patients))
		{
			std::cerr << errors::duplicateID;
			logList.emplace_back(logs::logDuplicateID);
			return;
		}

		std::print("Name: ");
		std::getline(std::cin >> std::ws, addName);

		if (verify::nameExist(addName, patients))
		{
			std::cerr << errors::nameAlredyExist;
			logList.emplace_back(logs::logNameAlredyExist);
			return;
		}

		std::print("Age: ");
		writeInput::writeInt(addAge, "Age");

		if (verify::intEqualZero(addAge))
		{
			std::cerr << errors::ageIsZero;
			logList.emplace_back(logs::logAgeIsZero);
			return;
		}

		setDepartment(patients);
	}
}