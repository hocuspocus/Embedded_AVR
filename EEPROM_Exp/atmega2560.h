#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

/* Register Access functions */
#define WRITEREG(addr, data) *((volatile unsigned char *)(addr)) = (data)
#define READREG(addr) *((volatile unsigned char *)(addr))
#define BV(bit) (1<<bit) 														/*Bit shifting macro*/

#define CLEAR_BIT(port, bit) *((volatile unsigned char *)port) = (*((volatile unsigned char *)port) & (~(1 << bit)))
#define SET_BIT(port, bit) *((volatile unsigned char *)port) = (*((volatile unsigned char *)port) | (1 << bit))

/*
	Pending:
		comments for I/O         
		comment for timers         
		comments for interrupts   -- done
		comments for SPI
		comment for UART
		
*/
/* GPIO Port Definitions */
//Port A
#define PORTA 		0x22
#define DDRA 		0x21
#define PINA 		0x20
#define PA0 		0
#define PA1 		1
#define PA2 		2
#define PA3 		3
#define PA4 		4
#define PA5 		5
#define PA6 		6
#define PA7 		7

//Port B
#define PORTB 		0x25
#define DDRB 		0x24
#define PINB 		0x23
#define PB0 		0
#define PB1 		1
#define PB2 		2
#define PB3 		3
#define PB4 		4
#define PB5 		5
#define PB6 		6
#define PB7 		7

//Port C
#define PORTC 		0x28
#define DDRC 		0x27
#define PINC 		0x26
#define PC0 		0
#define PC1 		1
#define PC2 		2
#define PC3 		3
#define PC4 		4
#define PC5 		5
#define PC6 		6
#define PC7 		7

//Port D
#define PORTD 		0x2B
#define DDRD 		0x2A
#define PIND 		0x29
#define PD0 		0
#define PD1 		1
#define PD2 		2
#define PD3 		3
#define PD4 		4
#define PD5 		5
#define PD6 		6
#define PD7 		7

//Port E
#define PORTE 		0x2E
#define DDRE 		0x2D
#define PINE 		0x2C
#define PE0 		0
#define PE1 		1
#define PE2 		2
#define PE3 		3
#define PE4 		4
#define PE5 		5
#define PE6 		6
#define PE7 		7

//Port F
#define PORTF 		0x31
#define DDRF 		0x30
#define PINF 		0x2F
#define PF0 		0
#define PF1 		1
#define PF2 		2
#define PF3 		3
#define PF4 		4
#define PF5 		5
#define PF6 		6
#define PF7 		7

//Port G
#define PORTG 		0x34
#define DDRG 		0x33
#define PING 		0x32
#define PG0 		0
#define PG1 		1
#define PG2 		2
#define PG3 		3
#define PG4 		4
#define PG5 		5
#define PG6 		6
#define PG7 		7

//Port H
#define PORTH 		0x102
#define DDRH 		0x101
#define PINH 		0x100
#define PH0 		0
#define PH1 		1
#define PH2 		2
#define PH3 		3
#define PH4 		4
#define PH5 		5
#define PH6 		6
#define PH7 		7

//Port J
#define PORTJ 		0x105
#define DDRJ 		0x104
#define PINJ 		0x103
#define PJ0 		0
#define PJ1 		1
#define PJ2 		2
#define PJ3 		3
#define PJ4 		4
#define PJ5 		5
#define PJ6 		6
#define PJ7 		7

//Port K
#define PORTK 		0x108
#define DDRK 		0x107
#define PINK 		0x106
#define PK0 		0
#define PK1 		1
#define PK2 		2
#define PK3 		3
#define PK4 		4
#define PK5 		5
#define PK6 		6
#define PK7 		7

//Port L
#define PORTL 		0x10B
#define DDRL 		0x10A
#define PINL 		0x109
#define PL0 		0
#define PL1 		1
#define PL2 		2
#define PL3 		3
#define PL4 		4
#define PL5 		5
#define PL6 		6
#define PL7 		7
	
/* SREG */
#define C 			0
#define Z 			1
#define N 			2
#define V 			3
#define S 			4
#define H 			5
#define T 			6
#define I 			7

/* Timers */
#define OCR2B 		0XB4
#define OCR2A 		0xB3

#define OCR5CH 		0x12D
#define OCR5CL 		0x12C
#define OCR5BH 		0x12B
#define OCR5BL 		0x12A
#define OCR5AH 		0x129
#define OCR5AL 		0x128
#define ICR5H 		0x127
#define ICR5L 		0x126
#define TCNT5H 		0x125
#define TCNT5L 		0x124

