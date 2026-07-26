#include <iostream>
#include <string>
#include <print>
#include <vector>
#include <algorithm>
#include <fstream>

namespace error {
	std::string errNumber = "ERROR: Write only numbers!";
}

class Device {
public:
	std::string name;
	std::string ipAddress;
	std::string type;
	int portCount;
	bool online;

	Device(std::string n, std::string i, std::string t, int p, bool o) {
		name = n;
		ipAddress = i;
		type = t;
		portCount = p;
		online = o;
	};
};
bool runtime = true;
std::vector<Device> devices;
const std::string fileName = "data.dat";

namespace verify {
	bool verifyName(std::string enterName) {
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == enterName)
			{
				return false;
			}
		}
		return true;
	}

	bool verifyIP(std::string duplicative) {
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].ipAddress == duplicative)
			{
				return false;
			}
		}
		return true;
	}

	bool existWithBool(std::string nameBooled) {
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == nameBooled)
			{
				return true;
			}
		}
		return false;
	}
}

bool getBoolFromString(std::string boolEnter) {
	bool boolExit;
	boolExit = (boolEnter == "y" || boolEnter == "Y");
	return boolExit;
}
void getStringFromBool(bool getBool) {
	if (getBool)
	{
		std::println("Device is online.");
	}
	else
	{
		std::println("Device is offline.");
	}
}

void addDevice() {
	std::println("=== Add device ===");
	std::print("Device name: ");
	std::string newName;
	std::getline(std::cin >> std::ws, newName);

	std::print("Device IP address: ");
	std::string newIPAddress;
	std::getline(std::cin >> std::ws, newIPAddress);

	std::print("Device type: ");
	std::string newType;
	std::getline(std::cin >> std::ws, newType);

	std::print("Device port count: ");
	int newPortCount;
	std::cin >> newPortCount;

	std::print("Device online: (y/n)");
	std::string newOnlineOffline;
	std::getline(std::cin >> std::ws, newOnlineOffline);
	bool newStatusDevice = getBoolFromString(newOnlineOffline);

	if (!verify::verifyName(newName))
	{
		std::cerr << "\nERROR: Name is duplicative.";
		return;
	}

	if (!verify::verifyIP(newIPAddress))
	{
		std::cerr << "\nERROR: IP is duplicative.";
		return;
	}
	devices.emplace_back(newName, newIPAddress, newType, newPortCount, newStatusDevice);
	std::println("Network device added.");
}

void showDevices() {
	std::println("=== Show devices ===");
	for (size_t i = 0; i < devices.size(); i++)
	{
		std::println("Device name: {}", devices[i].name);
		std::println("Device IP address: {}", devices[i].ipAddress);
		std::println("Device type: {}", devices[i].type);
		std::println("Device port: {}", devices[i].portCount);
		getStringFromBool(devices[i].online);
	}
}

namespace edit {
	std::string chooseName;

	void updateType() {
		std::println("== Edit type ==");
		std::print("Update type: ");
		std::string newType;
		std::getline(std::cin >> std::ws, newType);

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == chooseName)
			{
				std::println("Type updated from {} to {}", devices[i].type, newType);
				devices[i].type = newType;
				return;
			}
		}
	}

	void updatePorts() {
		std::println("== Edit port count ==");
		std::print("Update port count: ");
		int newCount;
		std::cin >> newCount;

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == chooseName)
			{
				std::println("Port count updated from {} to {}", devices[i].portCount, newCount);
				devices[i].portCount = newCount;
				return;
			}
		}

	}

	void updateStatus() {
		std::println("== Edit status(online/offline) ==");
		std::print("Update status: (y/n)");
		std::string newStatus;
		std::getline(std::cin >> std::ws, newStatus);
		bool newStatus_ = getBoolFromString(newStatus);

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == chooseName)
			{
				getStringFromBool(newStatus_); std::println("Old UI Version...");
				devices[i].online = newStatus_;
				return;
			}
		}
	}

	void lobby() {
		std::println("=== Edit device {} ===", chooseName);
		std::println("1) Type");
		std::println("2) Port count");
		std::println("3) Status: (online/offline)");
		std::print("4) Back\nChoose: ");
		int chooseEdit;
		std::cin >> chooseEdit;

		switch (chooseEdit)
		{
		case 1:
			updateType();
			break;

		case 2:
			updatePorts();
			break;

		case 3:
			updateStatus();
			break;

		case 4:
			break;

		default:
			std::cerr << error::errNumber;
			lobby();
			break;
		}
	}

	void main() {
		std::println("=== Edit device ===");
		std::print("Name: ");
		std::getline(std::cin >> std::ws, chooseName);

		if (verify::verifyName(chooseName))
		{
			std::cerr << "ERROR: This name isn't exist!";
			return;
		}
		lobby();
	}
}
namespace removes {
	std::string remover;

