/*
 * Led_int.h
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */

#ifndef LED_INT_H_
#define LED_INT_H_

#include "stdTypes.h"
#include "errorStates.h"

ES_t LED_enuInit(LED_t *Copy_pstrLed);

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID);

#endif /* LED_INT_H_ */
