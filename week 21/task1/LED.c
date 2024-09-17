/*
 * LED.c
 *
 *  Created on: Sep 17, 2024
 *      Author: mylap
 */
#include <avr/io.h>
#include <util/delay.h>

typedef unsigned char u8;
int main(void)
{
	*((char*)0x3B) |= (1<<4);
	*((char*)0x3A) |= (1<<4);
	_delay_ms(1000);
	*((char*)0x3B) &= ~(1<<4);
	while(1);
return 0;
}

