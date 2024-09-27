/*
 * Seg_conf.h
 *
 *  Created on: Sep 27, 2024
 *      Author: mylap
 */

#ifndef SEG_CONF_H_
#define SEG_CONF_H_

#define SEG_NUM 3

typedef struct
{
	u8 SEG_u8PortA;
	u8 SEG_u8PinA;

	u8 SEG_u8PortB;
	u8 SEG_u8PinB;

	u8 SEG_u8PortC;
	u8 SEG_u8PinC;

	u8 SEG_u8PortD;
	u8 SEG_u8PinD;

	u8 SEG_u8PortE;
	u8 SEG_u8PinE;

	u8 SEG_u8PortF;
	u8 SEG_u8PinF;

	u8 SEG_u8PortG;
	u8 SEG_u8PinG;

	u8 SEG_u8PortCMN;
	u8 SEG_u8PinCMN;

	u8 SEG_u8PortDOT;
	u8 SEG_u8PinDOT;

	u8 SEG_u8Type;
}SEG_t;


#endif /* SEG_CONF_H_ */
