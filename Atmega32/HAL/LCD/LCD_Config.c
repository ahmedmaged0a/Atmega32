/*
 * LCD_Config.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */
#include "../../LIB/errorState.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_Config.h"
#include "LCD_Private.h"

LCD_T  LCD_AstrLCDConfig [LCD_NUM] =
{
		{
				    /* Control Pins */
				DIO_u8PORTA , DIO_u8PIN0,
				DIO_u8PORTA , DIO_u8PIN1,
				DIO_u8PORTA , DIO_u8PIN2,

				   /* Data Pins */
				DIO_u8PORTB , DIO_u8PIN0,
				DIO_u8PORTB , DIO_u8PIN1,
				DIO_u8PORTB , DIO_u8PIN2,
				DIO_u8PORTB , DIO_u8PIN3,
				DIO_u8PORTB , DIO_u8PIN4,
				DIO_u8PORTB , DIO_u8PIN5,
				DIO_u8PORTB , DIO_u8PIN6,
				DIO_u8PORTB , DIO_u8PIN7,

				/*  LCD-Mode*/
				EIGHT_BIT
		}//First LCD


};
