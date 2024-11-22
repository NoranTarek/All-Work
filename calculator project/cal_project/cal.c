/*
 * cal.c
 *
 *  Created on: Nov 8, 2024
 *      Author: mylap
 */
#include "stdTypes.h"
#include "cal.h"

u8 CAL_u32SUM(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0;
	for(u8 counter = 0; counter < n;counter++)
	{
		n1 += ((counter * 10) * num1[counter]);
	}
	for(u8 counter = 0; counter < m;counter++)
	{
		n2 += ((counter * 10) * num2[counter]);
	}
	return (n1+n2+'0');
}

u8 CAL_u32SUB(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0;
	for(u8 counter = 0; counter < n;counter++)
	{
		n1 += ((counter * 10) * num1[counter]);
	}
	for(u8 counter = 0; counter < m;counter++)
	{
		n2 += ((counter * 10) * num2[counter]);
	}
	return (n1-n2+'0');
}

u8 CAL_u32MUL(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0;
	for(u8 counter = 0; counter < n;counter++)
	{
		n1 += ((counter * 10) * num1[counter]);
	}
	for(u8 counter = 0; counter < m;counter++)
	{
		n2 += ((counter * 10) * num2[counter]);
	}
	return ((n1*n2)+'0');
}

u8 CAL_u32DIV(u8 num1[],u8 num2[],u8 n, u8 m)
{
	u8 n1 = 0,n2 = 0;
	for(u8 counter = 0; counter < n;counter++)
	{
		n1 += ((counter * 10) * num1[counter]);
	}
	for(u8 counter = 0; counter < m;counter++)
	{
		n2 += ((counter * 10) * num2[counter]);
	}
	return ((n1/n2)+'0');
}
