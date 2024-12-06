/*
 * Led_conf.c
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Led_conf.h"
#include "Led_priv.h"

LED_t LED_AstrLed[LED_NUM]=
{
		{DIO_u8PORTA , DIO_PIN5 , LED_SINK ,LED_OFF},
		{DIO_u8PORTD , DIO_PIN3 , LED_SOURCE ,LED_ON},
		{DIO_u8PORTC , DIO_PIN1 , LED_SOURCE ,LED_OFF}
};
