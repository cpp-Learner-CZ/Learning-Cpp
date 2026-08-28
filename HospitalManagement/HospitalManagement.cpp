#include <iostream>
#include <print>

#include "Version.hpp"
#include "Patient.hpp"
#include "Verify.hpp"
#include "ErrorOrLogs.hpp"
#include "PatientManager.hpp"

std::vector<Patient> patients;

bool programRun = true;

void mainSwitch(const int& switchChoose) {
	switch (switchChoose)
	{
	case 1:
		addPatient::lobby(patients);
		break;

	case 2:
		std::println("This feature is not yet available.");
		break;

	case 3:
		std::println("This feature is not yet available.");
		break;

	case 4:
		std::println("This feature is not yet available.");
		break;

	case 5:
		std::println("This feature is not yet available.");
		break;

	case 6:
		std::println("This feature is not yet available.");
		break;

	case 7:
		std::println("This feature is not yet available.");
		break;

	case 8:
		std::println("This feature is not yet available.");
		break;

	case 9:
		std::println("This feature is not yet available.");
		break;

	case 10:
		std::println("This feature is not yet available.");
		break;

	case 11:
		std::println("This feature is not yet available.");
		break;

	case 12:
		std::println("This feature is not yet available.");
		break;

	case 13:
		std::println("This feature is not yet available.");
		break;

	case 14:
		std::println("This feature is not yet available.");
		break;

	case 15:
		programRun = false;
		break;

	default:
		std::cerr << errors::wrongNumber1to15;
		logList.emplace_back(logs::logWrongNumber1to15);
		break;
	}
}

int main()
{
	while (programRun)
	{
		std::println("\n==== Hospital management v{} ====", appVersion);
		std::println("1) Add patient");
		std::print("15) Exit\nChoose: ");
		int choose;
		writeInput::writeInt(choose, "Choose");

		mainSwitch(choose);
	}

	if (!programRun)
	{
		return 0;
	}
}