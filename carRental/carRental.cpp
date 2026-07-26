#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct car
{
	std::string mark;
	std::string model;
	int yearOfManufacture = 0;
	int kmTraveled = 0;
	bool availability = false;
};
std::vector <car> cars;

bool runtime = true;

void stringAvailability(bool availab) {
	if (!availab)
	{
		std::cout << "\nCar is not available";
	}
	else
	{
		std::cout << "\nCar is available";
	}
}

bool boolAvailabilityRead(std::string readerss) {
	bool availabilitysss = (readerss == "y" || readerss == "Y");
	return availabilitysss;
}

void addCar() {
	car carss;

	std::cout << "\n=== Add car ===";
	std::cout << "\nCar mark: ";
	std::getline(std::cin >> std::ws, carss.mark);

	std::cout << "\nCar model: ";
	std::getline(std::cin >> std::ws, carss.model);

	std::cout << "\nCar year of manufacture: ";
	std::cin >> carss.yearOfManufacture;

	std::cout << "\nKM Traveled: ";
	std::cin >> carss.kmTraveled;

	std::string availabilityReader;
	std::cout << "\nCar availabilty(y/n)";
	std::getline(std::cin  >> std::ws, availabilityReader);

	carss.availability = boolAvailabilityRead(availabilityReader);

	cars.push_back(carss);
	std::cout << "\nCar added.\n\n";
}

void showAllCars() {
	std::cout << "\n=== Show all cars ===";
	for (int i = 0; i < cars.size(); i++)
	{
		std::cout << "\nCar " << i + 1 << ".";
		std::cout << "\nMark: " << cars[i].mark;
		std::cout << "\nModel: " << cars[i].model;
		std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
		std::cout << "\nKM Traveled: " << cars[i].kmTraveled;
		stringAvailability(cars[i].availability);
	}
}

void searchCar() {
	bool foundeddzi = false;
	std::cout << "\n=== Search car ===";
	std::string marker;
	std::cout << "\nWrite mark: ";
	std::getline(std::cin >> std::ws, marker);
	std::string model;
	std::cout << "\nWrite model: ";
	std::getline(std::cin >> std::ws, model);
	for (int i = 0; i < cars.size(); i++)
	{
		if (marker == cars[i].mark && model == cars[i].model)
		{
		    foundeddzi = true;
			std::cout << "\nMark: " << cars[i].mark;
			std::cout << "\nModel: " << cars[i].model;
			std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
			std::cout << "\nKM Traveled: " << cars[i].kmTraveled;
			stringAvailability(cars[i].availability);
		}
	}
	if (!foundeddzi)
	{
		std::cout << "\nCar not found.";
	}
	foundeddzi = false;
}

void editMark() {
	bool updated = false;
	std::cout << "\nEDIT MARK";
	std::cout << "\nWrite mark for edit mark: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model for edit mark: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	std::cout << "\n\nWrite new mark: ";
	std::string newMark;
	std::getline(std::cin >> std::ws, newMark);

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model)
		{
			cars[i].mark = newMark;
			std::cout << "\nMark updated.";
			updated = true;
		}
	}
	if (!updated)
	{
		std::cout << "\nError: Car not found or can not update mark.";
	}
	updated = false;
}

void editModel() {
	bool updateda = false;
	std::cout << "\nEDIT MODEL";
	std::cout << "\nWrite mark for edit model: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model for edit model: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	std::cout << "\n\nWrite new model: ";
	std::string newModel;
	std::getline(std::cin >> std::ws, newModel);

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model)
		{
			cars[i].model = newModel;
			std::cout << "\nModel updated.";
			updateda = true;
		}
	}
	if (!updateda)
	{
		std::cout << "\nError: Car not found or can not update model.";
	}
	updateda = false;
}

void editYearOfManufacture() {
	bool updatedsss = false;
	std::cout << "\nEDIT YEAR OF MANUFACTURE";
	std::cout << "\nWrite mark for edit year of manufacture: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model for edit year of manufacture: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	std::cout << "\n\nWrite new year of manufacture: ";
	int newYearOfManufacture;
	std::cin >> newYearOfManufacture;

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model)
		{
			cars[i].yearOfManufacture = newYearOfManufacture;
			std::cout << "\nYear of manufacture updated.";
			updatedsss = true;
		}
	}
	if (!updatedsss)
	{
		std::cout << "\nError: Car not found or can not update year of manufacture.";
	}
	updatedsss = false;
}

void editKMTraveled() {
	bool updateda = false;
	std::cout << "\nEDIT KM TRAVELED";
	std::cout << "\nWrite mark for edit KM traveled: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model for edit KM traveled: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	std::cout << "\n\nWrite new KM traveled: ";
	int newKMTraveled;
	std::cin >> newKMTraveled;

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model)
		{
			cars[i].kmTraveled = newKMTraveled;
			std::cout << "\nKM travel updated.";
			updateda = true;
		}
	}

	if (!updateda)
	{
		std::cout << "\nError: Car not found or can not update KM traveled.";
	}
	updateda = false;
}

