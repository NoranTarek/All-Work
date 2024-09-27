/*
 * Led_conf.h
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */

#ifndef LED_CONF_H_
#define LED_CONF_H_

#include "stdTypes.h"
#define LED_NUM 3
typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;
	u8 LED_u8InitState;
}LED_t;


#endif /* LED_CONF_H_ */
