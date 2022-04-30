/*
 * LCD_Interface.h
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

ES_T LCD_enuInit(LCD_T *Copy_PsrtLCDConfig);

ES_T LCD_enuDisplayChar(u8 Copy_u8LCDID , u8 Copy_u8Char);

ES_T LCD_enuDisplayString(u8 Copy_u8LCDID , u8 * Copy_u8ptrString);

ES_T LCD_enuDisplayInteger(u8 Copy_u8LCDID , s32 Copy_s32Number);

ES_T LCD_enuSendCommand(u8 Copy_u8LCDID , u8 Copy_u8Command);

ES_T LCD_enuSetPosition(u8 Copy_u8LCDID , u8 Copy_u8Row , u8 Copy_u8Col);

ES_T LCD_enuDisplayFloatNum(u8 Copy_u8LCDID ,f32 Copy_f32Num);

//ES_T LCD_enuDisplayExtraChar(u8 Copy_u8LCDID,u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
