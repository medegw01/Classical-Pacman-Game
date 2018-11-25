/*******************************************************************************
 * Dot Class Interface                                                         *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. A programmer was going for work, so his wife told him that while he
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/
#ifndef DOT_H_INCLUDED
#define DOT_H_INCLUDED

#include "constants.h"

class Dot {
      public:
        /* Constructor initalizes private members */
        Dot();

        /*
         * Chooses a random location for the dot on the board. This
         * function chooses a location that is occupied by a space.
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns:
         *      - None
         */
        void set_random_location(char[ROWS][COLS]);

        /*
         * Places the Dot on the board, at its location.
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns: None.
         */
        void place_on_board(char[ROWS][COLS]);

        /* returns if the Dot is at this row and col */
        bool is_at(int r, int c);

        /* sets eaten to be the passed-in bool */
        void set_eaten(bool);

        /* returns if the dot has been eaten */
        bool was_eaten();

      private:
        int row, col;
        bool eaten;
};

#endif
