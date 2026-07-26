#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct warehouse
{
    std::string name;
    int units;
};

std::vector<warehouse> warehouseS;

void addItem() {
    warehouse warHouse;
    std::cout << "\nAdd item to warehouse\n";
    std::cout << "Item: ";
    std::cin >> warHouse.name;

    std::cout << "Units: ";
    std::cin >> warHouse.units;

    warehouseS.push_back(warHouse);

    std::cout << "Item added\n\n";
}

void viewWarehouse() {
    std::cout << "\nView warehouse\n";
    for (int i = 0; i < warehouseS.size(); i++)
    {
        std::cout << "Item " << i + 1 << "\n";
        std::cout << "Item: " << warehouseS[i].name << "\n";
        std::cout << "Units: " << warehouseS[i].units << "\n";
    }
}

void searchItem() {
    std::cout << "\nSearch item\n";
    std::cout << "Write item name: ";
    std::string itemS;

    std::cin >> itemS;
    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (itemS == warehouseS[i].name)
        {
            std::cout << "\nItem found: " << warehouseS[i].name << "\n";
            std::cout << "Item " << warehouseS[i].name << " has " << warehouseS[i].units << " units.";
        }
    }
}

void removeItem() {
    bool remov = false;
    std::cout << "\nREMOVEITEM\n";
    std::cout << "Remove item: ";

    std::string remover;
    std::cin >> remover;
    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (remover == warehouseS[i].name)
        {
            warehouseS.erase(warehouseS.begin() + i);
            std::cout << "Deleted.\n";
            remov = true;
            break;
        }
    }

    if (remov == false)
    {
        std::cout << "Item not found\n";
    }

}

void addUnits() {
    std::cout << "\nAdd units\n";
    std::cout << "Item: ";
    std::string addNameS;
    std::cin >> addNameS;

    std::cout << "Add units: ";
    int unitss;
    std::cin >> unitss;

    bool founderS = false;

    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (addNameS == warehouseS[i].name)
        {
            founderS = true;
        }
    }

    //Zastavi kod pred pridanim a zabrani chybe
    if (founderS == false)
    {
        std::cout << "Item not found.\n";
        return;
    }

    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (addNameS == warehouseS[i].name)
        {
            warehouseS[i].units += unitss;
            std::cout << "Units was added, now item " << warehouseS[i].name << " has " << warehouseS[i].units << " units.";
        }
    }
}

void totalInWarehouse() {
    int warehouseSize = 0;
    
    for (int i = 0; i < warehouseS.size(); i++)
    {
        warehouseSize += warehouseS[i].units;
    }

    std::cout << "In warehouse is " << warehouseSize << " items. ";
}

bool existName(std::string name) {
    bool existing = false;

    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (name == warehouseS[i].name)
        {
            existing = true;
            return existing;
        }
    }

    return existing;
}

void editName() {
    std::cout << "\n=== Edit name ===";
    std::cout << "\nWrite name for edit: ";

    std::string editer;
    std::cin >> editer;
    //Enter chacker name
    if (existName(editer))
    {
        std::cout << "\nWrite new name: ";
        std::string newName;
        std::cin >> newName;
        //Editing
        for (int i = 0; i < warehouseS.size(); i++)
        {
            //Founded
            if (editer == warehouseS[i].name)
            {
                //Edited
                warehouseS[i].name = newName;
                std::cout << "\nNew name " << newName << "\n";
                //Completed
                break;
            }
        }
    }
    else
    {
        std::cout << "\nThis name is not exist.";
    }
}

