/*
 * Seg_prog.c
 *
 *  Created on: Sep 27, 2024
 *      Author: mylap
 */
#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"

#include "Seg_priv.h"
#include "Seg_conf.h"

extern SEG_t SEG_AstrSeg [SEG_NUM];
extern u8 SEG_u8Dis[];

ES_t SEG_enuInit(SEG_t *Copy_PAstrSeg)
{
	u8 Local_u8ErrorState = ES_NOK;
	u32 Local_u32Check = 0;
	if(Copy_PAstrSeg != NULL)
	{
		for(u8 Local_u8Iter = 0;Local_u8Iter < SEG_NUM; Local_u8Iter ++)
		{
			Local_u32Check  =  DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortA,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinA, DIO_u8OUTPUT);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortB,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinB, DIO_u8OUTPUT)<<2);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortC,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinC, DIO_u8OUTPUT)<<4);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortD,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinD, DIO_u8OUTPUT)<<6);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortE,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinE, DIO_u8OUTPUT)<<8);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortF,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinF, DIO_u8OUTPUT)<<10);
			Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortG,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinG, DIO_u8OUTPUT)<<12);
			if(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortCMN != NOT_CONNECTED && Copy_PAstrSeg[Local_u8Iter].SEG_u8PinCMN != NOT_CONNECTED)
			{
				Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortCMN,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinCMN, DIO_u8OUTPUT)<<14);
			}
			if(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortDOT != NOT_CONNECTED && Copy_PAstrSeg[Local_u8Iter].SEG_u8PinDOT != NOT_CONNECTED)
			{
				Local_u32Check |= (DIO_enuSetPinDirection(Copy_PAstrSeg[Local_u8Iter].SEG_u8PortDOT,Copy_PAstrSeg[Local_u8Iter].SEG_u8PinDOT, DIO_u8OUTPUT)<<16);
			}
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER;
	}
	return Local_u8ErrorState;
}

ES_t SEG_enuDisplayNum(u8 Copy_u8SegNum ,u8 Copy_u8Num)
{
	u8 Local_u8ErrorState = ES_NOK;
	if(Copy_u8Num < 10 && Copy_u8SegNum < SEG_NUM)
	{
		u8 Local_u32Check = 0;
		if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_CATHODE)
		{
			Local_u32Check  =  DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortA,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinA, (SEG_u8Dis[Copy_u8Num]&1));
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortB,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinB, ((SEG_u8Dis[Copy_u8Num]>>1)&1))<<2);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortC,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinC, ((SEG_u8Dis[Copy_u8Num]>>2)&1))<<4);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortD,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinD, ((SEG_u8Dis[Copy_u8Num]>>3)&1))<<6);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortE,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinE, ((SEG_u8Dis[Copy_u8Num]>>4)&1))<<8);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortF,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinF, ((SEG_u8Dis[Copy_u8Num]>>5)&1))<<10);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortG,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinG, ((SEG_u8Dis[Copy_u8Num]>>6)&1))<<12);
		}
		else if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_ANODE)
		{
			Local_u32Check  =  DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortA,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinA, (SEG_u8Dis[Copy_u8Num]&1));
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortB,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinB, !((SEG_u8Dis[Copy_u8Num]>>1)&1))<<2);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortC,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinC, !((SEG_u8Dis[Copy_u8Num]>>2)&1))<<4);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortD,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinD, !((SEG_u8Dis[Copy_u8Num]>>3)&1))<<6);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortE,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinE, !((SEG_u8Dis[Copy_u8Num]>>4)&1))<<8);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortF,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinF, !((SEG_u8Dis[Copy_u8Num]>>5)&1))<<10);
			Local_u32Check |= (DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortG,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinG, !((SEG_u8Dis[Copy_u8Num]>>6)&1))<<12);
		}
		for(u8 Local_u8Iter = 0; Local_u8Iter < 14; Local_u8Iter += 2)
		{
			if((Local_u32Check >> Local_u8Iter) == 1)
			{
				Local_u8ErrorState = ES_OK;
			}
		}
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t SEG_enuEnableCommon(u8 Copy_u8SegNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	if( Copy_u8SegNum < SEG_NUM )
	{
		if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN != NOT_CONNECTED)
		{
			if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_CATHODE)
			{
				DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN,DIO_u8LOW);
			}
			else if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN,DIO_u8HIGH);
			}
		}
		Local_u8ErrorState = ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t SEG_enuDisableCommon(u8 Copy_u8SegNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	if( Copy_u8SegNum < SEG_NUM )
	{
		if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN != NOT_CONNECTED)
		{
			if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_CATHODE)
			{
				DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN,DIO_u8HIGH);
			}
			else if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN,DIO_u8LOW);
			}
		}
		Local_u8ErrorState = ES_OK;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE;
	}
	return Local_u8ErrorState;
}

