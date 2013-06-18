#ifndef _DEFINES_H_
#define _DEFINES_H_

enum
{
	// Generic requests
	USBTINY_ECHO,		// echo test
	USBTINY_READ,		// read byte
	USBTINY_WRITE,		// write byte
	USBTINY_CLR,		// clear bit 
	USBTINY_SET,		// set bit
	// Programming requests
	USBTINY_POWERUP,	// apply power (wValue:SCK-period, wIndex:RESET)
	USBTINY_POWERDOWN,	// remove power from chip
	USBTINY_SPI,		// issue SPI command (wValue:c1c0, wIndex:c3c2)
	USBTINY_POLL_BYTES,	// set poll bytes for write (wValue:p1p2)
	USBTINY_FLASH_READ,	// read flash (wIndex:address)
	USBTINY_FLASH_WRITE,	// write flash (wIndex:address, wValue:timeout)
	USBTINY_EEPROM_READ,	// read eeprom (wIndex:address)
	USBTINY_EEPROM_WRITE,	// write eeprom (wIndex:address, wValue:timeout)
	USBTINY_DDRWRITE,	// set port direction
	USBTINY_SPI1,		// a single SPI command

	USBTINY_CONFIGURE,	//The meaning of this frame will be different for each protocol.		
    USBTINY_PROTOCOL,	//The protocol it will use. Defines where the pointer will point (wValue = el enum del protocolo. wIndex no se usa)

};

enum
{
    PROTOCOL_SPI_AVR,
    PROTOCOL_SPI_S8253,    
};

// ----------------------------------------------------------------------
// I/O pins:
// ----------------------------------------------------------------------
//#define	PORT		PORTB
//#define	DDR		DDRB
//#define	PIN		PINB

#define	LED		PB0		// output
#define	RESET		PB4		// output
#define	MOSI		PB5		// output
//#define	MISO		PB6		// input
#define	SCK		PB7		// output

// ----------------------------------------------------------------------
#define	PORT		PORTB
#define	DDR			DDRB
#define	POWER_MASK	_BV(LED)
#define	RESET_MASK	_BV(RESET)
#define	SCK_MASK	_BV(SCK)
#define	MOSI_MASK	_BV(MOSI)
#define LED_MASK    _BV(LED)

// ----------------------------------------------------------------------
// Programmer input pins:
//	MISO	PB6
#define MISO       6
// ----------------------------------------------------------------------
#define	PIN		PINB
#define	MISO_MASK	_BV(MISO)
//#define	SCK_MASK	_BV(SCK)

//#define	BUFFEN		(D,4)		// output, active low

#define BUFFER_PORT					PORTD
#define BUFFER_PIN					_BV(4)
#define BUFFER_PORT_DDR				DDRD

#define LED_PORT					PORTD
#define LED_PIN						_BV(?)
#define LED_PORT_DDR				DDRD

#define USB_PORT					PORTD
#define USB_PIN						_BV(?)
#define USB_PORT_DDR				DDRD


#endif