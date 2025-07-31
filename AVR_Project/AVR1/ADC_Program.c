/*
 * ADC_Program.c
 *
 *  Created on: Jul 24, 2025
 *      Author: mylap
 */

#include "stdTypes.h"
#include "BIT_MATH.h"
#include "errorStates.h"

#include "ADC_Private.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"

static u16 *Global_ptr = NULL;
static void (*GlobalPtrFunc)(void) = NULL;

//IDLE or BUSY
static u8 ADC_State = IDLE ;

void ADC_voidInit(void)
{
	//Disable interrupt
	CLR_BIT(ADCSRA , ADCSRA_ADIE);

	//ref -> AVCC
	SET_BIT(ADMUX , ADMUX_REFS0);
	CLR_BIT(ADMUX , ADMUX_REFS1);

	//Prescaler -> 128
	SET_BIT(ADCSRA , ADCSRA_ADPS0);
	SET_BIT(ADCSRA , ADCSRA_ADPS1);
	SET_BIT(ADCSRA , ADCSRA_ADPS2);

	//ADC Enable
	SET_BIT(ADCSRA , ADCSRA_ADEN);
}

u16 ADC_u16ADCStartConvertPolling(u8 Copy_u8Channel)
{
	u16 ADC_Read = 0;

	ADMUX &= 0b11100000;
	ADMUX |= Copy_u8Channel;

	//Start Conversion
	SET_BIT(ADCSRA , ADCSRA_ADSC);

	while(0 == GET_BIT(ADCSRA , ADCSRA_ADIF));

	ADC_Read = ADCLH;

	//CLR flag
	SET_BIT(ADCSRA , ADCSRA_ADSC);

	return ADC_Read;
}

u8 ADC_u8ADCStartConvertInt(u8 Copy_u8Channel , u16 *pu16Reading , void(*ptrFunc)(void))
{
	u8 Local_u8Error = ES_OK;
	if((ADC_State == IDLE) && (NULL != pu16Reading) && (NULL != ptrFunc))
	{
		ADC_State = BUSY;
		Global_ptr = pu16Reading;
		GlobalPtrFunc = ptrFunc;

		ADMUX &= 0b11100000;
		ADMUX |= Copy_u8Channel;

		//Enable interrupt
		SET_BIT(ADCSRA , ADCSRA_ADIE);

		//Start Conversion
		SET_BIT(ADCSRA , ADCSRA_ADSC);


	}
	else
	{
		Local_u8Error = ES_NOK;
	}
	return Local_u8Error;
}

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
	//Return Reading
	*Global_ptr = ADCLH;
	//Execute function
	GlobalPtrFunc();
	//Disable interrupt
	CLR_BIT(ADCSRA , ADCSRA_ADIE);
	//Change state
	ADC_State = IDLE;
}
