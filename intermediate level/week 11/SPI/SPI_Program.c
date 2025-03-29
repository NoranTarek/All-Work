/*
 * SPI_Program.c
 *
 *  Created on: Mar 25, 2025
 *      Author: mylap
 */

#include "stdTypes.h"
#include "MATH_BIT.h"
#include "errorStates.h"

#include "SPI_interface.h"
#include "SPI_Configuration.h"
#include "SPI_private.h"


static u8 *SPI_pu8TData = NULL ;

static u8 *SPI_pu8RData = NULL ;

static u8 SPI_u8BufferSize;

static u8 SPI_u8Index;

static void (*SPI_pvNotificationFunc)(void)= NULL;

static u8 SPI_u8State= IDLE ;

void SPI_VoidInit(void)
{
	#if SPI_DATA_ORDER == SPI_DATA_LSB_FIRST
		SET_BIT(SPCR , SPCR_DORD) ;
	#elif SPI_DATA_ORDER == SPI_DATA_MSP_FIRST
		CLR_BIT(SPCR,SPCR_DORD);
	#else
		#error "wrong SPI_DATA_ORDER config"
	#endif

	#if SPI_MASTER_SLAVE_SELECT == SPI_MASTER
		SET_BIT(SPCR , SPCR_MSTR) ;
	#elif SPI_MASTER_SLAVE_SELECT == SPI_SLAVE
		CLR_BIT(SPCR , SPCR_MSTR) ;
	#else
		#error "wrong SPI_MASTER_SLAVE_SELECT config"
	#endif

	#if SPI_CLOCK_POLARITY == SPI_RISING_LEADING_FALLING_TRAILING
		CLR_BIT(SPCR , SPCR_CPOL) ;
	#elif SPI_CLOCK_POLARITY == SPI_FALLING_LEADING_RISING_TRAILING
		SET_BIT(SPCR , SPCR_CPOL) ;
	#else
		#error "wrong SPI_CLOCK_POLARITY config"
	#endif

	#if SPI_CLOCK_PHASE == SPI_SAMPLE_LEADING_SETUP_TRAILING
		CLR_BIT(SPCR , SPCR_CPHA) ;

	#elif SPI_CLOCK_PHASE == SPI_SETUP_LEADING_SAMPLE_TRAILING
		SET_BIT(SPCR , SPCR_CPHA) ;
	#else
		#error "wrong SPI_CLOCK_PHASE config"
	#endif

	#if SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_2
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_4
		CLR_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_8
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_16
		SET_BIT(SPCR , SPCR_SPR0) ;
		CLR_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_32
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		SET_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_64
		CLR_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#elif SPI_CLOCK_RATE == SPI_FREQ_DIVIDED_BY_128
		SET_BIT(SPCR , SPCR_SPR0) ;
		SET_BIT(SPCR , SPCR_SPR1) ;
		CLR_BIT(SPSR , SPSR_SPI2X) ;
	#else
		#error "wrong SPI_CLOCK_RATE config"
	#endif

	#if SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_DISABLE
		CLR_BIT(SPCR , SPCR_SPIE) ;
	#elif SPI_INTERRUPT_ENABLE_MODE == SPI_INTERRUPT_ENABLE
		SET_BIT(SPCR , SPCR_SPIE) ;
	#else
		#error "wrong SPI_INTERRUPT_ENABLE_MODE config"
	#endif

	#if SPI_ENABLE_MODE == SPI_DISABLE
		CLR_BIT(SPCR , SPCR_SPE) ;
	#elif SPI_ENABLE_MODE == SPI_ENABLE
		SET_BIT(SPCR , SPCR_SPE) ;
	#else
		#error "wrong SPI_ENABLE_MODE config"
	#endif

}


