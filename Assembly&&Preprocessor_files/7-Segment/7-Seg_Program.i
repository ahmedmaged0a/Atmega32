# 1 "7-Seg_Program.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "7-Seg_Program.c"






# 1 "../../LIB/errorState.h" 1
# 10 "../../LIB/errorState.h"
typedef enum
{
 ES_NOK,
 ES_OK,
 ES_NULL_POINTER,
 ES_OUTOFRANGE
}ES_T;
# 8 "7-Seg_Program.c" 2
# 1 "../../LIB/stdTypes.h" 1
# 16 "../../LIB/stdTypes.h"
typedef unsigned char u8 ;
typedef unsigned short int u16 ;
typedef unsigned int u32 ;
typedef unsigned long long int u64 ;

typedef signed char s8 ;
typedef signed short int s16 ;
typedef signed int s32 ;
typedef signed long long int s64 ;

typedef float f32 ;
typedef double f64 ;
typedef long double f80 ;

typedef volatile u8 vu8 ;
typedef volatile u16 vu16 ;
typedef volatile u32 vu32 ;
typedef volatile u64 vu64 ;

typedef volatile s8 vs8 ;
typedef volatile s16 vs16 ;
typedef volatile s32 vs32 ;
typedef volatile s64 vs64 ;
# 9 "7-Seg_Program.c" 2

# 1 "../../MCAL/DIO/DIO_interface.h" 1
# 34 "../../MCAL/DIO/DIO_interface.h"
 ES_T DIO_enuInit(void);

 ES_T DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value);

 ES_T DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value);

 ES_T DIO_enuTogglePortValue(u8 Copy_u8PortID);

 ES_T DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_Pu8Value);

 ES_T DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

 ES_T DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

 ES_T DIO_enuToggelPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

 ES_T DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 * Copy_Pu8Value);
# 11 "7-Seg_Program.c" 2

# 1 "7-Seg_Config.h" 1
# 13 "7-Seg_Program.c" 2
# 1 "7-Seg_Private.h" 1
# 16 "7-Seg_Private.h"
u8 SEG_Au8NumDisplay []= { 0x3f, 0x06, 0x5B,
       0x4F, 0x66, 0x6D,
       0x7D, 0x07, 0x7F,
       0x6F};
# 14 "7-Seg_Program.c" 2


ES_T Seven_Segment_enuInit(void)
{
 ES_T Local_enuErrorState = ES_NOK;
 u32 Local_u32Check = 0;

 Local_u32Check |= (DIO_enuSetPinDirection(0 , 0 , 1)<<0);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 1 , 1)<<2);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 2 , 1)<<4);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 3 , 1)<<6);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 4 , 1)<<8);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 5 , 1)<<10);
 Local_u32Check |= (DIO_enuSetPinDirection(0 , 6 , 1)<<12);
 Local_enuErrorState = ES_OK;
# 45 "7-Seg_Program.c"
 return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisplayNum(u8 Copy_u8Num)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_u8Num <= 9)
 {
# 66 "7-Seg_Program.c"
  DIO_enuSetPinValue(0 , 0 , !((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
  DIO_enuSetPinValue(0 , 1 , !((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1));
  DIO_enuSetPinValue(0 , 2 , !((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1));
  DIO_enuSetPinValue(0 , 3 , !((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1));
  DIO_enuSetPinValue(0 , 4 , !((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1));
  DIO_enuSetPinValue(0 , 5 , !((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1));
  DIO_enuSetPinValue(0 , 6 , !((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1));
  Local_enuErrorState = ES_OK;




 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }

 return Local_enuErrorState;

}

ES_T Seven_Segment_enuEnableCommon(void)
{
 ES_T Local_enuErrorState = ES_NOK;
# 106 "7-Seg_Program.c"
  return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableCommon(void)
{
 ES_T Local_enuErrorState = ES_NOK;
# 128 "7-Seg_Program.c"
  return Local_enuErrorState;

}

ES_T Seven_Segment_enuEnableDot(void)
{
 ES_T Local_enuErrorState = ES_NOK;
# 151 "7-Seg_Program.c"
 return Local_enuErrorState;

}

ES_T Seven_Segment_enuDisableDot(void)
{
 ES_T Local_enuErrorState = ES_NOK;
# 174 "7-Seg_Program.c"
 return Local_enuErrorState;

}

ES_T Seven_Segment_enuClearDisplay(void)
{
 ES_T Local_enuErrorState = ES_NOK;
# 192 "7-Seg_Program.c"
   DIO_enuSetPinValue(0 , 0 , 1);
   DIO_enuSetPinValue(0 , 1 , 1);
   DIO_enuSetPinValue(0 , 2 , 1);
   DIO_enuSetPinValue(0 , 3 , 1);
   DIO_enuSetPinValue(0 , 4 , 1);
   DIO_enuSetPinValue(0 , 5 , 1);
   DIO_enuSetPinValue(0 , 6 , 1);
   Local_enuErrorState = ES_OK;





  return Local_enuErrorState;

}
