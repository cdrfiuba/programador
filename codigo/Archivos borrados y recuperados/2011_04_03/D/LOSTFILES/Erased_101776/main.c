// ======================================================================
// Control a parallel port AVR programmer (avrdude type "bsd") via USB.
//
// Copyright (C) 2006 Dick Streefland
//
// This is free software, licensed under the terms of the GNU General
// Public License as published by the Free Software Foundation.
// ======================================================================

#include <avr/io.h>
#include "usb.h"
#include "usbtinyMod.h"
#include "macros.h"
#include "spi.h"





// ----------------------------------------------------------------------
// Handle a non-standard SETUP packet.
// ----------------------------------------------------------------------
extern	byte_t	usb_setup ( byte_t data[8] )
{
	/*byte_t	mask;
	byte_t	req;
	byte_t	ans = 0;
	byte_t	cmd0_temp;

	// Generic requests
	req = data[1];

	// Programming requests
	if	( req == USBTINY_POWERUP )
	{
		sck_period = data[2];
		mask = POWER_MASK;
		if	( data[4] )
		{
			mask |= RESET_MASK;
		}
		// Use AVR por default
		status = AVR_SCK | MICRO_AVR | TAMANIO_AVR;
		
		PORTD &= ~_BV(4);
		DDR  = POWER_MASK | RESET_MASK | SCK_MASK | MOSI_MASK;
		PORT = mask;
		// return 0;
	}
	else if	( req == USBTINY_POWERDOWN )
	{
	  //PORT |= RESET_MASK;
		DDR  = 0x00;
		PORT = 0x00;
		PORTD |= _BV(4);
		// return 0;
	}
	else if ( req == USBTINY_CONFIGURE )
	{
		status = data[2];
		cmd0 = data[4];
	}*/
	/*else if	( ! PORT )
	{
		//return 0;
	}*/
	/*else if	( req == USBTINY_SPI )
	{
	  spi( data + 2, data + 0, 4 );
		ans = 4;
		//return 4;
	}
	else if	( req == USBTINY_SPI1 )
	{
	  spi( data + 2, data + 0, 1 );
		ans = 1;
		//return 1;
	}
	else if	( req == USBTINY_POLL_BYTES )
	{
		poll1 = data[2];
		poll2 = data[3];
		//return 0;
	}
	else 
	{
		address = * (uint_t*) & data[4];
		if	( req == USBTINY_FLASH_READ )
		{
			cmd0_temp = 0x20;
			ans = 0xff;
			//return 0xff;	// usb_in() will be called to get the data
		}
		else if	( req == USBTINY_EEPROM_READ )
		{
			cmd0_temp = 0xa0;
			ans =  0xff;
			//return 0xff;	// usb_in() will be called to get the data
		}
		else {
			timeout = * (uint_t*) & data[2];
			if	( req == USBTINY_FLASH_WRITE )
			{
				cmd0_temp = 0x40;
				//return 0;	// data will be received by usb_out()
			}
			else if	( req == USBTINY_EEPROM_WRITE )
			{
				cmd0_temp = 0xc0;
				//return 0;	// data will be received by usb_out()
			}
		}	
		if ( ! (status & MICRO_S51_MASK) )		//Solo grabo el dato temp en cmd0 si estoy grabando un AVR	
		{						//Si estoy programando un S51, tengo que pasarlo en la trama CONFIGURE
			cmd0 = cmd0_temp;
		}
	}
	return ans;*/
}

// ----------------------------------------------------------------------
// Handle an IN packet.
// ----------------------------------------------------------------------
extern	byte_t	usb_in ( byte_t* data, byte_t len )
{
	/*byte_t	i;

	for	( i = 0; i < len; i++ )
	{
		spi_rw();
		data[i] = res[3];
	}
	return len;*/
}

// ----------------------------------------------------------------------
// Handle an OUT packet.
// ----------------------------------------------------------------------
extern	void	usb_out ( byte_t* data, byte_t len )
{
/*	byte_t	i;
	uint_t	usec;
	byte_t	r;

	for	( i = 0; i < len; i++ )
	{
		cmd[3] = data[i];
		spi_rw();
		cmd[0] ^= 0x60;	// turn write into read
		for	( usec = 0; usec < timeout; usec += 32 * sck_period )
		{	// when timeout > 0, poll until byte is written
		  spi( cmd, res, 4 );
			r = res[3];
			if	( r == cmd[3] && r != poll1 && r != poll2 )
			{
				break;
			}
		}
	}*/
}	 
	 

// ----------------------------------------------------------------------
// Main
// ----------------------------------------------------------------------
__attribute__((naked))		// suppress redundant SP initialization
int	main ( void )
{
  PORTD |= _BV(4);
  DDRD = _BV(6) | _BV(5) | _BV(4); // setup USB pullup, LED pin and buffer select pins to output
  //usb_init();
  PORTD = _BV(6) | _BV(4); // pull pull-up and buffer disable high
    ProgramLed();
    
    while(1);

  for	( ;; )
    {
      usb_poll();
    }
  return 0;
}
