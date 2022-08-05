#include "WindowHandler.h"

//  Prompts user for a file containg a puzzle to open and then displays the puzzle(solved or unsolved)
void openPuzzleFile(bool solved)
{
    std::cout << "Please enter the name of the file you want to open" << std::endl;
    std::string fileName;
    std::cin >> fileName;

    if (solved)
    {
        solvePuzzleFile(fileName);
        return;
    }

    unsolvedPuzzleFile(fileName);
}

// Displays the puzzle generator
void displayPuzzleCreator()
{
    std::cout << "How many words would you like in your puzzle?\n";
    std::cout << "Enter A Number: ";

    int numOfWords = 0;
    std::cin >> numOfWords;

    std::list<std::string> words;

    std::cout << "\n";
    for (int i = 0; i < numOfWords; i++)
    {
        std::cout << "Enter a word:";
        std::string word;
        std::cin >> word;

        words.push_back(word);
    }

    std::vector<std::vector<char>> solvedGrid = createPuzzleGrid(words);
    std::vector<std::vector<char>> unsolvedGrid = generateRandomCharacters(solvedGrid);

    output2DVector(unsolvedGrid);

    for (std::list<std::string>::iterator itWord = words.begin(); itWord != words.end(); ++itWord)
    {
        std::string word = *itWord;

        std::cout << word << std::endl;
    }

    std::cin.clear();

    std::cout << "\nWoud you like to save this puzzle?" << std::endl;
    std::cout << "Enter yes or no: ";

    std::string resp;
    std::cin >> resp;

    if (resp == "yes")
    {
        std::cout << "\nPlease enter a file name" << std::endl;
        std::string fileName;
        std::cin >> fileName;

        savePuzzleToFile(unsolvedGrid, solvedGrid, fileName, words);
    }

    return;
}
