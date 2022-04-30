/*
 * EXTI_Private.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_

#define LOW_LEVEL    1  //The low level of INT{no} generates an interrupt request.
#define ON_CHANGE    2  //Any logical change on INT{no} generates an interrupt request.
#define FALLING_EDGE 3  //The falling edge of INT{no} generates an interrupt request.
#define RISING_EDGE  4  //The rising edge of INT{no} generates an interrupt request.

#define INT_ACTIVE   1  //To Active INT{no}
#define INT_DEAVTIVE 0	//To DEactive INT{no}

#define INITIAL_ZERO  0


#define MAX_INT_ID   	3

#define BIT_MASKING     1

#define INT_0         0
#define INT_1         1
#define INT_2         2

#define GICR_BIT5     5
#define GICR_BIT6     6
#define GICR_BIT7     7

#define INT0_SET_FALLING     2
#define INT0_SET_RISING   	 3
#define INT0_SET_ON_CHANGE   1
#define INT0_SET_LOWLEVEL    0

#define INT1_SET_FALLING     2
#define INT1_SET_RISING   	 3
#define INT1_SET_ON_CHANGE   1
#define INT1_SET_LOWLEVEL    0

#define INT2_SET_FALLING     0
#define INT2_SET_RISING   	 1

#define BIT_0  0
#define BIT_1  1
#define BIT_2  2
#define BIT_3  3
#define BIT_4  4
#define BIT_5  5
#define BIT_6  6
#define BIT_7  7

#define CLEAR_TWO_BIT 3

#define MCUCR				*((u8*)0x55)
#define MCUCSR				*((u8*)0x54)
#define GICR				*((u8*)0x5B)
#define GIFR				*((u8*)0x5A)


#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
