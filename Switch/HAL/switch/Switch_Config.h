/*
 * Switch_Config.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#ifndef Switch_CONFIG_H_
#define Switch_CONFIG_H_

#define SW_NUM 3
typedef struct
{
	u8 SW_PortID;
	u8 SW_PinID;
	u8 SW_Status;
}SW_T;

#endif /* Switch_CONFIG_H_ */
