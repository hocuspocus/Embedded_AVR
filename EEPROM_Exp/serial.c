/*
	@description:		Lab 3 Serial 
	@author		:		Sunil Murali
*/
#include "atmega2560.h"
#include "serial.h"
#include "eeprom.h"

#define EEPROM_LAST_BYTE 4096

//unsigned char RXData;
//unsigned int RXFlag;

volatile unsigned int eeprom_current_byte;
volatile int eeprom_size;
volatile unsigned char RXData;
unsigned int writeflag=0;
unsigned int readflag=0;
unsigned int countflag=0;

void USART_init(void)
{
	/* Set baud rate*/
	WRITEREG(UBRR0H, (UBRR_VALUE>>8));
	WRITEREG(UBRR0L, UBRR_VALUE);
	/* Set frame format to 8 data bits, no parity, 1 stop bit*/
	WRITEREG(UCSR0C, (1<<UCSZ1)|(1<<UCSZ0));
	/*enable transmission and reception*/
	WRITEREG(UCSR0B, (1<<RXCIE)|(1<<RXEN)|(1<<TXEN));
	WRITEREG(UCSR0A,0);
}
/*
void USART_Transmit( unsigned char data )
{
	//wait while previous byte is completed
	while((READREG(UCSR0A) & (1<<UDRE))==0){};
	// Transmit data
	WRITEREG(UDR0, data);
}

unsigned char USART_Receive( void) 
{
	// Wait for byte to be received
	while((READREG(UCSR0A) & (1<<RXC))==0){};
	// Return received data
	return READREG(UDR0);
}
*/
//Receive USART
void __vector_25 (void)
{ 
    cli();
	//Read the received bit
	RXData = READREG(UDR0);														
	
    if(RXData == CTRL_Z){                  								//On Ctrl+Z, writeflag is toggled
		writeflag = !writeflag;
	}
	else if (RXData == CTRL_Y){											//On Ctrl+Y, readflag is turned on
		readflag = 1;
	}
	else if (RXData == CTRL_N){										//On Ctrl+N, display the count
		countflag = 1;
	}
	if(writeflag && RXData != CTRL_Z && RXData != CTRL_Y){				//Avoid saving the Ctrl+Z and Ctrl+Y character in EEPROM
		if(eeprom_current_byte == EEPROM_LAST_BYTE){					//Turn off the EEPROM write when last character is reached
			writeflag=0;
		}
	
		if (RXData == BACKSPACE){										//On backspace clear the previous character
			eeprom_current_byte = eeprom_current_byte==0 ? 0 : --eeprom_current_byte;
			EEPROM_write(eeprom_current_byte,0xFF);
		}
		else
			EEPROM_write(eeprom_current_byte++,RXData);					//On all other occasions, write the input char to EEPROM
	}
	SET_BIT(UCSR0B,UDRIE);												//Setting tx flag to print what is writt
	sei();
}

//Transmit USART
void __vector_26(void){
	cli();
	unsigned int i=0,tempVal,index=0;
	char temp[4];
	if(readflag){														//On read, get each character and put it in UDR0 register and wait for the transmit
		eeprom_size = eeprom_current_byte;
		for(i = 0; i < eeprom_size; i++){			
			while((READREG(UCSR0A) & (1<<UDRE))==0){};
			WRITEREG(UDR0, EEPROM_read(i));	
		}					
		readflag=0;														//readflag unset after all characters been read
	}
	else if(countflag){													//On count flag write the size
		if(eeprom_current_byte == 0){
			WRITEREG(UDR0,arr[0]);
		}
		else{															//convert number to characters and store them in array
			tempVal = eeprom_current_byte;
				
			while (tempVal > 0){
				temp[index++] = arr[tempVal%10];
				tempVal /= 10;
			}
			while(index--){												//printing the character array cntaingin the size 
				WRITEREG(UDR0,temp[index]);
			}
		}
		countflag = 0;													
	}
	else 
		WRITEREG(UDR0,RXData);											//transmit character that has been typed 

	CLEAR_BIT(UCSR0B,UDRIE);
	sei();
}

