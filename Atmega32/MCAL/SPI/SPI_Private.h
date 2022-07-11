/*
 * SPI_Private.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

/*------------------------ SPI Control Register – SPCR --------------------------*/
#define SPIE 	7               // SPI Interrupt Enable
#define SPE 	6			    //SPI Enable
#define DORD 	5             	// Data Order
#define MSTR 	4				// Master/Slave Select
#define CPOL 	3				// Clock Polarity {Reading of Writing first}
#define CPHA 	2				// Clock Phase {Sample or setup first}
#define SPR1 	1				//SPI Clock Rate Select 1
#define SPR0 	0				//SPI Clock Rate Select 0

/*------------------------ SPI Status Register – SPSR --------------------------*/
#define SPIF 	7			//SPI Interrupt Flag
#define WCOL 	6			//Write COLlision Flag
#define SPI2X 	0			//Double SPI Speed Bit


#define MSB_FIRST  1
#define LSB_FIRST  2

#define ENABLE  1
#define DISABLE 0

#define SPDR  	*((volatile u8*)0x2F)  //SPI Data Register
#define SPSR  	*((volatile u8*)0x2E)  //SPI Status Register
#define SPCR  	*((volatile u8*)0x2D)  //SPI Control Register


#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
