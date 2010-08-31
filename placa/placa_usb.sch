EESchema Schematic File Version 1
LIBS:power,/home/cancerbero/cosas/proyectos/kicad-projects/libs/attiny,device,conn,linear,regul,74xx,cmos4000,adc-dac,memory,xilinx,special,microcontrollers,dsp,microchip,analog_switches,motorola,texas,intel,audio,interface,digital-audio,philips,display,cypress,siliconi,contrib,valves,./placa_usb.cache
EELAYER 23  0
EELAYER END
$Descr A4 11700 8267
Sheet 1 1
Title "Programador USB"
Date "19 aug 2008"
Rev "1"
Comp "Laboratorio de Microcomputadores"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_4 P5
U 1 1 4897077F
P 9850 2400
F 0 "P5" V 9800 2400 50  0000 C C
F 1 "CONN_4" V 9900 2400 50  0000 C C
	1    9850 2400
	1    0    0    1   
$EndComp
$Comp
L +5V #PWR01
U 1 1 4887A648
P 5200 6550
F 0 "#PWR01" H 5200 6640 20  0001 C C
F 1 "+5V" H 5200 6640 30  0000 C C
	1    5200 6550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR02
U 1 1 487645E6
P 2150 3550
F 0 "#PWR02" H 2150 3640 20  0001 C C
F 1 "+5V" H 2150 3640 30  0000 C C
	1    2150 3550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 487645D8
P 2850 2900
F 0 "#PWR03" H 2850 2990 20  0001 C C
F 1 "+5V" H 2850 2990 30  0000 C C
	1    2850 2900
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 487645BF
P 9400 1250
F 0 "#PWR04" H 9400 1340 20  0001 C C
F 1 "+5V" H 9400 1340 30  0000 C C
	1    9400 1250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR05
U 1 1 487645AB
P 10800 4350
F 0 "#PWR05" H 10800 4440 20  0001 C C
F 1 "+5V" H 10800 4440 30  0000 C C
	1    10800 4350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR06
U 1 1 48764578
P 8150 3750
F 0 "#PWR06" H 8150 3840 20  0001 C C
F 1 "+5V" H 8150 3840 30  0000 C C
	1    8150 3750
	1    0    0    -1  
$EndComp
Connection ~ 8150 4450
Connection ~ 8150 3750
Connection ~ 8150 3850
Wire Wire Line
	8150 3750 8150 3850
Connection ~ 8150 5250
Wire Wire Line
	8150 4700 8600 4700
Wire Wire Line
	8150 5800 8600 5800
Wire Wire Line
	8900 6350 8150 6350
Wire Wire Line
	9500 2550 9370 2550
Wire Wire Line
	9500 2350 8950 2350
Wire Wire Line
	9370 2550 9370 2610
Wire Wire Line
	9370 2610 9400 2610
Wire Wire Line
	9400 2610 9400 3050
Wire Wire Line
	8350 2250 8950 2250
Connection ~ 9680 2100
Connection ~ 4400 7000
Connection ~ 4400 6900
Connection ~ 4400 6800
Connection ~ 4400 6600
Connection ~ 5200 6600
Wire Wire Line
	5200 6550 5200 6600
Wire Wire Line
	4400 6900 4150 6900
Wire Wire Line
	4400 6600 4150 6600
Connection ~ 5800 2100
Connection ~ 5800 1900
Connection ~ 5800 2300
Connection ~ 5800 2500
Connection ~ 5800 2700
Connection ~ 5800 3000
Connection ~ 5800 3800
Connection ~ 5800 4000
Connection ~ 5800 4200
Connection ~ 5800 4400
Wire Wire Line
	9400 1300 9400 1250
Wire Wire Line
	8050 5150 8050 6800
