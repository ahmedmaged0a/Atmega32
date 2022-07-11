/*
 * USART_Program.c
 *
 *  Created on: Jul 6, 2022
 *      Author: Ahmed Maged
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "USART_Private.h"
#include "USART_Config.h"

ES_T UART_enuInit(void)
{
	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8UCSRCval = 0;
	u16 Local_u8UBRRval = 0;
#if SPEED_MODE == NORMAL
	UCSRA &=~(CLEAR<<U2X);
	Local_enuErrorState = ES_OK;
#elif SPEED_MODE == DOUBLE
	UCSRA |= (SET<<U2X);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if CHARACTER_SIZE == FIVE
	Local_u8UCSRCval &=~(CLEAR<<UCSZ0);
	Local_u8UCSRCval &=~(CLEAR<<UCSZ1);
	UCSRB &=~(CLEAR<<UCSZ2);
	Local_enuErrorState = ES_OK;
#elif CHARACTER_SIZE == SIX
	Local_u8UCSRCval |= (SET<<UCSZ0);
	Local_u8UCSRCval &=~(CLEAR<<UCSZ1);
	UCSRB &=~(CLEAR<<UCSZ2);
	Local_enuErrorState = ES_OK;
#elif CHARACTER_SIZE == SEVEN
	Local_u8UCSRCval &=~ (CLEAR<<UCSZ0);
	Local_u8UCSRCval |=(SET<<UCSZ1);
	UCSRB &=~(CLEAR<<UCSZ2);
	Local_enuErrorState = ES_OK;
#elif CHARACTER_SIZE == EIGHT
	Local_u8UCSRCval |= (SET<<UCSZ0);
	Local_u8UCSRCval |= (SET<<UCSZ1);
	UCSRB &=~(CLEAR<<UCSZ2);
	Local_enuErrorState = ES_OK;
#elif CHARACTER_SIZE == NINE
	Local_u8UCSRCval |= (SET<<UCSZ0);
	Local_u8UCSRCval |= (SET<<UCSZ1);
	UCSRB |= (SET<<UCSZ2);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if UART_MODE == TRANSMITTER
	UCSRB |= (SET<<TXEN);
	UCSRB &=~ (CLEAR<<RXEN);
	Local_enuErrorState = ES_OK;
#elif UART_MODE == RECIEVER
	UCSRB &=~ (CLEAR<<TXEN);
	UCSRB |= (SET<<RXEN);
	Local_enuErrorState = ES_OK;
#elif UART_MODE == FULL_DOUBLEX
	UCSRB |= (SET<<TXEN);
	UCSRB |= (SET<<RXEN);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if MODE == SYNCRONOUS
	Local_u8UCSRCval |= (SET<<UMSEL);
	Local_enuErrorState = ES_OK;
#elif MODE == ASYNCRONOUS
	Local_u8UCSRCval &=~ (CLEAR<<UMSEL);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if PARITY_STATE == EVEN_PARITY
	Local_u8UCSRCval &=~(CLEAR<<UPM0);
	Local_u8UCSRCval |= (SET<<UPM1);
	Local_enuErrorState = ES_OK;
#elif PARITY_STATE == ODD_PARITY
	UCSRC |=(SET<<UPM0);
	UCSRC &=~(CLEAR<<UPM1);
	Local_enuErrorState = ES_OK;
#elif PARITY_STATE == DISABLED
	Local_u8UCSRCval &=~(CLEAR<<UPM0);
	Local_u8UCSRCval &=~(CLEAR<<UPM1);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if STOP_STATE == ONE_BIT
	Local_u8UCSRCval &=~(CLEAR<<USBS);
	Local_enuErrorState = ES_OK;
#elif STOP_STATE == TWO_BIT
	Local_u8UCSRCval |= (SET<<USBS);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif
	Local_u8UCSRCval |= (SET<<URSEL);
	UCSRC = Local_u8UCSRCval;

	Local_u8UBRRval = BAUD_VALUE(BAUD_RATE);
	Local_u8UBRRval &= ~(CLEAR<<URSEL_B);

	UBRRL = (u8)Local_u8UBRRval;
	UBRRH = (Local_u8UBRRval>>8);

	return Local_enuErrorState;
}

ES_T UART_enuSendChar(u8 Copy_u8Data)
{
	ES_T Local_enuErrorState = ES_NOK;
	while(!(1&(UCSRA>>UDRE)));
	UDR = Copy_u8Data;
	Local_enuErrorState = ES_OK;
	return Local_enuErrorState;
}

ES_T UART_enuRecieveChar(u8 *Copy_Pu8Data)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_Pu8Data != NULL)
	{
		while(!(1&(UCSRA>>RXC)));
		*Copy_Pu8Data= UDR;
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_T UART_enuSendString(const char* Copy_pcData)
{
	ES_T Local_enuErrorState = ES_NOK;
	if(Copy_pcData != NULL)
	{
		while(!(1&(UCSRA>>UDRE)));
		while(*Copy_pcData != '\0')
		{
			UDR = *Copy_pcData;
			Copy_pcData++;
		}
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;

	}

	return Local_enuErrorState;
}

ES_T UART_enuRecieveString(char *Copy_PcData)
{
	ES_T Local_enuErrorState = ES_NOK;
	u8 Local_u8Index = 0 , Local_u8Termination=0 , Local_u8Data=0;
	while(!(1&(UCSRA>>RXC)));
	Local_u8Termination = UDR;

	while(1)
	{
		while (!((UCSRA>>RXC)&1));
		Local_u8Data = UDR;
		if(Local_u8Data == Local_u8Termination)
		{
			Copy_PcData[Local_u8Index] = '\0';
			break;
		}
		Copy_PcData[Local_u8Index] = Local_u8Data;
		Local_u8Index++;

	}
	return Local_enuErrorState;
}
