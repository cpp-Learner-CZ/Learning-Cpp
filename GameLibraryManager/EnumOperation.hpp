#pragma once

#include "Game.hpp"

namespace enumOperation {
	Genre intToEnumGenre(int input);
	Status intToEnumStatus(int input);
	std::string enumGenreToString(Genre input);
	std::string enumStatusToString(Status input);
}