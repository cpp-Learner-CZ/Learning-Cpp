#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include<algorithm>

struct Task
{
	std::string name;
	int priority = 0;
	bool completed = false;
};
std::vector<Task> tasks;
bool runtime = true;
const std::string fileName = "cache.task";

bool getBooleanFromString(std::string booleaned) {
	bool boolear = (booleaned == "y" || booleaned == "Y"); 
	return boolear;
}

void getStringFromBoolean(bool baloun) {
	if (baloun)
	{
		std::cout << "\nCompleted.";
	}
	else {
		std::cout << "\nUncompleted.";
	}
}

bool truePriority(int priorit) {//je to opravdu v 1-5?
	if (!(priorit <= 5 && priorit !=0))
	{
		return false;
	}
	return true;
}

void addTask() {
	Task taskWrite;
	std::cout << "\n=== Add task ===";
	std::cout << "\nName: ";
	std::string readName;
	std::getline(std::cin >> std::ws, readName);

	std::cout << "\nPriority: (1-5)";
	int readPriority;
	std::cin >> readPriority;

	std::cout << "\nCompleted: (y/n)";
	std::string readCompleted;
	std::getline(std::cin >> std::ws, readCompleted);

	if (!truePriority(readPriority))
	{
		std::cerr << "\nError: Priority error.";
		return;
	}
	taskWrite.name = readName;
	taskWrite.priority = readPriority;
	taskWrite.completed = getBooleanFromString(readCompleted);

	tasks.push_back(taskWrite);
	std::cout << "\nTask added.\n\n";
}

void showTasks() {
	std::cout << "\n=== Show tasks ===";

	for (int i = 0; i < tasks.size(); i++)
	{
		std::cout << "\nName: " << tasks[i].name;
		std::cout << "\nPriority: " << tasks[i].priority;
		getStringFromBoolean(tasks[i].completed);
	}
}

void markAsCompleted() {
	bool exist = false;
	std::cout << "\n=== Mark as completed ===";
	std::cout << "\nName: ";
	std::string nameMark;
	std::getline(std::cin >> std::ws, nameMark);
	for (int i = 0; i < tasks.size(); i++)
	{
		if (nameMark == tasks[i].name)
		{
			exist = true;
		}
	}

	if (!exist)
	{
		std::cerr << "\nError: This name isn't existing.\n\n";
		return;
	}
	for (int i = 0; i < tasks.size(); i++)
	{
		if (nameMark == tasks[i].name)
		{
			tasks[i].completed = true;
			exist = false;
			std::cout << "\nTask " << tasks[i].name << " marked as complete.\n\n";
		}
	}
}

void removeTask() {
	bool completeddd = false;
	std::cout << "\n=== Remove task ===";
	std::cout << "\nName: ";
	std::string deleteName;
	std::getline(std::cin >> std::ws, deleteName);
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].name == deleteName)
		{
			completeddd = true;
			tasks.erase(tasks.begin() + i);
			std::cout << "\nTask removed.\n\n";
		}
	}
	
	if (!completeddd)
	{
		std::cerr << "\nError: This name isn't existing.\n\n";
		return;
	}
}

void filterOnlyCompleted() {
	std::cout << "\n== Only completed filter ==";
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].completed)
		{
			std::cout << "\nName: " << tasks[i].name;
			std::cout << "\nPriority: " << tasks[i].priority;
		}
	}
}

void filterOnlyUncompleted() {
	std::cout << "\n== Only uncompleted filter ==";
	for (int i = 0; i < tasks.size(); i++)
	{
		if (!tasks[i].completed)
		{
			std::cout << "\nName: " << tasks[i].name;
			std::cout << "\nPriority: " << tasks[i].priority;
		}
	}
}

void filterPriority12() {
	std::cout << "\n== Priority 1-2 filter ==";
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].priority == 1 || tasks[i].priority == 2)
		{
			std::cout << "\nName: " << tasks[i].name;
			getStringFromBoolean(tasks[i].completed);
		}
	}
}

void filterPriority45() {
	std::cout << "\n== Priority 4-5 filter ==";
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].priority == 4 || tasks[i].priority == 5)
		{
			std::cout << "\nName: " << tasks[i].name;
			getStringFromBoolean(tasks[i].completed);
		}
	}
}