#define OCR4CH 		0xAD
#define OCR4CL 		0xAC
#define OCR4BH 		0xAB
#define OCR4BL 		0xAA
#define OCR4AH 		0xA9
#define OCR4AL 		0xA8
#define ICR4H 		0xA7
#define ICR4L 		0xA6
#define TCNT4H 		0xA5
#define TCNT4L 		0xA4

#define OCR3CH 		0x9D
#define OCR3CL 		0x9C
#define OCR3BH 		0x9B
#define OCR3BL 		0x9A
#define OCR3AH 		0x99
#define OCR3AL 		0x98
#define ICR3H 		0x97
#define ICR3L 		0x96
#define TCNT3H 		0x95
#define TCNT3L 		0x94

#define OCR1CH 		0x8D
#define OCR1CL 		0x8C
#define OCR1BH 		0x8B
#define OCR1BL 		0x8A
#define OCR1AH 		0x89
#define OCR1AL 		0x88
#define ICR1H 		0x87
#define ICR1L 		0x86
#define TCNT1H	 	0x85
#define TCNT1L 		0x84

//TCCR2A
#define TCCR2A 		0xB0
#define WGM20 		0
#define WGM21 		1
#define COM2B0 		4
#define COM2B1 		5
#define COM2A0 		6
#define COM2A1 		7

/*TCCR0A 
• Bits 7:6 – COM0A1:0: Compare Match Output A Mode
These bits control the Output Compare pin (OC0A) behavior. If one or both of the COM0A1:0
bits are set, the OC0A output overrides the normal port functionality of the I/O pin it is connected
to. However, note that the Data Direction Register (DDR) bit corresponding to the OC0A pin
must be set in order to enable the output driver.
When OC0A is connected to the pin, the function of the COM0A1:0 bits depends on the
WGM02:0 bit setting. Table 15-2 shows the COM0A1:0 bit functionality when the WGM02:0 bits
are set to a normal or CTC mode (non-PWM).

Compare Output Mode, non-PWM Mode:
COM0A1 COM0A0 	Description
0 		0 		Normal port operation, OC0A disconnected.
0 		1 		Toggle OC0A on Compare Match.
1 		0 		Clear OC0A on Compare Match.
1 		1 		Set OC0A on Compare Match.

Compare Output Mode, Fast PWM Mode:
COM0A1 COM0A0 	Description
	0	0 		Normal port operation, OC0A disconnected.
	0	1		WGM02 = 0: Normal Port Operation, OC0A Disconnected.
				WGM02 = 1: Toggle OC0A on Compare Match.
	1 	0		Clear OC0A on Compare Match, set OC0A at BOTTOM
				(non-inverting mode).
	1 	1		Set OC0A on Compare Match, clear OC0A at BOTTOM
				(inverting mode).
Compare Output mode, Phase correcte PWM Mode:
COM0A1 COM0A0 	Description
	0 	0 		Normal port operation, OC0A disconnected.
	0 	1		WGM02 = 0: Normal Port Operation, OC0A Disconnected.
				WGM02 = 1: Toggle OC0A on Compare Match.
	1 	0		Clear OC0A on Compare Match when up-counting. Set OC0A on
				Compare Match when down-counting.
	1 	1		Set OC0A on Compare Match when up-counting. Clear OC0A on
				Compare Match when down-counting.

Bits 5:4 – COM0B1:0: Compare Match Output B Mode
These bits control the Output Compare pin (OC0B) behavior. If one or both of the COM0B1:0
bits are set, the OC0B output overrides the normal port functionality of the I/O pin it is connected
to. However, note that the Data Direction Register (DDR) bit corresponding to the OC0B pin
must be set in order to enable the output driver.
When OC0B is connected to the pin, the function of the COM0B1:0 bits depends on the
WGM02:0 bit setting. 

Bits 3, 2 – Res: Reserved Bits
These bits are reserved bits and will always read as zero.
• Bits 1:0 – WGM01:0: Waveform Generation Mode
Combined with the WGM02 bit found in the TCCR0B Register, these bits control the counting
sequence of the counter, the source for maximum (TOP) counter value, and what type of waveform
generation to be used, see Table 15-8. Modes of operation supported by the Timer/Counter
unit are: Normal mode (counter), Clear Timer on Compare Match (CTC) mode, and two types of
Pulse Width Modulation (PWM) modes

*/
#define TCCR0A 		0x44
#define WGM00 		0
#define WGM01 		1
#define COM0B0 		4
#define COM0B1 		5
#define COM0A0 		6
#define COM0A1 		7

