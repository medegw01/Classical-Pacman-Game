/*******************************************************************************
 * Ghost Class Interface                                                       *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. A programmer was going for work, so his wife told him that while he
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/
#ifndef GHOST_H_INCLUDED
#define GHOST_H_INCLUDED

#include "constants.h"

class Ghost {
      public:
        Ghost();

        /* for initializing location */
        void set_location(int row, int col);

        /* moves the ghost towards the given target (row and column).
         * ghosts can move through anything on the board, but they
         * cannot move through walls.
         * Returns: true if the ghost reaches the taget, and false
         * otherwise. */
        bool move(char[ROWS][COLS], int target_r, int target_c);

        /* places the ghost on the given board, at its location */
        void place_on_board(char[ROWS][COLS]);

        /* returns true if the ghost is at this row and column, false
         * otherwise */
        bool is_at(int r, int c);

      private:
        int row, col;
        int rowGhostMove;
        int colGhostMove;
        /* helper function for the ghost move function to help increase the
         * row*/
        void increase_row(char board[ROWS][COLS], int rowGhostMove);
        /* helper function for the ghost move function to help increase the
         * col*/
        void increase_col(char board[ROWS][COLS], int colGhostMove);
};
#endif
