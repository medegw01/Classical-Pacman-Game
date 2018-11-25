/*******************************************************************************
 * Game Class Implementation                                                   *
 * For Pacman Game (COMP 11 Project 1 | 2016 Spring)
 * Purpose: to combine different classes of the game and run the whole game    *
 * written by: Michael Edegware                                                *
 * Date: 3/26/2016                                                             *
 * Joke: Q. How can a man go eight days without sleep?                         *
 * A. He sleeps at night                                                       *
*******************************************************************************/

#include <iostream>
using namespace std;

#include "game.h"
#include "pacman.h"
#include "ghost.h"
#include "dot.h"
#include "termfuncs.h"

/* Constructor: initilize the private members*/
Game::Game() {
        r = 0;
        c = 0;
        num_dots_in_level = 0;
        num_boulder_in_level = 0;
        level = 0;
}
/* print_manual()
 * Purpose:   Prints the manual and stalls until the user types a character
 * Arguments: None
 * Returns:   None
 */
void Game::print_manual() {
        screen_clear();
        cout << "PACMAN GAME\n"
                "            \n"
                " Move left:    "
             << CMD_LFT << "\n"
                           " Move right:   "
             << CMD_RGT << "\n"
                           " Move up:      "
             << CMD_UP << "\n"
                          " Move down:    "
             << CMD_DWN << "\n"
                           " Quit:         "
             << CMD_QUIT << "\n"
                            "\n"
                            " Collect all the dots. They look like: "
             << DOT << "\n"
                       " Avoid the ghosts.     They look like: "
             << GHOST << "\n"
                         "\n"
                         " Good luck!\n"
                         "\n"
                         " Press any key to continue...\n";

        getachar();
}
/* clear_board()
 * Purpose:   helper function to  clear the board
 * Arguments: array of strings
 * Returns:   None
 */
void Game::clear_board(char board[ROWS][COLS]) {
        for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                        board[r][c] = SPACE;
                }
        }
}
/* display_game()
 * Purpose:   helper function to  print current state of game such that
 *            the boarders are not in the array
 * Arguments: None
 * Returns:   None
 */
void Game::display_game() {
        cout << BORD_CORN;
        for (int i = 0; i < 3 * ROWS - 2; i++) {
                cout << BORD_TOP;
        }
        cout << BORD_CORN << endl;
        for (int r = 0; r < ROWS; r++) {
                cout << BORD_SIDE;
                for (int c = 0; c < COLS; c++) {
                        cout << board[r][c];
                }
                cout << BORD_SIDE << endl;
        }
        cout << BORD_CORN;
        for (int i = 0; i < 3 * ROWS - 2; i++) {
                cout << BORD_TOP;
        }
        cout << BORD_CORN << endl;
        cout << "Score: " << p.get_score() << endl;
}
/* pacman_eat_food()
 * Purpose:   a helper function to indicate help pacman eat dots
 * Arguments: None
 * Returns:   true or false
 */
bool Game::pacman_eat_food(char board[ROWS][COLS]) {
        r = p.get_row();
        c = p.get_col();
        for (int i = 0; i < num_dots_in_level; i++) {
                if (!dots[i].was_eaten()) {
                        if (dots[i].is_at(r, c)) {
                                dots[i].set_eaten(true);
                                p.add_to_score(DOT_REWARD);
                        }
                }
        }
        for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                        if (board[i][j] == DOT) {
                                return true;
                        }
                }
        }
        return false;
}
/* initialize_ghost()
 * Purpose:   to initialize ghost to the four corners of board
 * Arguments: None
 * Returns:   None
 */
void Game::initialize_ghost() {
        ghosts[0].set_location(GHOST_INITIAL_POS, GHOST_INITIAL_POS);
        ghosts[1].set_location(ROWS - 1, GHOST_INITIAL_POS);
        ghosts[2].set_location(GHOST_INITIAL_POS, COLS - 1);
        ghosts[3].set_location(ROWS - 1, COLS - 1);
}
/* helper_dots(board[ROWS][COLS])
 * Purpose:  to populate the array of dots
 * Arguments: array of strings
 * Return: None
 */
