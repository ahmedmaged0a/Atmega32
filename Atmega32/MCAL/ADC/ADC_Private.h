/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

/*----------------------------- ADC Multiplexer Selection Register – ADMUX -------------------------*/
#define ADMUX	 *((volatile u8*)0x27)
#define REFS1 	7
#define REFS0 	6
#define ADLAR	5
#define MUX4 	4
#define MUX3 	3
#define MUX2	2
#define MUX1 	1
#define MUX0 	0

/*----------------------------- ADC Control and Status Register A – ADCSRA -------------------------*/
#define ADCSRA *((volatile u8*)0x26)
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0

#define ADCH *((volatile u8*)0x25)
#define ADCL *((volatile u8*)0x24)

/*----------------------------- Special FunctionIO Register – SFIOR -------------------------*/
#define SFIOR *((volatile u8*)0x50)
#define ADTS0  5
#define ADTS1  6
#define ADTS2  7


#define PRE_2	2
#define PRE_4	4
#define PRE_8	8
#define PRE_16	16
#define PRE_32	32
#define PRE_64	64
#define PRE_128	128

#define FREE_RUNNING_MODE 	0
#define ANALOG_COMPARATOR 	1
#define EXT0_INT 			2
#define TMR0_CMP 			3
#define TMR0_OVF 			4
#define TMR_CMP_B 			5
#define TMR1_OVF 			6
#define TMR1_CAPTURE 		7

#define AREF_INTERNAL_VOFF	0
#define AVCC				1
#define INTERNAL_V			2

#define LEFT_ADJUSTED		1
#define RIGHT_ADJUSTED		0

#define ENABLE  1
#define DISABLE	0

#define SINGLE_ENDED_MODE	0
#define DIFFERENTIAL_MODE	1

#define ADC_0	0
#define ADC_1	1
#define ADC_2	2
#define ADC_3	3
#define ADC_4	4
#define ADC_5	5
#define ADC_6	6
#define ADC_7	7

#define G_1  	1
#define G_200   200
#define G_10    10


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
