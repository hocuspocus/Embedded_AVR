/*
	@description		:		
*/
#include "eeprom.h"
#include "atmega2560.h"

/*EEPROM Read */
unsigned char EEPROM_read(unsigned int uiAddress)
{
	
	/* Wait for completion of previous write */
	while(READREG(EECR) & (1<<EEPE));

	/* Set up address register */
	//WRITEREG(EEAR, uiAddress);
	WRITEREG(EEARH, uiAddress>>8);
	WRITEREG(EEARL, uiAddress);
	/* Start eeprom read by writing EERE */
	WRITEREG(EECR, (1<<EERE));
	//*((volatile unsigned char *)EECR) |= 1<<EERE;
	/* Return data from Data Register */
	return READREG(EEDR);
}

/*EEPROM Write*/
void EEPROM_write(unsigned int uiAddress, unsigned char data)
{
	/* Wait for completion of previous write */
	while(READREG(EECR) & (1<<EEPE));

	/* Set up address and Data Registers */
	//EEARH = (unsigned char)uiAddress>>8;
	//EEARL = (unsigned char)uiAddress;
	WRITEREG(EEARH, uiAddress>>8);
	WRITEREG(EEARL, uiAddress);
	WRITEREG(EEDR, data);
	//EEDR = data;
	//cli();
	/* Write logical one to EEMPE */
	WRITEREG(EECR,(1<<EEMPE));
	//*((volatile unsigned char *)EECR) |= 1<<EEMPE;
	/* Start eeprom write by setting EEPE */
	WRITEREG(EECR, (1<<EEPE));
	//*((volatile unsigned char *)EECR) |= 1<<EEPE;
	//sei();
}
