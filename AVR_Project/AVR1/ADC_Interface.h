/*
 * ADC_Interface.h
 *
 *  Created on: Jul 24, 2025
 *      Author: mylap
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_voidInit(void);

u16 ADC_u16ADCStartConvertPolling(u8 Copy_u8Channel);

u8 ADC_u8ADCStartConvertInt(u8 Copy_u8Channel , u16 *pu16Reading , void(*ptrFunc)(void));

#endif /* ADC_INTERFACE_H_ */
