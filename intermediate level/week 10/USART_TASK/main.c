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

#include "LM_int.h"

int main(void)
{
	DIO_enuInit();
	ADC_voidInit();
	USART_voidInit();
	u8 Local_u8TempValue;
	LM35_CONFIG LM35;
	while(1)
	{
		LM35_u8GetTemp(&LM35 , &Local_u8TempValue);
		USART_u8SendData(Local_u8TempValue);
	}
	return 0;
}