/*TCCR0B
Bit 7 – FOC0A: Force Output Compare A
The FOC0A bit is only active when the WGM bits specify a non-PWM mode.
However, for ensuring compatibility with future devices, this bit must be set to zero when
TCCR0B is written when operating in PWM mode. When writing a logical one to the FOC0A bit,
an immediate Compare Match is forced on the Waveform Generation unit. The OC0A output is
changed according to its COM0A1:0 bits setting. Note that the FOC0A bit is implemented as a
strobe. Therefore it is the value present in the COM0A1:0 bits that determines the effect of the
forced compare.
A FOC0A strobe will not generate any interrupt, nor will it clear the timer in CTC mode using
OCR0A as TOP.
The FOC0A bit is always read as zero.
• Bit 6 – FOC0B: Force Output Compare B
The FOC0B bit is only active when the WGM bits specify a non-PWM mode.
However, for ensuring compatibility with future devices, this bit must be set to zero when
TCCR0B is written when operating in PWM mode. When writing a logical one to the FOC0B bit,
an immediate Compare Match is forced on the Waveform Generation unit. The OC0B output is
changed according to its COM0B1:0 bits setting. Note that the FOC0B bit is implemented as a
strobe. Therefore it is the value present in the COM0B1:0 bits that determines the effect of the
forced compare.
A FOC0B strobe will not generate any interrupt, nor will it clear the timer in CTC mode using
OCR0B as TOP.
The FOC0B bit is always read as zero.
• Bits 5:4 – Res: Reserved Bits
These bits are reserved bits and will always read as zero.
• Bit 3 – WGM02: Waveform Generation Mode
See the description in the “TCCR0A – Timer/Counter Control Register A” on page 129.
• Bits 2:0 – CS02:0: Clock Select
The three Clock Select bits select the clock source to be used by the Timer/Counter,

CS02 CS01 CS00 Description
  0    0    0   No clock source (Timer/Counter stopped)
  0    0    1   clkI/O/(No prescaling)
  0    1    0   clkI/O/8 (From prescaler)
  0    1    1   clkI/O/64 (From prescaler)
  1    0    0   clkI/O/256 (From prescaler)
  1    0    1   clkI/O/1024 (From prescaler)
  1    1    0   External clock source on T0 pin. Clock on falling edge.
  1    1    1   External clock source on T0 pin. Clock on rising edge.
*/
#define TCCR0B 		0x45
#define CS00 		0
#define CS01 		1
#define CS02 		2
#define WGM02		3
#define FOC0B 		6
#define FOC0A 		7

//TCCR2B
#define TCCR2B 		0xB1
#define CS20 		0
#define CS21 		1
#define CS22 		2
#define WGM22 		3
#define FOC2B 		6
#define FOC2A 		7

//TIMSK5
#define TIMSK5 		0x73
#define TOIE5 		0
#define OCIE5A 		1
#define OCIE5B 		2
#define OCIE5C 		3
#define ICIE5 		5

//TIMSK4
#define TIMSK4 		0x72
#define TOIE4 		0
#define OCIE4A 		1
#define OCIE4B 		2
#define OCIE4C 		3
#define ICIE14 		5

//TIMSK3
#define TIMSK3 		0x71
#define TOIE3 		0
#define OCIE3A 		1
#define OCIE3B 		2
#define OCIE3C 		3
#define ICIE3 		5

//TIMSK2
#define TIMSK2 		0x70
#define TOIE2 		0
#define OCIE2A 		1
#define OCIE2B 		2

//TIMSK1
#define TIMSK1 		0x6F
#define TOIE1 		0
#define OCIE1A 		1
#define OCIE1B 		2
#define OCIE1C 		3
#define ICIE1 		5

/*TIMSK0
• Bits 7:3, 0 – Res: Reserved Bits
These bits are reserved bits and will always read as zero.
• Bit 2 – OCIE0B: Timer/Counter Output Compare Match B Interrupt Enable
When the OCIE0B bit is written to one, and the I-bit in the Status Register is set, the
Timer/Counter Compare Match B interrupt is enabled. The corresponding interrupt is executed if
a Compare Match in Timer/Counter occurs, that is, when the OCF0B bit is set in the
Timer/Counter Interrupt Flag Register – TIFR0.
• Bit 1 – OCIE0A: Timer/Counter0 Output Compare Match A Interrupt Enable
When the OCIE0A bit is written to one, and the I-bit in the Status Register is set, the
Timer/Counter0 Compare Match A interrupt is enabled. The corresponding interrupt is executed
if a Compare Match in Timer/Counter0 occurs, that is, when the OCF0A bit is set in the
Timer/Counter 0 Interrupt Flag Register – TIFR0.
• Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
When the TOIE0 bit is written to one, and the I-bit in the Status Register is set, the
Timer/Counter0 Overflow interrupt is enabled. The corresponding interrupt is executed if an
overflow in Timer/Counter0 occurs, that is, when the TOV0 bit is set in the Timer/Counter 0 Interrupt
Flag Register – TIFR0.
*/
#define TIMSK0 		0x6E
#define TOIE0 		0
#define OCIE0A 		1
#define OCIE0B 		2

