#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct book
{
    std::string name;
    std::string author;
    int yearOfPublication = 0;
    bool availability = false;
};
std::vector<book> booker;

bool runtime = true;

void readAvailability(bool availabled) {
    if (availabled)
    {
        std::cout << "\nBook available.";
    }
    else
    {
        std::cout << "\nBook not available.";
    }
}

void addBook() {
    book bookAdd;

    std::cout << "\nAdd book";
    std::cout << "Name: ";
    std::cin >> bookAdd.name;

    std::cout << "Author: ";
    std::cin >> bookAdd.author;

    std::cout << "Year of publication: ";
    std::cin >> bookAdd.yearOfPublication;

    std::cout << "Availability: (1 = Yes, 0 = No)";
    int avay;
    std::cin >> avay;

    bool availabilityBookS = (avay == 1);
    bookAdd.availability = availabilityBookS;
    booker.push_back(bookAdd);
}

void listOfBooks() {
    std::cout << "\nList of books";
    for (int i = 0; i < booker.size(); i++)
    {
        std::cout << "\nBook number " << i + 1;
        std::cout << "\nName: " << booker[i].name;
        std::cout << "\nAuthor: " << booker[i].author;
        std::cout << "\nYear of publication: " << booker[i].yearOfPublication;
        readAvailability(booker[i].availability);
    }
}

void searchBook() {
    bool found = false;

    std::cout << "\nSearch book";
    std::cout << "\nWrite book name: ";
    std::string bookNames;
    std::cin >> bookNames;

    for (int i = 0; i < booker.size(); i++)
    {
        if (bookNames == booker[i].name)
        {
            found = true;
            std::cout << "\n\nBook found";
            std::cout << "\nName: " << booker[i].name;
            std::cout << "\nAuthor: " << booker[i].author;
            std::cout << "\nYear of publication: " << booker[i].yearOfPublication;
            readAvailability(booker[i].availability);
        }
    }
    if (found == false)
    {
        std::cout << "\nBook not found.";
    }
}

void removeBook() {
    bool found = false;

    std::cout << "\nRemove book";
    std::cout << "\nWrite name for remove book: ";

    std::string remover;
    std::cin >> remover;

    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == remover)
        {
            found = true;
            booker.erase(booker.begin() + i);
            break;
        }
    }
    if (found == false)
    {
        std::cout << "\nBook not found.";
    }
}

bool readyEdit = false;//Dulezite
std::string editor;//Dulezite

void editName() {
    std::cout << "\nEDIT NAME";
    std::cout << "\nWrite new name: ";

    std::string newName;
    std::cin >> newName;

    for (int i = 0; i < booker.size(); i++)
    {
        if (editor == booker[i].name)
        {
            booker[i].name = newName;
            std::cout << "\nName updated.\n";
            readyEdit = false;
        }
    }
}

void editAuthor() {
    std::cout << "\nEDIT AUTHOR";
    std::cout << "\nWrite new author: ";

    std::string newAuthor;
    std::cin >> newAuthor;

    for (int i = 0; i < booker.size(); i++)
    {
        if (editor == booker[i].name)
        {
            booker[i].author = newAuthor;
            std::cout << "\nAuthor updated.\n";
            readyEdit = false;
        }
    }
}

void editYearOfPublic() {
    std::cout << "\nEDIT YEAR OF PUBLICATION";
    std::cout << "\nWrite new year of publication: ";

    int newYear;
    std::cin >> newYear;

    for (int i = 0; i < booker.size(); i++)
    {
        if (editor == booker[i].name)
        {
            booker[i].yearOfPublication = newYear;
            std::cout << "\nYear of publication updated.\n";
            readyEdit = false;
        }
    }
}

void editAvailability() {
    std::cout << "\nEDIT AVAILABILITY";
    std::cout << "\nUpdate availability: (1 = Yes, 0 = No)";

    int available;
    std::cin >> available;
    bool availables = (available == 1);

    for (int i = 0; i < booker.size(); i++)
    {
        if (editor == booker[i].name)
        {
            booker[i].availability = availables;
            std::cout << "\nAvailable updated.\n";
            readyEdit = false;
        }
    }
}

void editBook() {
    std::cout << "\nEdit book";
    std::cout << "\nWrite name book for edit: ";
    std::cin >> editor;

    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == editor)
        {
            readyEdit = true;
            std::cout << "\nName: " << booker[i].name;
            std::cout << "\nAuthor: " << booker[i].author;
            std::cout << "\nYear of publication: " << booker[i].yearOfPublication;
            readAvailability(booker[i].availability);
        }
    } 
    if (!readyEdit)
    {
        std::cout << "\nBook for edit not found.\n\n";
        return;
    }
    std::cout << "\n\nEDIT";
    std::cout << "\n1) Name";
    std::cout << "\n2) Author: ";
    std::cout << "\n3) Year of publication";
    std::cout << "\n4) Availability";
    std::cout << "\n5) Cancel";
    std::cout << "\nChoose: ";

    int choosers;
    std::cin >> choosers;

    switch (choosers)
    {
    case 1:
        editName();
        break;

    case 2:
        editAuthor();
        break;

    case 3:
        editYearOfPublic();
        break;

    case 4:
        editAvailability();
        break;

    case 5: 
        break;

    default:
        std::cout << "\nWrite only numbers.";
        editBook();
        break;
    }
}

