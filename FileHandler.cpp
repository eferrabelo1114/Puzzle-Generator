#include "FileHandler.h"

// Finds the line number in which a given data header is located on within a given file
int FindInFile(std::fstream &puzzleFile, std::string dataHeader)
{
    std::string line;
    int lineNum = 1;

    while (getline(puzzleFile, line))
    {
        if (line == dataHeader)
        {
            return lineNum;
        }

        lineNum++;
    }

    return -1;
}

// Traverses the file stream until we reach the given line number
std::fstream &gotoLine(std::fstream &file, unsigned int num)
{
    file.seekg(std::ios::beg);

    for (int i = 0; i < num - 1; ++i)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return file;
}

// Returns the chunk of data that correlates with the specificed data header within the file
std::string getDataPieceFromFile(std::string fileName, std::string dataHeader)
{
    std::string line;
    std::string dataStream;

    std::fstream puzzleFile(fileName + ".txt");

    int lineNum = FindInFile(puzzleFile, dataHeader);

    if (lineNum != -1)
    {
        if (puzzleFile.is_open())
        {
            std::fstream &puzzleStream = gotoLine(puzzleFile, lineNum + 1);
            getline(puzzleStream, dataStream);

            while (getline(puzzleStream, line))
            {
                if (line.empty())
                {
                    break;
                }

                dataStream += "\n" + line;
            }

            return dataStream;
        }
    }

    return "NOT FOUND";
}

// Saves a puzzle 2D array with it's unsolved and solved counterpats aswell as its words to the specificed file name
void savePuzzleToFile(std::vector<std::vector<char>> unsolvedGrid, std::vector<std::vector<char>> solvedGrid, std::string fileName, std::list<std::string> words)
{
    std::ofstream puzzleFile;
    puzzleFile.open(fileName + ".txt");

    puzzleFile << "\nUNSOLVED_GRID\n";
    for (int i = 0; i < unsolvedGrid.size(); i++)
    {
        for (int j = 0; j < unsolvedGrid[i].size(); j++)
        {
            puzzleFile << unsolvedGrid[i][j] << " ";
        }

        puzzleFile << "\n";
    }

    puzzleFile << "\nPUZZLE_WORDS\n";
    for (std::list<std::string>::iterator itWord = words.begin(); itWord != words.end(); ++itWord)
    {
        std::string word = *itWord;

        puzzleFile << word << std::endl;
    }

    puzzleFile << "\nSOLVED_GRID\n";
    for (int i = 0; i < solvedGrid.size(); i++)
    {
        for (int j = 0; j < solvedGrid[i].size(); j++)
        {
            puzzleFile << solvedGrid[i][j] << " ";
        }
        puzzleFile << "\n";
    }

    puzzleFile.close();
}

// Opens and displays an unsolved puzzle from the specificed file
void unsolvedPuzzleFile(std::string fileName)
{
    std::string grid = getDataPieceFromFile(fileName, "UNSOLVED_GRID");
    std::string puzzleWords = getDataPieceFromFile(fileName, "PUZZLE_WORDS");

    std::cout << grid << std::endl;
    std::cout << "\n"
              << puzzleWords << std::endl;
}

// Opens and displays a solved puzzle from the specificed file
void solvePuzzleFile(std::string fileName)
{
    std::string grid = getDataPieceFromFile(fileName, "SOLVED_GRID");
    std::string puzzleWords = getDataPieceFromFile(fileName, "PUZZLE_WORDS");

    std::cout << grid << std::endl;
    std::cout << "\n"
              << puzzleWords << std::endl;
}