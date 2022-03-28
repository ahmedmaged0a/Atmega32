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


ES_T Seven_Segment_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	u32 Local_u32Check = ZERO_U8NUM;

	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8APORT , SEVEN_SEG_U8APIN , DIO_u8OUTPUT)<<ZERO_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8BPORT , SEVEN_SEG_U8BPIN , DIO_u8OUTPUT)<<TWO_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8CPORT , SEVEN_SEG_U8CPIN , DIO_u8OUTPUT)<<FOUR_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8DPORT , SEVEN_SEG_U8DPIN , DIO_u8OUTPUT)<<SIX_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8EPORT , SEVEN_SEG_U8EPIN , DIO_u8OUTPUT)<<EIGHT_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8FPORT , SEVEN_SEG_U8FPIN , DIO_u8OUTPUT)<<TEN_U8LSH);
	Local_u32Check |= (DIO_enuSetPinDirection(SEVEN_SEG_U8GPORT , SEVEN_SEG_U8GPIN , DIO_u8OUTPUT)<<TWIELVE_U8LSH);
	Local_enuErrorState = ES_OK;
#if SEVEN_SEG_COM_PIN < DIO_u8PIN7 && SEVEN_SEG_COM_PORT < DIO_u8PORTD
	Local_enuErrorState = ES_OK;
#elif SEVEN_SEG_COM_PIN == NOT_CONNECTED || SEVEN_SEG_COM_PORT == NOT_CONNECTED

#else
#error "COMMON PIN HAS ERROR SELECTION"
#endif

#if SEVEN_SEG_DOT_PIN < DIO_u8PIN7 && SEVEN_SEG_DOT_PORT < DIO_u8PORTD
	DIO_enuSetPinDirection(SEVEN_SEG_DOT_PORT,SEVEN_SEG_DOT_PIN,DIO_u8OUTPUT);
#elif SEVEN_SEG_DOT_PIN == NOT_CONNECTED || SEVEN_SEG_DOT_PORT == NOT_CONNECTED

#else
#error "DOT PIN HAS ERROR SELECTION"
#endif

	return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisplayNum(u8 Copy_u8Num)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8Num <= SEVEN_SEG_U8MAXRANGE)
	{

#if SEVEN_SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinValue(SEVEN_SEG_U8APORT , SEVEN_SEG_U8APIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>ZERO_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8BPORT , SEVEN_SEG_U8BPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>ONE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8CPORT , SEVEN_SEG_U8CPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>TWO_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8DPORT , SEVEN_SEG_U8DPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>THREE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8EPORT , SEVEN_SEG_U8EPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>FOUR_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8FPORT , SEVEN_SEG_U8FPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>FIVE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8GPORT , SEVEN_SEG_U8GPIN , ((SEG_Au8NumDisplay[Copy_u8Num]>>SIX_U8RSH)&BIT_U8MASKING));
		Local_enuErrorState = ES_OK;

#elif SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinValue(SEVEN_SEG_U8APORT , SEVEN_SEG_U8APIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>ZERO_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8BPORT , SEVEN_SEG_U8BPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>ONE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8CPORT , SEVEN_SEG_U8CPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>TWO_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8DPORT , SEVEN_SEG_U8DPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>THREE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8EPORT , SEVEN_SEG_U8EPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>FOUR_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8FPORT , SEVEN_SEG_U8FPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>FIVE_U8RSH)&BIT_U8MASKING));
		DIO_enuSetPinValue(SEVEN_SEG_U8GPORT , SEVEN_SEG_U8GPIN , !((SEG_Au8NumDisplay[Copy_u8Num]>>SIX_U8RSH)&BIT_U8MASKING));
		Local_enuErrorState = ES_OK;
#else
#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
#endif

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;

}

