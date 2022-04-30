/*
 * stdTypes.h
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_

#define CPU_TYPE	 	CPU_TYPES_32
#define CPU_BIT_ORDER	MSB_FIRST
#define CPU_BYTE_ORDER	HIGH_BYTE_ORDER
#define NULL		          (void*)0

typedef unsigned char           u8   ;
typedef unsigned short int      u16  ;
typedef unsigned int            u32  ;
typedef unsigned long long int  u64  ;

typedef signed char             s8   ;
typedef signed short int        s16  ;
typedef signed int              s32  ;
typedef signed long long int    s64  ;

typedef float                   f32  ;
typedef double                  f64  ;
typedef long double             f80  ;

typedef volatile u8             vu8  ;
typedef volatile u16            vu16 ;
typedef volatile u32            vu32 ;
typedef volatile u64            vu64 ;

typedef volatile s8             vs8  ;
typedef volatile s16            vs16 ;
typedef volatile s32            vs32 ;
typedef volatile s64            vs64 ;

#endif /* STDTYPES_H_ */
