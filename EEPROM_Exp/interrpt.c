/*
	Sunil Murali : LAB 3 Code
*/

#include "atmega2560.h"
#include "interrpt.h"
#include "delay.h"
#define F_CPU 8000000UL

#define blinkDelay 500           				                  /*delay for blink*/
#define LEDToggleTime 1 									      /* Time constant 1 second*/
unsigned int direction = 0;                          			  /*Direction : 0 -> ascending ; 1->Descendiing*/	
unsigned int swPressed;												/*which pin is pressed */

#define TIME_INTERVAL_COUNT	7800								  /* From below TIMER0_TIME = 0.025. Calculation for 0.025mSec interrupt level is 195
																	To get the 1 minute time interval count is (1/0.025)*195 = 7800
																  */
/*Courtesy of Previous Projects --- Start of Code reuse*/

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
	WRITEREG(TCCR0A,1<<WGM01);
	//TCCR0A = 1<<WGM01;

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
	WRITEREG(TCCR0B,(1<<CS02 |1<<CS00));
	//TCCR0B = (1<<CS02 |1<<CS00);
   
	// Load Compare values for timer 0
	WRITEREG(OCR0A,TIMER0_CNT);
	//OCR0A = TIMER0_CNT;
	WRITEREG(OCR0B,0);		// not using this feature
	//OCR0B = 0;
	/*----------------- Set TIMSK0 values -------------------------
	 * Bit(s) 7-3: Unused = 0
	 *          2: OCIE0B = 0  Disable timer compare interrupt B
	 *          1: OCIE0A = 1  Enable timer compare interrupt A
	 *          0: TOIE0  = 0  Disable overflow interrupt
     */
	WRITEREG(TIMSK0,1<<OCIE0A);
	//TIMSK0 = 1<<OCIE0A;
	/* Optional: Initialize timer to 0*/
	WRITEREG(TCNT0,0); 
	//TCNT0 = 0;
}

/*End of Code Reuse*/


void init_interrupts(){
	WRITEREG(PCICR,1<<PCIE2);
	//PCICR = 1<< PCIE2;
	/*
		Bit 2 – PCIE2: Pin Change Interrupt Enable 1
		When the PCIE2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), pin
		change interrupt 2 is enabled. Any change on any enabled PCINT23:16 pin will cause an interrupt.
		The corresponding interrupt of Pin Change Interrupt Request is executed from the PCI2
		Interrupt Vector. PCINT23:16 pins are enabled individually by the PCMSK2 Register.
	*/
	WRITEREG(PCMSK2, (1<<PCINT16 |1<<PCINT17 |1<<PCINT18 |1<<PCINT19 |1<<PCINT20 |1<<PCINT21 |1<<PCINT22 |1<<PCINT23));       
	//PCMSK2 = (1<<PCINT16 |1<<PCINT17 |1<<PCINT18 |1<<PCINT19 |1<<PCINT20 |1<<PCINT21 |1<<PCINT22 |1<<PCINT23);
	/*
		ENAABLE EXTENRNAL INTERRUPTS FOR ALL THE SWITCHES

  		Bit 7:0 – PCINT23:16: Pin Change Enable Mask 23:16
		Each PCINT23:16-bit selects whether pin change interrupt is enabled on the corresponding I/O
		pin. If PCINT23:16 is set and the PCIE2 bit in PCICR is set, pin change interrupt is enabled on
		the corresponding I/O pin. If PCINT23:16 is cleared, pin change interrupt on the corresponding
		I/O pin is disabled.
	*/
	
}

/*Need a better implementation of blinky*/
/*
	On button click the corresponding led will blink thrice
*/
void blinkthrice(){
	WRITEREG(PORTB, ~BV(lastLED));                              /*Restrat the LED rotation from first LED*/
	//PORTB = ~BV(lastLED);
	delay(blinkDelay);
	//PORTB = 0xFF;
	WRITEREG(PORTB, 0xFF);                              		/*Restrat the LED rotation from first LED*/
	delay(blinkDelay);	
}

/*Interrupts when the PortK goes high - ie, PCINT16:23 toggles */
//ISR(PCINT2_vect ){
void __vector_11(void){
	/*Checking for the Pressed switch*/
	//swPressed = ((~PORTK) & ((1<<PK0)|(1<<PK1)|(1<<PK2)|(1<<PK3)|(1<<PK4)|(1<<PK5)|(1<<PK6)|(1<<PK7)));	
	swPressed = READREG(PINK);
}


void onButtonPress(){
	cli();      /*This takes care of the timer interrupts which was causing issues*/
	/*Setting the lastLED to be lit based on the pin selection. While rotating the last LED to light up would be the switch that was pressed*/
	if(~swPressed & 0x01)
		lastLED = 0;
	else if(~swPressed & 0x02)
		lastLED = 1;
	else if(~swPressed & 0x04)
		lastLED = 2;
	else if(~swPressed & 0x08)
		lastLED = 3;
	else if(~swPressed & 0x10)
		lastLED = 4;
	else if(~swPressed & 0x20)
		lastLED = 5;
	else if(~swPressed & 0x40)
		lastLED = 6;
	else if(~swPressed & 0x80)
		lastLED = 7;
	pinBit = 0;
	//PORTB = ~_BV(lastLED);				/*.... Start LED Toggle from the first bit ie Bit 0*/
	blinkthrice();                 
	WRITEREG(PORTB,0xFF);
	//PORTB = 0xFF;
 	swPressed = 0;                          /*A poor implementation */
	sei();
}


/*Timer Interrupts*/
//ISR(TIMER0_COMPA_vect){
void __vector_21(void){
	count++;
	if(count % 7800 == 0){                					/*For 1 minute delay  -> 1 min /0.025 (TIMER0_TIME - configured in the Timer inits ) = 40 time intervals*/
		WRITEREG(PORTB, ~(1<<pinBit++));								/*PORT B is toggled and pinBit is increased*/
		//PORTB = ~(1<<pinBit++);
		count=0;										
	}
	if(pinBit > lastLED) pinBit =0; 						/*when the lastLED is reached pinBit starts from 0*/
}
