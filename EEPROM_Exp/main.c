/*
	Project			:		Lab 3 / Portable Device Drivers
	Author			:		Sunil Murali
	Description		:		This code will do the following function
							1. On load, the led will be running from 0-7.
							2. When there is a user event: Switch is pressed, led will rotate from 0 to the switch pressed
							
							Interrupts are used to detect the switch press event
							Timers are uded for delay	

							Pending:
								- Switch Debouncing
								- LEDS should toggle only when the switch is released
							
							Features Planning to Add:                 
								- Mode 1: LED going back and forth - led will toggle from 0 to last LED and to 0 : direction
								- Mode 2: When user presses a button blink thrice to acknowledge and restart count
								- Note: Mode 3: this will be the Current script for LED toggle
								- Mode set via USART menu for LEDs

	Code Instructions:
		1. PORT B - Configured for LEDS
		2. PORT K - Configured for switches
		
*/
#include "atmega2560.h"
#include "interrpt.h"
#include "eeprom.h"
#include "serial.h"
#include "delay.h"
#define INTERRUPT_INTERVAL 40                        			   /*Interrupt interval used in timer interrupts  */
extern unsigned int swPressed;												/*which pin is pressed */
	
/*Main Program*/
int main(){
	/*Port initializations forr LEDS and Switches*/
	WRITEREG(DDRB,0xFF);											/*PORTB for LEDS*/
	WRITEREG(PORTB,0x00);
	WRITEREG(DDRK,0x00);											/*PORTK as input from switches : PCIN16:PCINT23*/
	WRITEREG(PORTK,0xff);
	
	cli();                                                          /*Clear interrpts*/
	USART_init();													/* Initialize Serial Rx Tx - check*/
	init_timer();													/*Timer initialization - check*/	
	init_interrupts();												/*Interrupts initialization -Lock and Load*/
	
	/*Initializing the variables*/
	count = 0;											
	lastLED = 7;
	pinBit=0;
	swPressed=0;
	sei();         													/*Enable Interrupts*/
	while(1){
		if(swPressed)												/*When a switch is pressed onButtonPRess function is entered - which handles the PORTB bits*/
			onButtonPress();
	}
	return 0;
}
