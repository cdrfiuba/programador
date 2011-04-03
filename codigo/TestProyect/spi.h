#ifndef _SPI_H_
#define _SPI_H_

#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "usb.h"
#include "usbtinyMod.h"
#include "macros.h"


// ----------------------------------------------------------------------
// Delay exactly <sck_period> times 0.5 microseconds (6 cycles).
// ----------------------------------------------------------------------
__attribute__((always_inline))
static	void	delay ( void )
{
	asm volatile(
		"	mov	__tmp_reg__,%0	\n"
		"0:	rjmp	1f		\n"
		"1:	nop			\n"
		"	dec	__tmp_reg__	\n"
		"	brne	0b		\n"
		: : "r" (sck_period) );
}


// ----------------------------------------------------------------------
// Issue one SPI command.
// ----------------------------------------------------------------------
//__attribute__((naked))
static	void	spi ( byte_t* cmd, byte_t* res, int i )
{
/*	byte_t	c;
	byte_t	r;
	byte_t	mask;

	while (i != 0)
	{
	  i--;
		c = *cmd++;
		r = 0;
		for	( mask = 0x80; mask; mask >>= 1 )
		{
			if	( c & mask )
			{
				PORT |= MOSI_MASK;
			}
//			if (! status & INVERTED_SCK_MASK )
				delay();

			PORT |= SCK_MASK;
			delay();
			r <<= 1;
			if	( PIN & MISO_MASK )
			{
				r++;
			}
			PORT &= ~ SCK_MASK;
//			if ( status & INVERTED_SCK_MASK )
//				delay();
			
			PORT &= ~ MOSI_MASK;
		}
		*res++ = r;
	}*/
}



// ----------------------------------------------------------------------
// Create and issue a read or write SPI command.
// ----------------------------------------------------------------------
static	void	spi_rw ( void )
{
/*	unsigned char offset = 0;
	uint_t	a;
	uint_t	tam = (status & TAMANIO_MASK);	

	a = address++;
	cmd[0] = cmd0;
	if ( ( !(status & MICRO_S51_MASK) ) &&  ( ! (cmd0 & 0x80) ) )
	{	//Es AVR 							// NOT eeprom
		if ( a & 1 )
		{
			cmd[0] |= 0x08;	//La H
		}
		a >>= 1;	//Corro la direccion
	} 
	cmd[1] = a >> 8;
	cmd[2] = a;
	
	if ( (status & MICRO_S51_MASK ) == MICRO_8252 )
	{
		cmd[1] <<= 3;
		cmd[1] |= cmd0;
		offset = 1;
	}
	spi( cmd + offset, res, tam );*/
}


#endif
