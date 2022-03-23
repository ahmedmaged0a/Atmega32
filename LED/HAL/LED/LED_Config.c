/*
 * LED_Config.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "LED_Config.h"
#include "LED_Private.h"

#include "../../MCAL/DIO/DIO_interface.h"

LED_T LED_AstrLedConfig[LED_NUM] =
{
		{DIO_u8PORTA ,DIO_u8PIN5,LED_U8SOURCE , LED_U8OFF },
		{DIO_u8PORTB ,DIO_u8PIN0,LED_U8SOURCE , LED_U8OFF },
		{DIO_u8PORTA ,DIO_u8PIN4,LED_U8SINK , LED_U8OFF }
};