ES_T Seven_Segment_enuEnableCommon(void)
{
	ES_T Local_enuErrorState = ES_NOK;
#if SEVEN_SEG_COM_PIN < DIO_u8PIN7 && SEVEN_SEG_COM_PORT < DIO_u8PORTD
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinDirection(SEVEN_SEG_COM_PORT,SEVEN_SEG_COM_PIN,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinDirection(SEVEN_SEG_COM_PORT,SEVEN_SEG_COM_PIN,DIO_u8HIGH);
		Local_enuErrorState = ES_OK;
	#else
	#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
	#endif
#elif SEVEN_SEG_COM_PIN == NOT_CONNECTED || SEVEN_SEG_COM_PORT == NOT_CONNECTED

#else
#error "COMMON PIN HAS ERROR SELECTION"
#endif
		return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableCommon(void)
{
	ES_T Local_enuErrorState = ES_NOK;
#if SEVEN_SEG_COM_PIN < DIO_u8PIN7 && SEVEN_SEG_COM_PORT < DIO_u8PORTD
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinDirection(SEVEN_SEG_COM_PORT,SEVEN_SEG_COM_PIN,DIO_u8HIGH);
		Local_enuErrorState = ES_OK;
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinDirection(SEVEN_SEG_COM_PORT,SEVEN_SEG_COM_PIN,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	#else
	#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
	#endif
#elif SEVEN_SEG_COM_PIN == NOT_CONNECTED || SEVEN_SEG_COM_PORT == NOT_CONNECTED

#else
#error "COMMON PIN HAS ERROR SELECTION"
#endif
		return Local_enuErrorState;

}

ES_T Seven_Segment_enuEnableDot(void)
{
	ES_T Local_enuErrorState = ES_NOK;
#if SEVEN_SEG_DOT_PIN < DIO_u8PIN7 && SEVEN_SEG_DOT_PORT < DIO_u8PORTD
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinDirection(SEVEN_SEG_DOT_PORT,SEVEN_SEG_DOT_PIN,DIO_u8HIGH);
		Local_enuErrorState = ES_OK;
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinDirection(SEVEN_SEG_DOT_PORT,SEVEN_SEG_DOT_PIN,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	#else
	#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
	#endif
#elif SEVEN_SEG_DOT_PIN == NOT_CONNECTED || SEVEN_SEG_DOT_PORT == NOT_CONNECTED

#else
#error "DOT PIN HAS ERROR SELECTION"
#endif

	return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableDot(void)
{
	ES_T Local_enuErrorState = ES_NOK;
#if SEVEN_SEG_DOT_PIN < DIO_u8PIN7 && SEVEN_SEG_DOT_PORT < DIO_u8PORTD
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
		DIO_enuSetPinDirection(SEVEN_SEG_DOT_PORT,SEVEN_SEG_DOT_PIN,DIO_u8LOW);
		Local_enuErrorState = ES_OK;
	#elif SEVEN_SEG_TYPE == COMMON_ANODE
		DIO_enuSetPinDirection(SEVEN_SEG_DOT_PORT,SEVEN_SEG_DOT_PIN,DIO_u8HIGH);
		Local_enuErrorState = ES_OK;
	#else
	#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
	#endif
#elif SEVEN_SEG_DOT_PIN == NOT_CONNECTED || SEVEN_SEG_DOT_PORT == NOT_CONNECTED

#else
#error "DOT PIN HAS ERROR SELECTION"
#endif

	return Local_enuErrorState;

}

ES_T Seven_Segment_enuClearDisplay(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	#if SEVEN_SEG_TYPE == COMMON_CATHODE
			DIO_enuSetPinValue(SEVEN_SEG_U8APORT , SEVEN_SEG_U8APIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8BPORT , SEVEN_SEG_U8BPIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8CPORT , SEVEN_SEG_U8CPIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8DPORT , SEVEN_SEG_U8DPIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8EPORT , SEVEN_SEG_U8EPIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8FPORT , SEVEN_SEG_U8FPIN , DIO_u8LOW);
			DIO_enuSetPinValue(SEVEN_SEG_U8GPORT , SEVEN_SEG_U8GPIN , DIO_u8LOW);
			Local_enuErrorState = ES_OK;

	#elif SEVEN_SEG_TYPE == COMMON_ANODE
			DIO_enuSetPinValue(SEVEN_SEG_U8APORT , SEVEN_SEG_U8APIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8BPORT , SEVEN_SEG_U8BPIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8CPORT , SEVEN_SEG_U8CPIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8DPORT , SEVEN_SEG_U8DPIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8EPORT , SEVEN_SEG_U8EPIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8FPORT , SEVEN_SEG_U8FPIN , DIO_u8HIGH);
			DIO_enuSetPinValue(SEVEN_SEG_U8GPORT , SEVEN_SEG_U8GPIN , DIO_u8HIGH);
			Local_enuErrorState = ES_OK;

	#else
	#error "SEVEN-SEGMENT TYPE HAS WRONG SELECTION!!"
	#endif

		return Local_enuErrorState;

}
