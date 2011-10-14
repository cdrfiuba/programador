#ifndef _AVR_SPI_H_
#define _AVR_SPI_H_

#include "common.h"
#include "messages.h"
#include "macros.h"


void	AVR_spi ( byte_t* cmd, byte_t* res, byte_t n );
void	AVR_spi_rw ( void );
byte_t	AVR_usb_in ( byte_t* data, byte_t len );
void	AVR_usb_out ( byte_t* data, byte_t len );
byte_t  AVR_usb_setup(byte_t data[8]);

#endif