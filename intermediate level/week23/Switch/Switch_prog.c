/*
 * Switch_prog.c
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */
#include "stdTypes.h"
#include "DIO_int.h"
#include "errorStates.h"
#include "Switch_priv.h"
#include "Switch_conf.h"

ES_t Switch_enuInit(SW_t *copy_SWAstr)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_SWAstr != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < SW_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(copy_SWAstr[Local_u8Iterator].Switch_PortID,copy_SWAstr[Local_u8Iterator].Switch_PinID,DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(copy_SWAstr[Local_u8Iterator].Switch_PortID,copy_SWAstr[Local_u8Iterator].Switch_PinID,copy_SWAstr[Local_u8Iterator].Switch_status);
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_t Switch_enuGetState(SW_t *copy_SWAstr, u8 *copy_SWState)
{
	ES_t Local_enuErrorState = ES_NOK;
	if(copy_SWAstr != NULL && copy_SWState != NULL)
	{
		Local_enuErrorState = DIO_enuGetPinValue(copy_SWAstr->Switch_PortID, copy_SWAstr->Switch_PinID,copy_SWState);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

