/*
 * LED_Interface.
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

ES_T LED_enuInit(LED_T *Copy_AstrLedConfig);

ES_T LED_enuTurnOn(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum);

ES_T LED_enuTurnOff(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum);

ES_T LED_enuGetState(LED_T *Copy_AstrLedConfig ,u8 Copy_u8LedNum, u8 *Copy_u8LedState);


#endif /* LED_INTERFACE_H_ */
