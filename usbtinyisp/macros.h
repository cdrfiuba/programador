#ifndef _MACROS_H_
#define _MACROS_H_

#include "defines.h"


#define SET_PROG_LED				
#define CLR_PROG_LED

#define BUFFER_AS_OUTPUT BUFFER_PORT_DDR |=   BUFFER_PIN

#define BUFFER_ON	(BUFFER_PORT &= ~BUFFER_PIN)
#define BUFFER_OFF	(BUFFER_PORT |= BUFFER_PIN)

#define SET_SCK  		PORT |= SCK_MASK
#define CLR_SCK         PORT &= ~ SCK_MASK

#define SET_MOSI        PORT |= MOSI_MASK
#define CLR_MOSI        PORT &= ~ MOSI_MASK  

//#define LCD_AS_OUTPUT	LED_PORT_DDR |=   LCD_PIN
//#define USB_AS_OUTPUT	USB_PORT_DDR |=   USB_PIN



#endif