ES_t SPI_u8InitConfig (SPI_CONFIG *spi)
{
	u8 Local_u8ErrorState = ES_OK ;

	if ((spi != NULL) && (spi->SPI_u8ClockPhase != NULL) && (spi->SPI_u8ClockPolarity != NULL) && (spi->SPI_u8ClockRate != NULL) && (spi->SPI_u8DataOrder != NULL) && (spi->SPI_u8InterruptEnable != NULL) && (spi->SPI_u8MasterSlaveSelect != NULL) && (spi->SPI_u8SPIEnable != NULL))
	{
		switch (spi->SPI_u8ClockPhase)
		{
		case SPI_SAMPLE_LEADING_SETUP_TRAILING: CLR_BIT(SPCR , SPCR_CPHA) ; break ;
		case SPI_SETUP_LEADING_SAMPLE_TRAILING: SET_BIT(SPCR , SPCR_CPHA) ; break ;
		default: 								Local_u8ErrorState = ES_NOK ; break ;
		}
		switch (spi->SPI_u8ClockPolarity)
		{
		case SPI_RISING_LEADING_FALLING_TRAILING: CLR_BIT(SPCR , SPCR_CPOL) ; break ;
		case SPI_FALLING_LEADING_RISING_TRAILING: SET_BIT(SPCR , SPCR_CPOL) ; break ;
		default:								  Local_u8ErrorState = ES_NOK ; break ;
		}
		switch (spi->SPI_u8ClockRate)
		{
		case SPI_FREQ_DIVIDED_BY_2:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_4:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_8:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_16:
			SET_BIT(SPCR , SPCR_SPR0) ;
			CLR_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_32:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			SET_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_64:
			CLR_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		case SPI_FREQ_DIVIDED_BY_128:
			SET_BIT(SPCR , SPCR_SPR0) ;
			SET_BIT(SPCR , SPCR_SPR1) ;
			CLR_BIT(SPSR , SPSR_SPI2X) ;
			break ;
		default:
			Local_u8ErrorState = ES_NOK ;
			break ;
		}
		switch (spi->SPI_u8DataOrder)
		{
		case SPI_DATA_MSP_FIRST: CLR_BIT(SPCR , SPCR_DORD) ; break ;
		case SPI_DATA_LSB_FIRST: SET_BIT(SPCR , SPCR_DORD) ; break ;
		default:				 Local_u8ErrorState = ES_NOK ; break ;
		}
		switch (spi->SPI_u8MasterSlaveSelect)
		{
		case SPI_MASTER: SET_BIT(SPCR , SPCR_MSTR) ; break ;
		case SPI_SLAVE:  CLR_BIT(SPCR , SPCR_MSTR) ; break ;
		default:		 Local_u8ErrorState = ES_NOK ; break ;
		}
		switch (spi->SPI_u8InterruptEnable)
		{
		case SPI_INTERRUPT_DISABLE: CLR_BIT(SPCR , SPCR_SPIE) ; break ;
		case SPI_INTERRUPT_ENABLE:  SET_BIT(SPCR , SPCR_SPIE) ; break ;
		default:		 			Local_u8ErrorState = ES_NOK ; break ;
		}
		switch (spi->SPI_u8SPIEnable)
		{
		case SPI_DISABLE: CLR_BIT(SPCR , SPCR_SPE) ; break ;
		case SPI_ENABLE:  SET_BIT(SPCR , SPCR_SPE) ; break ;
		default:		  Local_u8ErrorState = ES_NOK ; break ;
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

ES_t SPI_u8Tranceive (u8 Copy_u8TData , u8 *Copy_u8RData)
{
	u8 Local_u8ErrorState = ES_OK ;
	u8 Local_uint32TimeoutCounter = 0 ;

	if (SPI_u8State == IDLE)
	{
		SPI_u8State = BUSY ;

		SPDR = Copy_u8TData ;

		while (((GET_BIT(SPSR , SPSR_SPIF)) == 0) && (Local_uint32TimeoutCounter < SPI_uint32TIMEOUT))
		{
			Local_uint32TimeoutCounter++ ;
		}
		if (Local_uint32TimeoutCounter == SPI_uint32TIMEOUT)
		{
			Local_u8ErrorState = ES_OUT_OF_RANGE ;
		}
		else
		{
			*Copy_u8RData = SPDR ;
		}
		SPI_u8State = IDLE ;
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE ;
	}

	return Local_u8ErrorState ;
}

ES_t SPI_u8BufferTranceiverSynch (u8 *Copy_u8TData , u8 *Copy_u8RData , u8 Copy_u8BufferSize)
{
	u8 Local_u8ErrorState = ES_OK ;
	u8 Local_u8Counter = 0 ;
	if ((Copy_u8TData != NULL) && (Copy_u8RData != NULL))
	{
		while (Local_u8Counter < Copy_u8BufferSize)
		{
			SPI_u8Tranceive(Copy_u8TData[Local_u8Counter] , &Copy_u8RData[Local_u8Counter]) ;
			Local_u8Counter++ ;
		}
	}
	else
	{
		Local_u8ErrorState = ES_NULL_POINTER ;
	}
	return Local_u8ErrorState ;
}

ES_t SPI_u8BufferTranceiverAsynch (SPI_BUFFER *spi_buffer)
{
	u8 Local_u8ErrorState = ES_OK ;

	if (SPI_u8State == IDLE)
	{
		if ((spi_buffer != NULL) && (spi_buffer->Copy_u8TData != NULL) && (spi_buffer->Copy_u8RData != NULL) && (spi_buffer->NotificationFuncn != NULL))
		{
			SPI_u8State = BUSY ;

			SPI_pu8TData = spi_buffer->Copy_u8TData ;
			SPI_pu8RData = spi_buffer->Copy_u8RData ;
			SPI_u8BufferSize = spi_buffer->Copy_u8BufferSize ;
			SPI_pvNotificationFunc = spi_buffer->NotificationFuncn ;

			SPI_u8Index = 0 ;

			SPDR = SPI_pu8TData[SPI_u8Index] ;

			SET_BIT(SPCR , SPCR_SPIE) ;
		}
		else
		{
			Local_u8ErrorState = ES_NULL_POINTER ;
		}
	}
	else
	{
		Local_u8ErrorState = ES_OUT_OF_RANGE ;
	}
	return Local_u8ErrorState ;
}

void __vector_12 (void)		__attribute__ ((signal)) ;
void __vector_12 (void)
{
	SPI_pu8RData[SPI_u8Index] = SPDR ;

	SPI_u8Index++ ;

	if (SPI_u8Index == SPI_u8BufferSize)
	{
		SPI_u8State = IDLE ;

		CLR_BIT(SPCR , SPCR_SPIE) ;

		SPI_pvNotificationFunc() ;
	}
	else
	{
		SPDR = SPI_pu8TData[SPI_u8Index] ;
	}
}
