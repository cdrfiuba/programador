#ifndef _COMMON_H_
#define _COMMON_H_

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "usb.h"

extern byte_t		sck_period;	// SCK period in microseconds (1..250)
extern byte_t		poll1;		// first poll byte for write
extern byte_t		poll2;		// second poll byte for write
extern uint_t		address;	// read/write address
extern uint_t		timeout;	// write timeout in usec
extern byte_t		cmd0;		// current read/write command byte
extern byte_t		cmd[4];		// SPI command buffer
extern byte_t		res[4];		// SPI result buffer
extern byte_t		status;


void	delay ( void );


#endif