/*TIFR0
Bits 7:3, 0 – Res: Reserved Bits
These bits are reserved bits and will always read as zero.
• Bit 2 – OCF0B: Timer/Counter 0 Output Compare B Match Flag
The OCF0B bit is set when a Compare Match occurs between the Timer/Counter and the data in
OCR0B – Output Compare Register0 B. OCF0B is cleared by hardware when executing the corresponding
interrupt handling vector. Alternatively, OCF0B is cleared by writing a logic one to
the flag. When the I-bit in SREG, OCIE0B (Timer/Counter Compare B Match Interrupt Enable),
and OCF0B are set, the Timer/Counter Compare Match Interrupt is executed.
• Bit 1 – OCF0A: Timer/Counter 0 Output Compare A Match Flag
The OCF0A bit is set when a Compare Match occurs between the Timer/Counter0 and the data
in OCR0A – Output Compare Register0. OCF0A is cleared by hardware when executing the corresponding
interrupt handling vector. Alternatively, OCF0A is cleared by writing a logic one to
the flag. When the I-bit in SREG, OCIE0A (Timer/Counter0 Compare Match Interrupt Enable),
and OCF0A are set, the Timer/Counter0 Compare Match Interrupt is executed.
Bit 0 – TOV0: Timer/Counter0 Overflow Flag
The bit TOV0 is set when an overflow occurs in Timer/Counter0. TOV0 is cleared by hardware
when executing the corresponding interrupt handling vector. Alternatively, TOV0 is cleared by
writing a logic one to the flag. When the SREG I-bit, TOIE0 (Timer/Counter0 Overflow Interrupt
Enable), and TOV0 are set, the Timer/Counter0 Overflow interrupt is executed.
*/
#define TIFR0		(0x15)
#define TOV0		0
#define OCF0A		1
#define OCF0B		2

//TIFR2 
#define TOV2 		0
#define OCF2A 		1
#define OCF2B 		2

/* SPI */
//SPCR
#define SPCR 		0x4C
#define SPR0 		0
#define SPR1 		1
#define CPHA 		2
#define CPOL 		3
#define MSTR 		4
#define DORD 		5
#define SPE 		6
#define SPIE 		7

//SPSR
#define SPSR 		0x4D
#define SPI2X 		0
#define WCOL 		6
#define SPIF 		7

/* USART */
#define UDR0 		(0xC6)
#define UDR1 		0xCE
#define UDR2 		0xD6
#define USR 		0x0B
#define UBRR0H 		0xC5
#define UBRR0L 		0xC4
#define UBRR1H 		0xCD
#define UBRR1L 		0xCC
#define UBRR2H 		0xD5
#define UBRR2L 		0xD4
#define UBRR3H 		0x135
#define UBRR3L 		0x134

/*UCSRnA
Bit 7 – RXCn: USART Receive Complete
This flag bit is set when there are unread data in the receive buffer and cleared when the receive
buffer is empty (that is, does not contain any unread data). If the Receiver is disabled, the
receive buffer will be flushed and consequently the RXCn bit will become zero. The RXCn Flag
can be used to generate a Receive Complete interrupt (see description of the RXCIEn bit).
• Bit 6 – TXCn: USART Transmit Complete
This flag bit is set when the entire frame in the Transmit Shift Register has been shifted out and
there are no new data currently present in the transmit buffer (UDRn). The TXCn Flag bit is automatically
cleared when a transmit complete interrupt is executed, or it can be cleared by writing
a one to its bit location. The TXCn Flag can generate a Transmit Complete interrupt (see
description of the TXCIEn bit).
• Bit 5 – UDREn: USART Data Register Empty
The UDREn Flag indicates if the transmit buffer (UDRn) is ready to receive new data. If UDREn
is one, the buffer is empty, and therefore ready to be written. The UDREn Flag can generate a
Data Register Empty interrupt (see description of the UDRIEn bit).
UDREn is set after a reset to indicate that the Transmitter is ready.
• Bit 4 – FEn: Frame Error
This bit is set if the next character in the receive buffer had a Frame Error when received, that is,
when the first stop bit of the next character in the receive buffer is zero. This bit is valid until the
receive buffer (UDRn) is read. The FEn bit is zero when the stop bit of received data is one.
Always set this bit to zero when writing to UCSRnA.
Bit 3 – DORn: Data OverRun
This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the receive
buffer is full (two characters), it is a new character waiting in the Receive Shift Register, and a
new start bit is detected. This bit is valid until the receive buffer (UDRn) is read. Always set this
bit to zero when writing to UCSRnA.
• Bit 2 – UPEn: USART Parity Error
This bit is set if the next character in the receive buffer had a Parity Error when received and the
Parity Checking was enabled at that point (UPMn1 = 1). This bit is valid until the receive buffer
(UDRn) is read. Always set this bit to zero when writing to UCSRnA.
• Bit 1 – U2Xn: Double the USART Transmission Speed
This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous
operation.
Writing this bit to one will reduce the divisor of the baud rate divider from 16 to 8 effectively doubling
the transfer rate for asynchronous communication.
• Bit 0 – MPCMn: Multi-processor Communication Mode
This bit enables the Multi-processor Communication mode. When the MPCMn bit is written to
one, all the incoming frames received by the USART Receiver that do not contain address information
will be ignored. The Transmitter is unaffected by the MPCMn setting.
*/
#define UCSR0A 		0xC0
#define UCSR1A 		0xC8
#define UCSR2A 		0xD0
#define UCSR3A 		0x130

