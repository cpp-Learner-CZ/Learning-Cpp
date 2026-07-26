#include <print>
#include <fstream>
#include <iostream>

#include "Data.hpp"
#include "Error.hpp"

std::vector<Game> games;

namespace fileAction {
	const std::string fileName = "file.dat";

	void saveData() {
		std::println("Saving...");
		std::ofstream writer(fileName);
		if (!writer.is_open())
		{
			writer.close();
			std::cerr << error::cantOpenFile;
			return;
		}
		int tempGenre;
		int tempStatus;
		for (size_t i = 0; i < games.size(); i++)
		{
			writer << games[i].name << "\n";
			writer << games[i].year << "\n";
			tempGenre = static_cast<int>(games[i].genre);
			tempStatus = static_cast<int>(games[i].status);
			writer << tempGenre << "\n";
			writer << tempStatus << "\n";
		}

		writer.close();
		std::println("Save completed, terminating program...");
	}

	void loadData() {
		std::println("Loading...");
		std::ifstream loader(fileName);
		if (!loader.is_open())
		{
			loader.close();
			std::cerr << error::cantOpenFile;
			return;
		}
		std::string tempName;
		int tempYear;
		Genre tempGenre_;
		Status tempStatus_;

		int tempStatus;
		int tempGenre;

		while (std::getline(loader, tempName))
		{
			loader >> tempYear;
			loader >> tempGenre;
			loader >> tempStatus;
			loader.ignore();

			tempGenre_ = static_cast<Genre>(tempGenre);
			tempStatus_ = static_cast<Status>(tempStatus);
			games.emplace_back(tempName, tempYear, tempGenre_, tempStatus_);
		}

		loader.close();
		std::println("Load completed, starting menu...");
	}
}