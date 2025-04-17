/*
 * I2C_Program.c
 *
 *  Created on: Apr 17, 2025
 *      Author: mylap
 */

#include "ErrorState.h"
#include "STD_Types.h"
#include "MATH_BIT.h"

#include "I2C_Configuration.h"
#include "I2C_Interface.h"
#include "I2C_Private.h"

void TWI_voidInitMaster(u8 Copy_u8Address)
{
	TWBR= (u8) (((F_CPU/SCL_Clock)-16) / (2*TWI_PRESCALLER));

	if (TWI_PRESCALLER==PRESCALLER_BY_1)
	{
		TWSR=0;
	}
	else if (TWI_PRESCALLER==PRESCALLER_BY_4)
	{
		TWSR=1;
	}
	else if (TWI_PRESCALLER==PRESCALLER_BY_16)
	{
		TWSR=2;
	}
	else if (TWI_PRESCALLER==PRESCALLER_BY_64)
	{
		TWSR=3;
	}

	if(Copy_u8Address != 0)
	{
		TWAR = Copy_u8Address<<1;
	}
	else
	{
		/*Do nothing*/
	}

	SET_BIT(TWCR,TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);
}

void TWI_voidInitSlave(u8 Copy_u8Address)
{
	TWAR = Copy_u8Address<<1;
	SET_BIT(TWCR,TWCR_TWEA);
	SET_BIT(TWCR,TWCR_TWEN);
}

ES_t TWI_SendStartCondition(void)
{
	ES_t Local_ErrorState = ES_OK;
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) != START_ACK )
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}
	return Local_ErrorState;
}

ES_t TWI_SendRepeatedStart(void)
{
	ES_t Local_ErrorState = ES_OK;
	SET_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);

	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) != START_ACK )
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}
	return Local_ErrorState;
}

ES_t TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	ES_t Local_ErrorState = ES_OK;

	TWDR = (Copy_u8SlaveAddress<<1) ;
	CLR_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK )
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}

	return Local_ErrorState;
}

ES_t TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	ES_t Local_ErrorState = ES_OK;
	TWDR = (Copy_u8SlaveAddress<<1) ;
	SET_BIT(TWDR,0);
	CLR_BIT(TWCR,TWCR_TWSTA);
	SET_BIT(TWCR,TWCR_TWINT);
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) != SLAVE_ADD_AND_WR_ACK )
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}
	return Local_ErrorState;
}

ES_t TWI_MasterWriteDataByte(u8 Copy_u8DataByte)
{
	ES_t Local_ErrorState = ES_OK;
	TWDR = Copy_u8DataByte;
	SET_BIT(TWCR,TWCR_TWINT);
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) !=  MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}
	return Local_ErrorState;
}

ES_t TWI_MasterReadDataByte(u8 *Copy_pu8DataByte)
{
	ES_t Local_ErrorState = ES_OK;
	if(Copy_pu8DataByte != NULL)
	{
		SET_BIT(TWCR,TWCR_TWINT);
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) !=  MSTR_RD_BYTE_WITH_ACK)
		{
			Local_ErrorState = ES_NOK;
		}
		else
		{
			*Copy_pu8DataByte = TWDR;
		}
	}
	else
	{
		Local_ErrorState = ES_NULL_POINTER;
	}
	return Local_ErrorState;
}

ES_t TWI_SlaveWriteDataByte(u8 Copy_u8DataByte)
{
	ES_t Local_ErrorState = ES_OK;
	TWDR = Copy_u8DataByte;
	SET_BIT(TWCR,TWCR_TWINT);
	while((GET_BIT(TWCR,TWCR_TWINT))==0);

	if((TWSR & 0xF8) !=  SLAVE_BYTE_TRANSMITTED)
	{
		Local_ErrorState = ES_NOK;
	}
	else
	{

	}
	return Local_ErrorState;
}

ES_t TWI_SlaveReadDataByte(u8 *Copy_pu8DataByte)
{
	ES_t Local_ErrorState = ES_OK;
	if(Copy_pu8DataByte != NULL)
	{
		SET_BIT(TWCR,TWCR_TWINT);
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) !=  SLAVE_ADD_RCVD_WR_REQ)
		{
			Local_ErrorState = ES_NOK;
		}
		SET_BIT(TWCR,TWCR_TWINT);
		while((GET_BIT(TWCR,TWCR_TWINT))==0);

		if((TWSR & 0xF8) !=  SLAVE_DATA_RECEIVED)
		{
			Local_ErrorState = ES_NOK;
		}
		else
		{
			*Copy_pu8DataByte = TWDR;
		}

	}
	else
	{
		Local_ErrorState = ES_NULL_POINTER;
	}
	return Local_ErrorState;
}


void TWI_SendStopCondition(void)
{
	SET_BIT(TWCR, TWCR_TWSTO);
	SET_BIT(TWCR,TWCR_TWINT);
}
