#pragma once
#include <vector>
#include <string>

extern std::vector<std::string> logList;

struct TreatmentList
{
	std::string treatmentString;
};

enum class Department
{
	Surgery = 1,
	Cardiology = 2,
	Neurology = 3,
    Emergency = 4
};

enum class Status
{
	New = 1,
	Admitted = 2,
	Treatment = 3,
	Discharged = 4,
    Critical = 5
};

class Patient
{
private:
	int ID;
	std::string name;
	int age;
	Department department;
	std::string diagnosis;
	Status status;
	std::string dateOfAdmission;
	std::vector<TreatmentList> treatments;

public:
	Patient() {}

	Patient(int ID, std::string name, int age, Department department, std::string diagnosis, Status status, std::string dateOfAdmission) : ID(ID), name(name), age(age), department(department), diagnosis(diagnosis), status(status), dateOfAdmission(dateOfAdmission) {}

	int getID() const;

	std::string getName() const;

	int getAge() const;

	Department getDepartment() const;

	std::string getDiagnosis() const;

	Status getStatus() const;

	std::string getDateOfAdmission() const;

	void showPatientINFO() const;
};