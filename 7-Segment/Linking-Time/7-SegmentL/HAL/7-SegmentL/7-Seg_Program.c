/*
 * 7-Seg_Program.c
 *
 *  Created on: Mar 26, 2022
 *      Author:  Ahmed Maged
 */
#include "../../LIB/errorState.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "7-Seg_Config.h"
#include "7-Seg_Private.h"

extern SEG_T SEVSEG_AstrSegConfig [SEVEN_SEG_NUM];

ES_T Seven_Segment_enuInit(SEG_T *Copy_PstrSegConfig)
{
	ES_T Local_enuErrorState = ES_NOK;

	u8 Local_u8Iter =0;
	if(Copy_PstrSegConfig != NULL)
	{
		for (Local_u8Iter=0; Local_u8Iter < SEVEN_SEG_NUM; Local_u8Iter++)
		{
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8APort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8APin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8BPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8BPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8CPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8CPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8DPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8DPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8EPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8EPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8FPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8FPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8GPort,Copy_PstrSegConfig[Local_u8Iter].SEG_u8GPin, DIO_u8OUTPUT);

			if (Copy_PstrSegConfig[Local_u8Iter].SEG_u8CMN_Port != NOT_CONNECTED &&
					Copy_PstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin != NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8CMN_Port ,Copy_PstrSegConfig[Local_u8Iter].SEG_u8CMN_Pin , DIO_u8OUTPUT );
			}

			if (Copy_PstrSegConfig[Local_u8Iter].SEG_u8DOT_Port != NOT_CONNECTED &&
					Copy_PstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin != NOT_CONNECTED)
			{
				DIO_enuSetPinDirection(Copy_PstrSegConfig[Local_u8Iter].SEG_u8DOT_Port ,Copy_PstrSegConfig[Local_u8Iter].SEG_u8DOT_Pin , DIO_u8OUTPUT );
			}
		}
	}
	else
	{
		return ES_NULL_POINTER;
	}
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_T Seven_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num)
{
	ES_T Local_enuErrorState = ES_NOK;

	if (Copy_u8Num <=SEVEN_SEG_U8MAXRANGE && Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , ((SEG_Au8NumDisplay[Copy_u8Num]>>ZERO_U8RSH)&BIT_U8MASKING) );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>ONE_U8RSH)&BIT_U8MASKING) );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>TWO_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>THREE_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>FOUR_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>FIVE_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , ((SEG_Au8NumDisplay[Copy_u8Num]>>SIX_U8RSH)&BIT_U8MASKING));
			Local_enuErrorState = ES_OK;

		}
		else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , !((SEG_Au8NumDisplay[Copy_u8Num]>>ZERO_U8RSH)&BIT_U8MASKING) );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>ONE_U8RSH)&BIT_U8MASKING) );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>TWO_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>THREE_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>FOUR_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>FIVE_U8RSH)&BIT_U8MASKING));
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , !((SEG_Au8NumDisplay[Copy_u8Num]>>SIX_U8RSH)&BIT_U8MASKING));
			Local_enuErrorState = ES_OK;

		}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}
ES_T Seven_Segment_enuEnableCommon(u8 Copy_u8SegID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED
				&& SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{

				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin ,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin ,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_7SEG_ERROR;
			}
		}
		else
		{
			Local_enuErrorState = ES_7SEG_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableCommon(u8 Copy_u8SegID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port != NOT_CONNECTED
				&& SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{

				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin ,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CMN_Pin ,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_7SEG_ERROR;
			}
		}
		else
		{
			Local_enuErrorState = ES_7SEG_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;

}

ES_T Seven_Segment_enuEnableDot(u8 Copy_u8SegID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED
				&& SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{

				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin ,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin ,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_7SEG_ERROR;
			}
		}
		else
		{
			Local_enuErrorState = ES_7SEG_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableDot(u8 Copy_u8SegID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port != NOT_CONNECTED
				&& SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin != NOT_CONNECTED)
		{
			if(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
			{

				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin ,DIO_u8LOW);
				Local_enuErrorState = ES_OK;
			}
			else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
			{
				DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Port ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DOT_Pin ,DIO_u8HIGH);
				Local_enuErrorState = ES_OK;
			}
			else
			{
				Local_enuErrorState = ES_7SEG_ERROR;
			}
		}
		else
		{
			Local_enuErrorState = ES_7SEG_ERROR;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;

}

ES_T Seven_Segment_enuClearDisplay(u8 Copy_u8SegID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8SegID < SEVEN_SEG_NUM)
	{
		if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_CATHODE)
		{
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , DIO_u8LOW );
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , DIO_u8LOW );
			Local_enuErrorState = ES_OK;

		}
		else if (SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8Type == COMMON_ANODE)
		{
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8APin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8BPin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8CPin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8DPin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8EPin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8FPin , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPort ,SEVSEG_AstrSegConfig[Copy_u8SegID].SEG_u8GPin , DIO_u8HIGH);
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_7SEG_ERROR;
		}
	}
	else
	{
		Local_enuErrorState =ES_OUTOFRANGE;
	}
	return Local_enuErrorState;

}
