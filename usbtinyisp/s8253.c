#include "s8253.h"


static  byte_t  s8253_spiOneByte(byte_t dataOut);
static	void	s8253_spi ( byte_t* cmd, byte_t* res, int i );
static  void    WaitDataWriteCompletion(byte_t writeByte, uint16_t add, byte_t size);


// ----------------------------------------------------------------------
// Issue one SPI byte.
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

	while (i != 0)
	{
	  	i--;
		c = *cmd++;
		r = 0;
		r = s8253_spiOneByte(c);
		*res++ = r;
	}
}

// ----------------------------------------------------------------------
// Check data is written in memory or exit by timeout
// ----------------------------------------------------------------------
static void WaitDataWriteCompletion(byte_t writeByte, uint16_t add, byte_t size)
{
    byte_t result[4] = {0x00,0x00,0x00,(~writeByte) };
    uint16_t usec = 0;
    cmd[1] = add >> 8;
	cmd[2] = add;
    while ( (result[3] != writeByte) && (usec < timeout) ) 
    {
        s8253_spi(cmd,result,size);
        usec += (32 * sck_period); /* TODO: ver de donde sale el 32 */
    }
}

// ----------------------------------------------------------------------
// cmd[0] ya debe estar cargada para lectura o escritura address ya debe estar cargada
// ----------------------------------------------------------------------
byte_t	s8253_usb_in ( byte_t* data, byte_t len )
{
    byte_t	i;

    for	( i = 0; i < len; i++,address++ )
    {           
        cmd[1] = address >> 8;
        cmd[2] = address;     
        s8253_spi(cmd,res,4);
        data[i] = res[3];
    }
    return len;
}

// ----------------------------------------------------------------------
// cmd[0] ya debe estar cargada para lectura o escritura address ya debe estar cargada
// ----------------------------------------------------------------------

static uint16_t pass = 0;
__attribute__((noinline))
void	s8253_usb_out ( byte_t* data, byte_t len )
{
    byte_t	i;

    if ( pass == 32)
    {
        cmd[0] = cmd0;
        pass = 0;
    }    
    else
        pass++;
    for	( i = 0; i < len; i++,address++ )
    {
        cmd[1] = address >> 8;
        cmd[2] = address;
        cmd[3] = data[i];
        s8253_spi(cmd,res,4);
        WaitDataWriteCompletion(data[i],address,4);
    }
}

// ----------------------------------------------------------------------
// Handle a non-standard SETUP packet.
// ----------------------------------------------------------------------
byte_t	s8253_usb_setup ( byte_t data[8] )
{
	byte_t	req;
	byte_t	ans = 0;

	// Generic requests
	req = data[1];

	// Programming requests
	if ( req == USBTINY_CONFIGURE )
	{
		status = data[2];
		cmd0 = data[4];
	}
	else if	( req == USBTINY_SPI )
	{
	    s8253_spi( data + 2, data + 0, 4 );
	    ans = 4;
	}
	else if	( req == USBTINY_SPI1 )
	{
	    s8253_spi( data + 2, data + 0, 1 );
		ans = 1;
	}
	else 
	{
		address = * (uint_t*) & data[4];
        cmd[0] = cmd0;
        if	( (req == USBTINY_FLASH_READ) || (req == USBTINY_EEPROM_READ))
        {
            ans = 0xFF;       
        }
        else
        {
            timeout = * (uint_t*) & data[2];    
        }        
	}
	return ans;
}