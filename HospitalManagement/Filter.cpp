#include <iostream>
#include <vector>
#include <print>

#include "Filter.hpp"
#include "Patient.hpp"
#include "ErrorOrLogs.hpp"
#include "Verify.hpp"

namespace filter {
	namespace filterActions {
		void ageBiggestThan18(const std::vector<Patient>& patients) {
			std::println("== Filter: Age biggest than 18 ==");
			for (size_t i = 0; i < patients.size(); i++)
			{
				if (patients[i].getAge() > 18)
				{
					patients[i].showPatientINFO();
				}
			}
		}

		void departmentIsCardiology(const std::vector<Patient>& patients) {
			std::println("== Filter: Department is cardiology ==");
			for (size_t i = 0; i < patients.size(); i++)
			{
				if (patients[i].getDepartment() == Department::Cardiology)
				{
					patients[i].showPatientINFO();
				}
			}
		}

		void statusIsNew(const std::vector<Patient>& patients) {
			std::println("== Filter: Status is new ==");
			for (size_t i = 0; i < patients.size(); i++)
			{
				if (patients[i].getStatus() == Status::New)
				{
					patients[i].showPatientINFO();
				}
			}
		}

		void statusIsCritical(const std::vector<Patient>& patients) {
			std::println("== Filter: Status is critical ==");
			for (size_t i = 0; i < patients.size(); i++)
			{
				if (patients[i].getStatus() == Status::Critical)
				{
					patients[i].showPatientINFO();
				}
			}
		}
	}

	void chooseFilter(const int& choose, const std::vector<Patient>& patients) {
		switch (choose)
		{
		case 1:
			filterActions::ageBiggestThan18(patients);
			break;

		case 2:
			filterActions::departmentIsCardiology(patients);
			break;

		case 3:
			filterActions::statusIsNew(patients);
			break;
		
		case 4:
			filterActions::statusIsCritical(patients);
			break;

		default:
			std::cerr << errors::wrongNumber1to4;
			logList.emplace_back(logs::logWrongNumber1to4);
			break;
		}
	}

	void filterLobby(const std::vector<Patient>& patients) {
		std::println("== Filter ==");
		std::println("1) Age bigger than 18");
		std::println("2) Department: cardiology");
		std::println("3) Status: new");
		std::println("4) Status: critical");
		std::print("5) Back\nChoose filter: ");

		int intFilter;
		writeInput::writeInt(intFilter, "Choose filter");
		chooseFilter(intFilter, patients);
	}
}