/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: mylap
 */

#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "LCD_int.h"

#include "Switch_int.h"
#include "Switch_config.h"

extern SW_t Switch_AstrSwitchState [SW_NUM];

int main(void)
{
	DIO_enuInit();
	Switch_enuInit(Switch_AstrSwitchState);
	u8 pinstate;
	u8 Local_u8BallX = 0;
	u8 Local_u8BallY = 0;
	u8 Local_u8BallDirectionX = 1;
	u8 Local_u8BallDirectionY = 1;
	LCD_enuInit();
	LCD_enuDisplayChar('O');
	while(1)
	{
		Local_u8BallX += Local_u8BallDirectionX;
		Local_u8BallY += Local_u8BallDirectionY;
		/*if(Local_u8BallY < 0)
			Local_u8BallDirectionY = (-Local_u8BallDirectionY);
		if(Local_u8BallY >= 2)
			Local_u8BallDirectionY = 2 - Local_u8BallDirectionY;*/
		LCD_voidSetPosition(Local_u8BallX,Local_u8BallY);
		if((Local_u8BallX == 0) || (Local_u8BallX == 16))
		{
			Switch_enuGetState(Switch_AstrSwitchState , &pinstate);
			if(pinstate == 0)
			{
				LCD_enuInit();
				LCD_enuDisplayChar('L');
				LCD_enuDisplayChar('O');
				LCD_enuDisplayChar('S');
				LCD_enuDisplayChar('E');
			}
			else if(pinstate == 1)
			{
				Local_u8BallDirectionX = -Local_u8BallDirectionX;
			}
		}
	}
	return 0;
}

