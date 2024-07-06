# Programador del Club de Robótica

El club cuenta con varios programadores ISP.

Cada programador cuenta con dos conexiones:
* Target (targ)
    - La conexión más usada. Sirve para programar un microcontrolador externo.
* ISP
    - Sirve para programar el programador (usualmente usando otro programador del club).
      De esta forma un programador sirve para crear más programadores.

## Conexiones

Cada puerto cuenta con 6 pines conectados a un cable plano:

- VCC (usualmente +5V que vienen de la conexión USB)
- GND
- SCK Señal de clock.
- RESET Permite "apagar" el microcontrolador y programarlo por SPI. De esa forma los demás pines pueden ser usados para otras tareas cuando el microcontrolador no está siendo programado.
- MISO (master-in slave-out)<sup>1</sup> Datos del microcontrolador al programador.
- MOSI (master-out slave-in)<sup>1</sup> Datos del programador al microcontrolador.

<sup>1 Nota: SIMO y SOMI suelen ser nombres más simpáticos pero menos usados.</sup>

La ubicación de cada pin en el puerto se muestra a continuación

<p align="center">
    <img alt="Ubicación de cada pin en el puerto." width="30%" src="./puertos.svg">
</p>


## [Wiki](https://github.com/cdrfiuba/programador/wiki)

