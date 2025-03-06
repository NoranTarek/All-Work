/*
 * USART_Program.c
 *
 *  Created on: Mar 6, 2025
 *      Author: mylap
 */
#include "stdTypes.h"
#include "BIT_MATH.h"

#include "USART_Configuration.h"
#include "USART_interface.h"
#include "USART_private.h"

#include "LCD_int.h"
#include <util/delay.h>



static const u8 *USART_pu8SendData = NULL ;
static u8 *USART_pu8ReceiveData = NULL ;
static u8 USART_u8BufferSize ;
static u8 USART_u8Index ;
static void (* USART_pvNotificationFunc)(void)= NULL;
static u8 USART_u8State= IDLE ;


void USART_voidInit (void)
{
	u8 Local_u8UCSRC = 0 ;
	u16 Local_u16UBRR = (u16)((SYSTEM_FREQUENCY / (16 * USART_BAUD_RATE)) - 1) ;
	UBRRH = (u8)(Local_u16UBRR >> 8) ;
	UBRRL = (u8)Local_u16UBRR ;

	#if (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X1)

		CLR_BIT(UCSRA , UCSRA_U2X) ;

	#elif (USART_MODE == ASYNCHRONOUS) && (USART_SYSTEM_SPEED == USART_X2)

		Local_u16UBRR /= 2 ;
		SET_BIT(UCSRA , UCSRA_U2X) ;

	#elif (USART_MODE == SYNCHRONOUS)

		Local_u16UBRR /= 8 ;

	#else
		#error "Wrong USART_MODE or USART_SYSTEM_SPEED config"
	#endif


	#if USART_MPCM == DISABLE
		CLR_BIT(UCSRA , UCSRA_MPCM) ;
	#elif USART_MPCM == ENABLE
		SET_BIT(UCSRA , UCSRA_MPCM) ;
	#else
		#error "Wrong USART_MPCM config"
	#endif

	#if USART_MODE == ASYNCHRONOUS
		CLR_BIT(Local_u8UCSRC , UCSRC_UMSEL) ;
	#elif USART_MODE == SYNCHRONOUS
		SET_BIT(Local_u8UCSRC , UCSRC_UMSEL) ;
	#else
		#error "Wrong USART_MODE config"
	#endif

	#if USART_PARITY_MODE == DISABLE
		CLR_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
	#elif USART_PARITY_MODE == EVEN_PARITY
		CLR_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
	#elif USART_PARITY_MODE == ODD_PARITY
		SET_BIT(Local_u8UCSRC , UCSRC_UPM0) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UPM1) ;
	#else
		#error "Wrong USART_PARITY_MODE config"
	#endif

	#if USART_STOP_BIT == STOP_BIT_1
		CLR_BIT(Local_u8UCSRC , UCSRC_USBS) ;
	#elif USART_STOP_BIT == STOP_BIT_2
		SET_BIT(Local_u8UCSRC , UCSRC_USBS) ;
	#else
		#error "Wrong USART_STOP_BIT config"
	#endif

	#if USART_DATA_SIZE == DATA_SIZE_5_BIT
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_6_BIT
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_7_BIT
		CLR_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_8_BIT
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
		CLR_BIT(UCSRB , UCSRB_UCSZ2) ;
	#elif USART_DATA_SIZE == DATA_SIZE_5_BIT
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ0) ;
		SET_BIT(Local_u8UCSRC , UCSRC_UCSZ1) ;
		SET_BIT(UCSRB , UCSRB_UCSZ2) ;
	#else
		#error "Wrong USART_DATA_SIZE config"
	#endif

	#if USART_MODE == SYNCHRONOUS
		#if USART_CLOCK_POLARITY == XCK_RISING_TX_XCH_FALLING_RX
			CLR_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
		#elif USART_CLOCK_POLARITY == XCK_RISING_RX_XCH_FALLING_TX
			SET_BIT(Local_u8UCSRC , UCSRC_UCPOL) ;
		#else
			#error "Wrong USART_STOP_BIT config"
		#endif
	#endif

	SET_BIT(Local_u8UCSRC , UCSRC_URSEL) ;

	UCSRC = Local_u8UCSRC ;

	#if USART_RX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_RXCIE) ;
	#elif USART_RX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_RXCIE) ;
	#else
		#error "Wrong USART_RX_COMPLETE_INTERRUPT config"
	#endif

	#if USART_TX_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	#elif USART_TX_COMPLETE_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_TXCIE) ;
	#else
		#error "Wrong USART_TX_COMPLETE_INTERRUPT config"
	#endif

	#if USART_UDR_EMPTY_INTERRUPT == DISABLE
		CLR_BIT(UCSRB , UCSRB_UDRIE) ;
	#elif USART_UDR_EMPTY_INTERRUPT == ENABLE
		SET_BIT(UCSRB , UCSRB_UDRIE) ;
	#else
		#error "Wrong USART_UDR_EMPTY_INTERRUPT config"
	#endif

	#if USART_RECEIVER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_RXEN) ;
	#elif USART_RECEIVER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_RXEN) ;
	#else
		#error "Wrong USART_RECEIVER_ENABLE config"
	#endif

	#if USART_TRANSMITTER_ENABLE == DISABLE
		CLR_BIT(UCSRB , UCSRB_TXEN) ;
	#elif USART_TRANSMITTER_ENABLE == ENABLE
		SET_BIT(UCSRB , UCSRB_TXEN) ;
	#else
		#error "Wrong USART_TRANSMITTER_ENABLE config"
	#endif
}

