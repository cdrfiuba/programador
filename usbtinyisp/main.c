// ======================================================================
// USB AVR programmer and SPI interface
//
// http://www.ladyada.net/make/usbtinyisp/
//
// This code works for both v1.0 and v2.0 devices.
//
// Copyright 2006-2010 Dick Streefland
//
// This is free software, licensed under the terms of the GNU General
// Public License as published by the Free Software Foundation.
// ======================================================================

#include <avr/io.h>
#include "defines.h"
#include "macros.h"
#include "def.h"
#include "usb.h"
#include "messages.h"
#include "AVR_spi.h"
#include "s8253.h"



//Pointers
static void (*pUsb_out)(byte_t* data, byte_t len);
static byte_t (*pUsb_in)(byte_t* data, byte_t len);
static byte_t (*pUsb_setup)(byte_t* data);
static void (*pSpi)(byte_t* cmd, byte_t* res, int i);


void ConfigurePointersDefaultValue()
{
/*		pUsb_in  = &AVR_usb_in;
		pUsb_out = &AVR_usb_out;
		pUsb_setup = &AVR_usb_setup;*/
}

void DefinePointers(byte_t protocol)
{
	if (protocol == 1)
	{
		pUsb_in  = &s8253_usb_in;
		pUsb_out = &s8253_usb_out;
		pUsb_setup = &s8253_usb_setup;
	}
	else
	{
		
	}	
}

// ----------------------------------------------------------------------
// Handle a non-standard SETUP packet.
// ----------------------------------------------------------------------
extern	byte_t	usb_setup ( byte_t data[8] )
{
	byte_t	mask;
	byte_t	req;
	byte_t	ans = 0;

	/*tGenericMessage * genericRequest;
	genericRequest = data;	
	req = genericRequest->typeRequest;*/
	
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
		//status = AVR_SCK | MICRO_AVR | TAMANIO_AVR;
				
		BUFFER_ON;
		DDR  = POWER_MASK | RESET_MASK | SCK_MASK | MOSI_MASK;		
		PORT = mask;
		
		/* ConfigurePointersDefaultValue(); */ //DEBUG
        DefinePointers(1);
		//return 0;
	}
	else if	( req == USBTINY_POWERDOWN )
	{
		DDR  = 0x00;
		PORT = 0x00;
		BUFFER_OFF;
		// return 0;
	}
	else if (req == USBTINY_PROTOCOL) 
	{
		DefinePointers(data[2]);
	} 
	else 
	{
		/*ans = (*pUsb_setup)(data);*/
        s8253_usb_setup(data);
	}
	
	return ans;		
}



// ----------------------------------------------------------------------
// Handle an IN packet.
// ----------------------------------------------------------------------
extern	byte_t	usb_in ( byte_t* data, byte_t len )
{   
	/*return (*pUsb_in)(data, len);*/
    return s8253_usb_in(data,len);
    
}

// ----------------------------------------------------------------------
// Handle an OUT packet.
// ----------------------------------------------------------------------
extern	void	usb_out ( byte_t* data, byte_t len )
{
	/*(*pUsb_out)(data, len);*/
    s8253_usb_out(data,len);
}


void Puntero1(byte_t* a, byte_t* b, byte_t c)
{
	/*AVR_spi(a,b,c);*/
}


void SetPointers()
{
	byte_t data1[2],data2[2];
	byte_t chara = 'a';
	void (*pFunc)(byte_t*, byte_t*, byte_t);
	pFunc =  &Puntero1;
	(*pFunc)(data1,data2,chara);
	
}




// ----------------------------------------------------------------------
// Main
// ----------------------------------------------------------------------
__attribute__((naked))		// suppress redundant SP initialization
extern	int	main ( void )
{
  
  DDRD = _BV(6) | _BV(5) | _BV(4); // setup USB pullup, LED pin and buffer select pins to output
  
  
  BUFFER_ON;
  BUFFER_AS_OUTPUT;
  //LCD_AS_OUTPUT;
  //USB_AS_OUTPUT;
  usb_init();
  
  PORTD = _BV(6) | _BV(4); // pull pull-up and buffer disable high

  for	( ;; )
    {
      usb_poll();
    }
  return 0;
}
