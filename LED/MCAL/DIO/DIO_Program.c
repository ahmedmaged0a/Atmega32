/*
 * previliges.c

 *
 *  Created on: Sep 9, 2021.
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "DIO_config.h"
#include "DIO_private.h"

ES_T DIO_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;

	DDRA = CONC(DIO_U8PA_PIN7_DIR,DIO_U8PA_PIN6_DIR,DIO_U8PA_PIN5_DIR,DIO_U8PA_PIN4_DIR,DIO_U8PA_PIN3_DIR,DIO_U8PA_PIN2_DIR,DIO_U8PA_PIN1_DIR,DIO_U8PA_PIN0_DIR);
	DDRB = CONC(DIO_U8PB_PIN7_DIR,DIO_U8PB_PIN6_DIR,DIO_U8PB_PIN5_DIR,DIO_U8PB_PIN4_DIR,DIO_U8PB_PIN3_DIR,DIO_U8PB_PIN2_DIR,DIO_U8PB_PIN1_DIR,DIO_U8PB_PIN0_DIR);
	DDRC = CONC(DIO_U8PC_PIN7_DIR,DIO_U8PC_PIN6_DIR,DIO_U8PC_PIN5_DIR,DIO_U8PC_PIN4_DIR,DIO_U8PC_PIN3_DIR,DIO_U8PC_PIN2_DIR,DIO_U8PC_PIN1_DIR,DIO_U8PC_PIN0_DIR);
	DDRD = CONC(DIO_U8PD_PIN7_DIR,DIO_U8PD_PIN6_DIR,DIO_U8PD_PIN5_DIR,DIO_U8PD_PIN4_DIR,DIO_U8PD_PIN3_DIR,DIO_U8PD_PIN2_DIR,DIO_U8PD_PIN1_DIR,DIO_U8PD_PIN0_DIR);

	PORTA = CONC(DIO_U8PA_PIN7_VAL,DIO_U8PA_PIN6_VAL,DIO_U8PA_PIN5_VAL,DIO_U8PA_PIN4_VAL,DIO_U8PA_PIN3_VAL,DIO_U8PA_PIN2_VAL,DIO_U8PA_PIN1_VAL,DIO_U8PA_PIN0_VAL);
	PORTB = CONC(DIO_U8PB_PIN7_VAL,DIO_U8PB_PIN6_VAL,DIO_U8PB_PIN5_VAL,DIO_U8PB_PIN4_VAL,DIO_U8PB_PIN3_VAL,DIO_U8PB_PIN2_VAL,DIO_U8PB_PIN1_VAL,DIO_U8PB_PIN0_VAL);
	PORTC = CONC(DIO_U8PC_PIN7_VAL,DIO_U8PC_PIN6_VAL,DIO_U8PC_PIN5_VAL,DIO_U8PC_PIN4_VAL,DIO_U8PC_PIN3_VAL,DIO_U8PC_PIN2_VAL,DIO_U8PC_PIN1_VAL,DIO_U8PC_PIN0_VAL);
	PORTD = CONC(DIO_U8PD_PIN7_VAL,DIO_U8PD_PIN6_VAL,DIO_U8PD_PIN5_VAL,DIO_U8PD_PIN4_VAL,DIO_U8PD_PIN3_VAL,DIO_U8PD_PIN2_VAL,DIO_U8PD_PIN1_VAL,DIO_U8PD_PIN0_VAL);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_T DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_U8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8PORTA:
			DDRA = Copy_u8Value;
			break;
		case DIO_U8PORTB:
			DDRB = Copy_u8Value;
			break;
		case DIO_U8PORTC:
			DDRC = Copy_u8Value;
			break;
		case DIO_U8PORTD:
			DDRD = Copy_u8Value;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}

ES_T DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_U8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8PORTA:
			PORTA = Copy_u8Value;
			break;
		case DIO_U8PORTB:
			PORTB = Copy_u8Value;
			break;
		case DIO_U8PORTC:
			PORTC = Copy_u8Value;
			break;
		case DIO_U8PORTD:
			PORTD = Copy_u8Value;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}

ES_T DIO_enuTogglePortValue(u8 Copy_u8PortID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_U8PORTD)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8PORTA:
			PORTA = ~PORTA;
			break;
		case DIO_U8PORTB:
			PORTB = ~PORTB;
			break;
		case DIO_U8PORTC:
			PORTC = ~PORTC;
			break;
		case DIO_U8PORTD:
			PORTD = ~PORTD;
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}

ES_T DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_Pu8Value)
{
	ES_T Local_enuErrorState = ES_NOK;

	if(Copy_Pu8Value != NULL)
	{
		if(Copy_u8PortID <= DIO_U8PORTD)
		{
			switch(Copy_u8PortID)
			{
			case DIO_U8PORTA:
				*Copy_Pu8Value = PINA;
				break;
			case DIO_U8PORTB:
				*Copy_Pu8Value = PINB;
				break;
			case DIO_U8PORTC:
				*Copy_Pu8Value = PINC;
				break;
			case DIO_U8PORTD:
				*Copy_Pu8Value = PIND;
				break;
			}
			Local_enuErrorState = ES_OK;
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
ES_T DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8PortID <= DIO_U8PORTD &&
			Copy_u8PinID <= DIO_U8PIN7 &&
			Copy_u8Value <= OUTPUT)
	{
		switch(Copy_u8PortID)
		{
		case DIO_U8PORTA:
			DDRA &= ~(DIO_U8MASKINGBIT << Copy_u8PinID);
			DDRA |= (Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_U8PORTB:
			DDRB &= ~(DIO_U8MASKINGBIT << Copy_u8PinID);
			DDRB |= (Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_U8PORTC:
			DDRC &= ~(DIO_U8MASKINGBIT << Copy_u8PinID);
			DDRC |= (Copy_u8Value<<Copy_u8PinID);
			break;
		case DIO_U8PORTD:
			DDRD &= ~(DIO_U8MASKINGBIT << Copy_u8PinID);
			DDRD |= (Copy_u8Value<<Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}
ES_T DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value)
{
	ES_T Local_enuErrorstate = ES_NOK;

	if (Copy_u8PortID <= DIO_U8PORTD &&
			Copy_u8PinID <= DIO_U8PIN7 &&
			Copy_u8Value <= OUTPUT)
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8PORTA:
			PORTA &= ~(DIO_U8MASKINGBIT<<Copy_u8PinID);
			PORTA |=  (Copy_u8Value << Copy_u8PinID);
			break;
		case DIO_U8PORTB:
			PORTB &= ~(DIO_U8MASKINGBIT<<Copy_u8PinID);
			PORTB |=  (Copy_u8Value << Copy_u8PinID);
			break;
		case DIO_U8PORTC:
			PORTC &= ~(DIO_U8MASKINGBIT<<Copy_u8PinID);
			PORTC |=  (Copy_u8Value << Copy_u8PinID);
			break;
		case DIO_U8PORTD:
			PORTD &= ~(DIO_U8MASKINGBIT<<Copy_u8PinID);
			PORTD |=  (Copy_u8Value << Copy_u8PinID);
			break;
		}
		Local_enuErrorstate = ES_OK;
	}
	else
	{
		Local_enuErrorstate = ES_OUTOFRANGE;
	}

	return Local_enuErrorstate;
}
ES_T DIO_enuToggelPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if (Copy_u8PortID <= DIO_U8PORTD &&
			Copy_u8PinID <= DIO_U8PIN7)
	{
		switch (Copy_u8PortID)
		{
		case DIO_U8PORTA:
			PORTA ^= (DIO_U8MASKINGBIT<<Copy_u8PinID);
			break;
		case DIO_U8PORTB:
			PORTB ^= (DIO_U8MASKINGBIT<<Copy_u8PinID);
			break;
		case DIO_U8PORTC:
			PORTC ^= (DIO_U8MASKINGBIT<<Copy_u8PinID);
			break;
		case DIO_U8PORTD:
			PORTD ^= (DIO_U8MASKINGBIT<<Copy_u8PinID);
			break;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}
ES_T DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 * Copy_Pu8Value)
{
	ES_T Local_enuErrorState = ES_NOK;
	if (Copy_Pu8Value != NULL)
	{
		if (Copy_u8PortID <= DIO_U8PORTD &&
				Copy_u8PinID <= DIO_U8PIN7)
		{
			switch (Copy_u8PortID)
			{
			case DIO_U8PORTA:
				*Copy_Pu8Value = ((PINA>>Copy_u8PinID) &DIO_U8MASKINGBIT);
				break;
			case DIO_U8PORTB:
				*Copy_Pu8Value = ((PINB>>Copy_u8PinID) &DIO_U8MASKINGBIT);
				break;
			case DIO_U8PORTC:
				*Copy_Pu8Value = ((PINC>>Copy_u8PinID) &DIO_U8MASKINGBIT);
				break;
			case DIO_U8PORTD:
				*Copy_Pu8Value = ((PIND>>Copy_u8PinID) &DIO_U8MASKINGBIT);
				break;
			}
			Local_enuErrorState = ES_OK;
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

