/*
 * lives.h
 *
 * Created: 16/05/2019 6:41:30 PM
 *  Author: Steve
 */ 


#ifndef LIVES_H_
#define LIVES_H_

#include <stdint.h>

// Initialises the lives
void init_lives(void);

// Decreases the remaining lives by the respective value
void decrement_lives(uint16_t value);

// Returns the number of lives remaining
uint32_t get_remaining_lives(void);

// Constant for the number of starting lives
#define STARTING_LIVES 4;

#endif /* LIVES_H_ */