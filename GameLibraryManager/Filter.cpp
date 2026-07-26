#include <print>
#include <iostream>
#include <string>

#include "Filter.hpp"
#include "Error.hpp"
#include "Data.hpp"
#include "EnumOperation.hpp"

namespace filter {
	void filterOnlyRPG() {
		std::println("== Filter only RPG ==");
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].genre == Genre::RPG)
			{
				std::println("Name: {}", games[i].name);
				std::println("Year: {}", games[i].year);
				std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
				std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
				std::println("----------------------");
			}
		}
	}

	void filterOnlyCompleted() {
		std::println("== Filter only completed ==");
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].status == Status::Completed)
			{
				std::println("Name: {}", games[i].name);
				std::println("Year: {}", games[i].year);
				std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
				std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
				std::println("----------------------");
			}
		}
	}

	void filterGameAfter2020() {
		std::println("== Filter game after 2020 ==");
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].year > 2020)
			{
				std::println("Name: {}", games[i].name);
				std::println("Year: {}", games[i].year);
				std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
				std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
				std::println("----------------------");
			}
		}
	}

	void filterOnlyOwnedGames() {
		std::println("== Filter only owned games ==");
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].status == Status::Owned)
			{
				std::println("Name: {}", games[i].name);
				std::println("Year: {}", games[i].year);
				std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
				std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
				std::println("----------------------");
			}
		}
	}

	//Choose filter from int
	void switchFilter(int inputSwitch) {
		switch (inputSwitch) {
		case 1:
			filterOnlyRPG();
			break;

		case 2:
			filterOnlyCompleted();
			break;

		case 3:
			filterGameAfter2020();
			break;

		case 4:
			filterOnlyOwnedGames();
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber;
			lobby;
			break;
		}
	}

	void lobby() {
		std::println("=== Filter game ===");
		std::println("1) Only RPG");
		std::println("2) Only completed");
		std::println("3) Game after 2020");
		std::println("4) Only owned games");
		std::print("5) Back\nChoose: ");
		int chooseFilter;
		std::cin >> chooseFilter;

		switchFilter(chooseFilter);
	}
}