/*
 * main.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */

#include "../LIB/errorState.h"
#include "../LIB/stdTypes.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/7-SegmentL/7-Seg_Config.h"
#include "../HAL/7-SegmentL/7-Seg_Interface.h"

#include <util/delay.h>

extern SEG_T SEVSEG_AstrSegConfig [SEVEN_SEG_NUM];


int main(void)
{
	DIO_enuInit();
	Seven_Segment_enuInit(SEVSEG_AstrSegConfig);

	while (1)
	{
		for(u8 i=0; i<10 ; i++)
		{
			Seven_Segment_enuDisplayNum(0,i);
			Seven_Segment_enuDisplayNum(1, 0);
			for (u8 j=0; j<10; j++)
			{
				Seven_Segment_enuDisplayNum(1, j);
				_delay_ms(300);
			}
		}
	}
	return 0;
}
