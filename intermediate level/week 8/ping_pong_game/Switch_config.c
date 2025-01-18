/*
 * Switch_config.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Ahmed El-Gaafrawy
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_priv.h"
#include "Switch_config.h"
#include "DIO_int.h"

SW_t Switch_AstrSwitchState [SW_NUM] =
{
		{DIO_u8PORTC , DIO_u8PIN2 , DIO_u8FLOAT}
};

