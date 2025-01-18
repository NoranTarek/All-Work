/*
 * LCD_Priv.h
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_

#define EIGHT_BIT   0
#define FOUR_BIT    1

#define LCD_SETCURSOR 0x80

#define LCD_ROW1    1
#define LCD_ROW2    2

#define LCD_COL1    1
#define LCD_COL2    2
#define LCD_COL3    3
#define LCD_COL4    4
#define LCD_COL5    5
#define LCD_COL6    6
#define LCD_COL7    7
#define LCD_COL8    8
#define LCD_COL9    9
#define LCD_COL10   10
#define LCD_COL11   11
#define LCD_COL12   12
#define LCD_COL13   13
#define LCD_COL14   14
#define LCD_COL15   15
#define LCD_COL16   16

static void LCD_Latch(u8 Copy_u8Data);

inline static void LCD_invidSendCommend(u8 Copy_u8Command);


#endif /* LCD_PRIV_H_ */
