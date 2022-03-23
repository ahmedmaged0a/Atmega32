/*
 * LED_Priviliges.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "LED_Config.h"
#include "LED_Private.h"

#include "../../MCAL/DIO/DIO_interface.h"

ES_T LED_enuInit(LED_T *Copy_AstrLedConfig)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_AstrLedConfig != NULL)
	{
		u8 Local_u8Iterator=0;
		for(Local_u8Iterator=0 ; Local_u8Iterator < LED_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8OUTPUT);
			if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8Connection == LED_U8SINK)
			{
				if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_U8ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8LOW);
				}
				else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_U8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8HIGH);
				}
				else
				{
					Local_enuErrorState = ES_OUTOFRANGE;
				}
			}
			else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8Connection == LED_U8SOURCE)
			{
				if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_U8ON)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8HIGH);
				}
				else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_U8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,DIO_u8LOW);
				}
				else
				{
					Local_enuErrorState = ES_OUTOFRANGE;
				}
			}
			else
			{
				Local_enuErrorState = ES_OUTOFRANGE;
			}

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_T LED_enuTurnOn(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_AstrLedConfig != NULL)
	{
		if(Copy_u8LedNum < LED_NUM)
		{
			if(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == LED_U8SINK)
			{
				Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,DIO_u8LOW);
			}
			else if (Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == LED_U8SOURCE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,DIO_u8HIGH);
			}
			else
			{
				Local_enuErrorState = ES_OUTOFRANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUTOFRANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_T LED_enuTurnOff(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_AstrLedConfig != NULL)
	{
		if(Copy_u8LedNum < LED_NUM)
		{
			if(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == LED_U8SINK)
			{
				Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,DIO_u8HIGH);
			}
			else if (Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == LED_U8SOURCE)
			{
				Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,DIO_u8LOW);
			}
			else
			{
				Local_enuErrorState = ES_OUTOFRANGE;
			}
		}
		else
		{
			Local_enuErrorState = ES_OUTOFRANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}

ES_T LED_enuGetState(LED_T *Copy_AstrLedConfig ,u8 Copy_u8LedNum, u8 *Copy_u8LedState)
{
	ES_T Local_enuErrorState = ES_NOK;
    if(Copy_AstrLedConfig != NULL && Copy_u8LedState != NULL)
    {
    	if(Copy_u8LedNum < LED_NUM)
    	{
    	Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,Copy_u8LedState);
    	}
    	else
    	{
    		Local_enuErrorState = ES_OUTOFRANGE;
    	}
    }
    else
    {
    	Local_enuErrorState = ES_NULL_POINTER;
    }
	return Local_enuErrorState;
}

