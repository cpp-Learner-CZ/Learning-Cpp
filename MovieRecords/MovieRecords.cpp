#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

bool runtime = true;
class Film {
public:
	std::string name;
	std::string genre;
	int year = 0;
	bool watch = false;
};
std::vector<Film> films;
const std::string saveFile = "data.movie";

bool getBoolFromString(std::string booleanSetter) {
	bool reason;
	reason = (booleanSetter == "Y" || booleanSetter == "y");
	return reason;
}

void getStringFromBoolean(bool boleaned) {
	if (boleaned)
	{
		std::cout << "\nMovie was watched";
	}
	else
	{
		std::cout << "\nMovie wasn't watched.";
	}
}

void addFilm() {
	Film filmer;
	std::cout << "\n===Add film ===";
	std::cout << "\nFilm name: ";
	std::getline(std::cin >> std::ws, filmer.name);

	std::cout << "\nFilm genre: ";
	std::getline(std::cin >> std::ws, filmer.genre);

	std::cout << "\nYear of publication: ";
	std::cin >> filmer.year;

	std::cout << "\nSeen: (y/n)";
	std::string seenGet;
	std::getline(std::cin >> std::ws, seenGet);
	filmer.watch = getBoolFromString(seenGet);

	films.push_back(filmer);
	std::cout << "\nFilm added.";
}

void showFilms() {
	std::cout << "\n=== Show movies ===";
	for (int i = 0; i < films.size(); i++)
	{
		std::cout << "\nName: " << films[i].name;
		std::cout << "\nGenre: " << films[i].genre;
		std::cout << "\nYear of publication: " << films[i].year;
		getStringFromBoolean(films[i].watch);
	}
}

std::string sEditName;

void vEditName() {
	std::cout << "\n== Edit name ==";
	std::cout << "\nWrite new name: ";
	std::string newName;
	std::getline(std::cin >> std::ws, newName);

	for (int i = 0; i < films.size(); i++)
	{
		if (sEditName == films[i].name)
		{
			films[i].name = newName;
			std::cout << "\nName updated.";
		}
	}
}

void vEditGenre() {
	std::cout << "\n== Edit genre ==";
	std::cout << "\nWrite new genre: ";
	std::string newGenre;
	std::getline(std::cin >> std::ws, newGenre);

	for (int i = 0; i < films.size(); i++)
	{
		if (sEditName == films[i].name)
		{
			films[i].genre = newGenre;
			std::cout << "\nGenre updated.";
		}
	}
}

void vEditYear() {
	std::cout << "\n== Edit year of publication ==";
	std::cout << "\nWrite new year: ";
	int newYear;
	std::cin >> newYear;

	for (int i = 0; i < films.size(); i++)
	{
		if (sEditName == films[i].name)
		{
			films[i].year = newYear;
			std::cout << "\nYear of publication updated.";
		}
	}
}

void vEditWatched() {
	std::cout << "\n== Edit watched ==";
	std::cout << "\nWrite watch: (y/n)";
	std::string newWatch;
	std::getline(std::cin >> std::ws, newWatch);
	bool placer = getBoolFromString(newWatch);

	for (int i = 0; i < films.size(); i++)
	{
		if (sEditName == films[i].name)
		{
			films[i].watch = placer;
			std::cout << "\nWatch updated.";
		}
	}
}

void editFilm() {
	bool editReady = false;
	std::cout << "\n=== Edit film ===";
	std::cout << "\nName for edit: ";
	std::getline(std::cin >> std::ws, sEditName);
	for (int i = 0; i < films.size(); i++)
	{
		if (sEditName == films[i].name)
		{
			editReady = true;
			std::cout << "\nName: " << films[i].name;
			std::cout << "\nGenre:" << films[i].genre;
			std::cout << "\nYear of publication: " << films[i].year;
			getStringFromBoolean(films[i].watch);
		}
	}
	
	if (!editReady)
	{
		std::cerr << "\nError: Film not found.";
		editReady = false;
		return;
	}
	editReady = false;
	std::cout << "\n=== Edit ===";
	std::cout << "\n1) Name";
	std::cout << "\n2) Genre";
	std::cout << "\n3) Year of publication";
	std::cout << "\n4) Watched";
	std::cout << "\n5) Back";
	std::cout << "\nChoose: ";
	int chooseEdit;
	std::cin >> chooseEdit;
	switch (chooseEdit)
	{
	case 1:
		vEditName();
		break;

	case 2:
		vEditGenre();
		break;

	case 3:
		vEditYear();
		break;

	case 4:
		vEditWatched();
		break;

	case 5:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		editFilm();
		break;
	}
}

void removeFilm() {
	std::cout << "\n=== Remove film ===";
	std::cout << "\nWrite name for remove: ";
	std::string removeName;
	std::getline(std::cin >> std::ws, removeName);

	for (int i = 0; i < films.size(); i++)
	{
		if (removeName == films[i].name)
		{
			films.erase(films.begin() + i);
			std::cout << "\nFilm " << removeName << " removed.";
			return;
		}
	}
	std::cerr << "\nError: Film not found.";
}

void filterWatched() {
	std::cout << "\n== Filter watched ==";
	for (int i = 0; i < films.size(); i++)
	{
		if (films[i].watch)
		{
			std::cout << "\nName: " << films[i].name;
			std::cout << "\nGenre: " << films[i].genre;
			std::cout << "\nYear of publication: " << films[i].year;
			getStringFromBoolean(films[i].watch);
		}
	}
}

void filterUnwatched() {
	std::cout << "\n== Filter unwatched ==";
	for (int i = 0; i < films.size(); i++)
	{
		if (!films[i].watch)
		{
			std::cout << "\nName: " << films[i].name;
			std::cout << "\nGenre: " << films[i].genre;
			std::cout << "\nYear of publication: " << films[i].year;
			getStringFromBoolean(films[i].watch);
		}
	}
}

