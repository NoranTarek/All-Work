/*
 * LM_prog.c
 *
 *  Created on: Dec 13, 2024
 *      Author: mylap
 */

#include "STD_Types.h"
#include "MATH_BIT.h"
#include "ErrorState.h"

#include "DIO_int.h"
#include "ADC_int.h"

#include "LM_int.h"
#include "LM_priv.h"


ES_t LM35_u8GetTemp (LM35_CONFIG *lm35 , u8 *Copy_u8TempValue)
{
	ES_t Local_u8ErrorState = ES_OK ;

	u16 Local_u16ADCResult ;
	u16 Local_u16AnalogValue ;

	u16 Local_u8ADCReference = ( lm35->Copy_u8ADCVoltageReference ) * 1000 ;

	ADC_u8GetResultSync( lm35->Copy_u8LM35Channel , &Local_u16ADCResult ) ;

	if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_10_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 1024UL) ;

	}
	else if ( lm35->Copy_u8ADCResolution == ADC_RESOLUTION_8_BIT )
	{
		Local_u16AnalogValue = (u16) ( ((u32)Local_u16ADCResult * (u32)Local_u8ADCReference ) / 256UL) ;
	}

	*Copy_u8TempValue = Local_u16AnalogValue / 10 ;

	return Local_u8ErrorState ;
}

