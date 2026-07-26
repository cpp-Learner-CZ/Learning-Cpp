#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

enum class State {
	Running = 1, 
	Stopped = 2,
	Suspended = 3
};
enum class OperatingSystem {
	Windows = 1,
	Linux = 2,
	FreeBSD = 3
};

class VirtualMachine {
public:
	std::string name;
	int ram;
	int cpuCores;
	State state;
	OperatingSystem os;

	VirtualMachine(std::string n, int r, int c, State s, OperatingSystem o) {
		name = n;
		ram = r;
		cpuCores = c;
		state = s;
		os = o;
	};
};
bool runtime = true;
std::vector<VirtualMachine> virtualed;

namespace verify {
	//Exist = true
	bool nameIsExist(std::string exist) {
		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == exist)
			{
				return true;
			}
		}
		return false;
	}

	bool ifCpuDoesnt0(int cores) {
		if (cores != 0)
		{
			return true;
		}
		return false;
	}

	//Get 0 = false, get 4+ = false, 1-3 = true
	bool goodStateInt(int enterIntState) {
		if (enterIntState != 0 && enterIntState <= 3)
		{
			return true;
		}
		return false;
	}

	//Get 0 = false, get 4+ = false, 1-3 = true
	bool goodOSInt(int enterIntOS) {
		if (enterIntOS != 0 && enterIntOS <= 3)
		{
			return true;
		}
		return false;
	}

	
}
namespace enumOperation {
	State setEnumStateFromInt(int setState) {
		switch (setState)
		{
		case 1:
			return State::Running;
			break;

		case 2:
			return State::Stopped;
			break;

		case 3:
			return State::Suspended;
			break;
		}
	}

	OperatingSystem	setEnumOSFromInt(int setOS) {
		switch (setOS)
		{
		case 1:
			return OperatingSystem::Windows;
			break;

		case 2:
			return OperatingSystem::Linux;
			break;

		case 3:
			return OperatingSystem::FreeBSD;
			break;
		}
	}

	std::string getStringFromEnumState(State state_) {
		switch (state_)
		{
		case State::Running:
			return "Running";
			break;
		case State::Stopped:
			return "Stopped";
			break;
		case State::Suspended:
			return "Suspended";
			break;
		}
	}

	std::string getStringFromEnumOS(OperatingSystem os_) {
		switch (os_)
		{	
		case OperatingSystem::Windows:
			return "Windows";
			break;
		case OperatingSystem::Linux:
			return "Linux";
			break;
		case OperatingSystem::FreeBSD:
			return "FreeBSD";
			break;
		}
	}
}
namespace error {
	const std::string wrongNumber = "ERROR: Write only numbers or correct numbers!";
	const std::string nameExist = "ERROR: This name is alredy exist!";
	const std::string nameIsntExist = "ERROR: This name isn't exist!";
	const std::string coreIs0 = "ERROR: Virtual machine musn't have 0 CPUs";
	const std::string unknownInputState = "ERROR: Unknown input in choose a state!";
	const std::string unknownInputOS = "ERROR: Unknown input in choose an OS!";
}
namespace add {
	std::string newName;
	int newRAM;
	int newCPUCores;
	State newState;
	OperatingSystem newOS;

	int chooseState;
	int chooseOS;

	void setEnum() {
		newState = enumOperation::setEnumStateFromInt(chooseState);
		newOS = enumOperation::setEnumOSFromInt(chooseOS);

		virtualed.emplace_back(newName, newRAM, newCPUCores, newState, newOS);
		std::println("Added.");
	}

	void enterOS() {
		std::println("OS VM");
		std::println("1) Windows");
		std::println("2) Linux");
		std::print("3) Free BSD\nChoose: ");
		std::cin >> chooseOS;

		if (!verify::goodOSInt(chooseOS))
		{
			std::cerr << error::unknownInputOS;
			return;
		}
		setEnum();
	}

	void enterState() {
		std::println("State VM");
		std::println("1) Running");
		std::println("2) Stopped");
		std::print("3) Suspnded\nChoose: ");
		std::cin >> chooseState;

		if (!verify::goodStateInt(chooseState))
		{
			std::cerr << error::unknownInputState;
			return;
		}
		enterOS();
	}

	void lobby() {
		std::println("=== Add VM ===");
		std::print("Write VM Name: ");
		std::getline(std::cin >> std::ws, newName);

		std::print("Write number of RAM: ");
		std::cin >> newRAM;

		std::print("Write number of CPU cores: ");
		std::cin >> newCPUCores;

		if (verify::nameIsExist(newName))
		{
			std::cerr << error::nameExist;
			return;
		}
		if (!verify::ifCpuDoesnt0(newCPUCores))
		{
			std::cerr << error::coreIs0;
			return;
		}

		enterState();
	}
}
namespace editor {
	std::string editName;

