#include "EnumOperation.hpp"

namespace enumOperation {
	Genre intToEnumGenre(int input) {
		switch (input)
		{	
		case 1:
			return Genre::Action;

		case 2:
			return Genre::Strategy;

		case 3:
			return Genre::RPG;

		case 4:
			return Genre::Simulation;
		}
	}

	Status intToEnumStatus(int input) {
		switch (input)
		{	
		case 1:
			return Status::Owned;

		case 2: 
			return Status::Playing;

		case 3:
			return Status::Completed;
		}
	}

	std::string enumGenreToString(Genre input) {
		switch (input)
		{
		case Genre::Action:
			return "Action";

		case Genre::Strategy:
			return "Strategy";

		case Genre::RPG:
			return "RPG";

		case Genre::Simulation:
			return "Simulation";
		}
	}

	std::string enumStatusToString(Status input) {
		switch (input)
		{	
		case Status::Owned:
			return "Owned";

		case Status::Playing:
			return "Playing";

		case Status::Completed:
			return "Completed";
		}
	}

}