/*
 * EXTI_Program.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */


#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"

#include "../Interrupt.h"

static volatile  void (*EXTI_ApfunINTFun[3])(void) = {NULL,NULL,NULL};

ES_T EXTI_enuInit(EXTI_T * Copy_PstrEXTIconfig)
{
	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator = INITIAL_ZERO;
	if(Copy_PstrEXTIconfig != NULL)
	{
		for(Local_u8Iterator = INITIAL_ZERO ; Local_u8Iterator < MAX_INT_ID ;Local_u8Iterator++)
		{
			if(Copy_PstrEXTIconfig[Local_u8Iterator].EXTI_u8Istate == INT_ACTIVE)
			{
				switch(Local_u8Iterator)
				{
				case INT_0:
					GICR |= (BIT_MASKING << GICR_BIT6);
					MCUCR &= ~ (CLEAR_TWO_BIT<<BIT_0);
					switch(Copy_PstrEXTIconfig[Local_u8Iterator].EXTI_u8SenceControl)
					{
					case FALLING_EDGE:
						MCUCR |= ( INT0_SET_FALLING<< BIT_0);
						Local_enuErrorState = ES_OK;
						break;
					case RISING_EDGE:
						MCUCR |= ( INT0_SET_RISING<< BIT_0);
						Local_enuErrorState = ES_OK;
						break;
					case ON_CHANGE:
						MCUCR |= ( INT0_SET_ON_CHANGE<< BIT_0);
						Local_enuErrorState = ES_OK;
						break;
					case LOW_LEVEL:
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUTOFRANGE;
					}

					break;
					case INT_1:
						GICR |= (BIT_MASKING << GICR_BIT7);
						MCUCR &= ~ (CLEAR_TWO_BIT<<BIT_2);
						switch(Copy_PstrEXTIconfig[Local_u8Iterator].EXTI_u8SenceControl)
						{
						case FALLING_EDGE:
							MCUCR |= ( INT1_SET_FALLING<< BIT_2);
							Local_enuErrorState = ES_OK;
							break;
						case RISING_EDGE:
							MCUCR |= ( INT1_SET_RISING<< BIT_2);
							Local_enuErrorState = ES_OK;
							break;
						case ON_CHANGE:
							MCUCR |= ( INT1_SET_ON_CHANGE<< BIT_2);
							Local_enuErrorState = ES_OK;
							break;
						case LOW_LEVEL:
							Local_enuErrorState = ES_OK;
							break;
						default:
							Local_enuErrorState = ES_OUTOFRANGE;
						}
						break;
						case INT_2:

							GICR |= (BIT_MASKING << GICR_BIT5);
							switch(Copy_PstrEXTIconfig[Local_u8Iterator].EXTI_u8SenceControl)
							{
							case FALLING_EDGE:
								MCUCSR &=~( BIT_MASKING<< BIT_6);
								Local_enuErrorState = ES_OK;
								break;
							case RISING_EDGE:
								MCUCSR |= ( INT2_SET_RISING<< BIT_6);
								Local_enuErrorState = ES_OK;
								break;
							default:
								Local_enuErrorState = ES_OUTOFRANGE;
							}
							break;
							default:
								Local_enuErrorState = ES_OUTOFRANGE;
				}
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return  Local_enuErrorState;
}

ES_T EXTI_enuSetSenceControl(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceControl)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTI_ID < MAX_INT_ID)
	{
		switch(Copy_u8EXTI_ID)
		{
		case INT_0:
			MCUCR &= ~ (CLEAR_TWO_BIT<<BIT_0);
			switch(Copy_u8SenceControl)
			{
			case FALLING_EDGE:
				MCUCR |= ( INT0_SET_FALLING<< BIT_0);
				Local_enuErrorState = ES_OK;
				break;
			case RISING_EDGE:
				MCUCR |= ( INT0_SET_RISING<< BIT_0);
				Local_enuErrorState = ES_OK;
				break;
			case ON_CHANGE:
				MCUCR |= ( INT0_SET_ON_CHANGE<< BIT_0);
				Local_enuErrorState = ES_OK;
				break;
			case LOW_LEVEL:
				Local_enuErrorState = ES_OK;
				break;
			default:
				Local_enuErrorState = ES_OUTOFRANGE;
			}
			break;
			case INT_1:
				MCUCR &= ~ (CLEAR_TWO_BIT<<BIT_2);
				switch(Copy_u8SenceControl)
				{
				case FALLING_EDGE:
					MCUCR |= ( INT1_SET_FALLING<< BIT_2);
					Local_enuErrorState = ES_OK;
					break;
				case RISING_EDGE:
					MCUCR |= ( INT1_SET_RISING<< BIT_2);
					Local_enuErrorState = ES_OK;
					break;
				case ON_CHANGE:
					MCUCR |= ( INT1_SET_ON_CHANGE<< BIT_2);
					Local_enuErrorState = ES_OK;
					break;
				case LOW_LEVEL:
					Local_enuErrorState = ES_OK;
					break;
				default:
					Local_enuErrorState = ES_OUTOFRANGE;
				}
				break;
				case INT_2:
					switch(Copy_u8SenceControl)
					{
					case FALLING_EDGE:
						MCUCSR &=~( BIT_MASKING<< BIT_6);
						Local_enuErrorState = ES_OK;
						break;
					case RISING_EDGE:
						MCUCSR |= ( INT2_SET_RISING<< BIT_6);
						Local_enuErrorState = ES_OK;
						break;
					default:
						Local_enuErrorState = ES_OUTOFRANGE;
					}
					break;
					default:
						Local_enuErrorState = ES_OUTOFRANGE;
		}

	}

	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return  Local_enuErrorState;
}

ES_T EXTI_enuEnableINT(u8 Copy_u8EXTI_ID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTI_ID < MAX_INT_ID)
	{
		switch(Copy_u8EXTI_ID)
		{
		case INT_0:
			GICR |= (BIT_MASKING << GICR_BIT6);
			Local_enuErrorState = ES_OK;
			break;
		case INT_1:
			GICR |= (BIT_MASKING << GICR_BIT7);
			Local_enuErrorState = ES_OK;
			break;
		case INT_2:
			GICR |= (BIT_MASKING << GICR_BIT5);
			Local_enuErrorState = ES_OK;
			break;
		default:
			Local_enuErrorState = ES_OUTOFRANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return  Local_enuErrorState;
}

ES_T EXTI_enuDisableINT(u8 Copy_u8EXTI_ID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8EXTI_ID < MAX_INT_ID)
	{
		switch(Copy_u8EXTI_ID)
		{
		case INT_0:
			GICR &=~ (BIT_MASKING << GICR_BIT6);
			Local_enuErrorState = ES_OK;
			break;
		case INT_1:
			GICR &=~ (BIT_MASKING << GICR_BIT7);
			Local_enuErrorState = ES_OK;
			break;
		case INT_2:
			GICR &=~ (BIT_MASKING << GICR_BIT5);
			Local_enuErrorState = ES_OK;
			break;
		default:
			Local_enuErrorState = ES_OUTOFRANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return  Local_enuErrorState;
}
ES_T EXTI_enuCallBack(volatile void(*Copy_Pfun)(void) , u8 Copy_u8EXTI_ID)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_Pfun != NULL)
	{
		if(Copy_u8EXTI_ID < MAX_INT_ID)
		{
			EXTI_ApfunINTFun[Copy_u8EXTI_ID]=Copy_Pfun;
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

	return  Local_enuErrorState;
}
ISR(VECTOR_INT0)
{
	if (EXTI_ApfunINTFun[0] != NULL)
	{
		EXTI_ApfunINTFun[0] ();
	}
}
ISR(VECTOR_INT1)
{
	if (EXTI_ApfunINTFun[1] != NULL)
	{
		EXTI_ApfunINTFun[1] ();
	}
}
ISR(VECTOR_INT2)
{
	if (EXTI_ApfunINTFun[2] != NULL)
	{
		EXTI_ApfunINTFun[2] ();
	}
}
