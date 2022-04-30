/*
 * LCD_Program.c
 *
 *  Created on: Mar 29, 2022
 *      Author: Ahmed Maged
 */
#include "../../LIB/errorState.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "LCD_Config.h"
#include "LCD_Private.h"

#include "util/delay.h"

extern LCD_T  LCD_AstrLCDConfig [LCD_NUM];

ES_T LCD_enuInit(LCD_T *Copy_PsrtLCDConfig)
{
	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator=0;
	if(Copy_PsrtLCDConfig != NULL)
	{
		for(Local_u8Iterator=0 ; Local_u8Iterator < LCD_NUM;Local_u8Iterator++)
		{
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8RSPort,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8RSPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8RWPort,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8RWPin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8ENPort,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8ENPin, DIO_u8OUTPUT);

			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D7Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D7Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D6Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D6Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D5Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D5Pin, DIO_u8OUTPUT);
			DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D4Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D4Pin, DIO_u8OUTPUT);

			_delay_ms(40);

			if(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8LCDMode==EIGHT_BIT)
			{
				DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D3Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D3Pin, DIO_u8OUTPUT);
				DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D2Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D2Pin, DIO_u8OUTPUT);
				DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D1Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D1Pin, DIO_u8OUTPUT);
				DIO_enuSetPinDirection(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D0Port,Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8D0Pin, DIO_u8OUTPUT);

				LCD_invidSendCommand(Local_u8Iterator,LCD_u8EightbitCommand);
			}
			else if(Copy_PsrtLCDConfig[Local_u8Iterator].LCD_u8LCDMode==FOUR_BIT)
			{
				LCD_invidSendCommand(Local_u8Iterator,LCD_u8FOURbitCommand);
			}
			else
			{
				Local_enuErrorState = ES_OUTOFRANGE;
			}
			_delay_ms(1);
			LCD_invidSendCommand(Local_u8Iterator,LCD_u8ClearCommand);
			_delay_ms(2);
			LCD_invidSendCommand(Local_u8Iterator,LCD_u8MoveDirection);

		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_T LCD_enuDisplayChar(u8 Copy_u8LCDID , u8 Copy_u8Char)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8LCDID <LCD_NUM)
	{
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
		LCD_invidSendData(Copy_u8LCDID,Copy_u8Char);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

ES_T LCD_enuDisplayString(u8 Copy_u8LCDID , u8 * Copy_u8ptrString)
{
	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8Iterator=0;
	if(Copy_u8LCDID <LCD_NUM)
	{
		if(Copy_u8ptrString != NULL)
		{
			while(Copy_u8ptrString[Local_u8Iterator] != '\0')
			{
				LCD_invidSendData(Copy_u8LCDID,Copy_u8ptrString[Local_u8Iterator]);
				Local_u8Iterator++;
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState=ES_NULL_POINTER;
		}

	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

ES_T LCD_enuDisplayInteger(u8 Copy_u8LCDID , s32 Copy_s32Number)
{
	ES_T Local_enuErrorState = ES_NOK;

	s32 Local_s32Reverse=0;
	u8 Local_u8Remainder=0 , Local_u8NumDigit=0;
	DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
	if(Copy_u8LCDID < LCD_NUM)
	{
		if(Copy_s32Number < 0)
		{
			LCD_invidSendData(Copy_u8LCDID,'-');
			Copy_s32Number *= -1 ;
		}
		while(Copy_s32Number)
		{
			Local_u8Remainder = Copy_s32Number % 10;
			Local_s32Reverse = Local_s32Reverse * 10 + Local_u8Remainder;
			Copy_s32Number /=10;
			Local_u8NumDigit ++;
		}
		while(Local_u8NumDigit)
		{
			Local_u8Remainder = Local_s32Reverse % 10;
			LCD_invidSendData(Copy_u8LCDID,Local_u8Remainder + '0');
			Local_s32Reverse /= 10;
			Local_u8NumDigit --;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}


	return Local_enuErrorState;
}

ES_T LCD_enuSendCommand(u8 Copy_u8LCDID , u8 Copy_u8Command)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8LCDID <LCD_NUM)
	{
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8LOW);
		LCD_invidSendCommand(Copy_u8LCDID, Copy_u8Command);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

ES_T LCD_enuSetPosition(u8 Copy_u8LCDID , u8 Copy_u8Row , u8 Copy_u8Col)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8LCDID < LCD_NUM && Copy_u8Row<LCD_u8Row2 && Copy_u8Col < LCD_u8Col16)
	{
		if(Copy_u8Row == LCD_u8Row1)
		{
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8LOW);
			LCD_invidSendCommand(Copy_u8LCDID , ((LCD_u8R1Command)+Copy_u8Col) );
		}
		else if(Copy_u8Row == LCD_u8Row2)
		{
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8LOW);
			LCD_invidSendCommand(Copy_u8LCDID , ((LCD_u8R2Command)+Copy_u8Col) );
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}

	return Local_enuErrorState;
}

/*ES_T LCD_enuDisplayExtraChar(u8 Copy_u8LCDID,u8* Copy_pu8Character,u8 Copy_u8CharNum ,u8 Copy_u8Position , u8 Copy_u8Entry)
{
	ES_T Local_enuErrorState = ES_NOK;

	if (Copy_u8CharNum <= 8 && Copy_u8LCDID < LCD_NUM)
	{
		if(Copy_pu8Character != NULL)
		{
			LCD_invidSendCommand(LCD_u8GCRAM);
			u8 Local_u8Iterator ;
			for (Local_u8Iterator=0 ; Local_u8Iterator < (Copy_u8CharNum *8) ;Local_u8Iterator ++)
			{
				DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
				LCD_vidLatch(Copy_pu8Character[Local_u8Iterator]);
			}
			if (Copy_u8Entry == LCD_u8DDRAMDEC)
			{
				LCD_invidSendCommand(Copy_u8Position);
				LCD_invidSendCommand(Copy_u8Entry);
			}
			for (Local_u8Iterator=0 ; Local_u8Iterator < Copy_u8CharNum  ;Local_u8Iterator ++)
			{
				DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
				LCD_invidSendData(Copy_u8LCDID,Local_u8Iterator);
			}
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NULL_POINTER;
		}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorState;
}
*/
static inline void  LCD_invidSendCommand(u8 Copy_u8LCDID , u8 Copy_u8Command)
{
	if(Copy_u8LCDID < LCD_NUM)
	{
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8LOW);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RWPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RWPin,DIO_u8LOW);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8LOW);

		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D7Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D7Pin,(Copy_u8Command>>BIT_SEVEN)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D6Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D6Pin,(Copy_u8Command>>BIT_SIX)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D5Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D5Pin,(Copy_u8Command>>BIT_FIVE)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D4Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D4Pin,(Copy_u8Command>>BIT_FOUR)&BIT_MASKING);

		if(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8LCDMode == EIGHT_BIT)
		{
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D3Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D3Pin,(Copy_u8Command>>BIT_THREE)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D2Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D2Pin,(Copy_u8Command>>BIT_TWO)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D1Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D1Pin,(Copy_u8Command>>BIT_ONE)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D0Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D0Pin,(Copy_u8Command>>BIT_ZERO)&BIT_MASKING);
		}
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8LOW);
	}
	_delay_ms(10);
}