void filterr() {
	std::cout << "\n=== Filter ===";
	std::cout << "\n1) Only completed";
	std::cout << "\n2) Only uncompleted";
	std::cout << "\n3) Priority 1-2";
	std::cout << "\n4) Priority 4-5";
	std::cout << "\n5) Back";
	std::cout << "\nChoose: ";
	int chooseFilter;
	std::cin >> chooseFilter;

	switch (chooseFilter)
	{
	case 1:
		filterOnlyCompleted();
		break;

	case 2:
		filterOnlyUncompleted();
		break;

	case 3:
		filterPriority12();
		break;

	case 4:
		filterPriority45();
		break;

	case 5:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		filterr();
		break;
	}
}

void sortByName() {
	std::cout << "\n== Sort by name ==";
	std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
		return a.name < b.name;
		});
	std::cout << "\nSorted by name.";
}

void sortByPriority() {
	std::cout << "\n== Sort by priority ==";
	std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
		return a.priority < b.priority;
		});
	std::cout << "\nSorted by priority.";
}

void sortByCompleted() {
	std::cout << "\n== Sort by completed ==";
	std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
		return a.completed < b.completed;
		});
	std::cout << "\nSorted by completed.";
}

void sorter() {
	std::cout << "\n=== Sort ===";
	std::cout << "\n1) By name";
	std::cout << "\n2) By priority";
	std::cout << "\n3) By completed";
	std::cout << "\n4) Back";
	std::cout << "\nChoose: ";
	int chooseSort;
	std::cin >> chooseSort;
	switch (chooseSort)
	{
	case 1:
		sortByName();
		break;

	case 2:
		sortByPriority();
		break;

	case 3:
		sortByCompleted();
		break;

	case 4:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		sorter();
		break;
	}
}

void saveData() {
	std::cout << "\nSaving...";
	std::ofstream writer(fileName);

	if (!writer.is_open())
	{
		std::cerr << "\nError: Can't open file " << fileName << "\n";
		writer.close();
		return;
	}
	for (int i = 0; i < tasks.size(); i++)
	{
		writer << tasks[i].name << "\n";
		writer << tasks[i].priority << "\n";
		writer << tasks[i].completed << "\n";
	}
	writer.close();
	std::cout << "\nSave completed, terminating program...";
}

void loadData() {
	Task taskRead;
	std::cout << "\nLoading...";
	std::ifstream loader(fileName);

	if (!loader.is_open())
	{
		std::cerr << "\nError: Can't load file " << fileName << "\n";
		loader.close();
		return;
	}
	
	while (std::getline(loader, taskRead.name))
	{
		
		loader >> taskRead.priority;
		loader >> taskRead.completed;
		loader.ignore();

		tasks.push_back(taskRead);
	}
	loader.close();
	std::cout << "\nLoad completed, opening menu...";
}

void statistics() {
	std::cout << "\n=== Statistics ===";
	int sizeTask = tasks.size();
	std::cout << "\nNumber of tasks: " << sizeTask;

	int completedTaskNumber = 0;
	for (int i = 0; i < tasks.size(); i++)
	{
		if (tasks[i].completed)
		{
			completedTaskNumber = completedTaskNumber + 1;
		}
	}
	std::cout << "\nNumber of completed: " << completedTaskNumber;

	int uncompletedTaskNumber = 0;
	for (int i = 0; i < tasks.size(); i++)
	{
		if (!tasks[i].completed)
		{
			uncompletedTaskNumber = uncompletedTaskNumber + 1;
		}
	}
	std::cout << "\nNumber of uncompleted: " << uncompletedTaskNumber;

	int diameterGet = 0;
	for (int i = 0; i < tasks.size(); i++)
	{
		diameterGet = diameterGet + tasks[i].priority;
	}
	float priorityDiameter = 0;
	priorityDiameter = diameterGet / sizeTask;
	std::cout << "\nPriority diameter: " << priorityDiameter;
}

int main()
{
	loadData();
	while (runtime)
	{
		std::cout << "\n\n==== Registr tasks ====";
		std::cout << "\n1) Add task";
		std::cout << "\n2) Show tasks";
		std::cout << "\n3) Mark as completed";
		std::cout << "\n4) Remove task";
		std::cout << "\n5) Filter";
		std::cout << "\n6) Sort";
		std::cout << "\n7) Statistics";
		std::cout << "\n8) Terminate";
		std::cout << "\nChoose: ";
		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			addTask();
			break;

		case 2:
			showTasks();
			break;

		case 3:
			markAsCompleted();
			break;

		case 4:
			removeTask();
			break;

		case 5:
			filterr();
			break;

		case 6:
			sorter();
			break;

		case 7:
			statistics();
			break;

		case 8:
			saveData();
			std::cout << "\nProgram was terminated.";
			runtime = false;
			break;

		default:
			std::cerr << "\nError: Write only numbers.";
			break;
		}
	}
}