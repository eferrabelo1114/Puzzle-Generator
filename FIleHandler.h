/**
    Handles the file saving/loading for the puzzle applicaiton.
    @file FileHandler.h
    @author Ethan Ferrabelo
    @version 1.0.3 8/5/2022
*/

#ifndef _FILEHANDLER_H
#define _FILEHANDLER_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <fstream>
#include <limits>

/**
    Finds the line number in which a given data header is located on within a given file
    @param puzzleFile a reference to the file to search through.
    @param dataHeader the key header to look for in the file.
    @return the line number that contains the header in the file
*/
int FindInFile(std::fstream &puzzleFile, std::string dataHeader);

/**
    Traverses the file stream until we reach the given line number
    @param file a reference to the file to traverse.
    @param num the line number to travers to.
    @return a file stream that begins at the given line number
*/
std::fstream &gotoLine(std::fstream &file, unsigned int num);

/**
    Returns the chunk of data that correlates with the specificed data header within the file
    @param fileName the name of the file to open.
    @param dataHeader the name of the data to extract.
    @return a string containing the chunk of data.
*/
std::string getDataPieceFromFile(std::string fileName, std::string dataHeader);

/**
    Saves a puzzle 2D array with it's unsolved and solved counterpats aswell as its words to the specificed file name
    @param unsolvedGrid the unsolved word search grid.
    @param solvedGrid the solved word search grid.
    @param fileName the name of the file to save to. Do not include ".txt" at the end of the name.
    @param words the words associated with the word search grid.
*/
void savePuzzleToFile(std::vector<std::vector<char>> unsolvedGrid, std::vector<std::vector<char>> solvedGrid, std::string fileName, std::list<std::string> words);

/**
    Opens and displays an unsolved puzzle from the specificed file
    @param fileName the name of the file to open.
*/
void unsolvedPuzzleFile(std::string fileName);

/**
    Opens and displays a solved puzzle from the specificed file
    @param fileName the name of the file to open.
*/
void solvePuzzleFile(std::string fileName);

#endif