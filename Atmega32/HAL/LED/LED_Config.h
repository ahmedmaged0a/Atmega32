/*
 * LED_Config.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM 3
typedef struct
{
	u8 LED_u8PortID ;
	u8 LED_u8PinID  ;
	u8 LED_u8Connection ;
	u8 LED_u8InitState;
}LED_T;

#endif
