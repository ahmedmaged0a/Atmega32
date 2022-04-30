/*
 * main.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../MCAL/EXTI/EXTI_Config.h"
#include "../MCAL/EXTI/EXTI_Interface.h"


#include "../MCAL/GIE/GIE_Interface.h"

extern EXTI_T EXTI_AstrEXTIconfig[3];

void toggle(void);
int main(void)
{
	DIO_enuInit();
	EXTI_enuInit(EXTI_AstrEXTIconfig);

	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8HIGH);

	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN3,DIO_u8INPUT);
	DIO_enuSetPinValue(DIO_u8PORTD,DIO_u8PIN2,DIO_u8PULLUP);
	EXTI_enuInit(EXTI_AstrEXTIconfig);
	GIE_enuInit();
	EXTI_enuCallBack(toggle,EXTI_INT1);
	while(1);
	return 0;
}
void toggle(void)
{
	DIO_enuToggelPinValue(DIO_u8PORTA,DIO_u8PIN2);
}
