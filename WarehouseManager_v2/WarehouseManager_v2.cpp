#include <iostream>
#include <print>
#include <limits>
#include <cstdlib>

#include "Warehouse.hpp"
#include "Version.hpp"
#include "ErrorOrLogs.hpp"
#include "Editor.hpp"

bool runProgram = true;


void mainSwitch(int& choose) {
    switch (choose)
    {
    case 1:
        add::lobby();
        break;

    case 2:
        showProductss();
        break;

    case 3:
        editProduct::lobby();
        break;

    case 4:
        break;

    case 5:
        break;

    case 6:
        break;

    case 7:
        break;

    case 8:
        break;

    case 9:
        break;

    case 10:
        break;

    case 11:
        runProgram = false;
        std::println("Program terminated.");
        exit(0);

    default:
        std::cerr << error::wrongNumber1to11;
        logAction.emplace_back(logs::wrongNumber1to11);
        break;
    }
}

int main()
{
    while (runProgram) {
        std::println("\n==== Warehouse manager v2:{} ====", appVersion);
        std::println("1) Add product");
        std::println("2) Show products");
        std::println("3) Edit product");
        std::println("4) Delete product");
        std::println("5) Search product");
        std::println("6) Filter");
        std::println("7) Sort");
        std::println("8) Statistics");
        std::println("9) Logs");
        std::println("10) Export");
        std::print("11) Exit\nChoose: ");
        int choose;

        while (!(std::cin >> choose)) {
            std::cerr << error::wrongNumber;
            logAction.emplace_back(logs::logWrongNumber);
            std::print("\nChoose: ");

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        mainSwitch(choose);
    }
}