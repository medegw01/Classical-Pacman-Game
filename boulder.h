
/*******************************************************************************
 * Boulder Class Interface                                                     *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * modified by: Michael Edegware                                               *
 * Date: 3/26/2016                                                             *
 * Joke: Q. A programmer was going for work, so his wife told him that while he
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/
#ifndef BOULDER_H_INCLUDED
#define BOULDER_H_INCLUDED

#include "constants.h"

class Boulder {
      public:
        /* Constructor: chooses a random location and size for the
         * boulder that doesn't overlap the middle */
        Boulder();

        /*
         * Places the Boulder on the board, at its location. Does not
         * attempt to access out of bounds slots of the array if the
         * boulder goes off the edge.
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns: None.
         */
        void place_on_board(char[ROWS][COLS]);

      private:
        int top_left_r, top_left_c, height, width;

        /* for checking if boulder overlaps the middle of the board */
        bool overlaps_middle();
};

#endif
