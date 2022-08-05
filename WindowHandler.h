/**
    Handles the application's windows
    @file PuzzleCreator.h
    @author Evan
    @version 1.0.0 8/5/2022
*/

#ifndef _WINDOWHANDLER_H
#define _WINDOWHANDLER_H

#include <iostream>
#include <string>
#include <vector>

#include "PuzzleCreator.h"
#include "FileHandler.h"

/**
    Prompts user for a file containg a puzzle to open and then displays the puzzle(solved or unsolved)
    @param solved Whether or not to display the puzzle solved.
*/
void openPuzzleFile(bool solved);

/**
    Displays the puzzle generator
*/
void displayPuzzleCreator();

#endif