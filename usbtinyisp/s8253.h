#ifndef _S8253_H_
#define _S8253_H_

#include "common.h"
#include "messages.h"
#include "macros.h"

byte_t	s8253_usb_in ( byte_t* data, byte_t len );
void	s8253_usb_out ( byte_t* data, byte_t len );
byte_t	s8253_usb_setup ( byte_t data[8] );

#endif