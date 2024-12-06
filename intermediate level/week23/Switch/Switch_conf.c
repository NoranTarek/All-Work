/*
 * Switch_conf.c
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */
#include "Switch_priv.h"
#include "stdTypes.h"
#include "errorStates.h"
#include "Switch_conf.h"
#include "DIO_int.h"

SW_t Switch_AStr [SW_NUM] = {
		{DIO_PORTA , DIO_PIN0 , DIO_u8PULL_UP},
		{DIO_PORTC , DIO_PIN5 , DIO_u8FLOAT},
		{DIO_PORTB , DIO_PIN7 , DIO_u8PULL_UP}
};

