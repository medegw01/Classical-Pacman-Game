/*******************************************************************************
 * Dot Class Implementation                                                    *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
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
#include "pacman.h"
/*
 * Pacman constructor
 * Purpose: to initialize private members
 * Arguments: none (constructor)
 * Return value: none (constructor)
*/
Pacman::Pacman() {
        center();
        num_moves = 0;
        score = 0;
        alive = true;
}
/* center
 * purpose: to change Pacman's location to be the center of the board
 * Argument: none
 * Return: none
 */

void Pacman::center() {
        row = ROWS / 2;
        col = COLS / 2;
        head = UP;
}
/*
* move
* Moves pacman based on an input command. This wraps Pacman
* across the borders of the board. If Pacman runs into a GHOST
* character, this sets Pacman to not be alive. If Pacman
* attempts to move into a BOULDER character, Pacman does not
* move.
* Arguments: 2D array of board and char command
* Returns: True or false
*/
bool Pacman::move(char board[ROWS][COLS], char command) {
        switch (command) {
        case CMD_UP:
                move_up(board);
                break;

        case CMD_LFT:
                move_left(board);
                break;

        case CMD_RGT:
                move_right(board);
                break;
        case CMD_DWN:
                move_down(board);
                break;
        case CMD_QUIT:
                alive = false;
                break;
        }
        num_moves++;
        if (alive == true) {
                return true;
        }
        return false;
}
/* move_up
 * purpose: move head up by a unit
 * Argument: 2D array
 * Return: none
  */
void Pacman::move_up(char board[ROWS][COLS]) {
        head = UP;
        if (board[row - 1][col] == DOT) {
                alive = true;
        } else if (board[row - 1][col] == GHOST) {
                alive = false;
        }
        if (board[row - 1][col] == BOULDER) {
                return;
        } else {
                board[row][col] = SPACE;
                if (row == 0) {
                        row = ROWS - 1; // wrap pacman when it reaches top end
                } else {
                        row--;
                }
        }
}
/* move_down
 * purpose: move head down by a unit
 * Argument: 2D array
 * Return: none
  */
void Pacman::move_down(char board[ROWS][COLS]) {
        head = DOWN;
        if (board[row + 1][col] == DOT) {
                alive = true;
        } else if (board[row + 1][col] == GHOST) {
                alive = false;
        }
        if (board[row + 1][col] == BOULDER) {
                return;
        } else {
                board[row][col] = SPACE;
                // num_moves++;
                if (row == ROWS - 1) { // wrap pacman when it reaches botton end
                        row = 0;
                } else {
                        row++;
                }
        }
}
/* move_left
 * purpose: move head down by a unit
 * Argument: 2D array
 * Return: none
 */
void Pacman::move_left(char board[ROWS][COLS]) {
        head = LEFT;
        if (board[row][col - 1] == DOT) {
                alive = true;
        } else if (board[row][col - 1] == GHOST) {
                alive = false;
        }
        if (board[row][col - 1] == BOULDER) {
                return;
        } else {
                board[row][col] = SPACE;
                if (col == 0) { // wrap pacman when it reaches left end
                        col = COLS - 1;
                } else {
                        col--;
                }
        }
}
/* move_right
* purpose: move head down by a unit
* Argument: 2D array
* Return: none
*/
void Pacman::move_right(char board[ROWS][COLS]) {
        head = RIGHT;
        if (board[row][col + 1] == DOT) {
                alive = true;
        } else if (board[row][col + 1] == GHOST) {
                alive = false;
        }
        if (board[row][col + 1] == BOULDER) {
                return;
        } else {
                board[row][col] = SPACE;
                if (col == COLS - 1) { // wrap pacman when it reaches right end
                        col = 0;
                } else {
                        col++;
                }
        }
}
/*
* place_on_board
* Purpose: to places Pacman on the board, at Pacman's location
* Arguments: 2D array of board
* Returns: None.
*/
void Pacman::place_on_board(char board[ROWS][COLS]) {
        board[row][col] = head;
}
/*
* get_num_moves
* Purpose: to return the number of moves Pacman has made
* Arguments: None
* Returns: None
*/
int Pacman::get_num_moves() {
        return num_moves;
}
/*
* set_col
* Purpose: to set value of col
* Arguments: integer
* Returns: None
*/
void Pacman::set_col(int new_col) {
        col = new_col;
}
/*
* set_row
* Purpose: to set value of row
* Arguments: integer
* Returns: None
*/
void Pacman::set_row(int new_row) {
        row = new_row;
}
/*
* get_row
* purpose:  col getters
* Arguments:none
* Returns: integer
 */
int Pacman::get_row() {
        return row;
}
/*
* get_col
* purpose:  col getter
* Arguments:none
* Returns: integer
 */
int Pacman::get_col() {
        return col;
}
/*
 * is_at
 * purpose:  to return true if the pacman is at this row and col
 * Arguments: two integers
 * Returns: true or false
  */
bool Pacman::is_at(int r, int c) {
        if (r == row && c == col) {
                return true;
        }
        return false;
}
/*
* add_to_score
* purpose:  takes an integer n, and adds n to the Pacman's score
* Arguments:an integer
* Returns: true or false
 */
void Pacman::add_to_score(int n) {
        score += n;
}
/*
*get_score
*purpose:  score getters
*Arguments:none
*Returns: integer
*/
int Pacman::get_score() {
        return score;
}
/*
*die()
*purpose: to kills Pacman
*Arguments:none
*Returns: none
*/
void Pacman::die() {
        alive = false;
}
/*
* is_alive()
* purpose:   returns true if the pacman is alive, false, otherwise
* Arguments:none
* Returns: true or false
*/
bool Pacman::is_alive() {
        return alive;
}
