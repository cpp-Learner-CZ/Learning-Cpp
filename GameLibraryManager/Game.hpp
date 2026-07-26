#pragma once

#include <string>

enum class Genre
{
	Action = 1,
	Strategy = 2,
	RPG = 3,
	Simulation = 4
};

enum class Status
{
	Owned = 1,
	Playing = 2,
	Completed = 3
};

class  Game
{
public:
	std::string name;
	int year;
	Genre genre;
	Status status;

	Game(std::string n, int y, Genre g, Status s) {
		name = n;
		year = y;
		genre = g;
		status = s;
	}
};

//Game add
namespace add {
	void addGame();
}

//Game remove
namespace removerer {
	void lobby();
}

void showGames();

void searchGame();