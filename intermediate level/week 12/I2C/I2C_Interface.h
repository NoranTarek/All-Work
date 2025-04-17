/*
 * I2C_Interface.h
 *
 *  Created on: Apr 17, 2025
 *      Author: mylap
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

void TWI_voidInitMaster(u8 Copy_u8Address);

void TWI_voidInitSlave(u8 Copy_u8Address);

ES_t TWI_SendStartCondition(void);

ES_t TWI_SendRepeatedStart(void);

ES_t TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

ES_t TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

ES_t TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

ES_t TWI_MasterReadDataByte(u8 *Copy_pu8DataByte);

ES_t TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

ES_t TWI_SlaveReadDataByte(u8 *Copy_pu8DataByte);


void TWI_SendStopCondition(void);

#endif /* I2C_INTERFACE_H_ */
