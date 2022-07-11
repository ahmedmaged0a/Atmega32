/*
 * SPI_Config.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*-------------------------DATA_ORDER-------------------------*/
// the LSB of the data word is transmitted first --> LSB_FIRST
// the MSB of the data word is transmitted first --> MSB_FIRST
#define DATA_ORDER 	MSB_FIRST

/*-------------------------SPI_MODE-------------------------*/
/* 1.) 0 ----> Read on rising edge, write on falling edge    -->Leading = rising
 * 2.) 1 ----> Read on falling edge, write on rising edge    -->Leading = rising
 * 3.) 2 ----> Read on falling edge, write on falling edge	 -->Leading = falling
 * 4.) 3 ----> Read on rising edge, write on falling edge	 -->Leading = falling
 * */
#define SPI_MODE    0

/*When this bit is written logic one the SPI speed (SCK Frequency) will be doubled when
  the SPI is in Master mode
*/
#define DOUBLE_SPEED   DISABLE



#endif /* MCAL_SPI_SPI_CONFIG_H_ */
