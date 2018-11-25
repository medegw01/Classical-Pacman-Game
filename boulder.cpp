/*******************************************************************************
 * Boulder Class Implementation                                                *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * Purpose: to place boulder on empty space but center of the board  and       *
 *          changes number of boulder in respect to the level                  *
 * modified by: Michael Edegware                                               *
 * Date: 3/26/2016                                                             *
 * Joke: Q. A programmer was going for work, so his wife told him that while he*
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/

#include <iostream>
using namespace std;

#include "termfuncs.h"
#include "constants.h"
#include "boulder.h"

/*
 * boulder constructor
 * Purpose: To construct a boulder that does not overlap the middle
 *          (so we can put pac-man in the middle to start)
 * Arguments: none (constructor)
 * Return value: none (constructor)
 */
Boulder::Boulder() {
        /* keep randomly choosing a location until we find a location and size
         * that doesn't overlap the middle */
        do {
                top_left_r = random_int(0, ROWS - 1);
                top_left_c = random_int(0, COLS - 1);
                height = random_int(MIN_BOULDER_HEIGHT, MAX_BOULDER_HEIGHT);
                width = random_int(MIN_BOULDER_WIDTH, MAX_BOULDER_WIDTH);
        } while (overlaps_middle());
}

/*
 * place_on_board
 * Purpose: places the boulder onto the 2D board
 * Arguments: a 2D char board
 * Returns: none
 */
void Boulder::place_on_board(char board[ROWS][COLS]) {
        for (int r = top_left_r; r <= top_left_r + height; r++) {
                for (int c = top_left_c; c <= top_left_c + width; c++) {
                        if (r < ROWS - 2 and c < COLS - 2) {
                                board[r][c] = BOULDER;
                        }
                }
        }
}

/*
 * Purpose: determines if the current boulder overlaps the middle position
 *          on the board
 * Arguments: none
 * Returns: true if the boulder would overlap the middle position,
 *               false otherwise
 */
bool Boulder::overlaps_middle() {
        bool center_row =
            (ROWS / 2) >= top_left_r and (ROWS / 2) <= (top_left_r + height);

        bool center_col =
            (COLS / 2) >= top_left_c and (COLS / 2) <= (top_left_c + width);

        return (center_row and center_col);
}
