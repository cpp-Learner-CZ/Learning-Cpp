#pragma once

#include <vector>
#include "Game.hpp"

extern std::vector<Game> games;

namespace fileAction {
	void saveData();

	void loadData();
}