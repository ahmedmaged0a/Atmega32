/*
 * EXTI_Interface.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */


#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

ES_T EXTI_enuInit(EXTI_T * Copy_PstrEXTIconfig);

ES_T EXTI_enuSetSenceControl(u8 Copy_u8EXTI_ID, u8 Copy_u8SenceControl);

ES_T EXTI_enuEnableINT(u8 Copy_u8EXTI_ID);

ES_T EXTI_enuDisableINT(u8 Copy_u8EXTI_ID);

ES_T EXTI_enuCallBack( volatile void(*Copy_Pfun)(void*) , u8 Copy_u8EXTI_ID);




#define LOW_LEVEL    1
#define ON_CHANGE    2
#define FALLING_EDGE 3
#define RISING_EDGE  4

#define INT_0         0
#define INT_1         1
#define INT_2         2

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
