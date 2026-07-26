#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct stamps
{
	std::string object;
	int stamp = 0;
};

std::vector<stamps> schoolList;
const std::string FileName = "file.school";

bool chackStamp(int stamper) {
	if (stamper <= 5 && stamper != 0)
	{
		return true;
	}
	return false;
}

void addStamp() {
	stamps stampsReady;
	std::cout << "\n=== Add stamp ===";
	std::cout << "\nWrite subject: ";
	std::getline(std::cin >> std::ws, stampsReady.object);

	std::cout << "\nWrite stamp: ";
	int stampPlacer = 0;
	std::cin >> stampPlacer;
	if (!chackStamp(stampPlacer))
	{
		std::cerr << "\nIncompatible stamp!";
		return;
	}
	stampsReady.stamp = stampPlacer;
	schoolList.push_back(stampsReady);
	
	std::cout << "\nStamp added.";
}

void showStamps() {
	std::cout << "\n=== Show stamps ===";
	for (int i = 0; i < schoolList.size(); i++)
	{
		std::cout << "\n" << i + 1 << ".";
		std::cout << "\n" << schoolList[i].object;
		std::cout << "\n" << schoolList[i].stamp;
	}
}

void sortBySubject() {
	std::sort(schoolList.begin(), schoolList.end(), [](const stamps& a, const stamps& b) {
		return a.object < b.object;
		});

	std::cout << "\nSorted.";
}

void sortByStamp() {
	std::sort(schoolList.begin(), schoolList.end(), [](const stamps& a, const stamps& b) {
		return a.stamp < b.stamp;
		});

	std::cout << "\nSorted.";
}

void sortStamps() {
	std::cout << "\n===Sort stamps ===";
	std::cout << "\n1) By subject";
	std::cout << "\n2) By stamp";
	std::cout << "\n3) Back";
	std::cout << "\nChoose: ";
	int choose;
	std::cin >> choose;

	switch (choose)
	{
	case 1:
		sortBySubject();
		break;

	case 2:
		sortByStamp();
		break;

	case 3:
		break;

	default:
		std::cerr << "\nWrite only numbers.";
		break;
	}
}

void saveToFile() {
	std::ofstream mainSaver(FileName);
	std::cout << "\nPreparing save...";
	if (!mainSaver.is_open())
	{
		std::cerr << "\nError: Can not open file, save canceled.";
		mainSaver.close();
		return;
	}
	for (int i = 0; i < schoolList.size(); i++)
	{
		mainSaver << schoolList[i].object << "\n";
		mainSaver << schoolList[i].stamp << "\n";
	}
	mainSaver.close();
	std::cout << "\nSave completed.\n\n";
}

void loadFromFile() {
	std::ifstream mainLoader(FileName);
	std::cout << "\nPreparing load...";
	if (!mainLoader.is_open())
	{
		std::cerr << "\nError: Can not find file.school file.";
		mainLoader.close();
		return;
	}
	stamps stampLoader;

	schoolList.clear();//Vycisteni hlavniho vectoru aby nedoslo k duplikaci
	mainLoader.clear();//Vycisteni proti duplikaci
	while (std::getline(mainLoader, stampLoader.object))
	{
		mainLoader >> stampLoader.stamp;
		mainLoader.ignore();
		schoolList.push_back(stampLoader);
	}
	mainLoader.close();
	std::cout << "\nLoad completed.";
}

void statistics() {
	std::cout << "\n=== Statistics ===";
	std::cout << "\nNumber of stamps: " << schoolList.size();

	float diameters = 0;
	for (int i = 0; i < schoolList.size(); i++)
	{
		diameters = diameters + schoolList[i].stamp;
	}
	float diameterrr = 0;
	diameterrr = diameters / schoolList.size();
	std::cout << "\nDiameter: " << diameterrr;

	std::sort(schoolList.begin(), schoolList.end(), [](const stamps& a, const stamps& b) {
		return a.stamp < b.stamp;
		});

    int best = schoolList[0].stamp;

	std::cout << "\nThe best: " << best;

	int interssss = schoolList.size() - 1;
	int worst = schoolList[interssss].stamp;

	std::cout << "\nThe worst: " << worst;

	std::sort(schoolList.begin(), schoolList.end(), [](const stamps& a, const stamps& b) {
		return a.object < b.object;
		});
}

int main()
{
	loadFromFile();
	bool runtime = true;
	while (runtime)
	{
		std::cout << "\n==== List of stamps ====";
		std::cout << "\n1) Add stamp";
		std::cout << "\n2) Show stamps";
		std::cout << "\n3) Sort stamps";
		std::cout << "\n4) Statistics";
		std::cout << "\n5) Terminate";
		std::cout << "\nChoose: ";

		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			addStamp();
			break;

		case 2:
			showStamps();
			break;

		case 3:
			sortStamps();
			break;

		case 4:
			statistics();
			break;

		case 5:
			saveToFile();
			std::cout << "\nProgram was terminated.";
			runtime = false;
			break;

		default:
			std::cerr << "\nWrite only numbers.";
			break;
		}
	}
}