/*
 * task2.c
 *
 *  Created on: Sep 17, 2024
 *      Author: mylap
 */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	*((char*)0x3A) = 0xff;
	*((char*)0x3B) = 0;
	int i = 0;
	while(1)
	{
		for(i = 0;i <= 7; i++)
		{
			*((char*)0x3B) |= (1<<i);
			_delay_ms(500);
		}
		for(i = 0;i <= 7; i++)
		{
			*((char*)0x3B) &= ~(1<<i);
			_delay_ms(500);
		}
	}
}
