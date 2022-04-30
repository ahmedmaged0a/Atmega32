/*
 * SW_Previliges.c
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "Switch_Private.h"
#include "Switch_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

ES_T SW_enuInit(SW_T * Copy_PstrSwState)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_PstrSwState != NULL)
	{
		u8 Local_u8Iterator = 0;
		for(Local_u8Iterator = 0 ; Local_u8Iterator < SW_NUM ; Local_u8Iterator++)
		{
			Local_enuErrorState = DIO_enuSetPinDirection(Copy_PstrSwState[Local_u8Iterator].SW_PortID ,Copy_PstrSwState[Local_u8Iterator].SW_PinID,DIO_u8INPUT);
			Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrSwState[Local_u8Iterator].SW_PortID ,Copy_PstrSwState[Local_u8Iterator].SW_PinID,Copy_PstrSwState[Local_u8Iterator].SW_Status);

		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_T SW_enuGetState(SW_T * Copy_PstrSwState , u8 * Copy_Pu8SwState)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_PstrSwState != NULL && Copy_Pu8SwState != NULL)
	{
			Local_enuErrorState = DIO_enuGetPinValue(Copy_PstrSwState->SW_PortID ,Copy_PstrSwState->SW_PinID , Copy_Pu8SwState);
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
