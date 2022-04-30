/*
 * 7-Seg_Config.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */
#include "../../LIB/errorState.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "7-Seg_Config.h"
#include "7-Seg_Private.h"

SEG_T SEVSEG_AstrSegConfig [SEVEN_SEG_NUM] =
{
		{DIO_u8PORTA , DIO_u8PIN0 , //pin a
		 DIO_u8PORTA , DIO_u8PIN1 , //pin b
		 DIO_u8PORTA , DIO_u8PIN2 , //pin c
		 DIO_u8PORTA , DIO_u8PIN3 , //pin d
		 DIO_u8PORTA , DIO_u8PIN4 , //pin e
		 DIO_u8PORTA , DIO_u8PIN5 , //pin f
		 DIO_u8PORTA , DIO_u8PIN6 , //pin g
		 NOT_CONNECTED , NOT_CONNECTED , //pin COM
		 NOT_CONNECTED , NOT_CONNECTED , //pin DOT
		 COMMON_CATHODE //type
		} , //First 7-Segment

		{DIO_u8PORTB , DIO_u8PIN0 , //pin a
		 DIO_u8PORTB , DIO_u8PIN1 , //pin b
		 DIO_u8PORTB , DIO_u8PIN2 , //pin c
		 DIO_u8PORTB , DIO_u8PIN3 , //pin d
		 DIO_u8PORTB , DIO_u8PIN4 , //pin e
		 DIO_u8PORTB , DIO_u8PIN5 , //pin f
		 DIO_u8PORTB , DIO_u8PIN6 , //pin g
		 NOT_CONNECTED , NOT_CONNECTED , //pin COM
		 NOT_CONNECTED , NOT_CONNECTED , //pin DOT
		 COMMON_CATHODE //type
		}//Second 7-Segment
};

