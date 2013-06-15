#ifndef _S8253_H_
#define _S8253_H_


static byte_t s8253_spiOneByte(byte_t dataOut);
static	void	s8253_spi ( byte_t* cmd, byte_t* res, int i );
extern	byte_t	s8253_usb_in ( byte_t* data, byte_t len );
extern	void	s8253_usb_out ( byte_t* data, byte_t len );

#endif