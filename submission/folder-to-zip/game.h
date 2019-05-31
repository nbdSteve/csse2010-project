/*
** game.h
**
** Written by Peter Sutton
**
** Function prototypes for those functions available externally.
*/

#ifndef GAME_H_
#define GAME_H_

#include <inttypes.h>

#include <stdio.h>
#include <avr/pgmspace.h>

// The game field is 16 rows in size by 8 columns, i.e. x (column number)
// ranges from 0 to 7 (left to right) and y (row number) ranges from
// 0 to 15 (bottom to top).
#define FIELD_HEIGHT 16
#define FIELD_BASE 0
#define FIELD_WIDTH 8

// Limits on the number of asteroids and projectiles we can have on the 
// game field at any one time. (These numbers should fit within the 
// range of an int8_t type - i.e. max 127, though in reality
// there are tighter constraints than this - e.g. there are only 128
// positions on the game field.)
#define MAX_PROJECTILES 4
#define MAX_ASTEROIDS 20

// Limits for how far the base can move to the left, and to the right
#define LEFT_MOVE_LIMIT 1
#define RIGHT_MOVE_LIMIT 6

// Arguments that can be passed to move_base() below
#define MOVE_LEFT 0
#define MOVE_RIGHT 1

// Initialise the game and output the initial display
void initialise_game(void); 

// Attempt to move the base station to the left or the right. Returns
// 1 if successful, 0 otherwise (e.g. already at edge). The "direction"
// argument takes on the value MOVE_LEFT or MOVE_RIGHT (see above).
int8_t move_base(int8_t direction);

// Fire a projectile - release a projectile from the base station.
// Returns 1 if successful, 0 otherwise (e.g. already a projectile
// which is in the position immediately above the base station, or
// the maximum number of projectiles in flight has been reached.
int8_t fire_projectile(void);

void advance_asteriods(void);
// Advance the projectiles that have been fired. Any projectiles that
// go off the top or that hit an asteroid are removed.
void advance_projectiles(void);

// Returns 1 if the game is over, 0 otherwise
int8_t is_game_over(void);

// Methods
// Author: Stephen Goodhill

// Returns 1 if the game is paused, 0 otherwise
int8_t is_game_paused(void);

// Returns 1 if the player is on the death screen, 0 otherwise
int8_t is_game_death_screen(void);

// Void to pause the game, if it is paused then un-pause and vice versa
void pause_game(void);

// Updates the game and terminal when the player is dead
void update_death_screen(void);

// Runs the death animation for the player
void update_death_animation(uint8_t flash_state);

// Calls the game over animation to be played
void game_over_animation(uint8_t x, uint8_t y);

// Method to check collisions with the projectiles
void check_projectile_collisions(void);

// Method to check collisions with the asteroids
void check_asteroid_collisions(void);

// Method to check collisions with the base station
void check_base_collisions(void);

// Method to create any missing asteroids
void create_missing_asteroids(void);

#endif