	void mainRemover() {
		std::println("Removing {}...", remover);
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == remover)
			{
				devices.erase(devices.begin() + i);
				std::println("Device {} removed.", remover);
			}
		}
	}

	void allowRemover() {
		std::println("\n=== Confirm remove ===");
		std::print("Are you sure for remove {}?\nPlease write y or n: ", remover);
		std::string confirmRemover;
		std::getline(std::cin >> std::ws, confirmRemover);
		bool confirmResult = getBoolFromString(confirmRemover);

		if (!confirmResult)
		{
			std::println("Remove {} canceled.", remover);
			return;
		}
		mainRemover();
	}

	void enterRemove() {
		std::println("=== Remove network device ===");
		std::print("Remove device name: ");
		std::getline(std::cin >> std::ws, remover);

		if (!verify::existWithBool(remover))
		{
			std::cerr << "\nERROR: Device " << remover << " not found!";
			return;
		}
		allowRemover();
	}
}
namespace search {

	void byName() {
		std::println("== Search by name ==");
		std::print("Search name: ");
		std::string seracherName;
		std::getline(std::cin >> std::ws, seracherName);
		bool founded = false;

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].name == seracherName)
			{
				founded = true;
				std::println("---- Device founded ----");
				std::println("Device name: {}", devices[i].name);
				std::println("Device IP address: {}", devices[i].ipAddress);
				std::println("Device type: {}", devices[i].type);
				std::println("Device port count: {}", devices[i].portCount);
				getStringFromBool(devices[i].online);
				std::println("------------------------");
			}
		}
		if (!founded)
		{
			std::cerr << "ERROR: Device " << seracherName << " is not exist!";
		}
	}

	void byIP() {
		std::println("== Search by IP address ==");
		std::print("Search IP address: ");
		std::string searcherIP;
		std::getline(std::cin >> std::ws, searcherIP);
		bool founded = false;

		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].ipAddress == searcherIP)
			{
				founded = true;
				std::println("---- Device founded ----");
				std::println("Device name: {}", devices[i].name);
				std::println("Device IP address: {}", devices[i].ipAddress);
				std::println("Device type: {}", devices[i].type);
				std::println("Device port count: {}", devices[i].portCount);
				getStringFromBool(devices[i].online);
				std::println("------------------------");
			}
		}
		if (!founded)
		{
			std::cerr << "ERROR: Device with IP address " << searcherIP << " is not exist!";
		}
	}

	void lobby() {
		std::println("=== Search device ===");
		std::println("1) By name");
		std::println("2) By IP address");
		std::print("3) Back\nChoose: ");
		int searchChoose;
		std::cin >> searchChoose;

		switch (searchChoose)
		{
		case 1:
			byName();
			break;

		case 2:
			byIP();
			break;

		case 3:
			break;

		default:
			std::cerr << error::errNumber;
			lobby();
			break;
		}
	}
}
namespace filter {
	void onlyOnline() {
		std::println("== Filter only online ==");
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].online)
			{
				std::println("Device name: {}", devices[i].name);
				std::println("Device IP address: {}", devices[i].ipAddress);
				std::println("Device type: {}", devices[i].type);
				std::println("Device port count: {}", devices[i].portCount);
				getStringFromBool(devices[i].online);
				std::println("--------------------------");
			}
		}
	}

	void onlyOffline() {
		std::println("== Filter only offline ==");
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (!devices[i].online)
			{
				std::println("Device name: {}", devices[i].name);
				std::println("Device IP address: {}", devices[i].ipAddress);
				std::println("Device type: {}", devices[i].type);
				std::println("Device port count: {}", devices[i].portCount);
				getStringFromBool(devices[i].online);
				std::println("--------------------------");
			}
		}
	}

	void moreThan24Ports() {
		std::println("== Filter more than 24 ports ==");
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].portCount > 24)
			{
				std::println("Device name: {}", devices[i].name);
				std::println("Device IP address: {}", devices[i].ipAddress);
				std::println("Device type: {}", devices[i].type);
				std::println("Device port count: {}", devices[i].portCount);
				getStringFromBool(devices[i].online);
				std::println("--------------------------");
			}
		}
	}

	void enterF() {
		std::println("=== Filter ===");
		std::println("1) Only online");
		std::println("2) Only ffline");
		std::println("3) More than 24 ports");
		std::print("4) Back\nChoose: ");
		int filterChoose;
		std::cin >> filterChoose;

		switch (filterChoose)
		{
		case 1:
			onlyOnline();
			break;

		case 2:
			onlyOffline();
			break;

		case 3:
			moreThan24Ports();
			break;

		case 4:
			break;

		default:
			std::cerr << error::errNumber;
			enterF();
			break;
		}
	}
}
namespace sorter {
	void byName() {
		std::println("== Sort by name ==");
		std::sort(devices.begin(), devices.end(), [](const Device& a, const Device& b) {
			return a.name < b.name;
			});
		std::println("Sorted.");
	}
	
