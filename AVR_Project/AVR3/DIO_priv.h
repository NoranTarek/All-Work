/*
 * DIO_priv.h
 *
 *  Created on: Sep 24, 2024
 *      Author: mylap
 */

#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

#define DIO_MASK_BIT 1

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1
#define FLOAT 0
#define PULL_UP 1
#define DIO_u8PORTOUTPUT 0xFF

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((u8*)0x39)

#define DDRB *((u8*)0x37)
#define PORTB *((u8*)0x38)
#define PINB *((u8*)0x36)

#define DDRC *((u8*)0x34)
#define PORTC *((u8*)0x35)
#define PINC *((u8*)0x33)

#define DDRD *((u8*)0x31)
#define PORTD *((u8*)0x32)
#define PIND *((u8*)0x30)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)  CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)




#endif /* DIO_PRIV_H_ */
