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
		Status status = Status::New;

		patients.emplace_back(addID, addName, addAge, addDepartment, addDiagnosis, status, addDateOfAdmission);
		std::println("Patient added.");
		logList.emplace_back(logs::logPatientAdded);
	}

	void consentAddPatient(std::vector<Patient>& patients) {
		std::println("=== Consent add patient ===");
		std::println("ID: {}", addID);
		std::println("Name: {}", addName);
		std::println("Age: {}", addAge);
		std::println("Department: {}", enumActions::departmentToString(addDepartment));
		std::println("Diagnosis: {}", addDiagnosis);
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
		std::print("Diagnosis: ");
		std::getline(std::cin >> std::ws, addDiagnosis);
		std::print("Date of admission: ");
		std::getline(std::cin >> std::ws, addDateOfAdmission);

		consentAddPatient(patients);
	}

	void setDepartment(std::vector<Patient>& patients) {
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

namespace editPatient {
	int chooseEditID;
	int index;
	std::string editName;
	int editAge;

	void enterEditName(std::vector<Patient>& patients) {
		std::print("Enter new name: ");
		std::getline(std::cin >> std::ws, editName);

		if (verify::nameExist(editName, patients))
		{
			std::cerr << errors::nameAlredyExist;
			logList.emplace_back(logs::logNameAlredyExist);
			return;
		}

		patients[index].setName(editName);
		std::println("Name updated successfully.");
		logList.emplace_back(logs::logEditNameCompleted);
	}

	void enterEditAge(std::vector<Patient>& patients) {
		std::print("Enter new age: ");
		writeInput::writeInt(editAge, "Enter new age");

		patients[index].setAge(editAge);
		std::println("Age updated successfully.");
		logList.emplace_back(logs::logEditAgeCompleted);
	}

	void editSwitch(const int choose, std::vector<Patient>& patients) {
		switch (choose)
		{
		case 1:
			enterEditName(patients);
			break;

		case 2:
			enterEditAge(patients);
			break;

		case 3:
			break;

		default:
			std::cerr << errors::wrongNumber1to3;
			logList.emplace_back(logs::logWrongNumber1to3);
			break;
		}
	}

	void lobby(std::vector<Patient>& patients) {
		std::println("=== Edit patient ===");
		std::print("ID: ");
		writeInput::writeInt(chooseEditID, "ID");
		if (!verify::IDExist(chooseEditID, patients))
		{
			std::cerr << errors::IDdoesntFound;
			logList.emplace_back(logs::logIDdoesntFound);
			return;
		}

		std::println("=== Edit patient ===");
		for (size_t i = 0; i < patients.size(); i++)
		{
			if (patients[i].getID() == chooseEditID)
			{
				index = i;
				patients[i].showPatientINFO();
				std::println(" - - - - - - - - - - - - - - -");
				std::println("==============================");
			}
		}
		std::println("1) Edit name");
		std::println("2) Edit age");
		std::print("3) Back\nEdit choose: ");
		int choose;
		writeInput::writeInt(choose, "Edit choose");

		editSwitch(choose, patients);
	}
}

void showPatients(std::vector<Patient>& patients) {
	std::println("=== Show patients ===");
	if (patients.size() == 0)
	{
		std::cerr << errors::patientsVectorEmpty;
		return;
	}

	for (size_t i = 0; i < patients.size(); i++)
	{
		patients[i].showPatientINFO();
		std::println("==============================\n");
	}
}