void editUnits() {
    std::cout << "\n=== Edit units ===";
    std::cout << "\nWrite name for edit units: ";

    std::string editer;
    std::cin >> editer;
    if (existName(editer))//Enter chacker name
    {
        std::cout << "\nWrite new units: ";
        int newUnits;
        std::cin >> newUnits;
        for (int i = 0; i < warehouseS.size(); i++)
        {
            if (editer == warehouseS[i].name)//Founded
            {
                warehouseS[i].units = newUnits; //Edited
                std::cout << "\nUpdated units in " << editer << " to " << newUnits << "\n";//Completed
                break;
            }
        }
    } else {
        std::cout << "\nThis name is not exist.";
    }
}

void editItem() {
    std::cout << "\nEdit item";
    std::cout << "\n1) Edit name";
    std::cout << "\n2) Edit units";
    std::cout << "\n3) Back";
    std::cout << "\n\nChoose: ";

    int chooseIntt;
    std::cin >> chooseIntt;

    switch (chooseIntt)
    {
    case 1:
        editName();
        break;

    case 2:
        editUnits();
        break;

    case 3:
        break;

    default:
        editItem();
        std::cout << "\nError, please write only numbers.";
        break;
    }
}

void sortName() {
    std::cout << "\nSort by name";
    std::sort(warehouseS.begin(), warehouseS.end(), [](const warehouse& a, const warehouse& b) {
        return a.name < b.name;
        });
    for (int i = 0; i < warehouseS.size(); i++)
    {
        std::cout << "\nItem " << i + 1 << "\nItem: " << warehouseS[i].name << "\nUnits : " << warehouseS[i].units;
    }
}

void sortUnits() {
    std::cout << "\nSort by units";
    std::sort(warehouseS.begin(), warehouseS.end(), [](const warehouse& a, const warehouse& b) {
        return a.units < b.units;
        });
    for (int i = 0; i < warehouseS.size(); i++)
    {
        std::cout << "\nItem " << i + 1 << "\nItem: " << warehouseS[i].name << "\nUnits: " << warehouseS[i].units;
    }
}

void sorter() {
    std::cout << "\n=== Sort ===";
    std::cout << "\nSort by";
    std::cout << "\n1) Name";
    std::cout << "\n2) Units";
    std::cout << "\n3) Back";

    std::cout << "\nChoose: ";
    int chooseSort;
    std::cin >> chooseSort;

    switch (chooseSort)
    {
    case 1:
        sortName();
        break;

    case 2:
        sortUnits();
        break;

    case 3:

        break;

    default:
        std::cout << "\nError, please write only numbers.";
        sorter();
        break;
    }
}

void filter() {
    std::cout << "\nFilter (More than 10)";

    for (int i = 0; i < warehouseS.size(); i++)
    {
        if (warehouseS[i].units >= 10)
        {
            std::cout << "\nName: " << warehouseS[i].name << "\nUnits: " << warehouseS[i].units;
        }
    }
}

int main() {
    int runtime = 1;

    while (runtime == 1)
    {
        std::cout << "\n=== Warehouse ===";
        std::cout << "\n1) Add item";
        std::cout << "\n2) View warehouse";
        std::cout << "\n3) Search item";
        std::cout << "\n4) Remove item";
        std::cout << "\n5) Add units";
        std::cout << "\n6) Total in wareouse";
        std::cout << "\n7) Edit item";
        std::cout << "\n8) Sort";
        std::cout << "\n9) Fiter";
        std::cout << "\n10) Terminate";

        std::cout << "\n\nChoose: ";
        int chooseInt;
        std::cin >> chooseInt;

        switch (chooseInt)
        {
        case 1:
            addItem();
            break;
        
        case 2:
            viewWarehouse();
            break;
        
        case 3:
            searchItem();
            break;
        
        case 4:
            removeItem();
            break;

        case 5:
            addUnits();
            break;

        case 6:
            totalInWarehouse();
            break;

        case 7:
            editItem();
            break;

        case 8:
            sorter();
            break;

        case 9:
            filter();
            break;

        case 10:
            std::cout << "Program terminated.";
            runtime = 0;
            break;
        
        default:
            std::cout << "\nError\n\n";
            break;
        }
    }
}