#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <print>//C++ 23

using std::print;
using std::println;

class Rack
{
public:
	std::string mark;
	int numberOfServer;
	int consumption;
	bool active;

	Rack()
	{
		mark = "";
		numberOfServer = 0;
		consumption = 0;
		active = false;
	}

	Rack(std::string m, int n, int c, bool a)
	{
		mark = m;
		numberOfServer = n;
		consumption = c;
		active = a;
	}
};
std::vector<Rack> racks;
bool runnable = true;
const std::string errorNumber = "\nERROR: Write only numbers!";
const std::string fileName = "data.dat";

bool getBoolFromString(std::string unknownBool) {
	bool returned;
	returned = (unknownBool == "y" || unknownBool == "Y");
	return returned;
}

void getStringFromBool(bool isBoolead) {
	if (isBoolead)
	{
		println("Rack is active.");
	}
	else
	{
		println("Rack isn't active.");
	}
}

bool verify(std::string grantedMark) {
	bool error_ = false;
	std::println("Verification input...");
	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == grantedMark)
		{
			error_ = true;
		}
	}

	if (error_)
	{
		std::cerr << "\nOperation canceled, mark is exist.";
		return false;
	}
	println("Operation completed, adding rack...");
	return true;
}

void addRack() {
	std::cout << "\n=== Add rack ===";
	std::cout << "\nRack mark: ";
	std::string newMark;
	std::getline(std::cin >> std::ws, newMark);

	std::cout << "\nNumber of servers: ";
	int newNumber;
	std::cin >> newNumber;

	std::cout << "\nConsumption: ";
	int newConsumption;
	std::cin >> newConsumption;

	std::cout << "\nActive: (y/n)";
	std::string newActive;
	std::getline(std::cin >> std::ws, newActive);
	bool newActive_ = getBoolFromString(newActive);

	if (!verify(newMark)) {
		return;
	} 

	Rack racker(newMark, newNumber, newConsumption, newActive_);
	racks.emplace_back(racker);
	println("Rack {} added.", newMark);
}

void showRacks() {
	println("=== Show racks ===");
	for (int i = 0; i < racks.size(); i++)
	{
		println("{}.", i + 1);
		println("Server mark: {}", racks[i].mark);
		println("Number of servers: {}", racks[i].numberOfServer);
		println("Consumption: {} W", racks[i].consumption);
		getStringFromBool(racks[i].active);
	}
}

std::string editNameChoose;
void editNumberOfServers() {
	println("== Edit number of servers ==");
	print("Number of servers: ");
	int editNumber;
	std::cin >> editNumber;

	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == editNameChoose)
		{
			racks[i].numberOfServer = editNumber;
			println("Number of servers updated to {} in rack {}.", editNumber, racks[i].mark);
		}
	}
}

void editConsumption() {
	println("== Edit consumption ==");
	print("Consumption: ");
	int newConsumption;
	std::cin >> newConsumption;

	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == editNameChoose)
		{
			racks[i].consumption = newConsumption;
			println("Consumption updated to {} W in rack {}.", newConsumption, editNameChoose);
		}
	}
}

void editStatus() {
	println("== Edit active ==");
	print("Active: (y/n)");
	std::string newActive;
	std::getline(std::cin >> std::ws, newActive);
	bool newActivation = getBoolFromString(newActive);

	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == editNameChoose)
		{
			racks[i].active = newActivation;
			println("Active state updated in rack {}.", editNameChoose);
		}
	}
}

void editRackFounded() {
	println("=== Edit rack {} ===", editNameChoose);
	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == editNameChoose)
		{
			println("Mark: {}", editNameChoose);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
			println("-----------------------");
		}
	}

	println("1) Edit number of servers");
	println("2) Edit consumption");
	println("3) Edit active");
	println("4) Back");
	print("Choose: ");
	int chooseEdit;
	std::cin >> chooseEdit;

	switch (chooseEdit)
	{
	case 1:
		editNumberOfServers();
		break;

	case 2:
		editConsumption();
		break;

	case 3:
		editStatus();
		break;

	case 4:
		break;

	default:
		std::cerr << errorNumber;
		editRackFounded();
		break;
	}
}

void editRack() {
	bool existing = false;
	println("=== Edit rack ===");
	print("Write mark for edit: ");
	std::getline(std::cin >> std::ws, editNameChoose);
    
	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == editNameChoose)
		{
			existing = true;
		}
	}
	if (!existing)
	{
		std::cerr << "\nERROR: Server not found!";
		return;
	}
	editRackFounded();
}

