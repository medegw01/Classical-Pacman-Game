/*******************************************************************************
 * Pacman Class Interface                                                      *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q.A programmer was going for work, so his wife told him that while he *
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/
#ifndef PACMAN_H_INCLUDED
#define PACMAN_H_INCLUDED

#include "constants.h"

class Pacman {
      public:
        Pacman();

        /* changes Pacman's location to be the center of the board */
        void center();
        /*
         * Moves pacman based on an input command. This wraps Pacman
         * across the borders of the board. If Pacman runs into a GHOST
         * character, this sets Pacman to not be alive. If Pacman
         * attempts to move into a BOULDER character, Pacman does not
         * move.
         *
         * Arguments:
         *      - 2D array of board.
         *      - char command. should be CMD_LFT, CMD_RGT, CMD_UP or
         *        CMD_DWN as defined by constants.h.
         *
         * Returns: True if pacman ate a DOT character (as defined in
         *          constants.h), false otherwise.
         */
        bool move(char[ROWS][COLS], char command);

        /*
         * Places Pacman on the board, at Pacman's location
         *
         * Arguments:
         *      - 2D array of board
         *
         * Returns: None.
         */
        void place_on_board(char[ROWS][COLS]);

        /* returns the number of moves Pacman has made */
        int get_num_moves();

        /* location getters and setters */
        void set_col(int);
        void set_row(int);
        int get_col();
        int get_row();

        /* returns if the Pacman is at this row and col */
        bool is_at(int r, int c);

        /* takes an integer n, and adds n to the Pacman's score */
        void add_to_score(int n);

        /* returns the Pacman's score */
        int get_score();

        /* kills Pacman */
        void die();

        /* returns true if the pacman is alive, false, otherwise */
        bool is_alive();

      private:
        bool alive;
        char head;
        int row, col;
        int num_moves;
        int score;
        /* move head up by a unit*/
        void move_up(char[ROWS][COLS]);
        /* move head down by a unit*/
        void move_down(char[ROWS][COLS]);
        /* move head right by a unit*/
        void move_right(char[ROWS][COLS]);
        /* move head left by a unit*/
        void move_left(char[ROWS][COLS]);
};

#endif
