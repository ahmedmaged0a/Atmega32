/*
 * Interrupt.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef MCAL_INTERRUPT_H_
#define MCAL_INTERRUPT_H_

#define ISR(VECTOR_NUMBER) void VECTOR_NUMBER (void) __attribute__((signal));\
						   void VECTOR_NUMBER (void)

#define VECTOR_RESET  __vector_0

#define VECTOR_INT0  __vector_1
#define VECTOR_INT1  __vector_2
#define VECTOR_INT2  __vector_3

#define VECTOR_TIMER2_COMP   __vector_4
#define VECTOR_TIMER2_OVF    __vector_5
#define VECTOR_TIMER1_CAPT   __vector_6
#define VECTOR_TIMER1_COMPA  __vector_7
#define VECTOR_TIMER1 COMPB  __vector_8
#define VECTOR_TIMER1_OVF    __vector_9
#define VECTOR_TIMER0 COMP   __vector_10
#define VECTOR_TIMER0_OVF    __vector_11

#define VECTOR_SPI   		 __vector_12
#define VECTOR_USART_RXC     __vector_13
#define VECTOR_USART_UDRE    __vector_14
#define VECTOR_USART_TXC     __vector_15

#define VECTOR_ADC   		 __vector_16
#define VECTOR_EE_RDY        __vector_17
#define VECTOR_ANA_COMP      __vector_18
#define VECTOR_TWI           __vector_19
#define VECTOR_SPM_RDY       __vector_20


#endif /* MCAL_INTERRUPT_H_ */
