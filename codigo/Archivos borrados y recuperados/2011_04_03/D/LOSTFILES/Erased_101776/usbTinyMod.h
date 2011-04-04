#ifndef USB_TINY_MOD_H
#define	USB_TINY_MOD_H

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
	USBTINY_DDRWRITE,        // set port direction
	USBTINY_SPI1,            // a single SPI command
	USBTINY_CONFIGURE	 // if command sent, use the inverted sck for 8253. (wValue = status, wIndex = comando)
};

// ----------------------------------------------------------------------
// Programmer output pins:
//	LED	PB0	(D0)
#define LED PB0
//	VCC	PB1	(D1)
//	VCC	PB2	(D2)
//	VCC	PB3	(D3)
//	RESET	PB5	(D4)
#define RESET PB4
//	MOSI	PB5	(D5)
#define MOSI  PB5
//	SCK	PB7	(D7)
#define SCK   PB7

// ----------------------------------------------------------------------
#define	PORT		PORTB
#define	DDR		DDRB
#define	POWER_MASK	_BV(LED)
#define	RESET_MASK	_BV(RESET)
#define	SCK_MASK	_BV(SCK)
#define	MOSI_MASK	_BV(MOSI)
#define LED_MASK        _BV(LED)

// ----------------------------------------------------------------------
// Programmer input pins:
//	MISO	PB6
#define MISO       6
// ----------------------------------------------------------------------
#define	PIN		PINB
#define	MISO_MASK	_BV(MISO)

//ximmmTTT

#define TAMANIO_MASK		0x07
#define TAMANIO_AVR			0x04
#define TAMANIO_8253		0x04
#define TAMANIO_8252		0x03

#define MICRO_S51_MASK		0x38
#define MICRO_AVR			0x00
#define MICRO_8253			0x08
#define	MICRO_8252			0x10

#define INVERTED_SCK_MASK	0x40	
#define AVR_SCK				0x00


#endif
