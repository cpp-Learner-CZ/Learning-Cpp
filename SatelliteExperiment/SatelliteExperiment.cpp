#include <iostream>
#include <string>
#include <vector>

struct Satellite {
    std::string name;
    int height;
    std::string status;
};

std::vector <Satellite> Satellites;

void addSatellite() {
    Satellite newSat;

    std::cout << "Enter the name of the satellite: ";
    std::cin >> newSat.name;

    std::cout << "Enter the satellite altitude: ";
    std::cin >> newSat.height;

    std::cout << "enter the satellite status: ";
    std::cin >> newSat.status;

    Satellites.push_back(newSat);
}

void showAllSatellite() {
    std::cout << "Satellites\n";

    for (int i = 0; i < Satellites.size(); i++)
    {
        std::cout << i + 1 << ". \n";
        std::cout << "Name: " << Satellites[i].name << "\n";
        std::cout << "Altitude: " << Satellites[i].height << "\n";
        std::cout << "Status: " << Satellites[i].status << "\n";
    }
}

void searchSatellite() {
    std::cout << "Search for satellite: ";
    std::string sat;

    std::cin >> sat;

    for (int i = 0; i < Satellites.size(); i++)
    {
        if (sat == Satellites[i].name)
        {
            std::cout << "\nFound: " << Satellites[i].name << "\n";
            std::cout << "Altitude: " << Satellites[i].height << "\n";
            std::cout << "Status: " << Satellites[i].status << "\n";
        }
    }
}

void removeSatellite() {
    std::cout << "REMOVE SATELLITE\nEnter satellite name: ";
    std::string satRemove;
    std::cin >> satRemove;

    for (int i = 0; i < Satellites.size(); i++)
    {
        if (satRemove == Satellites[i].name)
        {
            std::cout << "Deleted: " << Satellites[i].name;
            Satellites.erase(Satellites.begin() + i);
            break;
        }
    }
}


int main()
{
    int online = 1;

    while (online == 1) {
        std::cout << "\n===Satellite network===";
        std::cout << "\n1) Add satellite";
        std::cout << "\n2) Show all satellites";
        std::cout << "\n3) Search satellite";
        std::cout << "\n4) Remove satellite";
        std::cout << "\n5) End";
        std::cout << "\nChoose: ";

        int chooseI;
        std::cin >> chooseI;

        switch (chooseI) {
        case 1:
            addSatellite();
            break;
        case 2:
            showAllSatellite();
            break;
        case 3:
            searchSatellite();
            break;

        case 4:
            removeSatellite();
            break;

        case 5:
            online = 0; 
            std::cout << "Program ended.";
            break;
        }
    }
}