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
#include "ADC_Interface.h"
#include "USART_Interface.h"

#include <util/delay.h>

int main(void)
{
	u16 Res = 0;
	u16 AnalogRes = 0;
	DIO_enuSetPinDirection(DIO_u8PORTA , DIO_PIN0 , DIO_u8INPUT);
	DIO_enuInit();
	ADC_voidInit();
	USART_voidInit();
	while(1)
	{
		Res = ADC_u16ADCStartConvertPolling(0b00000);
		AnalogRes = (Res *5)/1023;
		USART_u8SendData(AnalogRes);
		_delay_ms(500);
	}
	return 0;
}

