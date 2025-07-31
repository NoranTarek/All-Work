/*
 * SPI_Program.c
 *
 *  Created on: Jul 31, 2025
 *      Author: mylap
 */

#include "stdTypes.h"
#include "BIT_MATH.h"

#include "SPI_Register.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"
#include "SPI_Configuration.h"

void SPI_voidInit(u8 Copy_u8SPIMode)
{
	if(Copy_u8SPIMode == SPI_MASTER_MODE)
	{
		//Set in master mode
		SET_BIT(SPCR , SPCR_MSTR);

		//Clock polarity -> rising
		CLR_BIT(SPCR , SPCR_CPOL);

		//Clock phase -> sample
		CLR_BIT(SPCR , SPCR_CPHA);

		//Set clock prescaler -> 64
		CLR_BIT(SPCR , SPCR_SPR0);
		SET_BIT(SPCR , SPCR_SPR1);
		CLR_BIT(SPSR , SPSR_SPI2X);

		//SPI -> enable
		SET_BIT(SPCR , SPCR_SPE);

	}
	else if(Copy_u8SPIMode == SPI_SLAVE_MODE)
	{
		//Set in slave mode
		CLR_BIT(SPCR , SPCR_MSTR);

		//SPI -> enable
		SET_BIT(SPCR , SPCR_SPE);
	}
}

u8 SPI_u8DataSendReceive(u8 Copy_u8Data)
{
	SPDR = Copy_u8Data;
	while(GET_BIT(SPSR , SPSR_SPIF) == 0);
	return SPDR;
}
