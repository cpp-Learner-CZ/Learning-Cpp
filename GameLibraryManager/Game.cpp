#include <iostream>
#include <print>
#include <string>

#include "Game.hpp"
#include "Verify.hpp"
#include "Error.hpp"
#include "EnumOperation.hpp"
#include "Data.hpp"

namespace add {
	std::string newName;
	int newYear;
	Genre genre_;
	Status status_;

	void saveGame() {
		games.emplace_back(newName, newYear, genre_, status_);

		std::println("Added.");
	}

	void setStatus() {
		std::println("== Set status ==");
		std::println("1) Owned");
		std::println("2) Playing");
		std::println("3) Completed");
		std::print("------------\nChoose: ");
		int chooseStatus;
		std::cin >> chooseStatus;

		if (!verify::enumStatusIsCompatible(chooseStatus))
		{
			std::cerr << error::wrongInputEnumSatus;
			return;
		}
		status_ = enumOperation::intToEnumStatus(chooseStatus);

		saveGame();
	}

	void setGenre() {
		std::println("== Set genre ==");
		std::println("1) Action");
		std::println("2) Strategy");
		std::println("3) RPG");
		std::println("4) Simulation");
		std::print("-------------\nChoose: ");
		int chooseGenre;
		std::cin >> chooseGenre;

		if (!verify::enumGenreIsCompatible(chooseGenre))
		{
			std::cerr << error::wrongInputEnumGenre;
			return;
		}
		genre_ = enumOperation::intToEnumGenre(chooseGenre);

		setStatus();
	}

	//Write name and year
	void addGame() {
		std::println("=== Add Game ===");
		std::print("Write name: ");
		std::getline(std::cin >> std::ws, newName);

		std::print("Write year: ");
		std::cin >> newYear;
		
		if (verify::nameExist(newName))
		{
			std::cerr << error::nameExistTrue;
			return;
		}
		setGenre();
	}
}
namespace removerer {
	std::string nameRemove;

	void removeDone() {
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == nameRemove)
			{
				games.erase(games.begin() + i);
				std::println("Game with name {} removed.", nameRemove);
				return;
			}
		}
		std::cerr << "ERROR: Unexpected error!";
	}

	void confirmRemove() {
		std::println("Confirm remove {}", nameRemove);
		std::print("Are you sure for remove {}? Write y or n: ", nameRemove);
		std::string confirmChoose;
		std::getline(std::cin >> std::ws, confirmChoose);
		bool confirmBool = (confirmChoose == "y" || confirmChoose == "Y");
		if (!confirmBool)
		{
			std::cerr << "Game remove canceled.";
			return;
		}
		removeDone();
	}

	//Write name
	void lobby() {
		std::println("=== Remove game ===");
		std::print("Name for remove: ");
		std::getline(std::cin >> std::ws, nameRemove);

		if (!verify::nameExist(nameRemove))
		{
			std::cerr << error::nameIsntExist;
			return;
		}
		confirmRemove();
	}
}

void showGames() {
	std::println("=== Show games ===");
	for (size_t i = 0; i < games.size(); i++)
	{
		std::println("Name: {}", games[i].name);
		std::println("Year: {}", games[i].year);
		std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
		std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
		std::println("----------------------");
	}
	if (games.size() == 0)
	{
		std::println("No game found.");
	}
}

void searchGame() {
	std::println("=== Search game ===");
	std::print("Search name: ");
	std::string searchGame;
	std::getline(std::cin >> std::ws, searchGame);
	bool found = false;
	for (size_t i = 0; i < games.size(); i++)
	{
		if (games[i].name == searchGame)
		{
			found = true;
			std::println("Name: {}", games[i].name);
			std::println("Year: {}", games[i].year);
			std::println("Genre: {}", enumOperation::enumGenreToString(games[i].genre));
			std::println("Status: {}", enumOperation::enumStatusToString(games[i].status));
			std::println("----------------------");
		}
	}

	if (!found)
	{
		std::cerr << error::nameIsntExist;
	}
}