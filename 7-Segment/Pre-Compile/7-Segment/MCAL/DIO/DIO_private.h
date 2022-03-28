/*
 * DIO_private.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DIO_U8MASKINGBIT 1

#define DIO_U8PORTA 0
#define DIO_U8PORTB 1
#define DIO_U8PORTC 2
#define DIO_U8PORTD 3

#define DIO_U8PIN0 0
#define DIO_U8PIN1 1
#define DIO_U8PIN2 2
#define DIO_U8PIN3 3
#define DIO_U8PIN4 4
#define DIO_U8PIN5 5
#define DIO_U8PIN6 6
#define DIO_U8PIN7 7

#define INPUT 0
#define OUTPUT 1

#define LOW 0
#define HIGH 1
#define FLOAT 0
#define PULL_UP 1

#define DDRA  		*((volatile u8*)0x3A)
#define PORTA		*((volatile u8*)0x3B)
#define PINA		*((volatile u8*)0x39)

#define DDRB  		*((volatile u8*)0x37)
#define PORTB		*((volatile u8*)0x38)
#define PINB		*((volatile u8*)0x36)

#define DDRC  		*((volatile u8*)0x34)
#define PORTC		*((volatile u8*)0x35)
#define PINC		*((volatile u8*)0x33)

#define DDRD  		*((volatile u8*)0x31)
#define PORTD		*((volatile u8*)0x32)
#define PIND		*((volatile u8*)0x30)

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)			CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

#endif /* DIO_PRIVATE_H_ */
