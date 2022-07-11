/*
 * USART_Interface.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_USART_USART_INTERFACE_H_
#define MCAL_USART_USART_INTERFACE_H_

ES_T UART_enuInit(void);

ES_T UART_enuSendChar(u8 Copy_u8Data);

ES_T UART_enuRecieveChar(u8 *Copy_Pu8Data);

ES_T UART_enuSendString(const char* Copy_pcData);

ES_T UART_enuRecieveString(char *Copy_PcData);


#endif /* MCAL_USART_USART_INTERFACE_H_ */