void removeRack() {
	std::string getDeleteMark;
	println("=== Remove rack ===");
	print("Write mark for remove: ");
	std::getline(std::cin >> std::ws, getDeleteMark);
	bool exist = false;

	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == getDeleteMark)
		{
			exist = true;
		}
	}
	if (!exist)
	{
		std::cerr << "\nERROR: This mark is not exst.";
		return;
	}

	print("Are you sure for remove {}? Write y or n: ", getDeleteMark);
	std::string confirmRemove;
	std::getline(std::cin >> std::ws, confirmRemove);

	bool confirmRemove_ = getBoolFromString(confirmRemove);
	if (!confirmRemove_)
	{
		println("Remove canceled.");
		return;
	}

	for (int i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == getDeleteMark)
		{
			racks.erase(racks.begin() + i);
			println("Rack removed.");
		}
	}
}

void searchRack() {
	println("=== Search rack ===");
	bool searchRackFounded = false;
	print("Write mark for serch: ");
	std::string markSearch;
	std::getline(std::cin >> std::ws, markSearch);

	for (size_t i = 0; i < racks.size(); i++)
	{
		if (racks[i].mark == markSearch)
		{
			println("\nFounded:");
			println("Mark: {}", racks[i].mark);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
			searchRackFounded = true;
		}
	}
	if (!searchRackFounded)
	{
		std::cerr << "\nERROR: Can't find " << markSearch << " rack.";
	}
}

void filterOnlyActive() {
	println("== Filter only active ==");
	for (size_t i = 0; i < racks.size(); i++)
	{
		if (racks[i].active)
		{
			println("Mark: {}", racks[i].mark);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
		}
	}
}

void filterOnlyInactive() {
	println("== Filter only inactive ==");
	for (size_t i = 0; i < racks.size(); i++)
	{
		if (!racks[i].active)
		{
			println("Mark: {}", racks[i].mark);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
		}
	}
}

void filterConsumptionBiggerThan5000W() {
	println("== Filter consumption bigger than 5 000 W ==");
	for (size_t i = 0; i < racks.size(); i++)
	{
		if (racks[i].consumption > 5000)
		{
			println("Mark: {}", racks[i].mark);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
		}
	}
}

void filterMoreThan20Servers() {
	println("== Filter more than 20 servers ==");
	for (size_t i = 0; i < racks.size(); i++)
	{
		if (racks[i].numberOfServer > 20)
		{
			println("Mark: {}", racks[i].mark);
			println("Number of servers: {}", racks[i].numberOfServer);
			println("Consumption: {} W", racks[i].consumption);
			getStringFromBool(racks[i].active);
		}
	}
}

void filterrrr() {
	println("=== Filter ===");
	println("1) Only active");
	println("2) Only inactive");
	println("3) Consumption bigger than 5 000 W");
	println("4) More than 20 servers");
	print("5) Back\nChoose: ");
	int filterChoose;
	std::cin >> filterChoose;

	switch (filterChoose)
	{
	case 1:
		filterOnlyActive();
		break;

	case 2:
		filterOnlyInactive();
		break;

	case 3:
		filterConsumptionBiggerThan5000W();
		break;

	case 4:
		filterMoreThan20Servers();
		break;

	case 5:
		break;

	default:
		filterrrr();
		std::cerr << errorNumber;
		break;
	}
}

void sortByMark() {
	println("== Sort by mark ==");
	std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
		return a.mark < b.mark;
		});
	println("Sorted.");
}

void sortByConsumption() {
	println("== Sort by consumption ==");
	std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
		return a.consumption < b.consumption;
		});
	println("Sorted.");
}

void sortByNumberOfServers() {
	println("== Sort by number of servers ==");
	std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
		return a.numberOfServer < b.numberOfServer;
		});
	println("Sorted.");
}

void sorter() {
	println("=== Sort ===");
	println("1) By mark");
	println("2) By consumption");
	println("3) By number of servers");
	print("4) Back\nChoose: ");
	int sortChoose;
	std::cin >> sortChoose;

	switch (sortChoose)
	{
	case 1:
		sortByMark();
		break;

	case 2:
		sortByConsumption();
		break;

	case 3:
		sortByNumberOfServers();
		break;

	case 4:
		break;

	default:
		std::cout << errorNumber;
		sorter();
		break;
	}
}

namespace sts {
	int rackActive() {
		int rackActiveOn = 0;
		for (size_t i = 0; i < racks.size(); i++)
		{
			if (racks[i].active)
			{
				rackActiveOn++;
			}
		}
		return rackActiveOn;
	}

	int serverTotalInt() {
		int serverNumber_ = 0;

		for (size_t i = 0; i < racks.size(); i++)
		{
			serverNumber_ = serverNumber_ + racks[i].numberOfServer;
		}
		return serverNumber_;
	}