#define MPCM 		0							//Multi Processor Communication mode
#define U2X 		1							//Double the USART Transmission speed
#define UPE 		2							//USART Parity Error
#define DOR 		3							//Data Overrrun
#define FE 			4							//Frame Error
#define UDRE 		5     	 	                //USART Data Register Emtyp
#define TXC 		6                           //Transmit Complete
#define RXC 		7                           //Receive Complete

/*UCSRnB
• Bit 7 – RXCIEn: RX Complete Interrupt Enable n
Writing this bit to one enables interrupt on the RXCn Flag. A USART Receive Complete interrupt
will be generated only if the RXCIEn bit is written to one, the Global Interrupt Flag in SREG is
written to one and the RXCn bit in UCSRnA is set.
• Bit 6 – TXCIEn: TX Complete Interrupt Enable n
Writing this bit to one enables interrupt on the TXCn Flag. A USART Transmit Complete interrupt
will be generated only if the TXCIEn bit is written to one, the Global Interrupt Flag in SREG is
written to one and the TXCn bit in UCSRnA is set.
• Bit 5 – UDRIEn: USART Data Register Empty Interrupt Enable n
Writing this bit to one enables interrupt on the UDREn Flag. A Data Register Empty interrupt will
be generated only if the UDRIEn bit is written to one, the Global Interrupt Flag in SREG is written
to one and the UDREn bit in UCSRnA is set.
• Bit 4 – RXENn: Receiver Enable n
Writing this bit to one enables the USART Receiver. The Receiver will override normal port operation
for the RxDn pin when enabled. Disabling the Receiver will flush the receive buffer
invalidating the FEn, DORn, and UPEn Flags.
Bit 3 – TXENn: Transmitter Enable n
Writing this bit to one enables the USART Transmitter. The Transmitter will override normal port
operation for the TxDn pin when enabled. The disabling of the Transmitter (writing TXENn to
zero) will not become effective until ongoing and pending transmissions are completed, that is,
when the Transmit Shift Register and Transmit Buffer Register do not contain data to be transmitted.
When disabled, the Transmitter will no longer override the TxDn port.
• Bit 2 – UCSZn2: Character Size n
The UCSZn2 bits combined with the UCSZn1:0 bit in UCSRnC sets the number of data bits
(Character SiZe) in a frame the Receiver and Transmitter use.
• Bit 1 – RXB8n: Receive Data Bit 8 n
RXB8n is the ninth data bit of the received character when operating with serial frames with nine
data bits. Must be read before reading the low bits from UDRn.
• Bit 0 – TXB8n: Transmit Data Bit 8 n
TXB8n is the ninth data bit in the character to be transmitted when operating with serial frames
with nine data bits. Must be written before writing the low bits to UDRn.
*/
#define UCSR0B 		0xC1
#define UCSR1B 		0xC9
#define UCSR2B 		0xD1
#define UCSR3B 		0x131

#define TXB8 		0							//transmit data bit 8 n
#define RXB8 		1							//receive data bit 8 n
#define UCSZ 		2							//character size n
#define TXEN 		3							//Transmitter enable
#define RXEN 		4							//Receiver enable
#define UDRIE 		5							//USART Data Register Empty Interrupt Enable n
#define TXCIE 		6							//TX Complete Interrup enable
#define RXCIE 		7							//RX Complete Interrupt Enable

//UCSRnC
#define UCSR0C 		0xC2
#define UCSR1C 		0xCA
#define UCSR2C 		0xD2
#define UCSR3C 		0x132

