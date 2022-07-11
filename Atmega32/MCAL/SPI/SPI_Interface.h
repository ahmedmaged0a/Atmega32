/*
 * SPI_Interface.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Maged
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

ES_T SPI_enuInitMaster();

ES_T SPI_enuInitSlave();

ES_T SPI_enuTransceive(u8 Copy_u8Data , u8 * Copy_Pu8ExchangedData);


#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