void editAvailability() {
	bool updatedv = false;
	std::cout << "\nEDIT AVAILABILITY";
	std::cout << "\nWrite mark for edit avilability: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model for edit availability: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	std::cout << "\n\nWrite new availability(y/n)";
	std::string newAvailability;
	std::getline(std::cin >> std::ws, newAvailability);

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model)
		{
			bool newAvailabled = boolAvailabilityRead(newAvailability);
			cars[i].availability = newAvailabled;
			std::cout << "\nAvailability updated.";
			updatedv = true;
		}
	}

	if (!updatedv)
	{
		std::cout << "\nError: Car not found or can not update availability.";
	}
	updatedv = false;
}

void editCarInformation() {
	std::cout << "\n=== Edit car information ===";
	std::cout << "\n1) Edit mark";
	std::cout << "\n2) Edit model";
	std::cout << "\n3) Edit year of manufacture";
	std::cout << "\n4) KM Traveled";
	std::cout << "\n5) Availability";
	std::cout << "\n6) Back";
	std::cout << "\nChoose: ";
	
	int editChoose;
	std::cin >> editChoose;
	switch (editChoose)
	{
	case 1:
		editMark();
		break;

	case 2:
		editModel();
		break;

	case 3:
		editYearOfManufacture();
		break;

	case 4:
		editKMTraveled();
		break;

	case 5:
		editAvailability();
		break;

	case 6:
		break;

	default:
		std::cout << "Write only numbers.";
		editCarInformation();
		break;
	}
}

void removeCar() {
	bool carDelete = false;
	std::cout << "\n=== Remove car";
	std::cout << "\nWrite mark: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].mark == editMarkChoose && cars[i].model == editModelChoose)
		{
			cars.erase(cars.begin() + i);
			carDelete = true;
			std::cout << "\nCar deleted.";
		}
	}
	if (!carDelete)
	{
		std::cout << "\nError: car not deleted or car not found.";
	}
	carDelete = false;
}

void rentCar() {
	bool rentttt = false;
	std::cout << "\n=== Rent car ===";
	std::cout << "\nWrite mark: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);
	
	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model && cars[i].availability == 1)
		{
			rentttt = true;
			cars[i].availability = 0;
			std::cout << "\nCar rented.";
		}
	}
	if (!rentttt)
	{
		std::cout << "\nError: Car not found or car is not available.";
	}
	rentttt = false;
}

void returnCar() {
	std::cout << "\n=== Return car ===";
	bool rentttt = false;
	std::cout << "\nWrite mark: ";
	std::string editMarkChoose;
	std::getline(std::cin >> std::ws, editMarkChoose);

	std::cout << "\nWrite model: ";
	std::string editModelChoose;
	std::getline(std::cin >> std::ws, editModelChoose);

	for (int i = 0; i < cars.size(); i++)
	{
		if (editMarkChoose == cars[i].mark && editModelChoose == cars[i].model && cars[i].availability == 0)
		{
			rentttt = true;
			cars[i].availability = 1;
			std::cout << "\nCar returned.";
		}
	}
	if (!rentttt)
	{
		std::cout << "\nError: Car not found or car is available.";
	}
	rentttt = false;
}

void filterOnlyAvailableCar() {
	std::cout << "\n== Only available cars ===";
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].availability == 1)
		{
			std::cout << "\nMark: " << cars[i].mark;
			std::cout << "\nModel: " << cars[i].model;
			std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
			std::cout << "\nKM traveled: " << cars[i].kmTraveled;
			stringAvailability(cars[i].availability);
		}
	}
}

void filterOnlyLendedCar() {
	std::cout << "\n== Only lended cars ==";
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].availability == 0)
		{
			std::cout << "\nMark: " << cars[i].mark;
			std::cout << "\nModel: " << cars[i].model;
			std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
			std::cout << "\nKM traveled: " << cars[i].kmTraveled;
			stringAvailability(cars[i].availability);
		}
	}
}

void madeAfter2020() {
	std::cout << "\n== Made after 2020 ==";
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].yearOfManufacture > 2020)
		{
			std::cout << "\nMark: " << cars[i].mark;
			std::cout << "\nModel: " << cars[i].model;
			std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
			std::cout << "\nKM traveled: " << cars[i].kmTraveled;
			stringAvailability(cars[i].availability);
		}
	}
}

