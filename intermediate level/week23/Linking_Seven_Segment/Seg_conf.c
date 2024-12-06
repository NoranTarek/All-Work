/*
 * Seg_conf.c
 *
 *  Created on: Sep 27, 2024
 *      Author: mylap
 */

#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"

#include "Seg_conf.h"
#include "Seg_priv.h"

SEG_t SEG_AstrSeg [SEG_NUM] =
{
		{DIO_PORTB , DIO_PIN5, DIO_PORTC , DIO_PIN7 , DIO_PORTC , DIO_PIN7 ,DIO_PORTC , DIO_PIN3,
	   	DIO_PORTA , DIO_PIN5 , DIO_PORTD , DIO_PIN1, DIO_PORTB , DIO_PIN3 , DIO_PORTD , DIO_PIN7 ,
		DIO_PORTA , DIO_PIN2 , COMMON_CATHODE},
		{DIO_PORTA , DIO_PIN3, DIO_PORTD , DIO_PIN7 , DIO_PORTC , DIO_PIN4 ,DIO_PORTB , DIO_PIN3,
		DIO_PORTD , DIO_PIN5 , DIO_PORTB , DIO_PIN1, DIO_PORTA , DIO_PIN0 , NOT_CONNECTED , NOT_CONNECTED ,
		DIO_PORTC , DIO_PIN2 , COMMON_ANODE}
};

