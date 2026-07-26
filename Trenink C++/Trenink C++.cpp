#include <iostream>
#include <string>
#include <vector>

//Create structure
struct Worker
{
    std::string name;
    int age;
    std::string room;
};

//Create vector
std::vector<Worker> Workers;

//Add user
void addUser() {
    Worker newW;
    std::cout << "\nName: ";
    std::cin >> newW.name;

    std::cout << "Age: ";
    std::cin >> newW.age;

    std::cout << "Room: ";
    std::cin >> newW.room;

    Workers.push_back(newW);
    std::cout << "User added.\n\n";
}

//show user
void showUser() {
    std::cout << "\nWorkes\n";
    for (int i = 0; i < Workers.size(); i++)
    {
        std::cout << "\nWorker " << i + 1;// 0 + 1 = 1
        std::cout << "\nName: " << Workers[i].name;
        std::cout << "\nAge: " << Workers[i].age;
        std::cout << "\nRoom: " << Workers[i].room << "\n";
    }
    std::cout << "\n\n";
}

//search user
void searchUser() {
    bool found = false;
    std::string nameing;

    std::cout << "Name: ";
    std::cin >> nameing;

    for (int i = 0; i < Workers.size(); i++)
    {
        if(nameing == Workers[i].name) {
            std::cout << "\nWorker found\n";
            std::cout << "\nName: " << Workers[i].name;
            std::cout << "\nAge: " << Workers[i].age;
            std::cout << "\nRoom: " << Workers[i].room << "\n\n";
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "\nWorker not found.\n";
    }
}

void removeUser() {
    std::cout << "REMOVE USER\nName: ";
    std::string remUser;
    std::cin >> remUser;

    for (int i = 0; i < Workers.size(); i++)
    {
        if (remUser == Workers[i].name)
        {
            std::cout << "Deleted: " << Workers[i].name;
            Workers.erase(Workers.begin() + i);
        }
    }
}

//Main
int main()
{
    int whiles = 1;

    while (whiles == 1) {
        int chooseMain;

        std::cout << "===Main Menu===\n\n";
        std::cout << "1) Add user\n";
        std::cout << "2) Show user\n";
        std::cout << "3) Search user\n";
        std::cout << "4) Delete user\n";
        std::cout << "5) End\n\n";

        std::cout << "Choose: ";
        std::cin >> chooseMain;

        switch (chooseMain) {
        case 1:
            addUser();
            break;

        case 2:
            showUser();
            break;

        case 3:
            searchUser();
            break;

        case 4:
            removeUser();
            break;

        case 5:
            whiles = 0;
            std::cout << "\n\nProgram closed\n";
            break;
        }

    }
    return 0;
}