Connection ~ 7850 2450
Connection ~ 7850 2250
Connection ~ 8450 2350
Connection ~ 2050 6300
Connection ~ 2350 6300
Connection ~ 2050 5800
Connection ~ 2350 5800
Connection ~ 2350 5700
Connection ~ 2050 5700
Connection ~ 2150 3700
Connection ~ 2850 3450
Connection ~ 2850 3050
Connection ~ 2850 1500
Connection ~ 3250 1500
Connection ~ 3300 1500
Connection ~ 3300 1700
Connection ~ 3300 2300
Connection ~ 3250 2500
Connection ~ 3300 2500
Wire Wire Line
	3250 2500 3300 2500
Wire Wire Line
	3300 1700 3300 1500
Connection ~ 2850 2500
Wire Wire Line
	2850 1500 2850 2650
Wire Wire Line
	7600 2450 7850 2450
Wire Wire Line
	7600 2250 7850 2250
Connection ~ 8350 2950
Connection ~ 8350 2250
Connection ~ 8350 2450
Connection ~ 8350 2550
Connection ~ 8950 2550
Connection ~ 10250 2600
Connection ~ 10250 2200
Connection ~ 9400 1900
Connection ~ 9400 1300
Connection ~ 9750 4850
Connection ~ 10800 4400
Connection ~ 10800 5000
Connection ~ 10800 5200
Connection ~ 10800 5300
Connection ~ 10000 5600
Connection ~ 10000 5500
Connection ~ 10000 5200
Connection ~ 10000 5400
Connection ~ 8750 6800
Connection ~ 8300 6500
Connection ~ 9200 6500
Connection ~ 8750 6250
Connection ~ 9750 5950
Connection ~ 9200 5950
Connection ~ 9250 5950
Connection ~ 8750 5700
Connection ~ 8300 5950
Connection ~ 9200 5400
Connection ~ 8300 5400
Connection ~ 9250 4850
Connection ~ 9200 4850
Connection ~ 8750 5150
Connection ~ 8300 4850
Connection ~ 7700 5150
Wire Wire Line
	2150 3550 2150 3700
Wire Wire Line
	3300 4000 3150 4000
Wire Wire Line
	3150 4000 3150 3450
Wire Wire Line
	3150 3450 2850 3450
Connection ~ 10800 5600
Wire Wire Line
	10800 5950 10800 5300
Connection ~ 10800 5400
Wire Wire Line
	10800 5000 10800 5200
Wire Wire Line
	10000 5200 9750 5200
Wire Wire Line
	9750 5200 9750 4850
Wire Wire Line
	9200 5400 10000 5400
Wire Wire Line
	7700 6500 8300 6500
Connection ~ 8050 5150
Connection ~ 8050 5700
Wire Wire Line
	8050 6250 8750 6250
Connection ~ 2200 6300
Wire Wire Line
	2200 6450 2200 6300
Wire Wire Line
	2350 5700 2350 5800
Wire Wire Line
	10250 2600 10250 2950
Wire Wire Line
	10250 2950 8350 2950
Connection ~ 8950 2350
Wire Wire Line
	8950 2250 8950 2550
Connection ~ 8950 2250
Wire Wire Line
	2850 2900 2850 3050
Wire Wire Line
	10250 2200 10250 2100
Connection ~ 9400 2100
Wire Wire Line
	2850 3450 2850 3700
Wire Wire Line
	8350 2550 8350 2450
Connection ~ 9400 2950
Connection ~ 8950 2950
Wire Wire Line
	2050 5700 2050 5800
Wire Wire Line
	2350 6300 2050 6300
Wire Wire Line
	8050 5700 8750 5700
Wire Wire Line
	8050 6800 8750 6800
Connection ~ 8050 6250
Wire Wire Line
	7700 4850 8300 4850
Wire Wire Line
	7700 5950 8300 5950
Wire Wire Line
	9200 4850 9250 4850
Wire Wire Line
	9750 5950 9750 5500
Wire Wire Line
	9750 5500 10000 5500
Wire Wire Line
	10000 5600 10000 6500
Wire Wire Line
	10000 6500 9200 6500
Wire Wire Line
	10800 4350 10800 4400
Connection ~ 10800 5500
Wire Wire Line
	7300 5150 8750 5150
