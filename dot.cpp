/*******************************************************************************
 * Dot Class Implementation                                                    *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)
 * Purpose: to implement the dot alogrithm of the pacman game                  *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. How can a man go eight days without sleep?                         *
 * A. He sleeps at night                                                       *
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "termfuncs.h"
#include "constants.h"
#include "dot.h"
/*
 * dot constructor
 * Purpose: to initialize private members
 * Arguments: none (constructor)
 * Return value: none (constructor)
 */
Dot::Dot() {
        row = 0;
        col = 0;
        eaten = false;
}

/*
* set_random_location
* purpose:  to chooses a random location for the dot on the board.
* Arguments: 2D array of board
* Returns: none
 */
void Dot::set_random_location(char board[ROWS][COLS]) {
        /* keep randomly choosing a location until we find a location and size
                 * that is empty*/
        row = random_int(1, ROWS - 2);
        col = random_int(1, COLS - 2);
        if (board[row][col] != SPACE) {
                set_random_location(board);
        }
}
/*
* place_on_board
* purpose:  to place dots on the board.
* Arguments: 2D array of board
* Returns: none
*/
void Dot::place_on_board(char board[ROWS][COLS]) {
        board[row][col] = DOT;
}

/*
 * is_at
 * purpose:  to returns if the Dot is at this row and col
 * Arguments: two integers
 * Returns: true or false
  */
bool Dot::is_at(int r, int c) {
        if (r == row && c == col) {
                return true;
        }
        return false;
}
/*
* set_eaten
* purpose:  to set the eaten bool
* Arguments: bool
* Returns: none
 */
void Dot::set_eaten(bool input) {
        eaten = input;
}
/*
 * set_eaten
 * purpose:  to return if the dot has been eaten
 * Arguments: none
 * Returns: true or false
  */
bool Dot::was_eaten() {
        return eaten;
}
