/*
 * LCD_Private.h
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define FOUR_BIT 4
#define EIGHT_BIT 8


static inline void  LCD_invidSendCommand(u8 Copy_u8LCDID , u8 Copy_u8Command);

static void  LCD_invidSendData(u8 Copy_u8LCDID , u8 Copy_u8Data);


#define LCD_u8EightbitCommand  0x38
#define LCD_u8FOURbitCommand   0x28

#define LCD_u8ClearCommand     0x01

#define LCD_u8DislayCommand    0x0f

#define LCD_u8MoveDirection    0x06



#define BIT_MASKING 1

#define BIT_SEVEN 7
#define BIT_SIX   6
#define BIT_FIVE  5
#define BIT_FOUR  4
#define BIT_THREE 3
#define BIT_TWO   2
#define BIT_ONE   1
#define BIT_ZERO  0


#define LCD_u8Row1  1
#define LCD_u8Row2  2

#define LCD_u8Col1   1
#define LCD_u8Col2   2
#define LCD_u8Col3   3
#define LCD_u8Col4   4
#define LCD_u8Col5   5
#define LCD_u8Col6   6
#define LCD_u8Col7   7
#define LCD_u8Col8   8
#define LCD_u8Col9   9
#define LCD_u8Col10  10
#define LCD_u8Col11  11
#define LCD_u8Col12  12
#define LCD_u8Col13  13
#define LCD_u8Col14  14
#define LCD_u8Col15  15
#define LCD_u8Col16  16

#define LCD_u8R1Command 0x80
#define LCD_u8R2Command 0xC0

#define LCD_u8GCRAM 0x40
#define LCD_u8DDRAMDEC 0x04
#endif /* HAL_LCD_LCD_PRIVATE_H_ */
