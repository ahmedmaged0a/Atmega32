/*
 * 7-Seg_Private.h
 *
 *  Created on: Mar 26, 2022
 *      Author:  Ahmed Maged
 */

#ifndef HAL_7_SEG_PRIVATE_H_
#define HAL_7_SEG_PRIVATE_H_

#define COMMON_ANODE    2
#define COMMON_CATHODE  1

#define NOT_CONNECTED   20

static u8 SEG_Au8NumDisplay []= {  0x3f, 0x06, 0x5B,
							0x4F, 0x66, 0x6D,
							0x7D, 0x07, 0x7F,
							0x6F};

#define ZERO_U8NUM         0
#define BIT_U8MASKING  1


#define  ZERO_U8LSH  0
#define  TWO_U8LSH  2
#define  FOUR_U8LSH  4
#define  SIX_U8LSH  6
#define  EIGHT_U8LSH  8
#define  TEN_U8LSH  10
#define  TWIELVE_U8LSH  12

#define ZERO_U8RSH  0
#define ONE_U8RSH  1
#define TWO_U8RSH  2
#define THREE_U8RSH  3
#define FOUR_U8RSH  4
#define FIVE_U8RSH  5
#define SIX_U8RSH  6

#define	 SEVEN_SEG_U8MAXRANGE  9
#endif /* HAL_7_SEG_PRIVATE_H_ */
