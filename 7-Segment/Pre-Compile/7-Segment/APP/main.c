/*
 * main.c
 *
 *  Created on: Mar 26, 2022
 *      Author: Ahmed Maged
 */
#include "../LIB/errorState.h"
#include "../LIB/stdTypes.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/7-Segment/7-Seg_Interface.h"

#include <util/delay.h>
int main(void)
{
	ES_T error;
	DIO_enuInit();
	error=Seven_Segment_enuInit();

	while (1)
	{
		if(error == ES_OK)
		{

			for (u8 i=0; i<10 ; i++)
			{
				Seven_Segment_enuDisplayNum(i);
				_delay_ms(500);
			}
		}

	}
	return 0;


	return 0;
}
