#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class Server
{
public:
	std::string name;
	std::string ip;
	int ram;
	bool online;

	Server(std::string n, std::string i, int r, bool o) {
		name = n;
		ip = i;
		ram = r;
		online = o;
	}
};
std::vector<Server> servers;
const std::string serverFile = "data.server";
bool runtime = true;

bool getBooleanFromString(std::string boolead) {
	bool booled;
	booled = (boolead == "Y" || boolead == "y");
	return booled;
}

void getStringFromBoolean(bool booleaded) {
	if (booleaded)
	{
		std::cout << "\nServer is online\n";
	}
	else
	{
		std::cout << "\nServer is offline\n";
	}
}

void addServer() {
	std::cout << "\n=== Add server ===";
	std::cout << "\nServer name: ";
	std::string newName;
	std::getline(std::cin >> std::ws, newName);

	std::cout << "\nServer IP address: ";
	std::string newIPAddress;
	std::getline(std::cin >> std::ws, newIPAddress);

	std::cout << "\nServer RAM: ";
	int newRAM;
	std::cin >> newRAM;

	std::cout << "\nServer online: (y/n)";
	std::string newStatus;
	std::getline(std::cin >> std::ws, newStatus);
	bool newOnline = getBooleanFromString(newStatus);

	Server Server(newName, newIPAddress, newRAM, newOnline);

	servers.emplace_back(Server);
	std::cout << "\nServer added.";
}

void showServers() {
	std::cout << "\n=== Show server ===";
	int sizeServer = servers.size();
	if (sizeServer == 0)
	{
		std::cerr << "\nError: No server exits.";
		return;
	}

	for (int i = 0; i < servers.size(); i++)
	{
		std::cout << "\nServer name: " << servers[i].name;
		std::cout << "\nServer IP address: " << servers[i].ip;
		std::cout << "\nServer RAM: " << servers[i].ram;
		getStringFromBoolean(servers[i].online);
	}
}

std::string editSearchName;

void editName() {
	std::cout << "\n=== Edit name ===";
	std::cout << "\nNew name: ";
	std::string newNameDDD;
	std::getline(std::cin >> std::ws, newNameDDD);

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == editSearchName)
		{
			servers[i].name = newNameDDD;
			std::cout << "\nName updated.";
		}
	}
}

void editIP() {
	std::cout << "\n=== Edit IP address ===";
	std::cout << "\nNew IP address: ";
	std::string newIPAddressDDD;
	std::getline(std::cin >> std::ws, newIPAddressDDD);

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == editSearchName)
		{
			servers[i].ip = newIPAddressDDD;
			std::cout << "\nIP address updated.";
		}
	}
}

void editRAM() {
	std::cout << "\n=== Edit RAM ===";
	std::cout << "\nNew RAM: ";
	int newRAMDDDD;
	std::cin >> newRAMDDDD;

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == editSearchName)
		{
			servers[i].ram = newRAMDDDD;
			std::cout << "\nRAM updated.";
		}
	}
}

void editStatus() {
	std::cout << "\n=== Edit Online/Offline ===";
	std::cout << "\nEdit online/offline: write y or n: ";
	std::string newStatusValueInString;
	std::getline(std::cin >> std::ws, newStatusValueInString);
	bool newStatusValue = getBooleanFromString(newStatusValueInString);

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == editSearchName)
		{
			servers[i].online = newStatusValue;
			std::cout << "\nState of Online/Offline updated.";
		}
	}
}

void editServer() {
	bool existEdit = false;
	std::cout << "\n=== Edit server ===";
	std::cout << "\nEdit server(write name): ";
	std::getline(std::cin >> std::ws, editSearchName);

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == editSearchName)
		{
			existEdit = true;
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
		}
	}
	if (!existEdit)
	{
		std::cerr << "\nError: Server " << editSearchName << " not found.";
		return;
	}

	std::cout << "\n=== Edit menu ===";
	std::cout << "\n1) Name";
	std::cout << "\n2) IP address";
	std::cout << "\n3) RAM";
	std::cout << "\n4) Online/Offline";
	std::cout << "\n5) Back";
	std::cout << "\nChoose: ";
	int editChoose;
	std::cin >> editChoose;

	switch (editChoose)
	{
	case 1:
		editName();
		break;

	case 2:
		editIP();
		break;

	case 3:
		editRAM();
		break;

	case 4:
		editStatus();
		break;

	case 5:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		editServer();
		break;
	}
}

void removeServer() {
	bool removed = false;
	std::cout << "\n=== Remove server ===";
	std::cout << "\nWrite name for remove: ";
	std::string removeName;
	std::getline(std::cin >> std::ws, removeName);

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == removeName)
		{
			servers.erase(servers.begin() + i);
			removed = true;
			std::cout << "\nServer removed.";
		}
	}

	if (!removed)
	{
		std::cerr << "\nError: Can't remove server.";
	}
}

void searchServer() {
	std::cout << "\n=== Search server ===";
	std::cout << "\nSearch name: ";
	std::string searchName;
	std::getline(std::cin >> std::ws, searchName);
	bool founded = false;

	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].name == searchName)
		{
			std::cout << "\nServer found!\n-------------";
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
			founded = true;
		}
	}

	if (!founded)
	{
		std::cerr << "\nError: Server not found.";
	}
}

void filterOnline() {
	std::cout << "\n== Filter online ==";
	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].online)
		{
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
		}
	}
}

void filterOffline() {
	std::cout << "\n== Filter offline ==";
	for (int i = 0; i < servers.size(); i++)
	{
		if (!servers[i].online)
		{
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
		}
	}
}

