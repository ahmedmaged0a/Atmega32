/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/SPI/SPI_Config.h"
#include "../MCAL/SPI/SPI_Interface.h"

#include <util/delay.h>

int main(void)
{
	u8 Local_u8DataExchange=0;
	DIO_enuInit();
	SPI_enuInitMaster();
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8OUTPUT);


    DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN4,DIO_u8INPUT);
    DIO_enuSetPinValue(DIO_u8PORTB,DIO_u8PIN4,DIO_u8PULLUP);

	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN5,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN6,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8OUTPUT);


	while(1)
	{

		SPI_enuTransceive(4,&Local_u8DataExchange);
		_delay_ms(10);
	}

	return 0;
}