void traveledLessThan100000KM() {
	std::cout << "\n== Traveled less than 100 000 KM";
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].kmTraveled < 100000)
		{
			std::cout << "\nMark: " << cars[i].mark;
			std::cout << "\nModel: " << cars[i].model;
			std::cout << "\nYear of manufacture: " << cars[i].yearOfManufacture;
			std::cout << "\nKM traveled: " << cars[i].kmTraveled;
			stringAvailability(cars[i].availability);
		}
	}
}

void filterrr() {
	std::cout << "\n=== Filter ===";
	std::cout << "\n1) Only available cars";
	std::cout << "\n2) Only lended cars";
	std::cout << "\n3) Made after 2020";
	std::cout << "\n4) Traveled less than 100 000 km";
	std::cout << "\n5) Back";
	std::cout << "\nChoose: ";

	int choooooooser;
	std::cin >> choooooooser;
	switch (choooooooser)
	{
	case 1:
		filterOnlyAvailableCar();
		break;

	case 2:
		filterOnlyLendedCar();
		break;

	case 3:
		madeAfter2020();
		break;

	case 4:
		traveledLessThan100000KM();
		break;

	case 5:
		break;

	default:
		std::cout << "\nWrite only numbers.";
		filterrr();
		break;
	}
}

void statistics() {
	std::cout << "\n=== Statistics ===";
	int numberCarsInt = cars.size();
	std::cout << "\nNumber of cars: " << numberCarsInt;
	int dostupnej = 0;
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].availability == 1)
		{
			dostupnej++;
		}
	}
	std::cout << "\nNumber of available cars: " << dostupnej;

	int nedostupnej = 0;
	for (int i = 0; i < cars.size(); i++)
	{
		if (cars[i].availability == 0)
		{
			nedostupnej++;
		}
	}
	std::cout << "\nNumber of unavailable cars: " << nedostupnej;

	int dateOfManufactureAll = 0;
	for (int i = 0; i < cars.size(); i++)
	{
		dateOfManufactureAll = dateOfManufactureAll + cars[i].yearOfManufacture;
	}
	float completedttt = dateOfManufactureAll / numberCarsInt;
	std::cout << "\nAverage of year of manufacture: " << completedttt;

	for (int i = 0; i < cars.size(); i++)
	{
		std::sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.yearOfManufacture < b.yearOfManufacture;
			});
	}
	
	std::cout << "\nOldest car: " << cars[0].mark << ", " << cars[0].model;
	int newer = numberCarsInt - 1;
	std::cout << "\nLatest car: " << cars[newer].mark << ", " << cars[newer].model;

	for (int i = 0; i < cars.size(); i++)
	{
		std::sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.mark < b.mark;
			});
	}
}

void carSort() {
	std::cout << "\n=== Car sort ===";
	std::cout << "\n1) By brand";
	std::cout << "\n2) Back";
	std::cout << "\nChoose: ";
	int sortChoose;
	std::cin >> sortChoose;
	switch (sortChoose)
	{
	case 1:
		std::sort(cars.begin(), cars.end(), [](const car& a, const car& b) {
			return a.mark < b.mark;
			});
		std::cout << "\nList sorted.";
		break;

	case 2:
		break;

	default:
		std::cout << "\nWrite only numbers.";
		carSort();
		break;
	}

}

void addTestData() {
	car caro;
	caro.mark = "a";
	caro.model = "b";
	caro.yearOfManufacture = 2021;
	caro.kmTraveled = 25000;
	caro.availability = true;

	cars.push_back(caro);
	std::cout << "\nCar added.";
}

int main()
{
	while (runtime)
	{
		std::cout << "\n==== CAR RENTAL ====";
		std::cout << "\n1) Add car";
		std::cout << "\n2) Show all cars";
		std::cout << "\n3) Search car";
		std::cout << "\n4) Edit car information";
		std::cout << "\n5) Remove car";
		std::cout << "\n6) Rent car";
		std::cout << "\n7) Return car";
		std::cout << "\n8) Filter";
		std::cout << "\n9) Statistics";
		std::cout << "\n10) Sort";
		std::cout << "\n11) Add test data";
		std::cout << "\n12) Terminate program";
		std::cout << "\nChoose: ";
		int choose;
		std::cin >> choose;
		switch (choose)
		{
		case 1:
			addCar();
			break;

		case 2:
			showAllCars();
			break;

		case 3:
			searchCar();
			break;

		case 4:
			editCarInformation();
			break;

		case 5:
			removeCar();
			break;

		case 6: 
			rentCar();
			break;

		case 7:
			returnCar();
			break;

		case 8:
			filterrr();
			break;

		case 9:
			statistics();
			break;

		case 10:
			carSort();
			break;

		case 11:
			addTestData();
			break;

		case 12:
			std::cout << "\nProgram terminated.";
			runtime = false;
			break;

		default:
			std::cout << "\nWrite only numbers!";
			break;
		}
	}
}