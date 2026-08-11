#include <iostream>
#include <print>
#include <vector>

#include "ErrorOrLogs.hpp"
#include "Verify.hpp"
#include "Car.hpp"
#include "Version.hpp"

bool ProgramRun = true;
std::vector<Car> carList;

void mainSwitch(const int& input) {
	switch (input)
	{
	case 1:
		addCar::lobby(carList);
		break;

	case 2:
		showCars(carList);
		break;

	case 3:
		break;

	case 4:
		break;

	case 5:
		break;

	case 6:
		break;

	case 7:
		break;

	case 8:
		break;

	case 9:
		break;

	case 10:
		break;

	case 11:
		break;

	case 12:
		break;

	case 13:
		break;

	case 14:
		ProgramRun = false;
		return;

	default:
		std::cerr << error::wrongNumber1to14;
		logList.emplace_back(logs::logWrongNumber1to14);
		break;
	}
}

int main()
{
	while (ProgramRun)
	{
		std::println("\n==== Fleet management v{} ====", version);
		std::println("1) Add car");
		std::println("2) Show cars");
		std::println("3) Edit car");
		std::println("4) Remove car");
		std::println("5) Search");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::println("9) Rent car");
		std::println("10) Return car");
		std::println("11) Service");
		std::println("12) Logs");
		std::println("13) Export logs");
		std::print("14) Exit\nChoose: ");
		int choose;
		inputt::intWrite(choose, "Choose");

		mainSwitch(choose);
	}

	if (!ProgramRun)
	{
		std::println("Program terminated.");
		return 0;
	}
}