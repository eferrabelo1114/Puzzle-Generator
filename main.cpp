#include "WindowHandler.h"

void displayMenu()
{
    std::cin.clear();

    std::cout << "\nWelcome to the puzzle maker 3000" << std::endl;
    std::cout << "\n[c] Create New Puzzle" << std::endl;
    std::cout << "[o] Open Puzzle" << std::endl;
    std::cout << "[s] Solve Puzzle" << std::endl;
    std::cout << "[e] Exit \n"
              << std::endl;
    std::cout << "Enter Menu Option:";

    char input;
    std::cin >> input;

    switch (input)
    {
    case 'c':
        displayPuzzleCreator();
        break;
    case 'o':
        openPuzzleFile(false);
        break;
    case 's':
        openPuzzleFile(true);
        break;
    case 'e':
        std::cout << "Thank you for using the puzzle maker 3000!" << std::endl;
        return;
    default:
        std::cout << "Invalid Input" << std::endl;
        break;
    }

    displayMenu();
}

int main()
{
    displayMenu();
    return 0;
}
