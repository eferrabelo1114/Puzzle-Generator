cmake_minimum_required(VERSION 3.18)
project(WordSearch)

set(CMAKE_CXX_STANDARD 14)

add_executable(WordSearch main.cpp FileHandler.cpp PuzzleCreator.cpp FileHandler.h PuzzleCreator.h WindowHandler.cpp WindowHandler.h)
