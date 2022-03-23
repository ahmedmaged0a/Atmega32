/*
 * main.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/switch/Switch_Config.h"
#include "../HAL/switch/Switch_Interface.h"

extern SW_T SW_AstrSwState[SW_NUM];
int main(void)
{
	DIO_enuInit();
	SW_enuInit(SW_AstrSwState);
	u8 Local_u8PinState=0;
	while(1)
	{
		SW_enuGetState(&SW_AstrSwState[1] , &Local_u8PinState);
		if(Local_u8PinState == 0)
		{
			DIO_enuSetPinValue(DIO_u8PORTA , DIO_u8PIN5 , DIO_u8HIGH);
		}
		else
			DIO_enuSetPinValue(DIO_u8PORTA , DIO_u8PIN5 , DIO_u8LOW);

	}

}
