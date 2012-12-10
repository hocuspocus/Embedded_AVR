/*
	Interrupts for LAB 3 : LED toggle
		Timer interrupt
		External Interrupt
*/

#ifndef interrpt_h																	/*INTERRPT_H DEFINITION STARTS*/
	#define interrpt_h
	extern void __vector_21 (void) __attribute__ ((signal));
	extern void __vector_11 (void) __attribute__ ((interrupt));						/* ISR(PCINT2_vect)*/

	/*
		Global declarations
		pinBit - this holds the current bit level of PORTB
		lastLED : this is the variable which holds the value for the last Bit level to light up the LED for - 7 at the load and on switch press, based on the switch 
	*/
	volatile unsigned int count;								  					/*Counter for timer*/
	volatile unsigned int pinBit;													/*current pin value */
	volatile unsigned int lastLED;													/* keeps track of the last LED to light*/

	void init_timer();																/*function to initalize the timers*/
	void init_interrupts();															/*interrupt initialization definitions*/
	void onButtonPress();															/*function executed when the btton click event occurs - when swPressed hols a value */
	void countincrease(void);														/*this function is unuses*/

#endif																				/* INTERRPT_H ENDS*/



