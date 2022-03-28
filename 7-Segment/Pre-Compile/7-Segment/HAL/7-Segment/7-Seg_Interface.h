/*
 * 7-Seg_Interface.h
 *
 *  Created on: Mar 26, 2022
 *      Author: Ahmed Maged
 */

#ifndef HAL_7_SEG_INTERFACE_H_
#define HAL_7_SEG_INTERFACE_H_

ES_T Seven_Segment_enuInit(void);

ES_T Seven_Segment_enuDisplayNum(u8 Copy_u8Num);

ES_T Seven_Segment_enuEnableCommon(void);

ES_T Seven_Segment_enuDisableCommon(void);

ES_T Seven_Segment_enuEnableDot(void);

ES_T Seven_Segment_enuDisableDot(void);

ES_T Seven_Segment_enuClearDisplay(void);

#endif /* HAL_7_SEG_INTERFACE_H_ */
