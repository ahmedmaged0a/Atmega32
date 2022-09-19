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

#include "../MCAL/ADC/ADC_Interface.h"

#include <util/delay.h>

extern EXTI_T EXTI_AstrEXTIconfig [3];

void read(void *p)
{
	ADC_enuRead((u16*)p);
}
int main(void)
{
	u16 Local_u16ADCread = 0;

	DIO_enuInit();
	DIO_enuSetPortDirection(DIO_u8PORTC,0xff);
	DIO_enuSetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PORTD,DIO_u8PIN2,DIO_u8INPUT);

	EXTI_enuInit(EXTI_AstrEXTIconfig);
	EXTI_enuSetSenceControl(INT_0,FALLING_EDGE);
	EXTI_enuEnableINT(INT_0);

	ADC_enuInit();
	ADC_enuSelectChannel(ADC_0);
	ADC_enuEnableTriggeringMode(ADC_u8EXT0_INTERRUPT);
	ADC_enuEnableInterruptMode();

	//u8 Local_u8ADCread = 0;
	ADC_enuCallBack(read,&Local_u16ADCread);
	ADC_enuStartConversion();

	GIE_enuEnable();
	while(1)
	{
		DIO_enuSetPortValue(DIO_u8PORTC,Local_u16ADCread);
	}

	return 0;
}