void filterMoviesAfter2020() {
	std::cout << "\n== Filter movies after 2020 ==";
	for (int i = 0; i < films.size(); i++)
	{
		if (films[i].year > 2020)
		{
			std::cout << "\nName: " << films[i].name;
			std::cout << "\nGenre: " << films[i].genre;
			std::cout << "\nYear of publication: " << films[i].year;
			getStringFromBoolean(films[i].watch);
		}
	}
}

void filterrr() {
	std::cout << "\n=== Filter ===";
	std::cout << "\n1) Watched";
	std::cout << "\n2) Unwatched";
	std::cout << "\n3) Movies after 2020";
	std::cout << "\n4) Back";
	std::cout << "\nChoose: ";
	int chooseFilter;
	std::cin >> chooseFilter;
	switch (chooseFilter)
	{
	case 1:
		filterWatched();
		break;

	case 2:
		filterUnwatched();
		break;

	case 3:
		filterMoviesAfter2020();
		break;

	case 4:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		filterrr();
		break;
	}
}

void sortByName() {
	std::cout << "\n== Sort by name ==";
	std::sort(films.begin(), films.end(), [](const Film& a, const Film& b) {
		return a.name < b.name;
		});
	std::cout << "\nSorted.";
}

void sortByGenre() {
	std::cout << "\n== Sort by genre ==";
	std::sort(films.begin(), films.end(), [](const Film& a, const Film& b) {
		return a.genre < b.genre;
		});
	std::cout << "\nSorted.";
}

void sortByYear() {
	std::cout << "\n== Sort by year ==";
	std::sort(films.begin(), films.end(), [](const Film& a, const Film& b) {
		return a.year < b.year;
		});
	std::cout << "\nSorted.";
}

void sorter() {
	std::cout << "\n=== Sort ===";
	std::cout << "\n1) By name";
	std::cout << "\n2) By genre";
	std::cout << "\n3) By year";
	std::cout << "\n4) Back";
	std::cout << "\nChoose: ";
	int sortChoose;
	std::cin >> sortChoose;
	switch (sortChoose)
	{
	case 1:
		sortByName();
		break;

	case 2:
		sortByGenre();
		break;

	case 3:
		sortByYear();
		break;

	case 4:
		break;

	default:
		std::cerr << "\nError: Write only numbers.";
		sorter();
		break;
	}

}

void loadData() {
	std::cout << "\nLoading...";
	std::ifstream loader(saveFile);
	if (!loader.is_open())
	{
		std::cerr << "\nError: Can't open file " << saveFile;
		loader.close();
		return;
	}

	Film filmAdder;
	while (std::getline(loader, filmAdder.name))
	{
		std::getline(loader, filmAdder.genre);
		loader >> filmAdder.year;
		loader >> filmAdder.watch;
		loader.ignore();
		films.push_back(filmAdder);
	}
	std::cout << "\nLoad completed, opening menu...";
	loader.close();
}

void saveData() {
	std::cout << "\nSaving...";
	std::ofstream saver(saveFile);
	if (!saver.is_open())
	{
		std::cerr << "\nError: Can't write to " << saveFile;
		saver.close();
		return;
	}

	for (int i = 0; i < films.size(); i++)
	{
		saver << films[i].name << "\n";
		saver << films[i].genre << "\n";
		saver << films[i].year << "\n";
		saver << films[i].watch << "\n";
	}
	saver.close();
	std::cout << "\nSave completed, terminating...";
}

void statistics() {
	std::cout << "\n=== Statistics ===";
	int sizeMovies = films.size();
	std::cout << "\nNumber of movies: " << sizeMovies;
	int showed = 0;
	for (int i = 0; i < films.size(); i++)
	{
		if (films[i].watch)
		{
			showed++;
		}
	}
	std::cout << "\nNumber of showed: " << showed;

	int unshowed = 0;
	for (int i = 0; i < films.size(); i++)
	{
		if (!films[i].watch)
		{
			unshowed++;
		}
	}
	std::cout << "\nNumber of unshowed: " << unshowed;

	std::sort(films.begin(), films.end(), [](const Film& a, const Film& b) {
		return a.year < b.year;
		});
	int sizeLatest = sizeMovies - 1;
	std::string oldest = films[0].name;
	std::string latest = films[sizeLatest].name;
	std::cout << "\nOldest movie: " << oldest;
	std::cout << "\nLatest movie: " << latest;

	std::sort(films.begin(), films.end(), [](const Film& a, const Film& b) {
		return a.name < b.name;
		});
}

int main()
{
	loadData();
	while (runtime)
	{
		std::cout << "\n==== Movie records ====";
		std::cout << "\n1) Add film";
		std::cout << "\n2) Show films";
		std::cout << "\n3) Edit film";
		std::cout << "\n4) Remove film";
		std::cout << "\n5) Filter";
		std::cout << "\n6) Sort";
		std::cout << "\n7) Statistics";
		std::cout << "\n8) Terminate";

		std::cout << "\nChoose: ";
		int choose;
		std::cin >> choose;
		switch (choose)
		{
		case 1:
			addFilm();
			break;

		case 2:
			showFilms();
			break;

		case 3:
			editFilm();
			break;

		case 4:
			removeFilm();
			break;

		case 5:
			filterrr();
			break;

		case 6:
			sorter();
			break;

		case 7:
			statistics();
			break;

		case 8:
			runtime = false;
			saveData();
			std::cout << "\nProgram terminated.";
			break;

		default:
			std::cerr << "\nError: Write only numbers.";
			break;
		}

	}
}