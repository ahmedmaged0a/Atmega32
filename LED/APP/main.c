/*
 * main.c
 *
 *  Created on: Sep 11, 2021.
 *      Author: Ahmed Maged
 */
#include "../LIB/stdTypes.h"
#include "../LIB/errorState.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/LED/LED_config.h"
#include "../HAL/LED/LED_Interface.h"

#include <util/delay.h>

extern LED_T LED_AstrLedConfig[LED_NUM];
int main(void)
{
	DIO_enuInit();
	LED_enuInit(LED_AstrLedConfig);
	while(1)
	{
		LED_enuTurnOn(LED_AstrLedConfig , 0);
		_delay_ms(10000);
		LED_enuTurnOff(LED_AstrLedConfig , 0);
		_delay_ms(10000);
	}
}