Wire Wire Line
	2850 3050 3300 3050
Wire Wire Line
	3300 3050 3300 3800
Connection ~ 2150 4200
Wire Wire Line
	8300 5400 7700 5400
Wire Wire Line
	7600 2350 8450 2350
Wire Wire Line
	3300 1500 3250 1500
Wire Wire Line
	3300 2500 3300 2300
Wire Wire Line
	3300 4200 2150 4200
Connection ~ 3300 4200
Connection ~ 3300 4000
Connection ~ 3300 3800
Wire Wire Line
	9200 5950 9250 5950
Connection ~ 7700 5150
Wire Wire Line
	5200 6700 5200 7100
Connection ~ 5200 6700
Connection ~ 5200 6800
Connection ~ 5200 6900
Connection ~ 5200 7000
Wire Wire Line
	4400 6800 4150 6800
Wire Wire Line
	4400 7000 4150 7000
Wire Wire Line
	9400 2100 9400 1900
Wire Wire Line
	9370 2100 9370 2250
Wire Wire Line
	9370 2100 10250 2100
Wire Wire Line
	9370 2250 9500 2250
Wire Wire Line
	8350 2450 9500 2450
Connection ~ 9500 2250
Connection ~ 9500 2350
Connection ~ 9500 2450
Connection ~ 9500 2550
Wire Wire Line
	8150 5250 8600 5250
Connection ~ 8150 5800
Wire Wire Line
	8150 6350 8150 4450
Connection ~ 8150 4700
$Comp
L JUMPER JP3
U 1 1 487642E9
P 8150 4150
F 0 "JP3" H 8150 4300 60  0000 C C
F 1 "JUMPER" H 8150 4070 40  0000 C C
	1    8150 4150
	0    1    1    0   
$EndComp
NoConn ~ 4400 6700
$Comp
L GND #PWR07
U 1 1 486A7E1E
P 5200 7100
F 0 "#PWR07" H 5200 7100 30  0001 C C
F 1 "GND" H 5200 7030 30  0001 C C
	1    5200 7100
	1    0    0    -1  
$EndComp
Text Label 4150 7000 0    60   ~
MISO
Text Label 4150 6900 0    60   ~
SCK
Text Label 4150 6800 0    60   ~
RST
Text Label 4150 6600 0    60   ~
MOSI
$Comp
L CONN_5X2 P4
U 1 1 486A7DD6
P 4800 6800
F 0 "P4" H 4800 7100 60  0000 C C
F 1 "CONN_5X2" V 4800 6800 50  0000 C C
	1    4800 6800
	1    0    0    -1  
$EndComp
NoConn ~ 5800 3600
NoConn ~ 5800 3400
NoConn ~ 5800 3200
NoConn ~ 5800 1700
NoConn ~ 5800 1500
Text Notes 900  5650 0    60   ~
de programacion
Text Notes 2800 5750 0    60   ~
USB
Text Notes 2550 5650 0    60   ~
de coneccion
Text Notes 5350 6500 0    60   ~
interna
Text Notes 5100 6400 0    60   ~
de programacion
Text Notes 5300 6300 0    60   ~
Conector
Text Notes 9750 2800 0    60   ~
USB
Text Notes 9900 5050 0    60   ~
Programacion
Text Notes 10200 4900 0    60   ~
de
Text Notes 10000 4750 0    60   ~
Conector
Text Label 5800 2700 0    60   ~
PD6
Text Label 5800 2100 0    60   ~
PD3
Text Label 5800 1900 0    60   ~
PD2
Text Label 7600 2450 0    60   ~
PD2
Text Label 7600 2250 0    60   ~
PD6
Text Label 7600 2350 0    60   ~
PD3
Text Label 5800 3800 0    60   ~
RST_B
$Comp
L R R6
U 1 1 48697D78
P 2150 3950
F 0 "R6" V 2230 3950 50  0000 C C
F 1 "10K" V 2150 3950 50  0000 C C
	1    2150 3950
	1    0    0    -1  
