/*
 * Seg_int.h
 *
 *  Created on: Sep 27, 2024
 *      Author: mylap
 */

#ifndef SEG_INT_H_
#define SEG_INT_H_

ES_t SEG_enuInit(SEG_t *Copy_PAstrSeg);

ES_t SEG_enuDisplayNum(u8 Copy_u8SegNum,u8 Copy_u8Num);

ES_t SEG_enuEnableCommon(u8 Copy_u8SegNum);

ES_t SEG_enuDisableCommon(u8 Copy_u8SegNum);

ES_t SEG_enuEnableDot(u8 Copy_u8SegNum);

ES_t SEG_enuDisableDot(u8 Copy_u8SegNum);

ES_t SEG_enuClearDisplay(u8 Copy_u8SegNum);

#endif /* SEG_INT_H_ */
