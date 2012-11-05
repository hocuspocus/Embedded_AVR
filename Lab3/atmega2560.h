/* Register Access functions */
#define WRITEREG(addr, data) *((volatile unsigned char *)(addr)) = (data)
#define READREG(addr) *((volatile unsigned char *)(addr))

/* GPIO Port Definitions */
//Port A
#define PORTA 0x22
#define DDRA 0x21
#define PA0 (1<<0)
#define PA1 (1<<1)
#define PA2 (1<<2)
#define PA3 (1<<3)
#define PA4 (1<<4)
#define PA5 (1<<5)
#define PA6 (1<<6)
#define PA7 (1<<7)

//Port B
#define PORTB 0x25
#define DDRB 0x24
#define PB0 (1<<0)
#define PB1 (1<<1)
#define PB2 (1<<2)
#define PB3 (1<<3)
#define PB4 (1<<4)
#define PB5 (1<<5)
#define PB6 (1<<6)
#define PB7 (1<<7)

//Port C
#define PORTC 0x28
#define DDRC 0x27
#define PC0 (1<<0)
#define PC1 (1<<1)
#define PC2 (1<<2)
#define PC3 (1<<3)
#define PC4 (1<<4)
#define PC5 (1<<5)
#define PC6 (1<<6)
#define PC7 (1<<7)

//Port D
#define PORTD 0x2B
#define DDRD 0x2A
#define PD0 (1<<0)
#define PD1 (1<<1)
#define PD2 (1<<2)
#define PD3 (1<<3)
#define PD4 (1<<4)
#define PD5 (1<<5)
#define PD6 (1<<6)
#define PD7 (1<<7)

//Port E
#define PORTE 0x2E
#define DDRE 0x2D
#define PE0 (1<<0)
#define PE1 (1<<1)
#define PE2 (1<<2)
#define PE3 (1<<3)
#define PE4 (1<<4)
#define PE5 (1<<5)
#define PE6 (1<<6)
#define PE7 (1<<7)

//Port F
#define PORTF 0x31
#define DDRF 0x30
#define PF0 (1<<0)
#define PF1 (1<<1)
#define PF2 (1<<2)
#define PF3 (1<<3)
#define PF4 (1<<4)
#define PF5 (1<<5)
#define PF6 (1<<6)
#define PF7 (1<<7)

//Port G
#define PORTG 0x34
#define DDRG 0x33
#define PG0 (1<<0)
#define PG1 (1<<1)
#define PG2 (1<<2)
#define PG3 (1<<3)
#define PG4 (1<<4)
#define PG5 (1<<5)
#define PG6 (1<<6)
#define PG7 (1<<7)

//Port H
#define PORTH 0x102
#define DDRH 0x101
#define PH0 (1<<0)
#define PH1 (1<<1)
#define PH2 (1<<2)
#define PH3 (1<<3)
#define PH4 (1<<4)
#define PH5 (1<<5)
#define PH6 (1<<6)
#define PH7 (1<<7)

//Port J
#define PORTJ 0x105
#define DDRJ 0x104
#define PJ0 (1<<0)
#define PJ1 (1<<1)
#define PJ2 (1<<2)
#define PJ3 (1<<3)
#define PJ4 (1<<4)
#define PJ5 (1<<5)
#define PJ6 (1<<6)
#define PJ7 (1<<7)

//Port K
#define PORTK 0x108
#define DDRK 0x107
#define PK0 (1<<0)
#define PK1 (1<<1)
#define PK2 (1<<2)
#define PK3 (1<<3)
#define PK4 (1<<4)
#define PK5 (1<<5)
#define PK6 (1<<6)
#define PK7 (1<<7)

//Port L
#define PORTL 0x10B
#define DDRL 0x10A
#define PL0 (1<<0)
#define PL1 (1<<1)
#define PL2 (1<<2)
#define PL3 (1<<3)
#define PL4 (1<<4)
#define PL5 (1<<5)
#define PL6 (1<<6)
#define PL7 (1<<7)

