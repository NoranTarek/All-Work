/*
 * I2C_Configuration.h
 *
 *  Created on: Apr 17, 2025
 *      Author: mylap
 */

#ifndef I2C_CONFIGURATION_H_
#define I2C_CONFIGURATION_H_

#define F_CPU 8000000UL


/*
	$ Options :-
		1-PRESCALLER_BY_1
		2-PRESCALLER_BY_4
		3-PRESCALLER_BY_16
		4-PRESCALLER_BY_64
*/
#define TWI_PRESCALLER  PRESCALLER_BY_1


/*Set SCL frequency to 400kHz, with 8Mhz system frequency*/
#define SCL_Clock  400000UL


#endif /* I2C_CONFIGURATION_H_ */
