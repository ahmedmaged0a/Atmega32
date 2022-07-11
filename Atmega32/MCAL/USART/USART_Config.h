/*
 * USART_Config.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_USART_USART_CONFIG_H_
#define MCAL_USART_USART_CONFIG_H_

/*Choose Speed Mode Between [NORMAL , DOUBLE] */
	#define SPEED_MODE  NORMAL

/*Choose Character Size Between [FIVE , SIX , SEVEN , EIGHT , NINE] */
	#define CHARACTER_SIZE  EIGHT

/*Choose UART Mode Between [TRANSMITTER , RECIEVER , FULL_DOUBLEX] */
	#define UART_MODE  FULL_DOUBLEX

/*selects between Asynchronous and Synchronous mode [SYNCRONOUS , ASYNCRONOUS] */
	#define MODE ASYNCRONOUS

/*Write Baud Rate (bps) */
	#define BAUD_RATE	9600ul

/*Choose Parity Mode  Between [EVEN_PARITY , ODD_PARITY  , DISABLED] */
	#define PARITY_STATE	DISABLED

/*Choose STOP_STATE  Between [ONE_BIT , TWO_BIT] */
	#define STOP_STATE		ONE_BIT

#endif /* MCAL_USART_USART_CONFIG_H_ */