/* SREG */
#define C (1<<0)
#define Z (1<<1)
#define N (1<<2)
#define V (1<<3)
#define S (1<<4)
#define H (1<<5)
#define T (1<<6)
#define I (1<<7)

/* Timers */
#define OCR2B 0XB4
#define OCR2A 0xB3

#define OCR5CH 0x12D
#define OCR5CL 0x12C
#define OCR5BH 0x12B
#define OCR5BL 0x12A
#define OCR5AH 0x129
#define OCR5AL 0x128
#define ICR5H 0x127
#define ICR5L 0x126
#define TCNT5H 0x125
#define TCNT5L 0x124

#define OCR4CH 0xAD
#define OCR4CL 0xAC
#define OCR4BH 0xAB
#define OCR4BL 0xAA
#define OCR4AH 0xA9
#define OCR4AL 0xA8
#define ICR4H 0xA7
#define ICR4L 0xA6
#define TCNT4H 0xA5
#define TCNT4L 0xA4

#define OCR3CH 0x9D
#define OCR3CL 0x9C
#define OCR3BH 0x9B
#define OCR3BL 0x9A
#define OCR3AH 0x99
#define OCR3AL 0x98
#define ICR3H 0x97
#define ICR3L 0x96
#define TCNT3H 0x95
#define TCNT3L 0x94

#define OCR1CH 0x8D
#define OCR1CL 0x8C
#define OCR1BH 0x8B
#define OCR1BL 0x8A
#define OCR1AH 0x89
#define OCR1AL 0x88
#define ICR1H 0x87
#define ICR1L 0x86
#define TCNT1H 0x85
#define TCNT1L 0x84

//TCCR2A
#define TCCR2A 0xB0
#define WGM20 (1<<0)
#define WGM21 (1<<1)
#define COM2B0 (1<<4)
#define COM2B1 (1<<5)
#define COM2A0 (1<<6)
#define COM2A1 (1<<7)

//TCCR0A
#define TCCR0A 0x44
#define WGM00 (1<<0)
#define WGM01 (1<<1)
#define COM0B0 (1<<4)
#define COM0B1 (1<<5)
#define COM0A0 (1<<6)
#define COM0A1 (1<<7)

//TCCR2B
#define TCCR2B 0xB1
#define CS20 (1<<0)
#define CS21 (1<<1)
#define CS22 (1<<2)
#define WGM22 (1<<3)
#define FOC2B (1<<6)
#define FOC2A (1<<7)

//TCCR0B
#define TCCR0B 0x45
#define CS00 (1<<0)
#define CS01 (1<<1)
#define CS02 (1<<2)
#define WGM02 (1<<3)
#define FOC0B (1<<6)
#define FOC0A (1<<7)

//TIMSK5
#define TIMSK5 0x73
#define TOIE5 (1<<0)
#define OCIE5A (1<<1)
#define OCIE5B (1<<2)
#define OCIE5C (1<<3)
#define ICIE5 (1<<5)

//TIMSK4
#define TIMSK4 0x72
#define TOIE4 (1<<0)
#define OCIE4A (1<<1)
#define OCIE4B (1<<2)
#define OCIE4C (1<<3)
#define ICIE14 (1<<5)

//TIMSK3
#define TIMSK3 0x71
#define TOIE3 (1<<0)
#define OCIE3A (1<<1)
#define OCIE3B (1<<2)
#define OCIE3C (1<<3)
#define ICIE3 (1<<5)

//TIMSK2
#define TIMSK2 0x70
#define TOIE2 (1<<0)
#define OCIE2A (1<<1)
#define OCIE2B (1<<2)

//TIMSK1
#define TIMSK1 0x6F
#define TOIE1 (1<<0)
#define OCIE1A (1<<1)
#define OCIE1B (1<<2)
#define OCIE1C (1<<3)
#define ICIE1 (1<<5)

//TIMSK0
#define TIMSK0 0x6E
#define TOIE0 (1<<0)
#define OCIE0A (1<<1)
#define OCIE0B (1<<2)

//TIFR2 
#define TOV2 (1<<0)
#define OCF2A (1<<1)
#define OCF2B (1<<2)