u8 USART_u8SendData (u8 Copy_u8Data)
{
	u8 Local_u8ErrorState = ES_OK ;
	u32 Local_u32TimeoutCounter = 0 ;
	if (USART_u8State == IDLE)
	{
		USART_u8State = BUSY ;
		while (((GET_BIT(UCSRA , UCSRA_UDRE)) == 0) && (Local_u32TimeoutCounter != USART_u32TIMEOUT))
		{
			Local_u32TimeoutCounter++ ;
		}

		if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
			Local_u8ErrorState = ES_OUT_OF_RANGE ;
		else
			UDR = Copy_u8Data ;

		USART_u8State = IDLE ;
	}
	else
	{
		Local_u8ErrorState = ES_NOK ;
	}
	return Local_u8ErrorState ;
}

u8 USART_u8RecevieData (u8 *Copy_u8ReceviedData)
{
	u8 Local_u8ErrorState ;
	u32 Local_u32TimeoutCounter = 0 ;
	if (Copy_u8ReceviedData != NULL)
	{
		if (USART_u8State == IDLE)
		{
			USART_u8State = BUSY ;

			while (((GET_BIT(UCSRA , UCSRA_RXC)) == 0) && (Local_u32TimeoutCounter != USART_u32TIMEOUT))
				Local_u32TimeoutCounter++ ;

			if (Local_u32TimeoutCounter == USART_u32TIMEOUT)
				Local_u8ErrorState = ES_OUT_OF_RANGE ;
			else
				*Copy_u8ReceviedData = UDR ;

			USART_u8State = IDLE ;
		}
		else
			Local_u8ErrorState = ES_NOK ;
	}
	else
		Local_u8ErrorState = ES_NULL_POINTER ;

	return Local_u8ErrorState ;
}

u8 USART_u8SendStringSynch (const u8 * Copy_pchString)
{
	u8 Local_u8ErrorState = ES_OK ;

	u32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Copy_pchString[Local_u32Index] != '\0')
		{
			Local_u8ErrorState = USART_u8SendData(Copy_pchString[Local_u32Index]) ;
			Local_u32Index++ ;
			if (Local_u8ErrorState != ES_OK)
				return Local_u8ErrorState ;
		}
	}
	else
		Local_u8ErrorState = ES_NULL_POINTER ;

	return Local_u8ErrorState ;
}

u8   USART_u8SendStringAsynch (const u8 * Copy_pchString , void (* NotificationFunc)(void))
{
	u8 Local_u8ErrorState = ES_OK ;

	if (USART_u8State == IDLE)
	{
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
		{
			USART_u8State = BUSY ;

			USART_pu8SendData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;
			USART_u8Index = 0 ;
			UDR = USART_pu8SendData[USART_u8Index] ;
			SET_BIT(UCSRB , UCSRB_TXCIE) ;
		}
		else
			Local_u8ErrorState = ES_NULL_POINTER ;
	}
	else
		Local_u8ErrorState = ES_NOK ;

	return Local_u8ErrorState ;
}

u8 USART_u8ReceiveBufferSynch (u8 *Copy_pchString , u32 Copy_u32BufferSize)
{
	u8 Local_u8ErrorState = ES_OK ;

	u32 Local_u32Index = 0 ;

	if (Copy_pchString != NULL)
	{
		while (Local_u32Index < Copy_u32BufferSize)
		{
			Local_u8ErrorState = USART_u8RecevieData(&Copy_pchString[Local_u32Index]) ;
			Local_u32Index++ ;

			if (Local_u8ErrorState != ES_OK)
				return Local_u8ErrorState ;
		}
	}
	else
		Local_u8ErrorState = ES_NULL_POINTER ;

	return Local_u8ErrorState ;
}

u8 USART_u8ReceiveBufferAsynch (u8 *Copy_pchString , u32 Copy_u32BufferSize , void (* NotificationFunc)(void))
{
	u8 Local_u8ErrorState = ES_OK ;

	if (USART_u8State == IDLE)
	{
		if ((Copy_pchString != NULL) && (NotificationFunc != NULL))
		{
			USART_u8State = BUSY ;

			USART_pu8ReceiveData = Copy_pchString ;
			USART_pvNotificationFunc = NotificationFunc ;
			USART_u8BufferSize = Copy_u32BufferSize;

			USART_u8Index = 0 ;

			SET_BIT(UCSRB , UCSRB_RXCIE) ;
		}
		else
			Local_u8ErrorState = ES_NULL_POINTER ;
	}
	else
		Local_u8ErrorState = ES_NOK ;

	return Local_u8ErrorState ;
}


void __vector_13 (void)		__attribute__ ((signal)) ;
void __vector_13 (void)
{
	USART_pu8ReceiveData[USART_u8Index] = UDR ;
	USART_u8Index++ ;

	if (USART_u8Index == USART_u8BufferSize)
	{
		USART_u8Index=0;
		USART_u8State = IDLE ;
		USART_pvNotificationFunc() ;
		CLR_BIT(UCSRB , UCSRB_RXCIE) ;
	}
	else
	{
		/*Do Noting*/
	}
}

void __vector_15 (void)		__attribute__ ((signal)) ;
void __vector_15 (void)
{
	USART_u8Index++ ;

	if (USART_pu8SendData[USART_u8Index] == '\0')
	{
		USART_u8Index=0;
		USART_u8State = IDLE ;
		USART_pvNotificationFunc() ;
		CLR_BIT(UCSRB , UCSRB_TXCIE) ;
	}
	else
	{
		UDR = USART_pu8SendData[USART_u8Index] ;
	}
}

