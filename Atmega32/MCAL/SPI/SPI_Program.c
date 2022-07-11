/*
 * SPI_Program.c
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Maged
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "SPI_Private.h"
#include "SPI_Config.h"
ES_T SPI_enuInitMaster()
{
	ES_T Local_enuErrorState = ES_NOK;
	SPCR |= (1<<SPE);
	/*Select Master*/
	SPCR |= (1<<MSTR);

	SPCR &= ~(1<<SPR0);
	SPCR &= ~(1<<SPR1);

#if DATA_ORDER == MSB_FIRST
	SPCR &=~(1<<DORD);
	Local_enuErrorState = ES_OK;
#elif DATA_ORDER == LSB_FIRST
	SPCR |= (1<<DORD);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if SPI_MODE == 0
	SPCR &=~(1<<CPOL);
	SPCR &=~(1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 1
	SPCR &=~(1<<CPOL);
	SPCR |= (1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 2
	SPCR |= (1<<CPOL);
	SPCR &=~(1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 3
	SPCR |= (1<<CPOL);
	SPCR |= (1<<CPHA);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if DOUBLE_SPEED == ENABLE
	/*Enable Double Speed*/
	SPSR |= (1<<SPI2X);
	Local_enuErrorState = ES_OK;
#elif DOUBLE_SPEED == DISABLE
	/*Disable Double Speed*/
	SPCR &=~ (1<<SPI2X);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

	return Local_enuErrorState;
}

ES_T SPI_enuInitSlave()
{
	ES_T Local_enuErrorState = ES_NOK;
	/*Enable SPI*/
	SPCR |= (1<<SPE);
	/*Select Slave Mode*/
	SPCR &=~(1<<MSTR);
#if DATA_ORDER == MSB_FIRST
	/*Send MSB bit first*/
	SPCR &=~(1<<DORD);
	Local_enuErrorState = ES_OK;
#elif DATA_ORDER == LSB_FIRST
	/*Send LSB bit first*/
	SPCR |= (1<<DORD);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif

#if SPI_MODE == 0
	/*Read on rising edge, write on falling edge    -->Leading = rising*/
	SPCR &=~(1<<CPOL);
	SPCR &=~(1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 1
	/*Read on falling edge, write on rising edge    -->Leading = rising*/
	SPCR &=~(1<<CPOL);
	SPCR |= (1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 2
	/*Read on falling edge, write on falling edge	 -->Leading = falling*/
	SPCR |= (1<<CPOL);
	SPCR &=~(1<<CPHA);
	Local_enuErrorState = ES_OK;
#elif SPI_MODE == 3
	/*Read on rising edge, write on falling edge	 -->Leading = falling*/
	SPCR |= (1<<CPOL);
	SPCR |= (1<<CPHA);
	Local_enuErrorState = ES_OK;
#else
	Local_enuErrorState = ES_NOK;
#endif
	return Local_enuErrorState;
}

ES_T SPI_enuTransceive(u8 Copy_u8Data , u8 *Copy_Pu8ExchangedData)
{
	ES_T Local_enuErrorState = ES_NOK;
	SPDR = Copy_u8Data;
		/*polling --> Wait Transfer Complete*/
		while(!(1&(SPSR>>SPIF)));
		/*Read Data After Exchange*/
		*Copy_Pu8ExchangedData = SPDR;
		Local_enuErrorState = ES_OK;
		return Local_enuErrorState;
}

