#include <iostream>
#include <print>

#include "Statistics.hpp"
#include "Data.hpp"
#include "Game.hpp"
#include "Sort.hpp"

namespace statistics {
	int countGames;

	int completedGames() {
		int completed = 0;
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].status == Status::Completed)
			{
				completed++;
			}
		}
		return completed;
	}

	int openGames() {
		int open = 0;
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].status == Status::Playing)
			{
				open++;
			}
		}
		return open;
	}

	int RPGCount() {
		int RPG = 0;
		for (size_t i = 0; i < games.size(); i++)
		{
			if (games[i].genre == Genre::RPG)
			{
				RPG++;
			}
		}
		return RPG;
	}

	std::string latestGame() {
		sorter::sortByName();
		int oldGame = countGames - 1;
		return games[oldGame].name;
	}

	std::string oldestGame() {
		sorter::sortByName();
		return games[0].name;
	}

	void showStatistics() {
		std::println("\n==== Statistics ====");
		countGames = games.size();
		std::println("Games count: {}", countGames);
		std::println("Completed games: {}", completedGames());
		std::println("Open games: {}", openGames());
		std::println("RPG count: {}", RPGCount());
		std::println("Oldest game: {}", oldestGame());
		std::println("Latest game: {}", latestGame());
	}
}