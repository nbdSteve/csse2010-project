/*
 * ssd.c
 *
 * Created: 15/05/2019 11:20:47 AM
 *  Author: Steve
 */ 

#include <avr/io.h>
#include "score.h"

// Convert all of the decimal inputs to hex
uint8_t seven_seg[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
volatile uint8_t digit = 0x04;
static uint8_t initialised = 0;
	
// Initialise the 7 segment display
void init_ssd(void) {
	DDRC = 0xFF;
	DDRD = 0x04;
	// Set this to 1 when the 7 segment display has been intialised
	initialised = 1;
}

void update_ssd(void) {
	// If the display is not intialised do nothing
	if (initialised == 0) return;	
	// Alternative method for the 7 segment display
	if (get_score() < 10) {
		PORTD = 0x02;
		PORTC = seven_seg[get_score()];
	} else {
		if (digit == 0x04) {
			PORTC = seven_seg[get_score() % 10];
			digit = 0x02;
		} else {
			PORTC = seven_seg[(get_score() / 10) % 10];
			digit = 0x04;
		}
		PORTD = digit;
	}
}