#include "PuzzleCreator.h"

// Gets the longest word from a specificed list of words
int getLongestWord(std::list<std::string> words)
{
    int longest = 0;

    for (std::list<std::string>::iterator itWord = words.begin(); itWord != words.end(); ++itWord)
    {
        std::string word = *itWord;

        if (word.length() > longest)
        {
            longest = word.length();
        }
    }

    return longest;
}

// Prints out a 2D vector array
void output2DVector(std::vector<std::vector<char>> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            std::cout << vect[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Increases the grid size of a given 2D Vector array by a specificed amount
void increaseGridSize(std::vector<std::vector<char>> *grid, int x)
{
    for (int i = 0; i < x; i++)
    {
        for (int i = 0; i < (*grid).size(); i++)
        {
            (*grid)[i].push_back(' ');
        }
    }

    std::vector<char> row;
    for (int j = 0; j < (*grid).size() + x; j++)
    {
        row.push_back(' ');
    }

    (*grid).push_back(row);
}

// Checks if a word will fit within the specified grid using the coordinates, orientation, and direction
/*
    TODO: This algo is a bit wonky
*/
bool validPosition(std::string word, std::vector<std::vector<char>> grid, int x, int y, int orientation, int direction)
{
    int gridLength = grid.size();

    if (direction == 0) // Word is being placed horizontally
    {
        if ((gridLength - x) < word.length())
        {
            return false;
        }

        int wordIndex = 0;

        if (orientation == 0) // Word is being placed backwards
        {
            wordIndex = word.length() - 1;
        }

        for (int i = x; i <= (x + (word.length() - 1)); i++)
        {
            if (grid[y][i] != ' ' && grid[y][i] != word.at(wordIndex))
            {
                return false;
            }
            else if (grid[y][i] != ' ' && grid[y][i] == word.at(wordIndex))
            {
                if (wordIndex == 0)
                {
                    return false;
                }
            }

            if (orientation == 0)
            {
                wordIndex--;

                continue;
            }

            wordIndex++;
        }

        return true;
    }

    else if (direction == 1) // Word is being placed vertically
    {
        if ((gridLength - y) < word.length())
        {
            return false;
        }

        int wordIndex = 0;
        if (orientation == 0) // Word is being placed backwards
        {
            wordIndex = word.length() - 1;
        }

        for (int i = y; i <= (y + (word.length() - 1)); i++)
        {
            if (grid[i][x] != ' ' && grid[i][x] != word.at(wordIndex))
            {
                return false;
            }
            else if (grid[i][x] != ' ' && grid[i][x] == word.at(wordIndex))
            {
                if (wordIndex == 0)
                {
                    return false;
                }
            }

            if (orientation == 0)
            {
                wordIndex--;
                continue;
            }

            wordIndex++;
        }

        return true;
    }

    return false;
}

// Main aglorithm that obtains random coordinates, orientation, and direction for a word on a grid
void pickWordPosition(std::string word, std::vector<std::vector<char>> *grid, int *x, int *y, int *orientation, int *direction)
{
    int gridLength = (*grid).size();

    *x = rand() % gridLength;
    *y = rand() % gridLength;

    *orientation = rand() % 2;
    *direction = rand() % 2;

    int iteration = 1;

    while (!validPosition(word, *grid, *x, *y, *orientation, *direction))
    {
        int gridLength = (*grid).size();

        *x = rand() % gridLength;
        *y = rand() % gridLength;

        *orientation = rand() % 2;
        *direction = rand() % 2;

        if (iteration >= 50)
        {
            increaseGridSize(grid, 1);
            iteration = 1;
        }

        iteration++;
    }
}

// Fills in the spaces around the words once placed on the grid
std::vector<std::vector<char>> generateRandomCharacters(std::vector<std::vector<char>> grid)
{
    std::vector<std::vector<char>> unsolvedGrid = grid;

    for (int i = 0; i < unsolvedGrid.size(); i++)
    {
        for (int j = 0; j < unsolvedGrid[i].size(); j++)
        {

            if (unsolvedGrid[i][j] == ' ')
            {
                unsolvedGrid[i][j] = 'a' + rand() % 26;
            }
        }
    }

    return unsolvedGrid;
}

// Places the word on the given grid
void placeWordInGrid(std::string word, std::vector<std::vector<char>> *grid)
{
    int x, y, direction, orientation;

    pickWordPosition(word, grid, &x, &y, &orientation, &direction);

    if (direction == 0)
    {

        int wordIndex = 0;

        if (orientation == 0)
        {
            wordIndex = word.length() - 1;
        }

        for (int i = x; i <= (x + (word.length() - 1)); i++)
        {
            (*grid)[y][i] = word.at(wordIndex);
            if (orientation == 0)
            {
                wordIndex--;
                continue;
            }

            wordIndex++;
        }
    }
    else if (direction == 1)
    {
        int wordIndex = 0;

        if (orientation == 0)
        {
            wordIndex = word.length() - 1;
        }

        for (int i = y; i <= (y + (word.length() - 1)); i++)
        {
            (*grid)[i][x] = word.at(wordIndex);

            if (orientation == 0)
            {
                wordIndex--;
                continue;
            }

            wordIndex++;
        }
    }
}

// Generates a random solved word search with the given words
std::vector<std::vector<char>> createPuzzleGrid(std::list<std::string> puzzleWords)
{
    int longestWord = getLongestWord(puzzleWords);

    std::vector<std::vector<char>> grid;

    for (int i = 0; i < longestWord; i++)
    {
        std::vector<char> row;

        for (int j = 0; j < longestWord; j++)
        {
            row.push_back(' ');
        }

        grid.push_back(row);
    }

    for (std::list<std::string>::iterator itWord = puzzleWords.begin(); itWord != puzzleWords.end(); ++itWord)
    {
        std::string word = *itWord;

        placeWordInGrid(word, &grid);
    }

    return grid;
}
