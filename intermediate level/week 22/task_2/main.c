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
	DDRA = 0;
	PORTA = 0xff;
	int counter = 0;
	char seg[] = {0x3f , 0x06 , 0x5B,
			      0x4f , 0x66 , 0x6D,
				  0x7d , 0x07 , 0x7f,
				  0x6f};
	DDRB = 0xff;
	PORTB = 0;
	PORTB = seg[counter];

	while(1)
	{
		if(((PINA>>0)&1) == 0)
		{
			if(counter < 9)
			{
				counter += 1;
				PORTB = seg[counter];
			}else{
				continue;
			}
			while(((PINA>>0)&1) == 0);
		}if(((PINA>>1)&1) == 0)
		{
			if(counter > 0)
			{
				counter -= 1;
				PORTB = seg[counter];
			}else{
				continue;
			}
			while(((PINA>>1)&1) == 0);
		}
	}
}
