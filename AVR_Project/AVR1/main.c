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
#include "USART_Interface.h"
#include "LCD_int.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"

#include <util/delay.h>

int main(void)
{
	u16 LDR_Read = 0 ;
	u8 LM_Read = 0;
	u8 SM_Read = 0;
	u8 LDR_Button = 1;
	u8 LM_Button = 1;
	u8 SM_Button = 1;
	DIO_enuSetPinDirection(DIO_u8PORTB , DIO_u8PIN0 , DIO_u8OUTPUT); //Fan PIN
	//Set ACD Pin
	DIO_enuSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8INPUT);
	ADC_voidInit();

	//Set pins Port
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8OUTPUT);
	DIO_enuInit();
	LCD_voidInitPortValues();
	LCD_voidInit();
	USART_voidInit();

	//DC pin for Opening water
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN1 , DIO_u8OUTPUT);

	//Buttons PINs Internal pull up
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN2 , DIO_u8HIGH);
	DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN3 , DIO_u8HIGH);
	DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN4 , DIO_u8HIGH);

	SPI_voidInit(SPI_MASTER_MODE);
	while(1)
	{
		USART_u8RecevieData(&LM_Read);
		if(LM_Read > 30)
		{
			DIO_enuSetPinValue(DIO_u8PORTB , DIO_u8PIN0 ,DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTB , DIO_u8PIN0 ,DIO_u8LOW);
		}
		LDR_Read = ADC_u16ADCStartConvertPolling(0b00000);
		if(LDR_Read < 200)
		{
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN0 , DIO_u8LOW);
		}
		SM_Read = SPI_u8DataSendReceive(0);
		if(SM_Read < 150)
		{
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN1 , DIO_u8LOW);
		}
		else
		{
			DIO_enuSetPinValue(DIO_u8PORTD , DIO_u8PIN1 , DIO_u8HIGH);
		}
		DIO_enuGetPinValue(DIO_u8PORTD , DIO_u8PIN2 , &LDR_Button);
		if(LDR_Button == 0)
		{
			DIO_enuTogPin(DIO_u8PORTD , DIO_u8PIN0);
		}
		DIO_enuGetPinValue(DIO_u8PORTD , DIO_u8PIN3 , &LM_Button);
		if(LM_Button == 0)
		{
			DIO_enuTogPin(DIO_u8PORTB , DIO_u8PIN0);
		}
		DIO_enuGetPinValue(DIO_u8PORTD , DIO_u8PIN4 , &SM_Button);
		if(SM_Button == 0)
		{
			DIO_enuTogPin(DIO_u8PORTD , DIO_u8PIN1);
		}
		LCD_voidSendString("Temp = ");
		LCD_voidSendNumber(LM_Read);
		LCD_voidClearDisplay();
		_delay_ms(500);
	}
	return 0;
}