	void byIP() {
		std::println("== Sort by IP address ==");
		std::sort(devices.begin(), devices.end(), [](const Device& a, const Device& b) {
			return a.ipAddress < b.ipAddress;
			});
		std::println("Sorted.");
	}
	
	void byPortCount() {
		std::println("== Sort by port count ==");
		std::sort(devices.begin(), devices.end(), [](const Device& a, const Device& b) {
			return a.portCount < b.portCount;
			});
		std::println("Sorted.");
	}
	
	void enterS() {
		std::println("\n=== Sort ===");
		std::println("1) By name");
		std::println("2) By IP address");
		std::println("3) By port count");
		std::print("4) Back\nChoose: ");
		int sortChoose;
		std::cin >> sortChoose;

		switch (sortChoose)
		{
		case 1:
			byName();
			break;

		case 2:
			byIP();
			break;

		case 3:
			byPortCount();
			break;

		case 4:
			break;

		default:
			std::cerr << error::errNumber;
			enterS();
			break;
		}
	}
}
namespace statistics {
	int devicesSize;

	void endStatistics() {
		int deviceAverage = 0;
		for (size_t i = 0; i < devices.size(); i++)
		{
			deviceAverage = deviceAverage + devices[i].portCount;
		}
		float deviceAverage_ = deviceAverage / devicesSize;
		std::println("Average count port: {}", deviceAverage_);
		//
		std::sort(devices.begin(), devices.end(), [](const Device& a, const Device& b) {
			return a.portCount > b.portCount;
			});
		std::string deviceMostPorts = devices[0].name;
		std::println("Device with most ports: {}", deviceMostPorts);

		std::sort(devices.begin(), devices.end(), [](const Device& a, const Device& b) {
			return a.name < b.name;
			});
	}

	void onlinOffline() {
		int online_ = 0;
		for (size_t i = 0; i < devices.size(); i++)
		{
			if (devices[i].online)
			{
				online_++;
			}
		}
		std::println("Total count online devices: {}", online_);

		int offline_ = devicesSize - online_;
		std::println("Total count offline devices: {}", offline_);
		endStatistics();
	}

	void devicesSt() {
		devicesSize = devices.size();
		std::println("=== Statistics ===");
		std::println("Total count devices: {}", devicesSize);
		onlinOffline();
	}
}
namespace files {
	void saveData() {
		std::println("Saving data...");
		std::ofstream writer(fileName);
		if (!writer.is_open())
		{
			writer.close();
			std::cerr << "\nERROR: Can't open file " << fileName;
			return;
		}

		for (size_t i = 0; i < devices.size(); i++)
		{
			writer << devices[i].name << "\n";
			writer << devices[i].ipAddress << "\n";
			writer << devices[i].type << "\n";
			writer << devices[i].portCount << "\n";
			writer << devices[i].online << "\n";
		}
		writer.close();
		std::println("Data saved, terminating...");
	}

	void loadData() {
		std::println("Loading data...");
		std::ifstream loader(fileName);
		if (!loader.is_open())
		{
			loader.close();
			std::cerr << "\nERROR: Can't open file " << fileName;
			return;
		}

		std::string name_;
		std::string IPAddress_;
		std::string type_;
		int portCount_;
		bool status_;
		while (std::getline(loader, name_))
		{
			std::getline(loader, IPAddress_);
			std::getline(loader, type_);
			loader >> portCount_;
			loader >> status_;
			loader.ignore();
			
			devices.emplace_back(name_, IPAddress_, type_, portCount_, status_);
		}
		loader.close();
		std::println("Data loaded, starting menu...");
	}
}

int main()
{
	files::loadData();
	while (runtime)
	{
		std::println("\n==== Network davice manager ====");
		std::println("1) Add device");
		std::println("2) Show devices");
		std::println("3) Edit device");
		std::println("4) Remove device");
		std::println("5) Search device");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::print("9) Terminate\nChoose: ");
		int choose;
		std::cin >> choose;
		
		switch (choose)
		{
		case 1:
			addDevice();
			break;

		case 2:
			showDevices();
			break;

		case 3:
			edit::main();
			break;

		case 4:
			removes::enterRemove();
			break;

		case 5:
			search::lobby();
			break;

		case 6:
			filter::enterF();
			break;

		case 7:
			sorter::enterS();
			break;

		case 8:
			statistics::devicesSt();
			break;

		case 9:
			runtime = false;
			files::saveData();
			std::println("Program terminated.");
			break;

		default:
			std::cerr << error::errNumber;
			break;
		}
	}
}