#include <print>
#include <iostream>
#include <string>

#include "Patient.hpp"
#include "PatientManager.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "EnumOperation.hpp"

namespace addPatient {
	int addID;
	std::string addName;
	int addAge;
	Department addDepartment;
	std::string addDiagnosis;
	std::string addDateOfAdmission;

	int intDepartment;

	void savePatient(std::vector<Patient>& patients) {
		patients.emplace_back(addID, addName, addAge, addDepartment, addDiagnosis, addDateOfAdmission);
		std::println("Patient added.");
		logList.emplace_back(logs::logPatientAdded);
	}

	void consentAddPatient(std::vector<Patient>& patients) {
		std::println("=== Consent add patient ===");
		std::println("ID: {}", addID);
		std::println("Name: {}", addName);
		std::println("Age: {}", addAge);
		std::println("Department: {}", enumActions::departmentToString(addDepartment));
		std::println("Diagnosis: ", addDiagnosis);
		std::println("Status: New");
		std::println("Date of admission: {}", addDateOfAdmission);
		std::println("------------------------------");
		std::print("Add patient: write y\nCancel add patient: write n\nConsent: ");
		std::string stringConsent;
		std::getline(std::cin >> std::ws, stringConsent);

		bool boolConsent = (stringConsent == "y" || stringConsent == "Y");
		if (!boolConsent)
		{
			std::println("The patient addition was canceled.");
			logList.emplace_back(logs::logPatientAdditionCanceled);
			return;
		}

		savePatient(patients);
	}

	void setDiagnosisAndDateOfAdmission(std::vector<Patient>& patients) {
		// TODO: Error maybe \n in diagnosis
		std::print("Diagnosis: ");
		std::getline(std::cin >> std::ws, addDiagnosis);
		std::print("Date of admission: ");
		std::getline(std::cin >> std::ws, addDateOfAdmission);

		consentAddPatient(patients);
	}

	void setDepartment(std::vector<Patient> patients) {
		do {
			std::println("\n== Set department ==");
			std::println("1) Surgery");
			std::println("2) Cardiology");
			std::println("3) Neurology");
			std::println("4) Emergency");
			std::print("Department: ");
			writeInput::writeInt(intDepartment, "Department");

			// Check if intDepartment is not between 1 and 4
			if (!verify::departmentValidInt1To4(intDepartment))
			{
				std::cerr << errors::wrongNumber1to4;
				logList.emplace_back(logs::logWrongNumber1to4);
				continue;
			}

		} while (!verify::departmentValidInt1To4(intDepartment));

		addDepartment = enumActions::intToDepartment(intDepartment);

		setDiagnosisAndDateOfAdmission(patients);
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

		// TODO: Error
		if (verify::IDExist(addID, patients))
		{
			std::cerr << errors::duplicateID;
			logList.emplace_back(logs::logDuplicateID);
			return;
		}

		std::print("Name: ");
		std::getline(std::cin >> std::ws, addName);

		// TODO: Error
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