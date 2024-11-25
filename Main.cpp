#include <iostream>
#include <vector>
#include "Publication.h"
#include "Library.h"
#include <unordered_map>
using namespace std;

bool quit = false;

enum class Action {
    rent = 0,
    reget,
    add,
    remove,
    print,
    quit,
    number

    
};

Action StringToAction(const std::string& actionStr) {
    static const std::unordered_map<std::string, Action> actionMap = {
        {"Rent", Action::rent},
        {"Reget", Action::reget},
        {"Add", Action::add},
        {"Remove", Action::remove},
        {"Print", Action::print},
        {"Quit", Action::quit}
    };
    auto it = actionMap.find(actionStr); // Wyszukaj w mapie
    if (it != actionMap.end()) {
        return it->second; // Jeœli znaleziono, zwróæ odpowiedni¹ wartoœæ Action
    }
    else {
        cout << "Wrong Action\n";



    }
}


void Interface(Library & library) {
    std::string actionStr;
    std::cout << "Actions: Rent, Reget, Add, Remove, Print, Quit\n";
    std::cin >> actionStr;

    
        Action action = StringToAction(actionStr); // Zamiana stringa na Action

        // Obs³uga w switch
        switch (action) {
            case Action::rent:
                int id;
                std::cout << "You selected: Rent, choose ID of publication\n";
                cin >> id;
                library.RentPublication(id);
                std::cout << "Rented\n";
                break;
            case Action::reget:
                std::cout << "You selected: Reget\n";
                cin >> id;
                library.RegetPublication(id);
                std::cout << "Regeted\n";
                break;
            case Action::add:
                int type;
                std::cout << "You selected: Add. Book(1) or Article(2)\n";
                cin >> type;
                cin.ignore();
                if (type == 1) {
                    string title;
                    string author;
                    string genre;
                    int edition;
                    int year;
                    std::cout << "Type title\n";
                    std::getline(std::cin, title); 

                    std::cout << "Type author\n";
                    std::getline(std::cin, author);

                    std::cout << "Type genre\n";
                    std::getline(std::cin, genre);

                    std::cout << "Type edition\n";
                    cin >> edition;
                    cin.ignore();

                    std::cout << "Type year\n";
                    cin >> year;
                    cin.ignore();

                    library.AddPublication(std::make_shared<Book>(title, year, author, genre, edition));

                }
                if (type == 2) {
                    string title;
                    string author;
                    string type;
                    int pubNumber;
                    int year;
                    int pages;
                    std::cout << "Type title\n";
                    std::getline(std::cin, title);

                    std::cout << "Type author\n";
                    std::getline(std::cin, author);

                    std::cout << "Type type\n";
                    std::getline(std::cin, type);

                    std::cout << "Type pages\n";
                    cin >> pages;
                    cin.ignore();

                    std::cout << "Type year\n";
                    cin >> year;
                    cin.ignore();

                    std::cout << "Type Publication Number\n";
                    cin >> pubNumber;
                    cin.ignore();

                    library.AddPublication(std::make_shared<Article>(title, year, author, type, pubNumber, pages));
                    
                }


                break;
            case Action::remove:
                std::cout << "You selected: Remove\n";
                cin >> id;
                library.RemovePublication(id);
                

                break;
            case Action::print:
                std::cout << "You selected: Print\n";
                library.PrintCollection();
                break;
            case Action::quit:
                std::cout << "You selected: Quit\n";
                quit = true;
                break;
            default:
                std::cout << "Unknown action.\n";
        }
}

int main() {

    Library library;

    auto book1 = std::make_shared<Book>("C++ Programming", 2000, "Test Author", "Programming", 1);
    auto article1 = std::make_shared<Article>("DailyNews", 2022, "Test Author2", "Report", 101, 12);
    library.AddPublication(book1);
    library.AddPublication(article1);
    

    while (!quit) {
        Interface(library);
    }

   

    return 0;


	
}