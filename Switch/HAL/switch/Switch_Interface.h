/*
 * Switch_Interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: Ahmed Maged
 */

#ifndef Switch_INTERFACE_H_
#define Switch_INTERFACE_H_

ES_T SW_enuInit(SW_T *Copy_PstrSwState);
ES_T SW_enuGetState(SW_T * Copy_PstrSwState , u8 * Copy_Pu8SwState);

#endif /* Switch_INTERFACE_H_ */
