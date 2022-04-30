/*
 * 7-Seg_Config.h
 *
 *  Created on: Mar 26, 2022
 *      Author:  Ahmed Maged
 */

#ifndef HAL_7_SEG_CONFIG_H_
#define HAL_7_SEG_CONFIG_H_

#define SEVEN_SEG_NUM    2

typedef struct
{
	u8 SEG_u8APort;
	u8 SEG_u8APin;

	u8 SEG_u8BPort;
	u8 SEG_u8BPin;

	u8 SEG_u8CPort;
	u8 SEG_u8CPin;

	u8 SEG_u8DPort;
	u8 SEG_u8DPin;

	u8 SEG_u8EPort;
	u8 SEG_u8EPin;

	u8 SEG_u8FPort;
	u8 SEG_u8FPin;

	u8 SEG_u8GPort;
	u8 SEG_u8GPin;

	u8 SEG_u8CMN_Port;
	u8 SEG_u8CMN_Pin;

	u8 SEG_u8DOT_Port;
	u8 SEG_u8DOT_Pin;

	u8 SEG_u8Type;


}SEG_T;

#endif /* HAL_7_SEG_CONFIG_H_ */
