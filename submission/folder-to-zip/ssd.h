/*
 * ssd.h
 *
 * Created: 16/05/2019 6:41:13 PM
 *  Author: Steve
 */ 


#ifndef SSD_H_
#define SSD_H_

#include <stdint.h>

// Initialise the ports for the seven seg display
void init_ssd(void);

// Update the display to show the current score
void update_ssd(void);

#endif /* SSD_H_ */