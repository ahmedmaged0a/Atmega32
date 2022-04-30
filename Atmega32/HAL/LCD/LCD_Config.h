/*
 * LCD_Config.h
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_NUM 1

typedef struct {

/*Control Pin -->*/
	u8 LCD_u8RSPort;
	u8 LCD_u8RSPin;

	u8 LCD_u8RWPort;
	u8 LCD_u8RWPin;

	u8 LCD_u8ENPort;
	u8 LCD_u8ENPin;

/*Data Pin -->*/
	u8 LCD_u8D7Port;
	u8 LCD_u8D7Pin;

	u8 LCD_u8D6Port;
	u8 LCD_u8D6Pin;

	u8 LCD_u8D5Port;
	u8 LCD_u8D5Pin;

	u8 LCD_u8D4Port;
	u8 LCD_u8D4Pin;

	u8 LCD_u8D3Port;
	u8 LCD_u8D3Pin;

	u8 LCD_u8D2Port;
	u8 LCD_u8D2Pin;

	u8 LCD_u8D1Port;
	u8 LCD_u8D1Pin;

	u8 LCD_u8D0Port;
	u8 LCD_u8D0Pin;

	u8 LCD_u8LCDMode;
}LCD_T;

#endif /* HAL_LCD_LCD_CONFIG_H_ */