$EndComp
Text Label 3300 4200 0    60   ~
RST
$Comp
L JUMPER JP2
U 1 1 48697A3C
P 10800 4700
F 0 "JP2" H 10800 4850 60  0000 C C
F 1 "JUMPER" H 10800 4620 40  0000 C C
	1    10800 4700
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 48697A1B
P 10800 5950
F 0 "#PWR08" H 10800 5950 30  0001 C C
F 1 "GND" H 10800 5880 30  0001 C C
	1    10800 5950
	1    0    0    -1  
$EndComp
NoConn ~ 10000 5300
$Comp
L CONN_5X2 P1
U 1 1 4869796F
P 10400 5400
F 0 "P1" H 10400 5700 60  0000 C C
F 1 "CONN_5X2" V 10400 5400 50  0000 C C
	1    10400 5400
	1    0    0    -1  
$EndComp
Text Label 7700 5400 0    60   ~
RST_B
Text Label 7700 5950 0    60   ~
SCK
Text Label 7700 6500 0    60   ~
MISO
Text Label 7700 4850 0    60   ~
MOSI
Text Label 5800 2300 0    60   ~
Enable
Text Label 7300 5150 0    60   ~
Enable
Text Notes 1000 5550 0    60   ~
LED Testigo
Text Notes 2550 5550 0    60   ~
LED Testigo
Text Label 5800 2500 0    60   ~
Verde
Text Label 5800 3000 0    60   ~
Rojo
Text Label 2350 5300 0    60   ~
Verde
Text Label 2050 5300 0    60   ~
Rojo
$Comp
L GND #PWR09
U 1 1 48697621
P 2200 6450
F 0 "#PWR09" H 2200 6450 30  0001 C C
F 1 "GND" H 2200 6380 30  0001 C C
	1    2200 6450
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 48697611
P 2350 6050
F 0 "R5" V 2430 6050 50  0000 C C
F 1 "1.5K" V 2350 6050 50  0000 C C
	1    2350 6050
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 4869760C
P 2050 6050
F 0 "R4" V 2130 6050 50  0000 C C
F 1 "1.5K" V 2050 6050 50  0000 C C
	1    2050 6050
	1    0    0    -1  
$EndComp
$Comp
L ZENER D2
U 1 1 486975FC
P 8950 2750
F 0 "D2" H 8950 2850 50  0000 C C
F 1 "3.6V" H 8950 2650 40  0000 C C
	1    8950 2750
	0    -1   -1   0   
$EndComp
$Comp
L ZENER D1
U 1 1 486975F0
P 8350 2750
F 0 "D1" H 8350 2850 50  0000 C C
F 1 "3.6V" H 8350 2650 40  0000 C C
	1    8350 2750
	0    -1   -1   0   
$EndComp
$Comp
L LED D4
U 1 1 4869756B
P 2050 5500
F 0 "D4" H 2050 5600 50  0000 C C
F 1 "LED" H 2050 5400 50  0000 C C
	1    2050 5500
	0    1    1    0   
$EndComp
$Comp
L LED D3
U 1 1 48697559
P 2350 5500
F 0 "D3" H 2350 5600 50  0000 C C
F 1 "LED" H 2350 5400 50  0000 C C
	1    2350 5500
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 48697513
P 9500 5950
F 0 "R3" V 9580 5950 50  0000 C C
F 1 "1.5K" V 9500 5950 50  0000 C C
	1    9500 5950
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 48697506
P 9500 4850
F 0 "R2" V 9580 4850 50  0000 C C
F 1 "1.5K" V 9500 4850 50  0000 C C
	1    9500 4850
	0    1    1    0   
$EndComp
Text Label 5800 4000 0    60   ~
MOSI
Text Label 5800 4200 0    60   ~
MISO
$Comp
L GND #PWR010
U 1 1 48667FE8
P 2850 2650
F 0 "#PWR010" H 2850 2650 30  0001 C C
F 1 "GND" H 2850 2580 30  0001 C C
	1    2850 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR011
