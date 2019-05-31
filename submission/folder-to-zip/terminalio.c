/*
 * terminalio.c
 *
 * Author: Peter Sutton
 */

#include "terminalio.h"

void move_cursor(int x, int y) {
    printf_P(PSTR("\x1b[%d;%dH"), y, x);
}

void normal_display_mode(void) {
	printf_P(PSTR("\x1b[0m"));
}

void reverse_video(void) {
	printf_P(PSTR("\x1b[7m"));
}

void clear_terminal(void) {
	printf_P(PSTR("\x1b[2J"));
}

void clear_to_end_of_line(void) {
	printf_P(PSTR("\x1b[K"));
}

void set_display_attribute(DisplayParameter parameter) {
	printf_P(PSTR("\x1b[%dm"), parameter);
}

void hide_cursor() {
	printf_P(PSTR("\x1b[?25l"));
}

void show_cursor() {
	printf_P(PSTR("\x1b[?25h"));
}

void enable_scrolling_for_whole_display(void) {
	printf_P(PSTR("\x1b[r"));
}

void set_scroll_region(int8_t y1, int8_t y2) {
	printf_P(PSTR("\x1b[%d;%dr"), y1, y2);
}

void scroll_down(void) {
	printf_P(PSTR("\x1bM"));	// ESC-M
}

void scroll_up(void) {
	printf_P(PSTR("\x1b\x44"));	// ESC-D
}

void draw_horizontal_line(int8_t y, int8_t start_x, int8_t end_x) {
	int8_t i;
	move_cursor(start_x, y);
	reverse_video();
	for(i=start_x; i <= end_x; i++) {
		printf(" ");	/* No need to use printf_P - printing 
						 * a single character gets optimised
						 * to a putchar call 
						 */
	}
	normal_display_mode();
}

void draw_vertical_line(int8_t x, int8_t start_y, int8_t end_y) {
	int8_t i;
	move_cursor(x, start_y);
	reverse_video();
	for(i=start_y; i < end_y; i++) {
		printf(" ");
		/* Move down one and back to the left one */
		printf_P(PSTR("\x1b[B\x1b[D"));
	}
	printf(" ");
	normal_display_mode();
}

/** Method to update the terminal and make it look nice :) **/
void update_terminal_attributes(uint32_t current_score, uint32_t remaining_lives) {
	//Top section
	draw_horizontal_line(1, 0, 79);
	draw_horizontal_line(7, 0, 79);
	//Bottom section
	draw_horizontal_line(10, 10, 40);
	draw_horizontal_line(18, 10, 40);
	draw_vertical_line(9, 10, 18);
	draw_vertical_line(41, 10, 18);
	move_cursor(12,12);
	printf_P(PSTR("Score: %3d\n"), current_score);
	move_cursor(12,13);
	printf_P(PSTR("(Number of asteroids hit)"));
	move_cursor(12,15);
	printf_P(PSTR("Lives: %3d\n"), remaining_lives);
	move_cursor(12,16);
	printf_P(PSTR("(Number of lives remaining)"));
}