/*
	Sunil Murali : LAB 3 Code
*/


#include "interrpt.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL 
#include <util/delay.h>


//Global declarations
//pinBit - this holds the current bit level of PORTB
//lastLED : this is the variable which holds the value for the last Bit level to light up the LED for - 7 at the load and on switch press, based on the switch 
volatile unsigned int pinBit = 0,lastLED=7;
unsigned int count = 0;								 //Counter for timer
unsigned int direction = 0;                          //Direction : 0 -> ascending ; 1->Descendiing

#define LEDToggleTime 1 								// Time constant 1 second

//Courtesy of Previous Projects --- Start of Code reuse

/* Update rate of Main Timer in seconds */
#define TIMER0_SCALER			1024

// "Medium" thread time set to every 25 mSecs.
#define TIMER0_TIME             0.025
/* The following calculates how many counts are needed to achieve the desired
 * rate. There is no checking on the resulting value, which must be less than
 * 255. 
 * For F_CPU = 8 MHz, this value works out to be 195, which is OK. 
 */
#define TIMER0_CNT				((TIMER0_TIME * F_CPU)/TIMER0_SCALER)

//Initialize function courtesy of Previous projects
void init_timer(){
	/*------------------ Set TCCR0A values --------------------------
	 * Bit 7: COM0A1 = 0  Normal port operation. No Output Compare
	 *     6: COM0A0 = 0
	 *     5: COM0B1 = 0  
	 *     4: COM0B0 = 0
	 *     3: unused = 0  
	 *     2: unused = 0
	 *     1: WGM01  = 1  Sets Waveform Generation mode to CTC
	 *     0: WGM00  = 0
	 */
	TCCR0A  = _BV(WGM01);

	/*------------------ Set TCCR0B values --------------------------
	 * Bit 7: FOCOA  = 0  Disable Force Output Compare
	 *     6: FOCOB  = 0
	 *     5: unused = 0
	 *     4: unused = 0
	 *     3: WGM02  = 0  Sets Waveform Generation mode to CTC
	 *     2: CS02   = 1  Sets prescaler to 1024, I/O clock
	 *     1: CS01   = 0
	 *     0: CS00   = 1
	 */
	TCCR0B = _BV(CS02) | _BV(CS00);
   
	// Load Compare values for timer 0
	OCR0A = TIMER0_CNT;
	OCR0B = 0;		// not using this feature

	/*----------------- Set TIMSK0 values -------------------------
	 * Bit(s) 7-3: Unused = 0
	 *          2: OCIE0B = 0  Disable timer compare interrupt B
	 *          1: OCIE0A = 1  Enable timer compare interrupt A
	 *          0: TOIE0  = 0  Disable overflow interrupt
     */
	TIMSK0 = _BV(OCIE0A);

	// Optional: Initialize timer to 0
	TCNT0 = 0; 
}

//End of Code Reuse

//Timer Interrupts
ISR(TIMER0_COMPA_vect){
	count++;
	if(count % 40 == 0){                                //1 minute delay       --     1 min /0.025 (TIMER0_TIME ) = 40 time intervals
		PORTB = ~_BV(pinBit++);							//PORT B is toggled and pinBit is increased
		count=0;										
	}
	if(pinBit > lastLED) pinBit =0; 					//when the lastLED is reached pinBit starts from 0
}

void init_interrupts(){

	PCICR = (1<<PCIE2);
	/*
		Bit 2 – PCIE2: Pin Change Interrupt Enable 1
		When the PCIE2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), pin
		change interrupt 2 is enabled. Any change on any enabled PCINT23:16 pin will cause an interrupt.
		The corresponding interrupt of Pin Change Interrupt Request is executed from the PCI2
		Interrupt Vector. PCINT23:16 pins are enabled individually by the PCMSK2 Register.
	*/
	PCMSK2  |= (1<<PCINT16) |(1<<PCINT17) |(1<<PCINT18) |(1<<PCINT19) |(1<<PCINT20) |(1<<PCINT21) |(1<<PCINT22) |(1<<PCINT23);       
	/*
  		Bit 7:0 – PCINT23:16: Pin Change Enable Mask 23:16
		Each PCINT23:16-bit selects whether pin change interrupt is enabled on the corresponding I/O
		pin. If PCINT23:16 is set and the PCIE2 bit in PCICR is set, pin change interrupt is enabled on
		the corresponding I/O pin. If PCINT23:16 is cleared, pin change interrupt on the corresponding
		I/O pin is disabled.
	*/
	//PCIFR = (1<<PCIF2);
}

//Need a better implementation of blinky
void blinkthrice(){
	PORTB = ~_BV(lastLED);                              //Restrat the LED rotation from first LED
	_delay_ms(200);
	PORTB = ~_BV(lastLED);                              //Restrat the LED rotation from first LED
	_delay_ms(200);
	PORTB = ~_BV(lastLED);                              //Restrat the LED rotation from first LED
	_delay_ms(200);
}

//Interrupts when the PortK goes high - ie, PCINT16:23 toggles
ISR(PCINT2_vect ){
	unsigned int swPressed;
	//Checking the Pressed switch
	swPressed = ((~PINK) & ((1<<PINK0)|(1<<PINK1)|(1<<PINK2)|(1<<PINK3)|(1<<PINK4)|(1<<PINK5)|(1<<PINK6)|(1<<PINK7)));       
	//PORTB = ~swPressed;                                   
	
	//Setting the lastLED to be lit based on the pin selection. While rotating the last LED to light up would be the switch that was pressed
	if(swPressed & (1<<PINK0))
		lastLED = 0;
	else if(swPressed & (1<<PINK1))
		lastLED = 1;
	else if(swPressed & (1<<PINK2))
		lastLED = 2;
	else if(swPressed & (1<<PINK3))
		lastLED = 3;
	else if(swPressed & (1<<PINK4))
		lastLED = 4;
	else if(swPressed & (1<<PINK5))
		lastLED = 5;
	else if(swPressed & (1<<PINK6))
		lastLED = 6;
	else if(swPressed & (1<<PINK7))
		lastLED = 7;
	pinBit = 0;
	PORTB = ~_BV(0);				  ///.... Start LED Toggle from the first bit ie Bit 0
	//blinkthrice();                  ///.... Blinking not working - need more work into it!
}
