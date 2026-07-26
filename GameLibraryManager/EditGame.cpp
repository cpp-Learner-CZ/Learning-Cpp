#include <print>
#include <iostream>
#include <string>

#include "EditGame.hpp"
#include "Error.hpp"
#include "Verify.hpp"
#include "Data.hpp"
#include "EnumOperation.hpp"

namespace editGame {
	std::string nameEditChoose;

	void editName() {
		std::println("== Edit name ==");
		std::print("New name: ");
		std::string newName;
		std::getline(std::cin >> std::ws, newName);
		
		if (verify::nameExist(newName))
		{
			std::cerr << error::nameExistTrue;
			return;
		}
		
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == nameEditChoose)
			{
				games[i].name = newName;
				std::println("Name updated.");
			}
		}
	}

	void editYear() {
		std::println("== Edit year ==");
		std::print("New year: ");
		int newYear;
		std::cin >> newYear;

		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == nameEditChoose)
			{
				games[i].year = newYear;
				std::println("Year updated.");
			}
		}
	}

	void editGenre() {
		std::println("== Edit genre ==");
		std::println("1) Action");
		std::println("2) Strategy");
		std::println("3) RPG");
		std::println("4) Simulation");
		std::print("-------------\nChoose: ");
		int newGenre_;
		std::cin >> newGenre_;

		if (!verify::enumGenreIsCompatible(newGenre_))
		{
			std::cerr << error::wrongInputEnumGenre;
			return;
		}
		Genre genre_ = enumOperation::intToEnumGenre(newGenre_);
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].genre == genre_)
			{
				std::cerr << error::alredySetGenre;
				return;
			}
		}

		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == nameEditChoose)
			{
				games[i].genre = genre_;
				std::println("Genre updated.");
			}
		}
	}

	void editStatus() {
		std::println("== Edit status ==");
		std::println("1) Owned");
		std::println("2) Playing");
		std::println("3) Completed");
		std::print("------------\nChoose: ");
		int newStatus_;
		std::cin >> newStatus_;

		if (!verify::enumStatusIsCompatible(newStatus_))
		{
			std::cerr << error::wrongInputEnumSatus;
			return;
		}
		Status status_ = enumOperation::intToEnumStatus(newStatus_);
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].status == status_)
			{
				std::cerr << error::alredySetStatus;
				return;
			}
		}

		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].name == nameEditChoose)
			{
				games[i].status = status_;
				std::println("Status updated.");
			}
		}
	}

	void editSwitch(int input) {
		switch (input)
		{
		case 1:
			editName();
			break;

		case 2:
			editYear();
			break;

		case 3:
			editGenre();
			break;

		case 4:
			editStatus();
			break;

		case 5:
			break;

		default:
			std::cerr << error::wrongNumber;
			lobby();
			break;
		}
	}

	void lobby() {
		std::println("=== Edit game ===");
		std::print("Edit name: ");
		std::getline(std::cin >> std::ws, nameEditChoose);
		if (!verify::nameExist(nameEditChoose))
		{
			std::cerr << error::nameIsntExist;
			return;
		}

		std::println("=== Edit game ===");
		std::println("1) Edit name: ");
		std::println("2) Edit year");
		std::println("3) Edit genre");
		std::println("4) Edit status");
		std::print("5) Back\nChoose: ");
		int chooseEdit;
		std::cin >> chooseEdit;

		editSwitch(chooseEdit);
	}
}