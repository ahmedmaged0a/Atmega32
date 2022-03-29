/*
 * interface.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PORTA 0
#define DIO_u8PORTB 1
#define DIO_u8PORTC 2
#define DIO_u8PORTD 3

#define DIO_u8PIN0 0
#define DIO_u8PIN1 1
#define DIO_u8PIN2 2
#define DIO_u8PIN3 3
#define DIO_u8PIN4 4
#define DIO_u8PIN5 5
#define DIO_u8PIN6 6
#define DIO_u8PIN7 7

#define DIO_u8INPUT 0
#define DIO_u8OUTPUT 1

#define DIO_u8LOW 0
#define DIO_u8HIGH 1

#define DIO_u8FLOAT 0
#define DIO_u8PULLUP 1

	ES_T DIO_enuInit(void);

	ES_T DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value);

	ES_T DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value);

	ES_T DIO_enuTogglePortValue(u8 Copy_u8PortID);

	ES_T DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_Pu8Value);

	ES_T DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

	ES_T DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

	ES_T DIO_enuToggelPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

	ES_T DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 * Copy_Pu8Value);

#endif /* DIO_INTERFACE_H_ */
