/*
 * main.c
 *
 *  Created on: Sep 18, 2024
 *      Author: mylap
 */

#include <util/delay.h>
#define DDRA *((char*)0x3A)
#define PORTA *((char*)0x3B)
#define PINA *((char*)0x39)

#define DDRB *((char*)0x37)
#define PORTB *((char*)0x38)
#define PINB *((char*)0x36)

int main(void)
{
	DDRA = 0xff;
	PORTA = 0;
	DDRB = 0;
	PORTB = 0xff;

	while(1)
	{
		if(((PINB>>0)&1) == 0)
		{
			PORTA |= (1<<0);
		}else if(((PINB>>0)&1) == 1)
		{
			PORTA &= ~(1<<0);
		}if(((PINB>>1)&1) == 0)
		{
			PORTA |= (1<<1);
		}else if(((PINB>>1)&1) == 1)
		{
			PORTA &= ~(1<<1);
		}
		if(((PINB>>2)&1) == 0)
		{
			PORTA |= (1<<0);
			PORTA |= (1<<1);
		}else if(((PINB>>2)&1) == 1)
		{
			PORTA &= ~(1<<0);
			PORTA &= ~(1<<1);
		}
		else
		{
			PORTA = 0;
		}
	}
}


