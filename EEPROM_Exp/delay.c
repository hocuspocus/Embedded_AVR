#include "delay.h"
void delay(unsigned int val)
{
	volatile unsigned int temp;
	volatile unsigned int temp2;

	for(temp = 0; temp < val; temp++) 
		for (temp2 = 0; temp2 < val; temp2 ++) ;
}

