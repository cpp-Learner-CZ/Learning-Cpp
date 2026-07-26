#include <iostream>
#include <print>

#include "Error.hpp"

bool programRun = true;

void mainSwitch(int inputSwitch) {
	switch (inputSwitch)
	{
	case 1:
		break;

	case 2:
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
		std::println("Program terminated.");
		programRun = false;
		break;

	default:
		std::cerr << error::wrongNumber;
		break;
	}


}

int main()
{
	
	//Main loop
	while (programRun)
	{
		std::println("==== Emploayee manager ====");
		std::println("1) Add employee");
		std::println("2) Show employees");
		std::println("3) Edit employee");
		std::println("4) Remove employee");
		std::println("5) Search employee");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::println("9) Export report");
		std::print("10) Terminate\nChoose: ");
		int choose;
		std::cin >> choose;

		mainSwitch(choose);
	}

	return 0;
}