En la [Wiki](https://github.com/cdrfiuba/programador/wiki) de este repositorio se detalla la construcción de un programador como su uso.

- [Programador del Club de Robótica](https://github.com/cdrfiuba/programador/wiki#programador-del-club-de-rob%C3%B3tica)
  - [¿Cómo armar el programador?](https://github.com/cdrfiuba/programador/wiki#c%C3%B3mo-armar-el-programador)
    - [Versión 1.8](https://github.com/cdrfiuba/programador/wiki#versi%C3%B3n-18)
    - [Versión 1.7](https://github.com/cdrfiuba/programador/wiki#versi%C3%B3n-17)
    - [Versión 1.6](https://github.com/cdrfiuba/programador/wiki#versi%C3%B3n-16)
  - [Lista de Materiales](https://github.com/cdrfiuba/programador/wiki#lista-de-materiales)
    - [Versión 1.6 a 1.8:](https://github.com/cdrfiuba/programador/wiki#versi%C3%B3n-16-a-18)
      - [Lista de materiales a soldar](https://github.com/cdrfiuba/programador/wiki#lista-de-materiales-a-soldar)
      - [Lista de materiales para comprar](https://github.com/cdrfiuba/programador/wiki#lista-de-materiales-para-comprar)
    - [Versión 1.5 o anteriores](https://github.com/cdrfiuba/programador/wiki#versi%C3%B3n-15-o-anteriores)
    - [¿Qué firmware debe llevar mi programador?](https://github.com/cdrfiuba/programador/wiki#qu%C3%A9-firmware-debe-llevar-mi-programador)
    - [Programar el microcontrolador del programador.](https://github.com/cdrfiuba/programador/wiki#programar-el-microcontrolador-del-programador)
    - [¿Cómo armar el conector para programar tu microcontrolador?](https://github.com/cdrfiuba/programador/wiki#c%C3%B3mo-armar-el-conector-para-programar-tu-microcontrolador)
      - [Configuración. Solución a problemas comunes](https://github.com/cdrfiuba/programador/wiki#configuraci%C3%B3n-soluci%C3%B3n-a-problemas-comunes)
      - [No tengo permisos para acceder al dispositivo (Linux)](https://github.com/cdrfiuba/programador/wiki#no-tengo-permisos-para-acceder-al-dispositivo-linux)
      - [Microcontrolador no reconocido.](https://github.com/cdrfiuba/programador/wiki#microcontrolador-no-reconocido)
      - [Para el ATtiny4313](https://github.com/cdrfiuba/programador/wiki#para-el-attiny4313)
      - [Para el ATmega88PA que adquirimos recientemente](https://github.com/cdrfiuba/programador/wiki#para-el-atmega88pa-que-adquirimos-recientemente)
- [Windows necesita un driver](https://github.com/cdrfiuba/programador/wiki#windows-necesita-un-driver)
  - [Licencias](https://github.com/cdrfiuba/programador/wiki#licencias)
  - [Hojas de datos](https://github.com/cdrfiuba/programador/wiki#hojas-de--datos)
  - [Archivos de fabricación](https://github.com/cdrfiuba/programador/wiki#archivos-de-fabricaci%C3%B3n)
- [Fabricantes](https://github.com/cdrfiuba/programador/wiki/Fabricantes)
- [Introducción súper básica a los microcontroladores](https://github.com/cdrfiuba/programador/wiki/Programaci%C3%B3n-de-microcontroladores-AVR-en-C)
- [Quemar un bootloader de Arduino](https://github.com/cdrfiuba/programador/wiki/Quemar-un-bootloader-de-Arduino)

## Pequeña guía para programar un microcontrolador externo

Se utiliza el microcontrolador `ATMEGA168A` a modo de ejemplo (ya que el club cuenta con varios).

La siguiente guía asume el uso de un oscilador externo, si bien el microcontrolador puede ser programador utilizando su oscilador interno.

Se conecta al microcontrolador como muestra la siguiente figura. El valor ideal de los capacitores conectados al cristal se detalla en la hoja de datos del microcontrolador. Para este microcontrolador los capacitores recomendados son de 12pF a 22pF. El capacitor de desacople no es requerido pero es siempre una buena idea agregar uno.

<p align="center">
    <img alt="Diagrama de la conexión en un protoboard" width="50%" src="./como_conectar.svg">
</p>

Asumiendo que se utiliza un cristal de 16 MHz se crea un archivo `main.c` con el siguiente código:

```C
#include <avr/io.h>
#define F_CPU 16000000UL  // Corresponde a 16 MHz
#include <util/delay.h>


int main (void) {
  DDRC |= _BV(DDC3);  // Se setea el pin 26 como salida

  while(1) {
      PORTC |= _BV(PC3);  // Se prende el pin 26

      _delay_ms(1); // Se espera un milisegundo

      PORTC &= ~_BV(PC3);  // Se apaga el pin 26

      _delay_ms(1);  // Se espera otro milisegundo
  }

  return 1;
}
```

Este código produce una onda cuadrada de 500Hz a la salida del pin 26.

Para programadorlo se crea el siguiente script `programar.sh`

```bash
#!/usr/bin/env sh

# Compilación del programa
avr-gcc -Os -mmcu=atmega168a -c -o main.o main.c
avr-gcc -Os -mmcu=atmega168a -o main.elf main.o
avr-objcopy -O ihex -R .eeprom main.elf main.hex

# Cargar el programa en el microcontrolador
avrdude -v -p m168 -c usbtiny -U flash:w:main.hex

# Limpieza de los archivos generados
rm main.o main.hex main.elf
```

A su vez se crea un script `fusibles.sh` para setear los fuses del microcontrolador
Si bien se puede obtener el valor de los fusibles a mano, existen páginas que ya hacen este trabajo.
Una posible página es https://www.engbedded.com/fusecalc
Esta página además posee la ventaja de darnos los flags para el comando de `avrdude`.

```bash
#!/usr/bin/env bash

avrdude -v -p m168 -c usbtiny -U lfuse:w:0xce:m -U hfuse:w:0xdf:m -U efuse:w:0xf9:m
```

Se da permiso de ejecución a ambos scripts por única vez
```console
$ chmod +x programar.sh
$ chmod +x fusibles.sh
```

Se setean los fusibles por única vez. Puede correrse también en el futuro si, por ejemplo, se desea dividir la cuenta del clock por 8, o utilizar el oscilador interno u otras razones. Pero ha de tenerse en cuenta que se debe modificar el script.

```console
$ ./fusibles.sh
```

Se programa el microcontrolador

```console
$ ./programar.sh
```

Ahora puede corroborarse que a la salida del pin 26 hay una onda cuadrada de 500Hz.