#define UCPOL 		0							//Clock Polarity
#define UCSZ0 		1							//Character Size	
#define UCSZ1 		2							//Character Size
#define USBS 		3							//Stop Bit Select
#define UPM0 		4							//Parity Mode
#define UPM1 		5							//Parity Mode
#define UMSEL0 		6							//USART Mode Select
#define UMSEL1 		7               	        //USART Mode Select 

/* ADC */
#define ADCL 		0x78
#define ADCH 		0x79

//ADMUX
#define MUX0 		0							//MUX 0 - 4 -> Analog Channel and Gain Selection Bits
#define MUX1 		1
#define MUX2 		2
#define MUX3 		3
#define MUX4 		4							
#define ADLAR 		5							//ADC Left Adjust result
#define REFS0 		6                  	    // Ref Seelction bit
#define REFS1 		7							// Ref Seelction bit

//ADCSRB
#define ADTS0 		0
#define ADTS1 		1
#define ADTS2 		2
#define MUX5 		3
#define ACME 		6

//ADCSRA
#define ADPS0 		0
#define ADPS1 		1
#define ADPS2 		2
#define ADIE 		3
#define ADIF 		4
#define ADATE 		5
#define ADSC 		6
#define ADEN 		7

/* EEPROM */
#define EEARH 		(0x42)
#define EEARL 		(0x41)
#define EEDR 		(0x40)
#define EECR 		(0x3F)


#define EERE		(0)
#define EEPE		(1)
#define EEMPE		(2)
#define EERIE		(3)
#define EEPM0		(4)
#define EEPM1		(5)

/* Interrupts */
#define MCUCR 		(0x35)
#define IVCE		0

#define TCNT0		(0x46)
#define OCR0A		(0x27)
#define OCR0B		(0x28)

/*
The IVCE bit must be written to logic one to enable change of the IVSEL bit. IVCE is cleared by
hardware four cycles after it is written or when IVSEL is written. Setting the IVCE bit will disable
interrupts, as explained in the IVSEL description.
*/
#define IVSEL		1 
/*
When the IVSEL bit is cleared (zero), the Interrupt Vectors are placed at the start of the Flash
memory. When this bit is set (one), the Interrupt Vectors are moved to the beginning of the Boot
Loader section of the Flash. The actual address of the start of the Boot Flash Section is determined
by the BOOTSZ Fuses.

Interrupts will automatically be disabled while this sequence is executed. Interrupts are disabled
in the cycle IVCE is set, and they remain disabled until after the instruction following the write to
IVSEL. If IVSEL is not written, interrupts remain disabled for four cycles. The I-bit in the Status
Register is unaffected by the automatic disabling.
*/
#define PUD 		4
#define JTD			7


/*External Interrupts
The External Interrupts are triggered by the INT7:0 pin or any of the PCINT23:0 pins. Observe
that, if enabled, the interrupts will trigger even if the INT7:0 or PCINT23:0 pins are configured as
outputs. This feature provides a way of generating a software interrupt.
The Pin change interrupt PCI2 will trigger if any enabled PCINT23:16 pin toggles, Pin change
interrupt PCI1 if any enabled PCINT15:8 toggles and Pin change interrupts PCI0 will trigger if
any enabled PCINT7:0 pin toggles. PCMSK2, PCMSK1 and PCMSK0 Registers control which
pins contribute to the pin change interrupts. Pin change interrupts on PCINT23 :0 are detected
asynchronously. This implies that these interrupts can be used for waking the part also from
sleep modes other than Idle mode.
The External Interrupts can be triggered by a falling or rising edge or a low level. This is set up
as indicated in the specification for the External Interrupt Control Registers – EICRA (INT3:0)
and EICRB (INT7:4). When the external interrupt is enabled and is configured as level triggered,
the interrupt will trigger as long as the pin is held low. Note that recognition of falling or rising
edge interrupts on INT7:4 requires the presence of an I/O clock. Low level interrupts and the edge interrupt on INT3:0 are detected asynchronously.
This implies that these interrupts can be used for waking the part also from sleep modes other
than Idle mode. The I/O clock is halted in all sleep modes except Idle mode.
Note that if a level triggered interrupt is used for wake-up from Power-down, the required level
must be held long enough for the MCU to complete the wake-up to trigger the level interrupt. If
the level disappears before the end of the Start-up Time, the MCU will still wake up, but no interrupt
will be generated. The start-up time is defined by the SUT and CKSEL
*/
/*EICRA External Interrupt Control Register A*/
#define EICRA 		(0x69)
#define ISC00		0
#define ISC01		1
#define ISC10		2
#define ISC11		3
#define ISC20		4
#define ISC21		5
#define ISC30		6
#define ISC31		7
/*
Bits 7:0 – ISC31, ISC30 – ISC00, ISC00: External Interrupt 3 - 0 Sense Control Bits
The External Interrupts 3 - 0 are activated by the external pins INT3:0 if the SREG I-flag and the
corresponding interrupt mask in the EIMSK is set. The level and edges on the external pins that
activate the interrupts are defined in Table 14-1 on page 114. Edges on INT3:0 are registered
asynchronously. Pulses on INT3:0 pins wider than the minimum pulse width given in Table 14-2
on page 114 will generate an interrupt. Shorter pulses are not guaranteed to generate an interrupt.
If low level interrupt is selected, the low level must be held until the completion of the
currently executing instruction to generate an interrupt. If enabled, a level triggered interrupt will
generate an interrupt request as long as the pin is held low. When changing the ISCn bit, an
interrupt can occur. Therefore, it is recommended to first disable INTn by clearing its Interrupt
Enable bit in the EIMSK Register. Then, the ISCn bit can be changed. Finally, the INTn interrupt
flag should be cleared by writing a logical one to its Interrupt Flag bit (INTFn) in the EIFR Register
before the interrupt is re-enabled.

ISCn1    |    ISCn0    |Description
   0     |       0     |The low level of INTn generates an interrupt request.
   0     |       1     |Any edge of INTn generates asynchronously an interrupt request.
   1     |       0     |The falling edge of INTn generates asynchronously an interrupt request.
   1     |       1     |The rising edge of INTn generates asynchronously an interrupt request.

*/

