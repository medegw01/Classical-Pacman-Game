/*******************************************************************************
 * Game Class Interface                                                        *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)                           *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. A programmer was going for work, so his wife told him that while he
 *       is out, he should get some decorations for her. He never came back.   *
 ******************************************************************************/

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "boulder.h"

class Game {
      public:
        // contructor
        Game();

        // prints the manual and stalls until the user types a character
        void print_manual();
        // Runs the Pacman game!
        void run();

      private:
        char board[ROWS][COLS];
        // helper function to  print current state of game
        void display_game();
        // helper function to check if pacman eats food
        // and  returns true if dot is left and false when dot is finished.
        bool pacman_eat_food(char board[ROWS][COLS]);
        // assign ghost to it's index
        void initialize_ghost();
        // to switch through levels
        void change_level(int level);
        // clear board
        void clear_board(char board[ROWS][COLS]);
        // helper function to assign oot elements to each arry index
        void helper_dots(char board[ROWS][COLS]);
        // helper function to assign oot elements to each arry index
        void is_pacman_dead();
        // helper function to assign oot elements to each arry index
        void helper_boulder(char board[ROWS][COLS]);
        // helper function to assign oot elements to each arry index
        void helper_ghosts(char board[ROWS][COLS]);
        // function to display message before the start of each level
        void display_message_after_gameEnd(int level);
        // function to display message after game ends
        void display_message_at_eachLevel(int level);
        // a function that plays the game within levels
        void play_game_within_level();
        char input;
        Pacman p;
        Ghost ghosts[NUM_GHOSTS];
        Dot dots[NUM_DOTS];
        Boulder boulders[NUM_BOULDERS];
        int r;
        int c;
        int num_dots_in_level;
        int num_boulder_in_level;
        int level;
};

#endif
