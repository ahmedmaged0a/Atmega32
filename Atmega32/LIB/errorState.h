/*
 * errorState.h
 *
 *  Created on: Sep 9, 2021
 *      Author: bayer
 */

#ifndef ERRORSTATE_H_
#define ERRORSTATE_H_
typedef enum
{
	ES_NOK,
	ES_OK,
	ES_NULL_POINTER,
	ES_OUTOFRANGE,
	ES_7SEG_ERROR,
	ES_SPI_TRANFER_ERROR
}ES_T;

#endif /* ERRORSTATE_H_ */
