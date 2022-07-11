/*
 * USART_Private.h
 *
 *  Created on: Jul 6, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_USART_USART_PRIVATE_H_
#define MCAL_USART_USART_PRIVATE_H_

/*------------------------ USART I/O Data Register – UDR --------------------------*/

	 /*The USART Transmit Data Buffer Register and USART Receive Data Buffer Registers
		share the same I/O address referred to as USART Data Register or UDR. The Transmit
		Data Buffer Register (TXB) will be the destination for data written to the UDR Register
		location. Reading the UDR Register location will return the contents of the Receive Data
		Buffer Register (RXB).

		For 5-, 6-, or 7-bit characters the upper unused bits will be ignored by the Transmitter
		and set to zero by the Receiver*/

		/*
		 	The transmit buffer can only be written when the UDRE Flag in the UCSRA Register is
			set. Data written to UDR when the UDRE Flag is not set, will be ignored by the USART
			Transmitter
		*/

/*------------------------ USART Control and Status Register A – UCSRA --------------------------*/

	/*This flag bit is set when there are unread data in the receive buffer and cleared when the receive buffer is empty (i.e., does not contain any unread data).*/
	#define RXC       7
	/*This flag bit is set when the entire frame in the transmit Shift Register has been shifted out and there are no new data currently present in the transmit buffer (UDR)*/
	#define TXC       6
	/*The UDRE Flag indicates if the transmit buffer (UDR) is ready to receive new data. If UDRE is one, the buffer is empty, and therefore ready to be written*/
	#define UDRE      5
	/*This bit is set if the next character in the receive buffer had a Frame Error when received.*/
	#define FE        4
	/*This bit is set if a Data OverRun condition is detected. A Data OverRun occurs when the receive buffer is full (two characters),*/
	#define DOR       3
	/*This bit is set if the next character in the receive buffer had a Parity Error when received and the parity checking was enabled at that point (UPM1 = 1)*/
	#define PE        2
 	/*This bit only has effect for the asynchronous operation. Write this bit to zero when using synchronous operation*/
	#define U2X       1
	/*This bit enables the Multi-processor Communication mode  ----> Master && Slaves*/
	#define MPCM      0

/*------------------------ USART Control and Status Register B – UCSRB --------------------------*/
	/*RX Complete Interrupt Enable*/
	#define  RXCIE   7
	/*TX Complete Interrupt Enable*/
	#define  TXCIE   6
	/*USART Data Register Empty Interrupt Enable*/
	#define  UDRIE   5
	/*Receiver Enable*/
	#define  RXEN  	 4
	/*Transmitter Enable*/
	#define  TXEN    3
	/*Character Size*/
	#define  UCSZ2   2
	/* Receive Data Bit 8*/
	#define  RXB8    1
	/*Transmit Data Bit 8*/
	#define  TXB8    0


/*------------------------ USART Control and Status Register C – UCSRC --------------------------*/
	/*This bit selects between accessing the UCSRC or the UBRRH Register*/
	#define  URSEL    7
	/*This bit selects between Asynchronous and Synchronous mode of operation*/
	#define  UMSEL    6
	/*Parity Mode BIT 1*/
	#define  UPM1     5
	/*Parity Mode BIT 0*/
	#define  UPM0  	  4
	/*Stop Bit Select*/
	#define  USBS     3
	/*Character Size*/
	#define  UCSZ1    2
	/*Character Size*/
	#define  UCSZ0    1
	/*Clock Polarity --> This bit is used for Synchronous mode only*/
	#define  UCPOL    0


#define  URSEL_B    15

#define SET 		1
#define CLEAR		1

#define NORMAL 	2
#define DOUBLE 	1

#define BAUD_VALUE(BAUD)  (u16)(F_CPU/(SPEED_MODE * 8 * BAUD)-1)

#define FIVE 	5
#define SIX 	6
#define SEVEN 	7
#define EIGHT 	8
#define NINE 	9

#define TRANSMITTER 	1
#define RECIEVER 		2
#define FULL_DOUBLEX 	3

#define EVEN_PARITY		1
#define ODD_PARITY 		2
#define DISABLED 		3

#define ONE_BIT			1
#define TWO_BIT 		2

#define SYNCRONOUS			1
#define ASYNCRONOUS 		2

#define UDR   	*((volatile u8*)0x2C)
#define UBRRL 	*((volatile u8*)0x92)
#define UCSRA 	*((volatile u8*)0x2B)
#define UCSRB 	*((volatile u8*)0x2A)
#define UCSRC 	*((volatile u8*)0x40)
#define UBRRH 	UCSRC



#endif /* MCAL_USART_USART_PRIVATE_H_ */
