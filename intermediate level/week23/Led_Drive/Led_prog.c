/*
 * Led_prog.c
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Led_conf.h"
#include "Led_priv.h"

ES_t LED_enuInit(LED_t *Copy_pstrLed)
{
	u8 Local_enuErrorstate = ES_NOK;
	if(Copy_pstrLed != NULL)
	{
		u8 Local_enuIterator;
		for(Local_enuIterator = 0;Local_enuIterator < LED_NUM; Local_enuIterator++)
		{
			Local_enuErrorstate = DIO_enuSetPinDirection(Copy_pstrLed[Local_enuIterator].LED_u8PortID, Copy_pstrLed[Local_enuIterator].LED_u8PinID,	OUTPUT);
			if(Copy_pstrLed[Local_enuIterator].LED_u8Connection == LED_SINK)
			{
				if(Copy_pstrLed[Local_enuIterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLed[Local_enuIterator].LED_u8PortID, Copy_pstrLed[Local_enuIterator].LED_u8PinID, DIO_u8LOW);
				}
				else if(Copy_pstrLed[Local_enuIterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLed[Local_enuIterator].LED_u8PortID, Copy_pstrLed[Local_enuIterator].LED_u8PinID, DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
			if(Copy_pstrLed[Local_enuIterator].LED_u8Connection == LED_SOURCE)
			{
				if(Copy_pstrLed[Local_enuIterator].LED_u8InitState == LED_OFF)
				{
					Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLed[Local_enuIterator].LED_u8PortID, Copy_pstrLed[Local_enuIterator].LED_u8PinID, DIO_u8LOW);
				}
				else if(Copy_pstrLed[Local_enuIterator].LED_u8InitState == LED_ON)
				{
					Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLed[Local_enuIterator].LED_u8PortID, Copy_pstrLed[Local_enuIterator].LED_u8PinID, DIO_u8HIGH);
				}
				else
				{
					return ES_OUT_OF_RANGE;
				}
			}
		}
	}
	else
	{
		Local_enuErrorstate = ES_NULL_POINTER;
	}
	return Local_enuErrorstate;
}

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID)
{
	u8 Local_enuErrorstate = ES_NOK;
	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID->LED_u8Connection == LED_SINK)
		{
			Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorstate = ES_NULL_POINTER;
	}
	return Local_enuErrorstate;
}

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID)
{
	u8 Local_enuErrorstate = ES_NOK;
	if(Copy_pstrLedID != NULL)
	{
		if(Copy_pstrLedID->LED_u8Connection == LED_SINK)
		{
			Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8HIGH);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enuErrorstate = DIO_enuSetPinValue(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID,DIO_u8LOW);
		}
			else
		{
			return ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorstate = ES_NULL_POINTER;
	}
	return Local_enuErrorstate;
}
