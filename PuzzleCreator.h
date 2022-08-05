/**
    Generates a random word search puzzle using the specificed words
    @file PuzzleCreator.h
    @author Evan
    @version 1.1.9 8/5/2022
*/

#ifndef _PUZZLECREATOR_H
#define _PUZZLECREATOR_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

/**
    Gets the longest word from a specificed list of words
    @param words A list of words.
    @return The length of the longest word.
*/
int getLongestWord(std::list<std::string> words);

/**
    Prints out a 2D vector array
    @param vect A 2D vector array
*/
void output2DVector(std::vector<std::vector<char>> vect);

/**
    Increases the grid size of a given 2D Vector array by a specificed amount
    @param grid A pointer to a 2D vector array.
    @param x The number to increase the array size by.
*/
void increaseGridSize(std::vector<std::vector<char>> *grid, int x);

/**
    Checks if a word will fit within the specified grid using the coordinates, orientation, and direction
    @param word The word to check against the grid.
    @param grid The word search grid to check against.
    @param x The starting X coordinate of the word within the grid.
    @param y The starting Y coordinate of the word within the grid.
    @param orientation The orientation of the word when placed( If the word reads backwards or forwards ).
    @param direction The direction of the word when placed( Vertical or Horizontal ).
    @return Whether or not the position is a valid position within the grid for the word.
*/
bool validPosition(std::string word, std::vector<std::vector<char>> grid, int x, int y, int orientation, int direction);

/**
    Main aglorithm that obtains random coordinates, orientation, and direction for a word on a grid
    @param word The word to check against the grid.
    @param grid A pointer to the grid to check against.
    @param x The starting X coordinate of the word within the grid.
    @param y The starting Y coordinate of the word within the grid.
    @param orientation The orientation of the word when placed( If the word reads backwards or forwards ).
    @param direction The direction of the word when placed( Vertical or Horizontal ).
*/
void pickWordPosition(std::string word, std::vector<std::vector<char>> *grid, int *x, int *y, int *orientation, int *direction);

/**
    Fills in the spaces around the words once placed on the grid
    @param grid The solved grid with empty spaces bettwen its words.
    @return A grid with random characters between its words.
*/
std::vector<std::vector<char>> generateRandomCharacters(std::vector<std::vector<char>> grid);

/**
    Places the word on the given grid
    @param word Word to place on the grid.
    @param grid Grid to place the word in.
*/
void placeWordInGrid(std::string word, std::vector<std::vector<char>> *grid);

/**
    Generates a random solved word search with the given words
    @param words Words to use when generating the word search.
    @return A solved word search grid containing the specificed words.
*/
std::vector<std::vector<char>> createPuzzleGrid(std::list<std::string> puzzleWords);

#endif