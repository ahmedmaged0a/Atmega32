/*******************************************************************************/
/*	Author		:	Ahmed Maged												   */
/*	Date		:	15 JUL 2022												   */
/*	Version		:	V01									    				   */
/*******************************************************************************/

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_
/*
* ==============================================================================================
* 							==  Here You Can Select ADC Prescaler Bits.
*
* 								 ADC_PRESCALER   Division Factor
* 								  PRE_2			 = 2
* 								  PRE_4		     = 4
* 								  PRE_8			 = 8
* 								  PRE_16		 = 16
* 								  PRE_32		 = 32
* 								  PRE_64		 = 64
* 								  PRE_128        = 128
* ==============================================================================================
*/
#define ADC_PRESCALERE		PRE_128

/*
* ==============================================================================================
* 							==	Here you can select the voltage reference for ADC.
* 								    REFS1   REFS0     Voltage Reference Selection
* 									[0]	    [0]     = AREF_INTERNAL_VOFF  !<<AREF, Internal Vref turned off >>
* 									[0]		[1]	  	= AVCC				  !<<AVCC with external capacitor at AREF pin >>
* 									[1]		[0]	  	= Reserved
* 									[1]		[1]	  	= INTERNAL_V     	  !<<Internal 2.56V Voltage Reference with external capacitor at AREF pin>>
* ==============================================================================================
*/
#define ADC_U8VOLTAGE_REFRENCE	AVCC

/*
* ==============================================================================================
* 								Choose The the presentation of the ADC conversion result.
* 								[LEFT_ADJUSTED] OR [WRITE_ADJUSTED]
* ==============================================================================================
*/
#define ADC_WRITEADJUST		RIGHT_ADJUSTED
/*
* ==============================================================================================
* 								Here You can choose between
* 								1- [Single Ended Mode]
* 								2- [Differential Mode]
* 								to be input source for you ADC
* ==============================================================================================
*/
#define ADC_INPUT_SOURCE  SINGLE_ENDED_MODE

/*
* ==============================================================================================
* The value of these bits selects which combination of analog inputs are connected to the ADC.
* [ADC_0]
* [ADC_1]
* [ADC_2]
* [ADC_3]
* [ADC_4]
* [ADC_5]
* [ADC_6]
* [ADC_7]
* ##NOTE : ADC_INPUT_SOURCE must be in single ended mode to work with this.
* ==============================================================================================
*/
#define ADC_u8INPUT		ADC_0
/*
* ==============================================================================================
* 									Here You Can Choose the Configuration for Differential mode
*										 Positive_input		Negative_input  Gain
*                                         [ADC0]            [ADC0]          [G_10 ]
*                                         [ADC1]            [ADC0]          [G_10 ]
*                                         [ADC0]            [ADC0]          [G_200]
*                                         [ADC1]            [ADC0]          [G_200]
*                                         [ADC2]            [ADC2]          [G_10 ]
*                                         [ADC3]            [ADC2]          [G_10 ]
*                                         [ADC2]            [ADC2]          [G_200]
*                                         [ADC3]            [ADC2]          [G_200]
*                                         [ADC0]            [ADC1]          [G_1 ]
*                                         [ADC1]            [ADC1]          [G_1 ]
*                                         [ADC2]            [ADC1]          [G_1 ]
*                                         [ADC3]            [ADC1]          [G_1 ]
*                                         [ADC4]            [ADC1]          [G_1 ]
*                                         [ADC5]            [ADC1]          [G_1 ]
*                                         [ADC6]            [ADC1]          [G_1 ]
*                                         [ADC7]            [ADC1]          [G_1 ]
*                                         [ADC0]            [ADC2]          [G_1 ]
*                                         [ADC1]            [ADC2]          [G_1 ]
*                                         [ADC2]            [ADC2]          [G_1 ]
*                                         [ADC3]            [ADC2]          [G_1 ]
*                                         [ADC4]            [ADC2]          [G_1 ]
* ##NOTE : ADC_INPUT_SOURCE must be in Differential mode[ t o work with this.
* ==============================================================================================
*/
#define POSITIVE_DIF_IN 	ADC_0
#define NEGATIVE_DIF_IN 	ADC_0
#define ADC_GAIN			G_10

#endif /* MCAL_ADC_ADC_CONFIG_H_ */
