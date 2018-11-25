/*******************************************************************************
 * Ghost Class Implementation                                                  *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * Purpose: to move the ghost towards pacman and end game if it reaches pacman *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. How can a man go eight days without sleep?                         *
 * A. He sleeps at night                                                       *
 ******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

#include "termfuncs.h"
#include "constants.h"
#include "ghost.h"
/*
* Ghost constructor
* Purpose: to initialize private members
* Arguments: none (constructor)
* Return value: none (constructor)
*/
Ghost::Ghost() {
        row = 0;
        col = 0;
        rowGhostMove = 0;
        colGhostMove = 0;
}
/* set_location
* Purpose: for initializing location
* Arguments: integer
* Returns: None
*/
void Ghost::set_location(int r, int c) {
        row = r;
        col = c;
}
/*move
* Purpose: for implimenting the ghost movement
* Arguments: an array of strings and two integers
* Returns: true or false
*/
bool Ghost::move(char board[ROWS][COLS], int target_r, int target_c) {
        rowGhostMove = target_r - row;
        colGhostMove = target_c - col;
        if (abs(rowGhostMove) >= abs(colGhostMove)) {
                increase_row(board, rowGhostMove);

        } else if (abs(colGhostMove) >= abs(rowGhostMove)) {
                increase_col(board, colGhostMove);

        } else {
                return false;
        }
        // check if ghost reaches pacman;
        if (row == target_r || col == target_c) {
                return true;
        }
        return false;
}

/*
* place_on_board
* Purpose: to places Ghost on the board, at Ghost's location
* Arguments: 2D array of board
* Returns: None.
*/
void Ghost::place_on_board(char board[ROWS][COLS]) {
        board[row][col] = GHOST;
}

/*
 * is_at
 * purpose:  to return true if the ghost is at this row and col
 * Arguments: two integers
 * Returns: true or false
  */
bool Ghost::is_at(int r, int c) {
        if (r == row && c == col) {
                return true;
        }
        return false;
}
/* increase_row
* Purpose: to increase the ghost's col
* Arguments: 2D array of board and an integer
* Returns: None.
*/
void Ghost::increase_col(char board[ROWS][COLS], int colGhostMove) {
        if (colGhostMove >= 0) {
                if (board[row][col + 1] == GHOST) {
                        return;
                } else {
                        col++;
                }
        } else if (colGhostMove <= 0) {
                if (board[row][col - 1] == GHOST) {
                        return;
                } else {
                        col--;
                }
        }
}
/*
* increase_row
* Purpose: to increase the ghost's row
* Arguments: 2D array of board and an integer
* Returns: None.
*/
void Ghost::increase_row(char board[ROWS][COLS], int rowGhostMove) {
        if (rowGhostMove >= 0) {
                if (board[row + 1][col] == GHOST) {
                        return;
                } else {
                        row++;
                }
        } else if (rowGhostMove <= 0) {
                if (board[row - 1][col] == GHOST) {
                        return;
                } else {
                        row--;
                }
        }
}