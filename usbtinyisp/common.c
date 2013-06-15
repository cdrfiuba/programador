#include "common.h"

// ----------------------------------------------------------------------
// Local data
// ----------------------------------------------------------------------
byte_t		sck_period;	// SCK period in microseconds (1..250)
byte_t		poll1;		// first poll byte for write
byte_t		poll2;		// second poll byte for write
uint_t		address;	// read/write address
uint_t		timeout;	// write timeout in usec
byte_t		cmd0;		// current read/write command byte
byte_t		cmd[4];		// SPI command buffer
byte_t		res[4];		// SPI result buffer

byte_t		status;



// ----------------------------------------------------------------------
// Delay exactly <sck_period> times 0.5 microseconds (6 cycles).
// ----------------------------------------------------------------------
__attribute__((always_inline))
void	delay ( void )
{
	asm volatile(
		"	mov	__tmp_reg__,%0	\n"
		"0:	rjmp	1f		\n"
		"1:	nop			\n"
		"	dec	__tmp_reg__	\n"
		"	brne	0b		\n"
		: : "r" (sck_period) );
}