	void editNameS() {
		std::println("== Edit name ==");
		std::print("Write new name: ");
		std::string newName;
		std::getline(std::cin >> std::ws, newName);
		if (verify::nameIsExist(newName))
		{
			std::cerr << error::nameExist;
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == editName)
			{
				virtualed[i].name = newName;
				std::println("Name updated.");
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error.";
	}

	void editRAM() {
		std::println("== Edit RAM size ==");
		std::print("Write new RAM size: ");
		int newRAM;
		std::cin >> newRAM;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == editName)
			{
				virtualed[i].ram = newRAM;
				std::println("RAM size updated.");
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error.";
	}

	void editCPU() {
		std::println("== Edit CPU cores count ==");
		std::print("Write new CPU cores count: ");
		int newCPUCore;
		std::cin >> newCPUCore;

		if (!verify::ifCpuDoesnt0(newCPUCore))
		{
			std::cerr << error::coreIs0;
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == editName)
			{
				virtualed[i].cpuCores = newCPUCore;
				std::println("CPU cores count updated.");
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error.";
	}

	void editState() {
		std::println("== Edit state");
		std::println("1) Running");
		std::println("2) Stopped");
		std::print("3) Suspnded\nChoose: ");
		int newState;
		std::cin >> newState;

		if (!verify::goodStateInt(newState))
		{
			std::cerr << error::unknownInputState;
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == editName)
			{
				virtualed[i].state = enumOperation::setEnumStateFromInt(newState);
				std::println("State updated.");
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error.";
	}

	void editOS() {
		std::println("== Edit OS ==");
		std::println("1) Windows");
		std::println("2) Linux");
		std::print("3) Free BSD\nChoose: ");
		int newOS;
		std::cin >> newOS;

		if (!verify::goodOSInt(newOS))
		{
			std::cerr << error::unknownInputOS;
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == editName)
			{
				virtualed[i].os = enumOperation::setEnumOSFromInt(newOS);
				std::println("OS updated.");
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error.";
	}
	
	void lobby() {
		std::println("=== Edit VM ===");
		std::print("Write name for edit: ");
		std::getline(std::cin >> std::ws, editName);
		if (!verify::nameIsExist(editName))
		{
			std::cerr << error::nameIsntExist;
			return;
		}

		std::println("=== Edit VM ===");
		std::println("1) Edit name");
		std::println("2) Edit RAM size");
		std::println("3) Edit CPU cores count");
		std::println("4) Edit state");
		std::println("5) Edit OS");
		std::print("6) Back\nChoose: ");
		int editChoose;
		std::cin >> editChoose;

		switch (editChoose)
		{
		case 1:
			editNameS();
			break;

		case 2:
			editRAM();
			break;

		case 3:
			editCPU();
			break;

		case 4:
			editState();
			break;

		case 5:
			editOS();
			break;

		case 6:
			break;

		default:	
			std::cerr << error::wrongNumber;
			lobby();
			break;
		}
	}
}
namespace remover {
	std::string removeName;

	void confirmRemove() {
		std::print("Are you sure for remove {}? Write y or n: ", removeName);
		std::string confirm;
		std::getline(std::cin >> std::ws, confirm);
		bool confirm_ = (confirm == "y" || confirm == "Y");

		if (!confirm_)
		{
			std::println("Remove canceled.");
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].name == removeName)
			{
				virtualed.erase(virtualed.begin() + i);
				std::println("Removed {}.", removeName);
			}
		}
	}

	void lobby() {
		std::println("=== Remove VM ===");
		std::print("Write name VM for remove: ");
		std::getline(std::cin >> std::ws, removeName);

		if (!verify::nameIsExist(removeName))
		{
			std::cerr << error::nameIsntExist;
			return;
		}
		confirmRemove();
	}
}
namespace filter {
	void onlyRun() {
		std::println("== Filter only running ==");

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].state == State::Running)
			{
				std::println("Name: {}", virtualed[i].name);
				std::println("RAM count: {}", virtualed[i].ram);
				std::println("CPU Cores count: {}", virtualed[i].cpuCores);
				std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
				std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
				std::println("----------------------");
			}
		}
	}

	void onlyStop() {
		std::println("== Filter only stopped ==");

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].state == State::Stopped)
			{
				std::println("Name: {}", virtualed[i].name);
				std::println("RAM count: {}", virtualed[i].ram);
				std::println("CPU Cores count: {}", virtualed[i].cpuCores);
				std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
				std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
				std::println("----------------------");
			}
		}
	}

	void onlyLinux() {
		std::println("== Filter only Linux ==");

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].os == OperatingSystem::Linux)
			{
				std::println("Name: {}", virtualed[i].name);
				std::println("RAM count: {}", virtualed[i].ram);
				std::println("CPU Cores count: {}", virtualed[i].cpuCores);
				std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
				std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
				std::println("----------------------");
			}
		}
	}

	void onlyWindows() {
		std::println("== Filter only Windows ==");

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].os == OperatingSystem::Windows)
			{
				std::println("Name: {}", virtualed[i].name);
				std::println("RAM count: {}", virtualed[i].ram);
				std::println("CPU Cores count: {}", virtualed[i].cpuCores);
				std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
				std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
				std::println("----------------------");
			}
		}
	}

	void RAMBigger8GB() {
		std::println("== Filter RAM bigger than 8 GB ==");

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].ram > 8)
			{
				std::println("Name: {}", virtualed[i].name);
				std::println("RAM count: {}", virtualed[i].ram);
				std::println("CPU Cores count: {}", virtualed[i].cpuCores);
				std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
				std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
				std::println("----------------------");
			}
		}
	}

	void lobby() {
		std::println("=== Filter ===");
		std::println("1) Only running");
		std::println("2) Only stopped");
		std::println("3) Only Linux");
		std::println("4) Only Windows");
		std::println("5) RAM bigger than 8 GB");
		std::print("6) Back\nChoose filter: ");
		int chooseFilter;
		std::cin >> chooseFilter;

		switch (chooseFilter)
		{
		case 1:
			onlyRun();
			break;

		case 2:
			onlyStop();
			break;

		case 3:
			onlyLinux();
			break;

		case 4:
			onlyWindows();
			break;

		case 5:
			RAMBigger8GB();
			break;

		case 6:
			break;

		default:
			std::cerr << error::wrongNumber;
			lobby;
			break;
		}
    }
}
namespace sorter {
	void sName() {
		std::sort(virtualed.begin(), virtualed.end(), [](const VirtualMachine& a, const VirtualMachine& b) {
			return a.name < b.name;
			});
	}

