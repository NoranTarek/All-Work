/*
 * SPI_Interface.h
 *
 *  Created on: Jul 31, 2025
 *      Author: mylap
 */

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define SPI_MASTER_MODE			0
#define SPI_SLAVE_MODE			1

/*
 * Options:
 * 1-SPI_MASTER_MODE .
 * 2-SPI_SLAVE_MODE  .
 * */

void SPI_voidInit(u8 Copy_u8SPIMode);

u8 SPI_u8DataSendReceive(u8 Copy_u8Data);

#endif /* SPI_INTERFACE_H_ */
