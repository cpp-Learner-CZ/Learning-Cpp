#include <iostream>
#include <vector>
#include <print>

#include "Game.hpp"
#include "Data.hpp"
#include "Error.hpp"
#include "EditGame.hpp"
#include "Filter.hpp"
#include "Sort.hpp"
#include "Statistics.hpp"

bool runtime = true;

int main()
{
	fileAction::loadData();
	//Main loop
	while (runtime)
	{
		std::println("\n==== Game Library ====");
		std::println("1) Add game");
		std::println("2) Show games");
		std::println("3) Edit game");
		std::println("4) Remove game");
		std::println("5) Search game");
		std::println("6) Filter");
		std::println("7) Sort");
		std::println("8) Statistics");
		std::print("9) Terminate\nChoose: ");
		int choose;
		std::cin >> choose;

		switch (choose)
		{
		case 1:
			add::addGame();
			break;

		case 2:
			showGames();
			break;

		case 3:
			editGame::lobby();
			break;

		case 4:
			removerer::lobby();
			break;

		case 5:
			searchGame();
			break;

		case 6:
			filter::lobby();
			break;

		case 7:
			sorter::lobby();
			break;

		case 8:
			statistics::showStatistics();
			break;

		case 9:
			runtime = false;
			fileAction::saveData();
			std::println("Program terminated.");
			return 0;

		default:
			std::cerr << error::wrongNumber;
			break;
		}
	}
}