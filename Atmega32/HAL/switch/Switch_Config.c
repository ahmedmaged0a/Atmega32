/*
 * Switch_Config.c

 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "Switch_Private.h"
#include "Switch_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

SW_T SW_AstrSwState[SW_NUM] =
{
		{DIO_u8PORTA , DIO_u8PIN4 ,DIO_u8FLOAT},
		{DIO_u8PORTD , DIO_u8PIN3 ,DIO_u8PULLUP},
		{DIO_u8PORTC , DIO_u8PIN5 ,DIO_u8FLOAT}
};