	void sRAM() {
		std::sort(virtualed.begin(), virtualed.end(), [](const VirtualMachine& a, const VirtualMachine& b) {
			return a.ram < b.ram;
			});
	}

	void sCountCPU() {
		std::sort(virtualed.begin(), virtualed.end(), [](const VirtualMachine& a, const VirtualMachine& b) {
			return a.cpuCores < b.cpuCores;
			});
	}

	void sState() {
		std::sort(virtualed.begin(), virtualed.end(), [](const VirtualMachine& a, const VirtualMachine& b) {
			return a.state < b.state;
			});
	}

	void lobby() {
		std::println("=== Sort ===");
		std::println("1) By name");
		std::println("2) By RAM");
		std::println("3) By CPU count");
		std::println("4) By state");
		std::print("5) Back\nChoose sort: ");
		int chooseSort;
		std::cin >> chooseSort;

		switch (chooseSort)
		{
		case 1:
			sName();
			std::println("Sorted.");
			break;

		case 2:
			sRAM();
			std::println("Sorted.");
			break;

		case 3:
			sCountCPU();
			std::println("Sorted.");
			break;

		case 4:
			sState();
			std::println("Sorted.");
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber;
			lobby();
			break;
		}
	}
}
namespace statistics {
	int sizeVM;

	int stateRunning() {
		int runVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].state == State::Running)
			{
				runVMCount++;
			}
		}
		return runVMCount;
	}

	int stateStopped() {
		int stopVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].state == State::Stopped)
			{
			     stopVMCount++;
			}
		}
		return stopVMCount;
	}

	int stateSuspended() {
		int suspVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].state == State::Suspended)
			{
				suspVMCount++;
			}
		}
		return suspVMCount;
	}

	int osWindows() {
		int windowsVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].os == OperatingSystem::Windows)
			{
				windowsVMCount++;
			}
		}
		return windowsVMCount;
	}

	int osLinux() {
		int linuxVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].os == OperatingSystem::Linux)
			{
				linuxVMCount++;
			}
		}
		return linuxVMCount;
	}

	int osBSD() {
		int BSDVMCount = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			if (virtualed[i].os == OperatingSystem::FreeBSD)
			{
				BSDVMCount++;
			}
		}
		return BSDVMCount;
	}

	double averageRAM() {
		int sizeRAM = 0;
		
		for (size_t i = 0; i < virtualed.size(); i++)
		{
			sizeRAM = virtualed[i].ram + sizeRAM;
		}
		double averageRAM_ = sizeRAM / sizeVM;
		return averageRAM_;
	}

	double averageCPU() {
		int sizeCPU = 0;

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			sizeCPU = virtualed[i].cpuCores + sizeCPU;
		}
		double averageCPU_ = sizeCPU / sizeVM;
		return averageCPU_;
	}

	void enter() {
		std::println("=== Statistics ===");
		sizeVM = virtualed.size();
		std::println("Total number of VM: {}", sizeVM);
		std::println("Total number of running: {}", stateRunning());
		std::println("Total number of stopped: {}", stateStopped());
		std::println("Total number of suspended: {}", stateSuspended());
		std::println("Total number of Windows OS: {}", osWindows());
		std::println("Total number of Linux OS: {}", osLinux());
		std::println("Total number of FreeBSD OS: {}", osBSD());
		std::println("Average count RAN: {}", averageRAM());
		std::println("Average count CPU: {}", averageCPU());
	}
}
namespace sFileS {
	const std::string sFileName = "VM.dat";