void Game::helper_dots(char board[ROWS][COLS]) {
        for (int i = 0; i < num_dots_in_level; i++) {
                dots[i].set_random_location(board);
                dots[i].set_eaten(false);
                dots[i].place_on_board(board);
        }
}

/* helper_boulders(board[ROWS][COLS])
 * Purpose:  to populate the array of boulders
 * Arguments: array of strings
 * Return: None
 */
void Game::helper_boulder(char board[ROWS][COLS]) {
        for (int i = 0; i < num_boulder_in_level; i++) {
                boulders[i].place_on_board(board);
        }
}

/* helper_ghost(board[ROWS][COLS])
 * Purpose:  to populate the array of ghosts
 * Arguments: array of strings
 * Return: None
 */
void Game::helper_ghosts(char board[ROWS][COLS]) {
        for (int i = 0; i < NUM_GHOSTS; i++) {
                ghosts[i].move(board, r, c);
                ghosts[i].place_on_board(board);
        }
}
/* is_pacman_dead()
  * Purpose: an helper function to kill pacman
  * Arguments:integer
  * Return: none
  */
void Game::is_pacman_dead() {
        for (int i = 0; i < NUM_GHOSTS; i++) {
                if (ghosts[i].is_at(r, c)) {
                        p.die();
                }
        }
}

/* change_level(int level)
  * Purpose:to change to another level when all dots are eaten and
            pacman is stilol alive
  * Arguments:integer
  * Return: none
  */
void Game::change_level(int level) {
        num_dots_in_level = level * DOTS_PER_LEVEL;
        num_boulder_in_level = level * BOULDERS_PER_LEVEL;
}
/* display_message_after_gameEnd(int)
 * Purpose:   to display message when game is over
 * Arguments: integer
 * Returns:   None
 */
void Game::display_message_after_gameEnd(int level) {
        screen_clear();
        display_game();
        if (level >= NUM_LEVELS) {
                cout << "You Won :)" << endl;
        } else {
                cout << "You lost :(" << endl;
        }
}
/* display_message_at_eachLevel(int)
 * Purpose:   to display message at the begining of each level
 * Arguments: integer
 * Returns:   None
 */
void Game::display_message_at_eachLevel(int level) {
        display_game();
        cout << "Level"
             << " " << level << ":";
        cout << " "
             << "Press any key to start" << endl;
}
/* play_game_within_level()
 * Purpose:   to play game within levels the game
 * Arguments: None
 * Returns:   None
 */
void Game::play_game_within_level() {
        // game runs when all dots have not been eaten or if pacman is alife
        while (p.is_alive() && pacman_eat_food(board)) {
                is_pacman_dead();
                clear_board(board);
                helper_boulder(board);
                for (int i = 0; i < num_dots_in_level;
                     i++) { // print only uneaten dots
                        if (!dots[i].was_eaten()) {
                                dots[i].place_on_board(board);
                        }
                }
                p.place_on_board(board);
                if (p.get_num_moves() % GHOST_FREQ == 0) {
                        helper_ghosts(board);
                } else { // p.increase_number_move();
                        for (int i = 0; i < NUM_GHOSTS; i++) {
                                ghosts[i].place_on_board(board);
                        }
                }
                screen_clear();
                display_game();
                if (!pacman_eat_food(board)) {
                        screen_clear();
                        return;
                }
                input = getacharnow(SPEED);
                p.move(board, input);
                screen_clear();
        }
}

/* run()
 * Purpose:   to run the game
 * Arguments: None
 * Returns:   None
 */
void Game::run() {
        screen_clear();
        // for loop to change levels
        for (int k = 1; k <= NUM_LEVELS; k++) {
                change_level(k);
                level++;            // check the current level
                clear_board(board); // clear board at the start of each level
                initialize_ghost();
                helper_boulder(board);
                p.center();
                p.place_on_board(board);
                helper_ghosts(board);
                helper_dots(board);
                display_message_at_eachLevel(k);
                getachar(); // press any key to start a level
                screen_clear();
                play_game_within_level();
                if (!p.is_alive()) { // check if pacman is alive or dead then
                                     // end game if dead
                        break;
                } else {
                        p.add_to_score(LEVEL_REWARD);
                }
        }
        display_message_after_gameEnd(level);
}
