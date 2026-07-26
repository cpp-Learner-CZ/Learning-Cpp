#include <print>
#include <iostream>
#include <algorithm>

#include "Sort.hpp"
#include "Error.hpp"
#include "Data.hpp"

namespace sorter {
	void sortByName() {
		std::sort(games.begin(), games.end(), [](const Game& a, const Game& b) {
			return a.name < b.name;
			});
	}

	void sortByYear() {
		std::sort(games.begin(), games.end(), [](const Game& a, const Game& b) {
			return a.year < b.year;
			});
	}

	void sortByGenre() {
		std::sort(games.begin(), games.end(), [](const Game& a, const Game& b) {
			return static_cast<int>(a.genre) < static_cast<int>(b.genre);
			});
	}

	//Switch for sorting
	void sortSwitch(int chooseSort) {
		switch (chooseSort)
		{
		case 1:
			sortByName();
			std::println("Sorted by name.");
			break;

		case 2:
			sortByYear();
			std::println("Sorted by year.");
			break;

		case 3:	
			sortByGenre();
			std::println("Sorted by genre.");
			break;

		case 4:
			break;

		default:
			std::cerr << error::wrongNumber;
			break;
		}	
	}

	void lobby() {
		std::println("=== Sort ===");
		std::println("1) Sort by name");
		std::println("2) Sort by year");
		std::println("3) Sort by genre");
		std::print("4) Back\nChoose: ");
		int chooseSort;
		std::cin >> chooseSort;

		sortSwitch(chooseSort);
	}
}