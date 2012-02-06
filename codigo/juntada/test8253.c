
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
		if	( c & mask )
		{
			PORT |= MOSI_MASK;
		}
//			if (! status & INVERTED_SCK_MASK )
			delay();

		PORT |= SCK_MASK;
		delay();
		dataIn <<= 1;
		if	( PIN & MISO_MASK )
		{
			dataIn++;
		}
		PORT &= ~ SCK_MASK;
//			if ( status & INVERTED_SCK_MASK )
//				delay();
		
		PORT &= ~ MOSI_MASK;
	}
	return dataIn;

}

	// ----------------------------------------------------------------------
// Issue one SPI command.
// ----------------------------------------------------------------------
//__attribute__((naked))
static	void	spi ( byte_t* cmd, byte_t* res, int i )
{
	byte_t	c;
	byte_t	r;
	

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
	}
}
