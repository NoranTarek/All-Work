/*
 * cal.h
 *
 *  Created on: Nov 8, 2024
 *      Author: mylap
 */

#ifndef CAL_H_
#define CAL_H_


#define NUM_SIZE 4

u8 CAL_u32SUM(u8 num1[],u8 num2[],u8 n, u8 m,u8 *Res[NUM_SIZE]);

u8 CAL_u32SUB(u8 num1[],u8 num2[],u8 n, u8 m);

u8 CAL_u32MUL(u8 num1[],u8 num2[],u8 n, u8 m);

u8 CAL_u32DIV(u8 num1[],u8 num2[],u8 n, u8 m);

#endif /* CAL_H_ */
