/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/*
* ==============================================================================================
* 								APIs Supported by "MCAL ADC DRIVER"
* 								For more information about the APIs check the function definitions
* ==============================================================================================
*/
ES_T ADC_enuInit(void);

ES_T ADC_enuStartConversion(void);

ES_T ADC_enuPollingSystem(void);

ES_T ADC_enuReadHighReg(u8 * Copy_Pu8Value);

ES_T ADC_enuRead(u16 * Copy_Pu16Value);

ES_T ADC_enuCallBack(void(*Copy_pAPPfun (void *)) , void * Copy_PvidParam);

ES_T ADC_enuEnable(void);

ES_T ADC_enuDisable(void);

ES_T ADC_enuSelectChannel(u8 Copy_u8ChannelID);

ES_T ADC_enuEnableTriggeringMode(u8 Copy_u8TriggeringSource);

ES_T ADC_enuDisableTriggeringMode(void);

ES_T ADC_enuEnableInterruptMode(void);


#define ADC_u8FREE_RUNNING  		 0
#define ADC_u8ANALOG_COMPARATOR      1
#define ADC_u8EXT0_INTERRUPT   		 2
#define ADC_u8TMR0_COMPARE  		 3
#define ADC_u8TMR0_OVF          	 4
#define ADC_u8TMR_COMPARE_B          5
#define ADC_u8TMR1_OVF          	 6
#define ADC_u8TMR1_CAPTURE           7


#define ADC_0    0
#define ADC_1    1
#define ADC_2    2
#define ADC_3    3
#define ADC_4    4
#define ADC_5    5
#define ADC_6    6
#define ADC_7    7


#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
