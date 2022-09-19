/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "ADC_Private.h"
#include "ADC_Config.h"

#include "../Interrupt.h"

static volatile void (*ADC_pFunISRfun)(void *) = NULL;
static volatile void *ADC_pFunISRparam = NULL;


/**================================================================
* @Fn			- ADC_Initialization Func
* @brief 		- Initialize ADC Configuration According to the Configuration file [ADC_Config.h]
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuInit(void)
{
	ADCSRA |= (1<<ADEN);
	ES_T Local_enuErrorState = ES_NOK;
	//prescaler Handling
#if ADC_PRESCALERE == PRE_2
	ADCSRA |=  (1<<ADPS0);
	ADCSRA &=~ (1<<ADPS1);
	ADCSRA &=~ (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_4
	ADCSRA &=~  (1<<ADPS0);
	ADCSRA |=   (1<<ADPS1);
	ADCSRA &=~  (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_8
	ADCSRA |=  (1<<ADPS0);
	ADCSRA |=  (1<<ADPS1);
	ADCSRA &=~ (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_16
	ADCSRA &=~  (1<<ADPS0);
	ADCSRA &=~  (1<<ADPS1);
	ADCSRA |=   (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_32
	ADCSRA |=  (1<<ADPS0);
	ADCSRA &=~ (1<<ADPS1);
	ADCSRA |=  (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_64
	ADCSRA &=~  (1<<ADPS0);
	ADCSRA |=	(1<<ADPS1);
	ADCSRA |=   (1<<ADPS2);
#elif ADC_PRESCALERE == PRE_128
	ADCSRA |=  (1<<ADPS0);
	ADCSRA |= (1<<ADPS1);
	ADCSRA |= (1<<ADPS2);
#else
#error "Error in Prescaler Division Factor !!"
#endif

	//Voltage Reference Handling
#if ADC_U8VOLTAGE_REFRENCE == AREF_INTERNAL_VOFF
	ADMUX &=~(1<<REFS0);
	ADMUX &=~(1<<REFS1);
#elif ADC_U8VOLTAGE_REFRENCE == AVCC
	ADMUX |=  (1<<REFS0);
	ADMUX &=~ (1<<REFS1);
#elif ADC_U8VOLTAGE_REFRENCE == INTERNAL_V
	ADMUX |=  (1<<REFS0);
	ADMUX |=  (1<<REFS1);
#else
#error "Error in Voltage Ref !!"
#endif

	//presentation of the ADC conversion result Handling
#if ADC_WRITEADJUST	 == LEFT_ADJUSTED
	ADMUX |= (1<<ADLAR);
#elif ADC_WRITEADJUST == RIGHT_ADJUSTED
	ADMUX &=~ (1<<ADLAR);
#else
#error "Error in Adjustment !!"
#endif

	return Local_enuErrorState;
}

/**================================================================
* @Fn			- ADC_Start Conversion
* @brief 		- Start Conversion for ADC in [Single mode or Free running mode]
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
* @Note			- In Single Conversion mode, write this bit to one to start each conversion
* 				  In Free Running Mode, write this bit to one to start the first conversion only
*/
ES_T ADC_enuStartConversion(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	ADCSRA |=(1<<ADSC);
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- for polling System
* @brief 		- Only its usage for waiting the flag of ADC and Clear it to start another reading
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuPollingSystem(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	//Waiting flag in ADCSRA REG
	while(1&(ADCSRA>>ADIF) == 0);
	ADCSRA |= (1<<ADIF);

	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_Read High Register
* @brief 		- in LEFT_Adjusted we need only to read HIGH Register
* @param [in] 	- Copy_Pu8Value
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuReadHighReg(u8 * Copy_Pu8Value)
{
	ES_T Local_enuErrorState = ES_NOK;
#if ADC_WRITEADJUST ==  LEFT_ADJUSTED
	*Copy_Pu8Value = ADCH;
	Local_enuErrorState = ES_OK;
#elif ADC_WRITEADJUST ==  RIGHT_ADJUSTED
	*Copy_Pu8Value = (((u16)ADCL >> 2) | (ADCH << 6));
	Local_enuErrorState = ES_OK;
#else
#error "Error in Reading ADC !"
#endif
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_Read
* @brief 		- Which read 10-bits of ADC [ADCL + ADCH]
* @param [in] 	- Copy_Pu16Value
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuRead(u16 * Copy_Pu16Value)
{
	ES_T Local_enuErrorState = ES_NOK;
#if ADC_WRITEADJUST ==  LEFT_ADJUSTED
	*Copy_Pu16Value  = ADCL;
	*Copy_Pu16Value  = (*Copy_Pu16Value>>6) | ((u16)ADCH<<2);
	Local_enuErrorState = ES_OK;
#elif ADC_WRITEADJUST ==  RIGHT_ADJUSTED
	*Copy_Pu16Value  = ADCL;
	*Copy_Pu16Value |= ((u16)ADCH <<8 );
	Local_enuErrorState = ES_OK;
#else
#error "Error in Reading ADC !"
#endif
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuCallBack
* @brief 		- Which read 10-bits of ADC [ADCL + ADCH]
* @param [in] 	- void(*Copy_pAPPfun (void *)) which is global pointer to function
* @param [in] 	- void * Copy_PvidParam which is global pointer to void variable
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuCallBack(void(*Copy_pAPPfun (void *)) , void * Copy_PvidParam)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_pAPPfun != NULL)
	{
		ADC_pFunISRfun   = Copy_pAPPfun;
		ADC_pFunISRparam = Copy_PvidParam;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuEnable
* @brief 		- enable ADC
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuEnable(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	ADCSRA |= (1<<ADEN);
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuEnable
* @brief 		- Disable ADC
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuDisable(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	ADCSRA &= ~ (1<<ADEN);
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuSelectChannel
* @brief 		- Select Channel for your ADC from [0-7]
* @param [in] 	- Copy_u8ChannelID number of channel
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuSelectChannel(u8 Copy_u8ChannelID)
{
	ES_T Local_enuErrorState = ES_NOK;
	//Clear MUX4:0
	ADMUX &=~ 0x1F;
	//Single Ended Mode
	if(ADC_INPUT_SOURCE == SINGLE_ENDED_MODE)
	{
		switch(Copy_u8ChannelID)
		{
		case ADC_0:
			Local_enuErrorState = ES_OK;
			break;
		case ADC_1:
			ADMUX |= (1<<MUX0);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_2:
			ADMUX |= (1<<MUX1);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_3:
			ADMUX |= (1<<MUX0);
			ADMUX |= (1<<MUX1);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_4:
			ADMUX |= (1<<MUX2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_5:
			ADMUX |= (1<<MUX0);
			ADMUX |= (1<<MUX2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_6:
			ADMUX |= (1<<MUX1);
			ADMUX |= (1<<MUX2);
			Local_enuErrorState = ES_OK;
			break;
		case ADC_7:
			ADMUX |= (1<<MUX0);
			ADMUX |= (1<<MUX1);
			ADMUX |= (1<<MUX2);
			Local_enuErrorState = ES_OK;
			break;
		default:
			Local_enuErrorState = ES_NOK;
		}
	}
	//Differential Mode
	else if(ADC_INPUT_SOURCE == DIFFERENTIAL_MODE)
	{

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuEnableTriggeringMode
* @brief 		- enable triggering mode of ADC based of triggering source
* @param [in] 	- Copy_u8TriggeringSource which is trigger source
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource)
{
	ES_T Local_enuErrorState = ES_NOK;
	//Disable Auto Trigger
	ADCSRA &= ~ (1 << ADATE);
	switch(Copy_u8TriggeringSource)
	{
	case FREE_RUNNING_MODE:
		SFIOR &=~ (1<<ADTS0);
		SFIOR &=~ (1<<ADTS1);
		SFIOR &=~ (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case ANALOG_COMPARATOR:
		SFIOR |=  (1<<ADTS0);
		SFIOR &=~ (1<<ADTS1);
		SFIOR &=~ (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case EXT0_INT:
		SFIOR &=~    (1<<ADTS0);
		SFIOR |=     (1<<ADTS1);
		SFIOR &=~    (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case TMR0_CMP:
		SFIOR |=  (1<<ADTS0);
		SFIOR |=   (1<<ADTS1);
		SFIOR &=~  (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case TMR0_OVF:
		SFIOR &=~ (1<<ADTS0);
		SFIOR &=~ (1<<ADTS1);
		SFIOR |=  (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case TMR_CMP_B:
		SFIOR |=  (1<<ADTS0);
		SFIOR &=~ (1<<ADTS1);
		SFIOR |=  (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case TMR1_OVF:
		SFIOR &=~ (1<<ADTS0);
		SFIOR |=  (1<<ADTS1);
		SFIOR |=  (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	case TMR1_CAPTURE:
		SFIOR |=  (1<<ADTS0);
		SFIOR |=  (1<<ADTS1);
		SFIOR |=  (1<<ADTS2);
		Local_enuErrorState = ES_OK;
		break;
	default:
		Local_enuErrorState =ES_NOK;

	}
	ADCSRA |=  (1 << ADATE);

	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuDisableTriggeringMode
* @brief 		- Disable Triggering mode in ADC
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuDisableTriggeringMode(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	//Disable Auto Trigger
	ADCSRA &= ~ (1 << ADATE);
	return Local_enuErrorState;
}
/**================================================================
* @Fn			- ADC_enuEnableInterruptMode
* @brief 		- Enable Interrupt mode in ADC
* @param [in] 	- none
* @retval 		- ErrorState Value Which can be [OK for no error appear ...NOK for errors appear]
*/
ES_T ADC_enuEnableInterruptMode(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	ADCSRA |= (1<<ADIE);
	return Local_enuErrorState;
}

ISR(VECTOR_ADC)
{
	if(ADC_pFunISRfun != NULL)
	{
		ADC_pFunISRfun(ADC_pFunISRparam);
	}
}