void filterRAM32() {
	std::cout << "\n== Filter RAM bigger than 32 GB ==";
	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].ram > 32)
		{
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
		}
	}
}

void filterRAM16GB() {
	std::cout << "\n== Filter RAM less than 16 GB ==";
	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].ram < 16)
		{
			std::cout << "\nServer name: " << servers[i].name;
			std::cout << "\nServer IP address: " << servers[i].ip;
			std::cout << "\nServer RAM: " << servers[i].ram;
			getStringFromBoolean(servers[i].online);
		}
	}
}

void filterrr() {
	std::cout << "\n=== Filter ===";
	std::cout << "\n1) Only online";
	std::cout << "\n2) Only offline";
	std::cout << "\n3) RAM bigger than 32 GB";
	std::cout << "\n4) RAM less than 16 GB";
	std::cout << "\n5) Back";
	std::cout << "\nChoose: ";
	int choooooooose;
	std::cin >> choooooooose;

	switch (choooooooose)
	{
	case 1:
		filterOnline();
		break;

	case 2:
		filterOffline();
		break;

	case 3:
		filterRAM32();
		break;

	case 4:
		filterRAM16GB();
		break;

	case 5:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		filterrr();
		break;
	}
}

void sortName() {
	std::cout << "\n== Sort by name ==";
	std::sort(servers.begin(), servers.end(), [](const Server& a, const Server& b) {
		return a.name < b.name;
		});
	std::cout << "\nSorted.";
}

void sortRAM() {
	std::cout << "\n== Sort by RAM ==";
	std::sort(servers.begin(), servers.end(), [](const Server& a, const Server& b) {
		return a.ram < b.ram;
		});
	std::cout << "\nSorted.";
}

void sortIP() {
	std::cout << "\n== Sort by IP address ==";
	std::sort(servers.begin(), servers.end(), [](const Server& a, const Server& b) {
		return a.ip < b.ip;
		});
	std::cout << "\nSorted.";
}

void sorter() {
	std::cout << "\n=== Sort ===";
	std::cout << "\n1) By name";
	std::cout << "\n2) By RAM";
	std::cout << "\n3) By IP address";
	std::cout << "\n4) Back\nChoose: ";
	int chooseSort;
	std::cin >> chooseSort;

	switch (chooseSort)
	{
	case 1:
		sortName();
		break;

	case 2:
		sortRAM();
		break;

	case 3:
		sortIP();
		break;

	case 4:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		sorter();
		break;
	}
}

void statistics() {
	std::cout << "\n=== Statistics ===";
	int serverSize = servers.size();
	std::cout << "\nNumber of servers: " << serverSize;

	int online = 0;
	for (int i = 0; i < servers.size(); i++)
	{
		if (servers[i].online)
		{
			online++;
		}
	}
	std::cout << "\nOnline servers: " << online;
	int offline = serverSize - online;
	std::cout << "\nOffline servers: " << offline;

	int counter = 0;
	for (int i = 0; i < servers.size(); i++)
	{
		counter = counter + servers[i].ram;
	}
	float average = counter / serverSize;
	std::cout << "\nAverage RAM: " << average;
}

void loadData() {
	std::cout << "\nLoading...";
	std::ifstream loader(serverFile);
	if (!loader.is_open())
	{
		std::cerr << "\nError: Can't load file " << serverFile;
		loader.close();
		return;
	}

	std::string instanceLoadName;
	std::string instanceLoadIP;
	int instanceLoadRAM;
	bool instanceLoadOnline;

	while (std::getline(loader, instanceLoadName))
	{
		std::getline(loader, instanceLoadIP);
		loader >> instanceLoadRAM;
		loader >> instanceLoadOnline;
		loader.ignore();

		Server Server(instanceLoadName, instanceLoadIP, instanceLoadRAM, instanceLoadOnline);

		servers.emplace_back(Server);
	}
	loader.close();
	std::cout << "\nLoad completed, menu loaded.";
}

void saveData() {
	std::cout << "\nSaving...";
	std::ofstream writer(serverFile);
	if (!writer.is_open())
	{
		std::cerr << "\nError: Can't write to file " << serverFile;
		writer.close();
		return;
	}

	for (int i = 0; i < servers.size(); i++)
	{
		writer << servers[i].name << "\n";
		writer << servers[i].ip << "\n";
		writer << servers[i].ram << "\n";
		writer << servers[i].online << "\n";
	}
	writer.close();
	std::cout << "\nSave completed, terminating program...";
}

int main()
{
	loadData();
	while (runtime)
	{
		std::cout << "\n\n==== Server management ====";
		std::cout << "\n1) Add server";
		std::cout << "\n2) Show servers";
		std::cout << "\n3) Edit server";
		std::cout << "\n4) Remove server";
		std::cout << "\n5) Search server";
		std::cout << "\n6) Filter";
		std::cout << "\n7) Sort";
		std::cout << "\n8) Statistics";
		std::cout << "\n9) Terminate program";
		std::cout << "\nChoose: ";
		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			addServer();
			break;

		case 2:
			showServers();
			break;

		case 3: 
			editServer();
			break;

		case 4:
			removeServer();
			break;

		case 5:
			searchServer();
			break;

		case 6:
			filterrr();
			break;

		case 7:
			sorter();
			break;

		case 8:
			statistics();
			break;

		case 9:
			runtime = false;
			saveData();
			std::cout << "\nProgram terminated.";
			return 0;

		default:
			std::cerr << "\nError: Write only numbers.";
			break;
		}
	}
}