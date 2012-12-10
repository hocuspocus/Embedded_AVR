/*
	Serial for LAB 3 : LED toggle
*/

#ifndef serial_h								/*SERIAL_H BEGINS*/
#define serial_h

void __vector_25 (void) __attribute__ ((signal)); 	/*RX interrupt vector*/
void __vector_26 (void) __attribute__ ((signal));
/*initialize serial RX and TX*/
#ifndef F_CPU
#define F_CPU 8000000UL
#endif
#define BAUD 9600											/* Baud Rate for the communication set at 9600*/
#define UBRR_VALUE (((F_CPU / (BAUD * 16UL))) - 1)			/*UBRR Value calculation*/

#define CTRL_N (unsigned char)0x0E
#define CTRL_Y (unsigned char)0x19
#define CTRL_Z (unsigned char)0x1A
#define BACKSPACE (unsigned char)0x28

/*Init USART*/
void USART_init();

/*Serial RX*/
unsigned char USART_Receive( void );

/*Serial TX*/
void USART_Transmit( unsigned char data );

/*digits 0-9*/
unsigned char numarr[] = "0123456789";

#endif											/*SERIAL_H END*/
