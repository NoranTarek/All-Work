/*
 * Switch_conf.h
 *
 *  Created on: Sep 26, 2024
 *      Author: mylap
 */

#ifndef SWITCH_CONF_H_
#define SWITCH_CONF_H_

#define SW_NUM 3

typedef struct
{
	u8 Switch_PortID;
	u8 Switch_PinID;
	u8 Switch_status;
}SW_t;


#endif /* SWITCH_CONF_H_ */