static void  LCD_invidSendData(u8 Copy_u8LCDID , u8 Copy_u8Data)
{
	if(Copy_u8LCDID < LCD_NUM)
	{
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RWPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RWPin,DIO_u8LOW);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8LOW);

		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D7Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D7Pin,(Copy_u8Data>>BIT_SEVEN)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D6Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D6Pin,(Copy_u8Data>>BIT_SIX)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D5Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D5Pin,(Copy_u8Data>>BIT_FIVE)&BIT_MASKING);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D4Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D4Pin,(Copy_u8Data>>BIT_FOUR)&BIT_MASKING);

		if(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8LCDMode == EIGHT_BIT)
		{
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D3Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D3Pin,(Copy_u8Data>>BIT_THREE)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D2Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D2Pin,(Copy_u8Data>>BIT_TWO)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D1Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D1Pin,(Copy_u8Data>>BIT_ONE)&BIT_MASKING);
			DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D0Port,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8D0Pin,(Copy_u8Data>>BIT_ZERO)&BIT_MASKING);
		}
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8HIGH);
		_delay_ms(10);
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8ENPin,DIO_u8LOW);
	}
}
ES_T LCD_enuDisplayFloatNum(u8 Copy_u8LCDID ,f32 Copy_f32Num)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_u8LCDID < LCD_NUM)
	{
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);

	s32 Local_s32ReverseINT=0;
	s32 Local_s32ReverseDEC=0;
	u8 Local_u8RemainderINT=0 ,Local_u8RemainderDEC=0, Local_u8NumDigitINT=0 , Local_u8NumDigitDEC=0;

	u32 Local_u32IntPart1=0 ; f32 Local_f32FloatPart=0.0 ;
	u32 Local_u32IntPart2=0 ;
	Local_u32IntPart1 = (u32) Copy_f32Num;

	Local_f32FloatPart = Copy_f32Num - Local_u32IntPart1;
	Local_u32IntPart2 = Local_f32FloatPart * 10000;
	if(Copy_f32Num <0)
	{
		LCD_invidSendData(Copy_u8LCDID,'-');
		Copy_f32Num *= -1 ;
	}
	while (Local_u32IntPart1)
	{
		Local_u8RemainderINT = Local_u32IntPart1 % 10;
		Local_s32ReverseINT = Local_s32ReverseINT * 10 + Local_u8RemainderINT;
		Local_u32IntPart1 /=10;
		Local_u8NumDigitINT ++;
	}
	while (Local_u32IntPart2)
	{
		Local_u8RemainderDEC = Local_u32IntPart2 % 10;
		Local_s32ReverseDEC = Local_s32ReverseDEC * 10 + Local_u8RemainderDEC;
		Local_u32IntPart2 /=10;
		Local_u8NumDigitDEC ++;
	}
	while (Local_u8NumDigitINT)
	{
		Local_u8RemainderINT = Local_s32ReverseINT % 10;
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
		LCD_invidSendData(Copy_u8LCDID,(Local_u8RemainderINT + '0'));
		Local_s32ReverseINT /= 10;
		Local_u8NumDigitINT --;
	}
	LCD_invidSendData(Copy_u8LCDID,'.');
	while (Local_u8NumDigitDEC)
	{
		Local_u8RemainderDEC = Local_s32ReverseDEC % 10;
		DIO_enuSetPinValue(LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPort,LCD_AstrLCDConfig[Copy_u8LCDID].LCD_u8RSPin,DIO_u8HIGH);
		LCD_invidSendData(Copy_u8LCDID,(Local_u8RemainderDEC + '0'));
		Local_s32ReverseDEC /= 10;
		Local_u8NumDigitDEC --;
	}
	}
	else
	{
		Local_enuErrorState = ES_OUTOFRANGE;
	}
	return Local_enuErrorState;
}

