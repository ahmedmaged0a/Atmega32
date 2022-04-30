/*
 * 7-Seg_Interface.h
 *
 *  Created on: Mar 26, 2022
 *      Author: Ahmed Maged
 */

#ifndef HAL_7_SEG_INTERFACE_H_
#define HAL_7_SEG_INTERFACE_H_

ES_T Seven_Segment_enuInit(SEG_T *Copy_PstrSegConfig);

ES_T Seven_Segment_enuDisplayNum(u8 Copy_u8SegID,u8 Copy_u8Num);

ES_T Seven_Segment_enuEnableCommon(u8 Copy_u8SegID);

ES_T Seven_Segment_enuDisableCommon(u8 Copy_u8SegID);

ES_T Seven_Segment_enuEnableDot(u8 Copy_u8SegID);

ES_T Seven_Segment_enuDisableDot(u8 Copy_u8SegID);

ES_T Seven_Segment_enuClearDisplay(u8 Copy_u8SegID);

#endif /* HAL_7_SEG_INTERFACE_H_ */
