# Sudoku-Solver


A Sudoku is a number-placement puzzle. An n×n grid has n rows, n columns and n blocks (which is made of
a k × k grid of cells, where n = k
2
). Some cells will have numbers already, and the goal is to place a number
from {1, . . . , n} into each cell, such that each row, column and block contains every number once and only
once. A valid Sudoku puzzle should have one unique solution.

## About:

This C++ program is a Sudoku solver that can handle a 9x9 grid, but it is designed to be extendable for larger grids with more symbols. The grid cells can contain numbers or letters, making it versatile for different Sudoku variations.

Key Features:
Matrix Representation: The Sudoku grid is represented as a 9x9 matrix (2D array of characters).

Value Validation: The function isSafe() checks whether a given value can be placed in a specific cell without violating the Sudoku rules (i.e., no duplicate values in the same row, column, or 3x3 subgrid).

Allowed Values Calculation: The function allowedValues() generates a list of all possible values that can be placed in a particular cell, considering the current state of the board.

Caching Valid Values: The function cacheValidValues() precomputes and stores possible values for all empty cells, which optimizes the solving process.

Backtracking Solver: The main solving function, solveSudoku(), uses a backtracking algorithm to fill in the grid. It tries each possible value for each empty cell and backtracks if it encounters an invalid configuration.

Interactive Input: The program accepts a 9x9 grid as input where '0' represents empty cells that need to be filled.

Output: The program prints the solved Sudoku grid if a solution is found or notifies the user if no solution exists.