	int sytemTotalConsumption() {
		int totalConsumption_ = 0;

		for (size_t i = 0; i < racks.size(); i++)
		{
			totalConsumption_ = totalConsumption_ + racks[i].consumption;
		}
		return totalConsumption_;
	}

	float averageConsumption() {
		float averageConsumption = 0;
		int totalRacks = racks.size();
		int totalConsumptionen = sytemTotalConsumption();

		averageConsumption = totalConsumptionen / totalRacks;
		return averageConsumption;
	}

	void biggestConsumptionRack() {
		std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
			return a.consumption > b.consumption;
			});

		std::string biggerConsumptionRack = racks[0].mark;
		println("Biggest consumption rack: {}", biggerConsumptionRack);

		std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
			return a.mark < b.mark;
			});
	}

	void rackWithMostServer() {
		std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
			return a.numberOfServer > b.numberOfServer;
			});

		std::string rackMostServer = racks[0].mark;
		println("Rack with most servers: {}", rackMostServer);

		std::sort(racks.begin(), racks.end(), [](const Rack& a, const Rack& b) {
			return a.mark < b.mark;
			});
	}
}

void statistics() {
	println("=== Statistics ===");
	int rackNumber = racks.size();
	println("Number of racks: {}", rackNumber);

	int rackOnline = sts::rackActive();
	println("Number of active racks: {}", rackOnline);

	int totalNumberOfServers = sts::serverTotalInt();
	println("Total number of servers: {}", totalNumberOfServers);

	int totalConsumptionnn = sts::sytemTotalConsumption();
	println("Total consumption: {} W", totalConsumptionnn);

	int averageConsumptionnn = sts::averageConsumption();
	println("Average consumption: {} W", averageConsumptionnn);

	sts::biggestConsumptionRack();
	sts::rackWithMostServer();
}

void loadData() {
	println("Loading...");
	std::ifstream loader(fileName);
	if (!loader.is_open())
	{
		std::cerr << "\nERROR: Can load file " << fileName;
		loader.close();
		return;
	}

	std::string loadMark;
	int loadNumberServer;
	int loadConsumption;
	bool loadActive;

	while (std::getline(loader, loadMark))
	{
		loader >> loadNumberServer;
		loader >> loadConsumption;
		loader >> loadActive;
		loader.ignore();
		Rack rack(loadMark, loadNumberServer, loadConsumption, loadActive);

		racks.emplace_back(rack);
	}
	loader.close();
	println("Load completed, starting menu...");
}

void saveData() {
	println("Saving...");
	std::ofstream writer(fileName);
	if (!writer.is_open())
	{
		std::cerr << "\nERROR: Can't open file " << fileName;
		writer.close();
		return;
	}

	for (size_t i = 0; i < racks.size(); i++)
	{
		writer << racks[i].mark << "\n";
		writer << racks[i].numberOfServer << "\n";
		writer << racks[i].consumption << "\n";
		writer << racks[i].active << "\n";
	}
	writer.close();
	println("Save completed, terminating program...");

}

int resetDatacenter() {
	racks.clear();
	std::ofstream deleter(fileName);
	if (!deleter.is_open())
	{
		deleter.close();
		std::cerr << "\nCRITICAL ERROR: Terminating program...";
		runnable = false;
		return 0;
	}

	deleter << "";
	deleter.close();
	println("Action reset datacenter completed.");
	return 1;
}

int main()
{
	loadData();
	while (runnable)
	{
		std::cout << "\n==== Datacenter management ====";
		std::cout << "\n1) Add rack";
		std::cout << "\n2) Show racks";
		std::cout << "\n3) Edit rack";
		std::cout << "\n4) Remove rack";
		std::cout << "\n5) Search rack";
		std::cout << "\n6) Filter";
		std::cout << "\n7) Sort";
		std::cout << "\n8) Statistics";
		std::cout << "\n9) Reset datacenter";
		std::cout << "\n10) Terminate\nChoose: ";
		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			addRack();
			break;

		case 2:
			showRacks();
			break;

		case 3:
			editRack();
			break;

		case 4:
			removeRack();
			break;

		case 5:
			searchRack();
			break;

		case 6:
			filterrrr();
			break;

		case 7:
			sorter();
			break;

		case 8:
			statistics();
			break;

		case 9:
			if (!resetDatacenter())
			{
				return 0;
			}
			break;

		case 10:
			saveData();
			std::cout << "\nProgram terminated.";
			runnable = false;
			return 0;
		default:
			std::cerr << errorNumber;
			break;
		}
	}
}