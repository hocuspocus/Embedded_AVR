/*
	@description 		:  		EEPROM defintions
	@author				:		Sunil Murali
*/

#ifndef eeprom_h		
	#define eeprom_h
	unsigned char EEPROM_read(unsigned int uiAddress);
	void EEPROM_write(unsigned int uiAddress, unsigned char ucData);
#endif
