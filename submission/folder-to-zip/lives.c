/*
 * lives.c
 *
 * Created: 16/05/2019 6:40:53 PM
 *  Author: Steve
 */ 

#include "lives.h"
#include <avr/io.h>

uint32_t remaining_lives;
uint8_t ioboard_led[4] = {0x00,0x02,0x06,0x07};//{0xF0, 0xF4, 0xF6, 0xF7}; {0x00,0x04,0x06,0x07}; //{0b0000, 0b0010, 0b0110, 0b0111};


// Initialise the players lives
void init_lives(void) {
	remaining_lives = STARTING_LIVES;
	DDRA = 0x0F;
	PORTA = 0x0F;
}

// Decreases the number of lives remaining by the given value
void decrement_lives(uint16_t value) {
	remaining_lives -= value;
	PORTA = ioboard_led[remaining_lives];
}

// Returns the number of lives remaining
uint32_t get_remaining_lives(void) {
	return remaining_lives;
}