#include <print>
#include <fstream>
#include <iostream>
#include <string>

#include "Data.hpp"
#include "Error.hpp"
#include "Employee.hpp"

namespace fileActions {
	const std::string fileName = "employeeSave.dat";

	void saveData() {
		std::println("Saving data...");
		std::ofstream writer(fileName);
		if (!writer.is_open())
		{
			logsVector.emplace_back("[Error] Can't save data.");
			writer.close();
			std::cerr << error::fileWriteError;
			return;
		}

		for (size_t i = 0; i < employees.size(); i++)
		{
			writer << employees[i].firstName << "\n";
			writer << employees[i].lastName << "\n";
			writer << employees[i].age << "\n";
			writer << employees[i].salary << "\n";

			//Function using static_cast for convert an enum to an int.
			int tempDepartment = static_cast<int>(employees[i].department);
			writer << tempDepartment << "\n";

			int tempEmployementStatus = static_cast<int>(employees[i].employmentStatus);
			writer << tempEmployementStatus << "\n";
		}

		writer.close();
		std::println("Save completed, terminating program...");
		logsVector.emplace_back("[INFO] Save completed.");
	}

	void loadData() {
		std::println("Loading data...");
		std::ifstream loader(fileName);
		if (!loader.is_open())
		{
			logsVector.emplace_back("[Error] Can't load data.");
			loader.close();
			std::cerr << error::fileLoadError;
			return;
		}

		std::string tempFirstName;
		std::string tempLastName;
	    int tempAge;
		double tempSalary;
		Department tempDepartment;
		EmploymentStatus tempEmploymentStatus;

		int tempDepartment_;
		int tempEmploymentStatus_;

		while (std::getline(loader, tempFirstName))
		{
			std::getline(loader, tempLastName);
			loader >> tempAge;
			loader >> tempSalary;
			loader >> tempDepartment_;
			loader >> tempEmploymentStatus_;

			loader.ignore();

			//Function using static_cast to convert an int to an enum.
			tempDepartment = static_cast<Department>(tempDepartment_);
			tempEmploymentStatus = static_cast<EmploymentStatus>(tempEmploymentStatus_);

			employees.emplace_back(tempFirstName, tempLastName, tempAge, tempSalary, tempDepartment, tempEmploymentStatus);
		}

		loader.close();
		std::println("Load completed.");
		logsVector.emplace_back("[INFO] Load completed.");
	}
}