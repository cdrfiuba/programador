# ======================================================================
# Makefile for USBtinyISP AVR programmer
#
# Copyright 2006-2010 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

USBTINY		= ./
TARGET_ARCH	= -mmcu=attiny2313
OBJECTS		= main.o
FLASH_CMD	= avrdude -c usbtiny -pt4313 -U flash:w:main.hex
FUSES_CMD	= avrdude -c usbtiny -pt4313 -U hfuse:w:0xdf:m -U lfuse:w:0xef:m
STACK		= 32
FLASH		= 2048
SRAM		= 128
SCHEM		= 

# ======================================================================
# Common Makefile for USBtiny applications
#
# Macros to be defined before including this file:
#
# USBTINY	- the location of this directory
# TARGET_ARCH	- gcc -mmcu= option with AVR device type
# OBJECTS	- the objects in addition to the USBtiny objects
# FLASH_CMD	- command to upload main.hex to flash
# FUSES_CMD	- command to program the fuse bytes
# STACK		- maximum stack size (optional)
# FLASH		- flash size (optional)
# SRAM		- SRAM size (optional)
# SCHEM		- Postscript version of the schematic to be generated
#
# Copyright 2006-2010 Dick Streefland
#
# This is free software, licensed under the terms of the GNU General
# Public License as published by the Free Software Foundation.
# ======================================================================

check	= $(shell $(CC) $1 -c -xc /dev/null -o/dev/null 2>/dev/null && echo $1)

#CC	= "C:/Program Files (x86)/Atmel/AVR Studio 5.0/AVR ToolChain/bin/avr-gcc"
CC	= avr-gcc
OPTIM	= -Os -ffunction-sections $(call check,-fno-split-wide-types)
CFLAGS	= -g -Wall -I. -I$(USBTINY) $(OPTIM)
LDFLAGS	= -g -Wl,--relax,--gc-sections
MODULES = crc.o int.o usb.o common.o avr_spi.o $(OBJECTS)
UTIL	= $(USBTINY)/../util

main.hex:

all:		main.hex $(SCHEM)

clean:
	rm -f main.elf *.o tags gschem.log

clobber:	clean
	rm -f main.hex $(SCHEM)

main.elf:	$(MODULES)
	$(LINK.o) -o $@ $(MODULES)

main.hex:	main.elf
	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
	# We should have a better script to analize the size
	avr-size main.hex

disasm:		main.elf
	avr-objdump -S main.elf

flash:		main.hex
	$(FLASH_CMD)

fuses:
	$(FUSES_CMD)

crc.o:		$(USBTINY)/crc.S $(USBTINY)/def.h $(USBTINY)usbtiny.h
	$(COMPILE.c) $(USBTINY)/crc.S
int.o:		$(USBTINY)/int.S $(USBTINY)/def.h $(USBTINY)usbtiny.h
	$(COMPILE.c) $(USBTINY)/int.S
usb.o:		$(USBTINY)/usb.c $(USBTINY)/def.h $(USBTINY)/usb.h $(USBTINY)usbtiny.h
	$(COMPILE.c) $(USBTINY)/usb.c
common.o: 	$(USBTINY)/common.h $(USBTINY)/macros.h
	$(COMPILE.c) $(USBTINY)/common.c
avr_spi.o:	$(USBTINY)/AVR_spi.h $(USBTINY)/macros.h $(USBTINY)/messages.h $(USBTINY)/common.h
	$(COMPILE.c) $(USBTINY)/AVR_spi.c
main.o:		$(USBTINY)/usb.h $(USBTINY)/AVR_spi.h

%.ps:		%.sch $(UTIL)/sch2ps
	$(UTIL)/sch2ps $<