void filterAvailable() {
    std::cout << "\nFILTER AVAILABLE";
    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].availability)
        {
            std::cout << "\nName: " << booker[i].name;
            std::cout << "\nAuthor: " << booker[i].author;
            std::cout << "\nYear of publication: " << booker[i].yearOfPublication << "\n";
        }
    }
}

void filterNotAvailable() {
    std::cout << "\nFITER NOT AVAILABLE";
    for (int i = 0; i < booker.size(); i++)
    {
        if (!booker[i].availability)
        {
            std::cout << "\nName: " << booker[i].name;
            std::cout << "\nAuthor: " << booker[i].author;
            std::cout << "\nYear of publication: " << booker[i].yearOfPublication << "\n";
        }
    }
}

void filterrr() {
    std::cout << "\nAvailability filter";
    std::cout << "\n1) Available";
    std::cout << "\n2) Not available";
    std::cout << "\n3) Back";
    std::cout << "\nChoose: ";

    int chooserrr;
    std::cin >> chooserrr;
    switch (chooserrr)
    {
    case 1:
        filterAvailable();
        break;

    case 2:
        filterNotAvailable();
        break;

    case 3:
        break;

    default:
        std::cout << "\nWrite only numbers.";
        filterrr();
        break;
    }
}

void statisticsss() {
    std::cout << "\nSTATISTICS";
    std::cout << "\n----------";
    std::cout << "\nBooks: " << booker.size();
    for (int i = 0; i < booker.size(); i++)
    {
        std::sort(booker.begin(), booker.end(), [](const book& a, const book& b) {
            return a.yearOfPublication > b.yearOfPublication;
            });
    }

    int last = booker.size() - 1;

    std::cout << "\nNew: " << booker[0].name;
    std::cout << "\nOld: " << booker[last].name;
    for (int i = 0; i < booker.size(); i++)
    {
        std::sort(booker.begin(), booker.end(), [](const book& a, const book& b) {
            return a.name < b.name;
            });
    }
}

void lendBook() {
    bool bookReady = false;
    std::string nameLendBook;
    std::cout << "\nLand a book\nBook must be available.\nLand book: ";
    std::cin >> nameLendBook;

    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == nameLendBook && booker[i].availability == 1)
        {
            bookReady = true;
            break;
        }
    }
    if (!bookReady)
    {
        std::cout << "\nError: Book is not exist or book is not available.";
        return;
    }
    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == nameLendBook)
        {
            booker[i].availability = 0;
            std::cout << "\nBook was borrowed.";
        }
    }
    bookReady = false;
}

void returnBookkk() {
    std::cout << "\nReturn book\nReturn book: ";
    std::string returnBookName;
    std::cin >> returnBookName;
    bool readyReturn = false;

    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == returnBookName && booker[i].availability == 0)
        {
            readyReturn = true;
        }
    }
    if (!readyReturn)
    {
        std::cout << "\nError: Book is not exist or book is available.";
        return;
    }
    for (int i = 0; i < booker.size(); i++)
    {
        if (booker[i].name == returnBookName)
        {
            booker[i].availability = 1;
            std::cout << "\nBook returned.";
        }
    }
    readyReturn = false;
}

int main()
{
    while (runtime)
    {
        std::cout << "\n=== Library ===";
        std::cout << "\n1) Add book";
        std::cout << "\n2) List of books";
        std::cout << "\n3) Search book";
        std::cout << "\n4) Remove book";
        std::cout << "\n5) Edit book";
        std::cout << "\n6) Availability filter";
        std::cout << "\n7) Statistics";
        std::cout << "\n8) Lend a book";
        std::cout << "\n9) Return book";
        std::cout << "\n10) Terminate";
        std::cout << "\nChoose: ";

        int choose;
        std::cin >> choose;

        switch (choose)
        {
        case 1:
            addBook();
            break;

        case 2:
            listOfBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            removeBook();
            break;

        case 5:
            editBook();
            break;

        case 6:
            filterrr();
            break;

        case 7:
            statisticsss();
            break;

        case 8:
            lendBook();
            break;

        case 9:
            returnBookkk();
            break;

        case 10:
            runtime = false;
            std::cout << "\nProgram was terminated.";
            break;

        default:
            std::cout << "\nWrite only numbers.";
            break;
        }
    }
 }