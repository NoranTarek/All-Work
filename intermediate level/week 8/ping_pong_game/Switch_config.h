/*
 * Switch_config.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef SWITCH_CONFIG_H_
#define SWITCH_CONFIG_H_

#define SW_NUM		1
typedef struct
{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_Status;
}SW_t;
#endif /* SWITCH_CONFIG_H_ */
