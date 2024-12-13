/*
 * main.c
 *
 *  Created on: Dec 13, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "ADC_int.h"
#include "LCD_int.h"

#include "LM_int.h"

int main(void)
{
	DIO_enuInit();
	ADC_voidInit();
	u8 Local_u8TempValue;
	LM35_CONFIG LM35;
	LM35_u8GetTemp(&LM35 , &Local_u8TempValue);
	while(1)
	{
		if(Local_u8TempValue > 40)
		{
			LCD_enuDisplayChar('O');LCD_enuDisplayChar('p');LCD_enuDisplayChar('e');LCD_enuDisplayChar('n');
			LCD_enuDisplayChar(' ');LCD_enuDisplayChar('t');LCD_enuDisplayChar('h');LCD_enuDisplayChar('e');
			LCD_enuDisplayChar(' ');LCD_enuDisplayChar('f');LCD_enuDisplayChar('a');LCD_enuDisplayChar('n');
		}
	}
	return 0;
}