/*EICRA External Interrupt Control Register A*/
#define EICRB 		(0x6A)
#define ISC40		0
#define ISC41		1
#define ISC50		2
#define ISC51		3
#define ISC60		4
#define ISC61		5
#define ISC70		6
#define ISC71		7

/*
Bits 7:0 – ISC71, ISC70 - ISC41, ISC40: External Interrupt 7 - 4 Sense Control Bits
The External Interrupts 7 - 4 are activated by the external pins INT7:4 if the SREG I-flag and the
corresponding interrupt mask in the EIMSK is set. The level and edges on the external pins that
activate the interrupts are defined in Table 14-3. The value on the INT7:4 pins are sampled
before detecting edges. If edge or toggle interrupt is selected, pulses that last longer than one
clock period will generate an interrupt. Shorter pulses are not guaranteed to generate an interrupt.
Observe that CPU clock frequency can be lower than the XTAL frequency if the XTAL
divider is enabled. If low level interrupt is selected, the low level must be held until the completion
of the currently executing instruction to generate an interrupt. If enabled, a level triggered
interrupt will generate an interrupt request as long as the pin is held low.

ISCn1    |    ISCn0    |Description
   0     |       0     |The low level of INTn generates an interrupt request.
   0     |       1     |Any edge of INTn generates asynchronously an interrupt request.
   1     |       0     |The falling edge of INTn generates asynchronously an interrupt request.
   1     |       1     |The rising edge of INTn generates asynchronously an interrupt request.

*/

/*EIMSK - External Interrupt Mask Register
When an INT7:0 bit is written to one and the I-bit in the Status Register (SREG) is set (one), the
corresponding external pin interrupt is enabled. The Interrupt Sense Control bits in the External
Interrupt Control Registers – EICRA and EICRB – defines whether the external interrupt is activated
on rising or falling edge or level sensed. Activity on any of these pins will trigger an
interrupt request even if the pin is enabled as an output. This provides a way of generating a
software interrupt.
*/
#define EIMSK		(0x1D)
#define INT0		0	
#define INT1		1
#define INT2		2
#define INT3		3
#define INT4		4
#define INT5		5
#define INT6		6
#define INT7		7


/*EIFR - External Interrupt Flag Register
When an edge or logic change on the INT7:0 pin triggers an interrupt request, INTF7:0 becomes
set (one). If the I-bit in SREG and the corresponding interrupt enable bit, INT7:0 in EIMSK, are
set (one), the MCU will jump to the interrupt vector. The flag is cleared when the interrupt routine
is executed. Alternatively, the flag can be cleared by writing a logical one to it. These flags are
always cleared when INT7:0 are configured as level interrupt. Note that when entering sleep
mode with the INT3:0 interrupts disabled, the input buffers on these pins will be disabled. This
may cause a logic change in internal signals which will set the INTF3:0 flags.
*/
#define EIFR		(0x1C)
#define INTF0		0	
#define INTF1		1
#define INTF2		2
#define INTF3		3
#define INTF4		4
#define INTF5		5
#define INTF6		6
#define INTF7		7

