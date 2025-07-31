/*
 * LCD_int.h
 *
 *  Created on: Oct 16, 2024
 *      Author: mylap
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_
#include "DIO_int.h"

void LCD_voidInit(void);

void LCD_voidSendCommand(u8 command);

void LCD_voidSendData(u8 data);

void LCD_voidInitPortValues(void);

void LCD_voidSendString(const u8 *str);

void LCD_voidSendNumber(u32 value);

void LCD_voidSendFloatingNumber(f32 value);

u8 LCD_u8GoToXY(u8 col , u8 row);

void LCD_voidClearDisplay();


#endif /* LCD_INT_H_ */