	void saveData() {
		std::println("Saving...");
		std::ofstream writer(sFileName);
		if (!writer.is_open())
		{
			std::cerr << "ERROR: Can't open file!";
			writer.close();
			return;
		}

		for (size_t i = 0; i < virtualed.size(); i++)
		{
			writer << virtualed[i].name << "\n";
			writer << virtualed[i].ram << "\n";
			writer << virtualed[i].cpuCores << "\n";
			State tempState = virtualed[i].state;
			writer << static_cast<int>(tempState) << "\n";

			OperatingSystem tempOS = virtualed[i].os;
			writer << static_cast<int>(tempOS);
		}
		writer.close();
		std::println("Save completed, terminating program...");
	}

	void loadData() {
		std::println("Loading...");
		std::ifstream loader(sFileName);
		if (!loader.is_open())
		{
			std::cerr << "ERROR: Can't open file!";
			loader.close();
			return;
		}

		std::string nameTemp;
		int RAMTemp;
		int CPUTemp;
		State stateTemp;
		OperatingSystem osTemp;

		int stateTemp_;
		int osTemp_;

		while (std::getline(loader, nameTemp))
		{
			loader >> RAMTemp;
			loader >> CPUTemp;
			loader >> stateTemp_;
			loader >> osTemp_;
			loader.ignore();
			stateTemp = static_cast<State>(stateTemp_);
			osTemp = static_cast<OperatingSystem>(osTemp_);

			virtualed.emplace_back(nameTemp, RAMTemp, CPUTemp, stateTemp, osTemp);
		}

		loader.close();
		std::println("Load completed, starting menu...");
	}
}

void showVMs() {
	std::println("=== Show VMs ===");
	for (size_t i = 0; i < virtualed.size(); i++)
	{
		std::println("Name: {}", virtualed[i].name);
		std::println("RAM count: {}", virtualed[i].ram);
		std::println("CPU Cores count: {}", virtualed[i].cpuCores);
		std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
		std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
		std::println("----------------------");
	}
	if (virtualed.size() == 0)
	{
		std::cerr << "ERROR: VMs not found!";
	}
}

void searchVM() {
	std::println("=== Search VM ===");
	std::print("Search name: ");
	std::string searchName;
	std::getline(std::cin >> std::ws, searchName);

	if (!verify::nameIsExist(searchName))
	{
		std::cerr << error::nameIsntExist;
		return;
	}

	for (size_t i = 0; i < virtualed.size(); i++)
	{
		if (virtualed[i].name == searchName)
		{
			std::println("----------------------");
			std::println("Name: {}", virtualed[i].name);
			std::println("RAM count: {}", virtualed[i].ram);
			std::println("CPU Cores count: {}", virtualed[i].cpuCores);
			std::println("State: {}", enumOperation::getStringFromEnumState(virtualed[i].state));
			std::println("OS: {}", enumOperation::getStringFromEnumOS(virtualed[i].os));
			std::println("----------------------");
		}
	}
}

int main()
{
	sFileS::loadData();
	while (runtime)
	{
		std::println("\n==== Virtual machine manager ====");
		std::println("1) Add VM");
		std::println("2) Show VMs");
		std::println("3) Edit VM");
		std::println("4) Remove VM");
		std::println("5) Search VM");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::print("9) Terminate\nChoose: ");
		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			add::lobby();
			break;

		case 2:
			showVMs();
			break;

		case 3:
			editor::lobby();
			break;

		case 4:
			remover::lobby();
			break;

		case 5:
			searchVM();
			break;

		case 6:
			filter::lobby();
			break;

		case 7:
			sorter::lobby();
			break;

		case 8:
			statistics::enter();
			break;

		case 9:
			runtime = false;
			sFileS::saveData();
			std::println("Program terminated.");
			return 0;

		default:
			std::cerr << error::wrongNumber;
			break;
		}
	}
}