/* SPI */
//SPCR
#define SPCR 0x4C
#define SPR0 (1<<0)
#define SPR1 (1<<1)
#define CPHA (1<<2)
#define CPOL (1<<3)
#define MSTR (1<<4)
#define DORD (1<<5)
#define SPE (1<<6)
#define SPIE (1<<7)

//SPSR
#define SPSR 0x4D
#define SPI2X (1<<0)
#define WCOL (1<<6)
#define SPIF (1<<7)

/* USART */
#define UDR0 0xC6
#define UDR1 0xCE
#define UDR2 0xD6
#define USR 0x0B
#define UBRR0H 0xC5
#define UBRR0L 0xC4
#define UBRR1H 0xCD
#define UBRR1L 0xCC
#define UBRR2H 0xD5
#define UBRR2L 0xD4
#define UBRR3H 0x135
#define UBRR3L 0x134

//UCSRnA
#define UCSR0A 0xC0
#define UCSR1A 0xC8
#define UCSR2A 0xD0
#define UCSR3A 0x130

#define MPCM (1<<0)						//Multi Processor Communication mode
#define U2X (1<<1)							//Double the USART Transmission speed
#define UPE (1<<2)							//USART Parity Error
#define DOR (1<<3)							//Data Overrrun
#define FE (1<<4)							//Frame Error
#define UDRE (1<<5)                        //USART Data Register Emtyp
#define TXC (1<<6)                         //Transmit Complete
#define RXC (1<<7)                         //Receive Complete

//UCSRnB
#define UCSR0B 0xC1
#define UCSR1B 0xC9
#define UCSR2B 0xD1
#define UCSR3B 0x131

#define TXB8 (1<<0)						//transmit data bit 8 n
#define RXB8 (1<<1)						//receive data bit 8 n
#define UCSZ2 (1<<2)						//character size n
#define TXEN (1<<3)						//Transmitter enable
#define RXEN (1<<4)						//Receiver enable
#define UDRIE (1<<5)						//USART Data Register Empty Interrupt Enable n
#define TXCIE (1<<6)						//TX Complete Interrup enable
#define RXCIE (1<<7)						//RX Complete Interrupt Enable

//UCSRnC
#define UCSR0C 0xC2
#define UCSR1C 0xCA
#define UCSR2C 0xD2
#define UCSR3C 0x132

#define UCPOL (1<<0)						//Clock Polarity
#define UCSZ0 (1<<1)						//Character Size	
#define UCSZ1 (1<<2)						//Character Size
#define USBS (1<<3)						//Stop Bit Select
#define UPM0 (1<<4)						//Parity Mode
#define UPM1 (1<<5)						//Parity Mode
#define UPM1 (1<<5)						//Parity Mode
#define UMSEL0 (1<<6)						//USART Mode Select
#define UMSEL1 (1<<7)                      //USART Mode Select 

/* ADC */
#define ADCL 0x78
#define ADCH 0x79

//ADMUX
#define MUX0 (1<<0)							//MUX 0 - 4 -> Analog Channel and Gain Selection Bits
#define MUX1 (1<<1)
#define MUX2 (1<<2)
#define MUX3 (1<<3)
#define MUX4 (1<<4)							
#define ADLAR (1<<5)						//ADC Left Adjust result
#define REFS0 (1<<6)                        // Ref Seelction bit
#define REFS1 (1<<7)						// Ref Seelction bit

//ADCSRB
#define ADTS0 (1<<0)
#define ADTS1 (1<<1)
#define ADTS2 (1<<2)
#define MUX5 (1<<3)
#define ACME (1<<6)

//ADCSRA
#define ADPS0 (1<<0)
#define ADPS1 (1<<1)
#define ADPS2 (1<<2)
#define ADIE (1<<3)
#define ADIF (1<<4)
#define ADATE (1<<5)
#define ADSC (1<<6)
#define ADEN (1<<7)

/* EEPROM */
#define EEARH (0x42)
#define EEARL (0x41)
#define EEDR (0x40)
#define EECR (0x3F)


