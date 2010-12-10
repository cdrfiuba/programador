#ifndef _MACROS_H_
#define _MACROS_H_

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "usbtiny.h"


// ----------------------------------------------------------------------
// Local data
// ----------------------------------------------------------------------
/*Pongo las statics aca, porque solo puedo definirlas una vez y el extern no vale con el 
modificador static*/
static	byte_t		sck_period;	// SCK period in microseconds (1..250)
static	byte_t		poll1;		// first poll byte for write
static	byte_t		poll2;		// second poll byte for write
static	uint_t		address;	// read/write address
static	uint_t		timeout;	// write timeout in usec
static	byte_t		cmd0;		// current read/write command byte
static	byte_t		cmd[4];		// SPI command buffer
static	byte_t		res[4];		// SPI result buffer
static	byte_t		status;		


#define SET_SCK  		PORT |= SCK_MASK
#define CLR_SCK         PORT &= ~ SCK_MASK

#define SET_MOSI        PORT |= MOSI_MASK
#define CLR_MOSI        PORT &= ~ MOSI_MASK        

#endif
