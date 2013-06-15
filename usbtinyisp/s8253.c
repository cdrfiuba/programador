#include "s8253.h"

// ----------------------------------------------------------------------
// Issue one SPI command.
// ----------------------------------------------------------------------
static byte_t s8253_spiOneByte(byte_t dataOut)
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
static	void	s8253_spi ( byte_t* cmd, byte_t* res, int i )
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


// ----------------------------------------------------------------------
// Create and issue a read or write SPI command.
// ----------------------------------------------------------------------
/*static	void	s8253_spi_rw ( void )
{
	uint_t	a;
	
	a = address++;
	
	cmd[0] = cmd0;
	cmd[1] = a >> 8;
	cmd[2] = a;	
	spi( cmd, res, tam );
}*/

extern	byte_t	s8253_usb_in ( byte_t* data, byte_t len )
{
	byte_t	i;

	for	( i = 0; i < len; i++ )
	{
		s8253_spi_rw();
		data[i] = res[3];
	}
	return len;
}

/*cmd[0] ya debe estar cargada para lectura o escritura
* address ya debe estar cargada 
*/
extern	void	s8253_usb_out ( byte_t* data, byte_t len )
{
	byte_t	i;
	uint_t	usec;
	byte_t	r;

	for	( i = 0; i < len; i++ )
	{	
		cmd[3] = data[i];
		spi_rw();
		WaitDateWriteCompletion(data[i],address-1,4);			
	}		
}


void WaitDateWriteCompletion(byte_t writeByte, byte_t add, byte_t size)
{
    byte_t result[4] = {0x00,0x00,0x00,(~writeByte) };
    cmd[1] = add >> 8;
	cmd[2] = add;
    while (result[3] != writeByte)
    {
        spiOneCommand(cmd,result,size);
    }
}