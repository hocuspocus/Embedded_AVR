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
#include <avr\interrupt.h>

//Main Program
int main(){
	//Port initializations fr LEDS and Switches
	DDRB 	= 0xFF;    //PORTB for LEDS
	PORTB 	= 0x00;
	DDRK = 0x00;  //PORTK as input from switches : PCIN16:PCINT23
	PORTK = 0xff;
	
	cli();                                                               //Clear interrpts
	init_timer();
	init_interrupts();
	sei();                                                         //Enabling interrupts after initialization
	
	while(1){
		//Nothing to do here
    }
}


