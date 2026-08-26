#pragma once
#include <vector>
#include <string>

extern std::vector<std::string> logList;

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
	Status status = Status::New;
	std::string dateOfAdmission;
	std::vector<std::string> treatments;

public:
	Patient() {}

	Patient(int ID, std::string name, int age, Department department, std::string diagnosis, std::string dateOfAdmission) : ID(ID), name(name), age(age), department(department), diagnosis(diagnosis), dateOfAdmission(dateOfAdmission) {}

	int getID() const;

	std::string getName() const;

	int getAge() const;
};