/*PCICR - Pin change interrupt control register

Bit 2 – PCIE2: Pin Change Interrupt Enable 1
When the PCIE2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), pin
change interrupt 2 is enabled. Any change on any enabled PCINT23:16 pin will cause an interrupt.
The corresponding interrupt of Pin Change Interrupt Request is executed from the PCI2
Interrupt Vector. PCINT23:16 pins are enabled individually by the PCMSK2 Register.
• Bit 1 – PCIE1: Pin Change Interrupt Enable 1
When the PCIE1 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), pin
change interrupt 1 is enabled. Any change on any enabled PCINT15:8 pin will cause an interrupt.
The corresponding interrupt of Pin Change Interrupt Request is executed from the PCI1
Interrupt Vector. PCINT15:8 pins are enabled individually by the PCMSK1 Register.
Bit 0 – PCIE0: Pin Change Interrupt Enable 0
When the PCIE0 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), pin
change interrupt 0 is enabled. Any change on any enabled PCINT7:0 pin will cause an interrupt.
The corresponding interrupt of Pin Change Interrupt Request is executed from the PCI0 Interrupt
Vector. PCINT7:0 pins are enabled individually by the PCMSK0 Register.
*/
#define PCICR		(0x68)
#define PCIE0		0
#define PCIE1		1
#define PCIE2		2

/*PCIFR - Pin change interrupt flag register
Bit 2 – PCIF2: Pin Change Interrupt Flag 1
When a logic change on any PCINT23:16 pin triggers an interrupt request, PCIF2 becomes set
(one). If the I-bit in SREG and the PCIE2 bit in PCICR are set (one), the MCU will jump to the
corresponding Interrupt Vector. The flag is cleared when the interrupt routine is executed. Alternatively,
the flag can be cleared by writing a logical one to it.
• Bit 1 – PCIF1: Pin Change Interrupt Flag 1
When a logic change on any PCINT15:8 pin triggers an interrupt request, PCIF1 becomes set
(one). If the I-bit in SREG and the PCIE1 bit in PCICR are set (one), the MCU will jump to the
corresponding Interrupt Vector. The flag is cleared when the interrupt routine is executed. Alternatively,
the flag can be cleared by writing a logical one to it.
• Bit 0 – PCIF0: Pin Change Interrupt Flag 0
When a logic change on any PCINT7:0 pin triggers an interrupt request, PCIF0 becomes set
(one). If the I-bit in SREG and the PCIE0 bit in PCICR are set (one), the MCU will jump to the
corresponding Interrupt Vector. The flag is cleared when the interrupt routine is executed. Alternatively,
the flag can be cleared by writing a logical one to it.
*/

#define PCIFR		(0x1B)
#define PCIF0		0
#define PCIF1		1
#define PCIF2		2


/*PCMSK2 - Pin Change Mask register 2
Bit 7:0 – PCINT23:16: Pin Change Enable Mask 23:16
Each PCINT23:16-bit selects whether pin change interrupt is enabled on the corresponding I/O
pin. If PCINT23:16 is set and the PCIE2 bit in PCICR is set, pin change interrupt is enabled on
the corresponding I/O pin. If PCINT23:16 is cleared, pin change interrupt on the corresponding
I/O pin is disabled.
*/
#define PCMSK2 		(0x6D)
#define PCINT16		0
#define PCINT17		1
#define PCINT18		2
#define PCINT19		3
#define PCINT20		4
#define PCINT21		5
#define PCINT22		6
#define PCINT23		7

/*PCMSK1 - Pin Change Mask register 2
Bit 7:0 – PCINT15:8: Pin Change Enable Mask 15:8
Each PCINT15:8-bit selects whether pin change interrupt is enabled on the corresponding I/O
pin. If PCINT15:8 is set and the PCIE1 bit in EIMSK is set, pin change interrupt is enabled on the
corresponding I/O pin. If PCINT15:8 is cleared, pin change interrupt on the corresponding I/O
pin is disabled.
*/
#define PCMSK1 		(0x6C)
#define PCINT15		7
#define PCINT14		6
#define PCINT13		5
#define PCINT12		4
#define PCINT11		3
#define PCINT10		2
#define PCINT9		1
#define PCINT8		0


/*PCMSK0 - Pin Change Mask register 0
Each PCINT7:0 bit selects whether pin change interrupt is enabled on the corresponding I/O pin.
If PCINT7:0 is set and the PCIE0 bit in PCICR is set, pin change interrupt is enabled on the corresponding
I/O pin. If PCINT7:0 is cleared, pin change interrupt on the corresponding I/O pin is
disabled.
*/
#define PCMSK0 		(0x6B)
#define PCINT0		0
#define PCINT1		1
#define PCINT2		2
#define PCINT3		3
#define PCINT4		4
#define PCINT5		5
#define PCINT6		6
#define PCINT7		7