U 1 1 48667FA9
P 2850 3700
F 0 "#PWR011" H 2850 3700 30  0001 C C
F 1 "GND" H 2850 3630 30  0001 C C
	1    2850 3700
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 48667F87
P 2850 3250
F 0 "C1" H 2900 3350 50  0000 L C
F 1 "100n" H 2900 3150 50  0000 L C
	1    2850 3250
	1    0    0    -1  
$EndComp
Text Label 5800 4400 0    60   ~
SCK
$Comp
L GND #PWR012
U 1 1 48667B56
P 9400 3050
F 0 "#PWR012" H 9400 3050 30  0001 C C
F 1 "GND" H 9400 2980 30  0001 C C
	1    9400 3050
	1    0    0    -1  
$EndComp
$Comp
L JUMPER JP1
U 1 1 48667B26
P 9400 1600
F 0 "JP1" H 9400 1750 60  0000 C C
F 1 "JUMPER" H 9400 1520 40  0000 C C
	1    9400 1600
	0    1    1    0   
$EndComp
$Comp
L CAPAPOL C2
U 1 1 48667A9F
P 10250 2400
F 0 "C2" H 10300 2500 50  0000 L C
F 1 "100u" H 10300 2300 50  0000 L C
	1    10250 2400
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 48667A7D
P 8100 2450
F 0 "R8" V 8180 2450 50  0000 C C
F 1 "27" V 8100 2450 50  0000 C C
	1    8100 2450
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 48667A75
P 8700 2350
F 0 "R7" V 8780 2350 50  0000 C C
F 1 "27" V 8700 2350 50  0000 C C
	1    8700 2350
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 48667A2A
P 8100 2250
F 0 "R1" V 8180 2250 50  0000 C C
F 1 "1.5K" V 8100 2250 50  0000 C C
	1    8100 2250
	0    -1   -1   0   
$EndComp
$Comp
L CRYSTAL X1
U 1 1 486679B7
P 3300 2000
F 0 "X1" H 3300 2150 60  0000 C C
F 1 "12MHz" H 3300 1850 60  0000 C C
	1    3300 2000
	0    1    1    0   
$EndComp
$Comp
L C C4
U 1 1 486678E1
P 3050 2500
F 0 "C4" H 3100 2600 50  0000 L C
F 1 "22p" H 3100 2400 50  0000 L C
	1    3050 2500
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 486678DC
P 3050 1500
F 0 "C3" H 3100 1600 50  0000 L C
F 1 "22p" H 3100 1400 50  0000 L C
	1    3050 1500
	0    1    1    0   
$EndComp
$Comp
L 74LS125 U1
U 4 1 48667894
P 8750 6500
F 0 "U1" H 8750 6600 50  0000 L B
F 1 "74HC125N" H 8800 6350 40  0000 L T
	4    8750 6500
	-1   0    0    -1  
$EndComp
$Comp
L 74LS125 U1
U 3 1 48667881
P 8750 4850
F 0 "U1" H 8750 4950 50  0000 L B
F 1 "74HC125N" H 8800 4700 40  0000 L T
	3    8750 4850
	1    0    0    -1  
$EndComp
$Comp
L 74LS125 U1
U 2 1 48667878
P 8750 5400
F 0 "U1" H 8750 5500 50  0000 L B
F 1 "74HC125N" H 8800 5250 40  0000 L T
	2    8750 5400
	1    0    0    -1  
$EndComp
$Comp
L 74LS125 U1
U 1 1 48667869
P 8750 5950
F 0 "U1" H 8750 6050 50  0000 L B
F 1 "74HC125N" H 8800 5800 40  0000 L T
	1    8750 5950
	1    0    0    -1  
$EndComp
$Comp
L ATTINY2313DIP/SO ~U1
U 1 1 48667824
P 4550 2950
F 0 " U1" H 4525 4450 60  0000 C C
F 1 "ATTINY2313DIP/SO" H 4550 4650 60  0000 C C
	1    4550 2950
	1    0    0    -1  
$EndComp
$EndSCHEMATC