ES_t SEG_enuEnableDot(u8 Copy_u8SegNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	if( Copy_u8SegNum < SEG_NUM )
		{
			if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT != NOT_CONNECTED)
			{
				if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_CATHODE)
				{
					DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT,DIO_u8HIGH);
				}
				else if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_ANODE)
				{
					DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT,DIO_u8LOW);
				}
			}
			Local_u8ErrorState = ES_OK;
		}
		else
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE;
		}
	return Local_u8ErrorState;
}

ES_t SEG_enuDisableDot(u8 Copy_u8SegNum)
{
	u8 Local_u8ErrorState = ES_NOK;
		if( Copy_u8SegNum < SEG_NUM )
			{
				if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT != NOT_CONNECTED)
				{
					if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_CATHODE)
					{
						DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT,DIO_u8LOW);
					}
					else if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8Type == COMMON_ANODE)
					{
						DIO_enuSetPinValue(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT,SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT,DIO_u8HIGH);
					}
				}
				Local_u8ErrorState = ES_OK;
			}
			else
			{
				Local_u8ErrorState = ES_OUT_OF_RANGE;
			}
	return Local_u8ErrorState;
}

ES_t SEG_enuClearDisplay(u8 Copy_u8SegNum)
{
	u8 Local_u8ErrorState = ES_NOK;
	u32 Local_u32Check = 0;
		if(SEG_AstrSeg != NULL)
		{
			for(u8 Local_u8Iter = 0;Local_u8Iter < SEG_NUM; Local_u8Iter ++)
			{
				if(SEG_AstrSeg[Local_u8Iter].SEG_u8Type == COMMON_CATHODE)
				{
					Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortA,SEG_AstrSeg[Local_u8Iter].SEG_u8PinA, DIO_u8LOW);
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortB,SEG_AstrSeg[Local_u8Iter].SEG_u8PinB, DIO_u8LOW));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortC,SEG_AstrSeg[Local_u8Iter].SEG_u8PinC, DIO_u8LOW));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortD,SEG_AstrSeg[Local_u8Iter].SEG_u8PinD, DIO_u8LOW));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortE,SEG_AstrSeg[Local_u8Iter].SEG_u8PinE, DIO_u8LOW));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortF,SEG_AstrSeg[Local_u8Iter].SEG_u8PinF, DIO_u8LOW));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortG,SEG_AstrSeg[Local_u8Iter].SEG_u8PinG, DIO_u8LOW));
					if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortCMN != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinCMN != NOT_CONNECTED)
					{
						Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortCMN,SEG_AstrSeg[Local_u8Iter].SEG_u8PinCMN, DIO_u8LOW);
					}
					if(SEG_AstrSeg[Copy_u8SegNum].SEG_u8PortDOT != NOT_CONNECTED && SEG_AstrSeg[Copy_u8SegNum].SEG_u8PinDOT != NOT_CONNECTED)
					{
						Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortDOT,SEG_AstrSeg[Local_u8Iter].SEG_u8PinDOT, DIO_u8HIGH);
					}
				}else if (SEG_AstrSeg[Local_u8Iter].SEG_u8Type == COMMON_ANODE)
				{
					Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortA,SEG_AstrSeg[Local_u8Iter].SEG_u8PinA, DIO_u8HIGH);
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortB,SEG_AstrSeg[Local_u8Iter].SEG_u8PinB, DIO_u8HIGH));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortC,SEG_AstrSeg[Local_u8Iter].SEG_u8PinC, DIO_u8HIGH));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortD,SEG_AstrSeg[Local_u8Iter].SEG_u8PinD, DIO_u8HIGH));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortE,SEG_AstrSeg[Local_u8Iter].SEG_u8PinE, DIO_u8HIGH));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortF,SEG_AstrSeg[Local_u8Iter].SEG_u8PinF, DIO_u8HIGH));
					Local_u32Check = (DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortG,SEG_AstrSeg[Local_u8Iter].SEG_u8PinG, DIO_u8HIGH));
					}
					if(SEG_AstrSeg[Local_u8Iter].SEG_u8PortCMN != NOT_CONNECTED && SEG_AstrSeg[Local_u8Iter].SEG_u8PinCMN != NOT_CONNECTED)
					{
						Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortCMN,SEG_AstrSeg[Local_u8Iter].SEG_u8PinCMN, DIO_u8HIGH);
					}
					if(SEG_AstrSeg[Local_u8Iter].SEG_u8PortDOT != NOT_CONNECTED && SEG_AstrSeg[Local_u8Iter].SEG_u8PinDOT != NOT_CONNECTED)
					{
						Local_u32Check =  DIO_enuSetPinValue(SEG_AstrSeg[Local_u8Iter].SEG_u8PortDOT,SEG_AstrSeg[Local_u8Iter].SEG_u8PinDOT, DIO_u8LOW);
					}
			}
			for(u8 Local_u8Iter = 0; Local_u8Iter < 14; Local_u8Iter += 2)
			{
				if((Local_u32Check >> Local_u8Iter) == 1)
				{
					Local_u8ErrorState = ES_OK;
				}
			}
		}
		else
		{
			Local_u8ErrorState = ES_NULL_POINTER;
		}
	return Local_u8ErrorState;
}
