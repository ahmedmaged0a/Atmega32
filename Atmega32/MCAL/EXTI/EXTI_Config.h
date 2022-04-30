/*
 * EXTI_Config.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

typedef struct
{
	u8 EXTI_u8Istate;
	u8 EXTI_u8SenceControl;
}EXTI_T;


#define EXTI_INT0  0
#define EXTI_INT1  1
#define EXTI_INT2  2

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
