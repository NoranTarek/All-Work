/*
 * main.c
 *
 *  Created on: Mar 16, 2025
 *      Author: mylap
 */

#include "STD_Types.h"
#include "ErrorState.h"
#include "MATH_BIT.h"

#include "DIO_int.h"
#include "LM_int.h"
#include "ADC_int.h"
#include "Timer_Interface.h"

int main()
{
	DIO_enuInit();
	ADC_voidInit();
	TIMER1_voidInit();
	u8 Local_u8TempValue;
	LM35_CONFIG LM35;
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8OUTPUT);
	while(1)
	{
		LM35_u8GetTemp(&LM35 , &Local_u8TempValue);
		if(Local_u8TempValue <= 20)
		{
			TIMER_voidSetPWM(TIMER2_u8GetTimerCounterValue()/5);
		}
		else if(Local_u8TempValue <= 50)
		{
			TIMER_voidSetPWM(TIMER2_u8GetTimerCounterValue()/2);
		}
		else if(Local_u8TempValue <= 70)
		{
			TIMER_voidSetPWM((u8))(TIMER2_u8GetTimerCounterValue()*.7));
		}
	}
	return 0;
}
