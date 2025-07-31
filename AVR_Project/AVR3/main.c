/*
 * main.c
 *
 *  Created on: Mar 25, 2025
 *      Author: mylap
 */

#include "stdTypes.h"

#include "DIO_int.h"
#include "SPI_Interface.h"
#include "ADC_Interface.h"

void main()
{
	u8 Read;
	DIO_enuSetPinDirection(DIO_u8PORTA , DIO_u8PIN0 , DIO_u8INPUT); //Sensor PIN

	ADC_voidInit();
	SPI_voidInit(SPI_SLAVE_MODE);

	while(1)
	{
		Read = ADC_u16ADCStartConvertPolling(0b00000);
		SPI_u8DataSendReceive((Read * 256) / 1023);
	}
}

