#include "avr_spi.h"

static void	AVR_spi ( byte_t* cmd, byte_t* res, byte_t n );
static void	AVR_spi_rw ( void );


static void	AVR_spi ( byte_t* cmd, byte_t* res, byte_t n )
{
	byte_t	c;
	byte_t	r;
	byte_t	mask;

	while	( n != 0 )
	{
		n--;
		c = *cmd++;
		r = 0;
		for	( mask = 0x80; mask; mask >>= 1 )
		{
			if	( c & mask )
			{
				PORT |= MOSI_MASK;
			}
			delay();
			PORT |= SCK_MASK;
			delay();
			r <<= 1;
			if	( PIN & MISO_MASK )
			{
				r++;
			}
			PORT &= ~ MOSI_MASK;
			PORT &= ~ SCK_MASK;
		}
		*res++ = r;
	}
}


// ----------------------------------------------------------------------
// Create and issue a read or write SPI command.
// ----------------------------------------------------------------------
static void	AVR_spi_rw ( void )
{
	uint_t	a;

	a = address++;
	if	( cmd0 & 0x80 )
	{	// eeprom
		a <<= 1;
	}
	cmd[0] = cmd0;
	if	( a & 1 )
	{
		cmd[0] |= 0x08;
	}
	cmd[1] = a >> 9;
	cmd[2] = a >> 1;
	AVR_spi( cmd, res, 4 );
}


byte_t	AVR_usb_in ( byte_t* data, byte_t len )
{
	byte_t	i;

	for	( i = 0; i < len; i++ )
	{
		AVR_spi_rw();
		data[i] = res[3];
	}
	return len;
}


void	AVR_usb_out ( byte_t* data, byte_t len )
{
	byte_t	i;
	uint_t	usec;
	byte_t	r;

	for	( i = 0; i < len; i++ )
	{
		cmd[3] = data[i];
		AVR_spi_rw();
		cmd[0] ^= 0x60;	// turn write into read
		for	( usec = 0; usec < timeout; usec += 32 * sck_period )
		{	// when timeout > 0, poll until byte is written
			AVR_spi( cmd, res, 4 );
			r = res[3];
			if	( r == cmd[3] && r != poll1 && r != poll2 )
			{
				break;
			}
		}
	}
}

byte_t AVR_usb_setup(byte_t data[8])
{
	// Generic requests
	byte_t req = data[1];
	byte_t ans = 0;
	
	if	( req == USBTINY_SPI )
	{
		AVR_spi( data + 2, data + 0, 4 );
		ans = 4;
	}
	if	( req == USBTINY_SPI1 )
	{
		AVR_spi( data + 2, data + 0, 1 );
		ans = 1;
	}
	if	( req == USBTINY_POLL_BYTES )
	{
		poll1 = data[2];
		poll2 = data[3];
	}
	address = * (uint_t*) & data[4];
	if	( req == USBTINY_FLASH_READ )
	{
		cmd0 = 0x20;
		ans = 0xff;	// usb_in() will be called to get the data
	}
	if	( req == USBTINY_EEPROM_READ )
	{
		cmd0 = 0xa0;
		ans = 0xff;	// usb_in() will be called to get the data
	}
	timeout = * (uint_t*) & data[2];
	if	( req == USBTINY_FLASH_WRITE )
	{
		cmd0 = 0x40;
		// data will be received by usb_out()
	}
	if	( req == USBTINY_EEPROM_WRITE )
	{
		cmd0 = 0xc0;
		// data will be received by usb_out()
	}	
	return ans;	
}
