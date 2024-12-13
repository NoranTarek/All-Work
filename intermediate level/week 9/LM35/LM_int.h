/*
 * LM_int.h
 *
 *  Created on: Dec 13, 2024
 *      Author: mylap
 */

#ifndef LM_INT_H_
#define LM_INT_H_

#define ADC_RESOLUTION_10_BIT 0
#define ADC_RESOLUTION_8_BIT  1



typedef struct
	{
		u8 Copy_u8LM35Channel ;
		u8 Copy_u8ADCVoltageReference ;
		u8 Copy_u8ADCResolution ;
	} LM35_CONFIG ;

	ES_t LM35_u8GetTemp (LM35_CONFIG *lm35 , u8 * Copy_u8TempValue) ;

#endif /* LM_INT_H_ */
