#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "def.h"
#include "usb.h"
#include "macros.h"
#include "usbtinyMod.h"
#include "spi.h"


byte_t programEnable_Cmm[] = {0xAC,0x53,0x00,0x00};
byte_t chipErase_Cmm[]     = {0xAC,0x80,0x00,0x00};
byte_t writeByte_Cmm[]     = {0x40,0x00,0x00,0x00};
byte_t readByte_Cmm[]      = {0x20,0x00,0x00,0x00};

byte_t led_05s_program[] = {
0xB2,
0x80,
0x11,
0x20,
0x80,
0xFA,          
0x7E,
0x08,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,              
0x7E,
0x10,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,          
0x7E,
0x04,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,
};


byte_t led_1s_program[] = {
0xB2,
0x80,
0x11,
0x06,
0x80,
0xFA,          
0x7E,
0x08,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,              
0x7E,
0x10,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,          
0x7E,
0x04,
0x7A,
0xFF,
0x7B,
0xFF,
0xDB,
0xFE,
0xDA,
0xFA,
0xDE,
0xF6,
0x22,
};


void test8253_normal_write()
{


}

/* Sends one byte over SPI.
   Returns the data in.
*/

static byte_t spiOneByte(byte_t dataOut)
{
	byte_t	mask;
	byte_t  dataIn = 0;

	for	( mask = 0x80; mask; mask >>= 1 )
	{

		SET_SCK;
		if	( dataOut & mask )
		{
			SET_MOSI;            
		}
//			if (! status & INVERTED_SCK_MASK )
		delay();

		dataIn <<= 1;
		if	( PIN & MISO_MASK )
		{
			dataIn++;
		}
		CLR_SCK;
        delay();
//			if ( status & INVERTED_SCK_MASK )
//				delay();
		CLR_MOSI;		
	}
	return dataIn;
}

	// ----------------------------------------------------------------------
// Issue one SPI command.
// ----------------------------------------------------------------------
//__attribute__((naked))
static	void	spiOneCommand ( byte_t* cmd, byte_t* res, int i )
{
	byte_t	c;
	byte_t	r;
    byte_t  mask;	

	while (i != 0)
	{
	  	i--;
		c = *cmd++;
		r = 0;
		r = spiOneByte(c);
		*res++ = r;
	}
}

void CheckChipErase()
{
    byte_t result[4] = {0x00,0x00,0x00,0x00} ;
    while(result[3] != 0xFF)
    {
        spiOneCommand(readByte_Cmm,result,4);//Leo la direccion 0x00
    }
}

void WaitDateWriteCompletion(byte_t writeByte, byte_t address, byte_t size)
{
    byte_t result[4] = {0x00,0x00,0x00,(~writeByte) };
    readByte_Cmm [2] = address;
    while (result[3] != writeByte)
    {
        spiOneCommand(readByte_Cmm,result,size);
    }
}


void ProgramLed()
{
    byte_t address = 0 ,i ;
    byte_t addressTotal = 45;
    byte_t result[4];
    byte_t mask;

        PORTD &= ~_BV(4);   //Enable Buffer
		DDR  = POWER_MASK | RESET_MASK | SCK_MASK | MOSI_MASK;
		PORT = mask;


    spiOneCommand(programEnable_Cmm,result,4);
    
    spiOneCommand(chipErase_Cmm,result,4);
    CheckChipErase();    

    for (i = 0; i < addressTotal; i++,address++)
    {
        writeByte_Cmm[2] = address;
        writeByte_Cmm[3] = led_1s_program[i];        
        spiOneCommand(writeByte_Cmm,result,4);
        WaitDateWriteCompletion(writeByte_Cmm[3], address, 4);
    }
    //Fin, bajo el reset y pongo todo como entrada.
        DDR  = 0x00;
		PORT = 0x00;
		PORTD |= _BV(4);
}

