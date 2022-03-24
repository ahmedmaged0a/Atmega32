# 1 "DIO_Program.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "DIO_Program.c"
# 9 "DIO_Program.c"
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
# 10 "DIO_Program.c" 2
# 1 "../../LIB/errorState.h" 1
# 10 "../../LIB/errorState.h"
typedef enum
{
 ES_NOK,
 ES_OK,
 ES_NULL_POINTER,
 ES_OUTOFRANGE
}ES_T;
# 11 "DIO_Program.c" 2

# 1 "DIO_config.h" 1
# 13 "DIO_Program.c" 2
# 1 "DIO_private.h" 1
# 14 "DIO_Program.c" 2

ES_T DIO_enuInit(void)
{
 ES_T Local_enuErrorState = ES_NOK;

 *((volatile u8*)0x3A) = 0b11111111;
 *((volatile u8*)0x37) = 0b11111111;
 *((volatile u8*)0x34) = 0b11111111;
 *((volatile u8*)0x31) = 0b11111111;

 *((volatile u8*)0x3B) = 0b00000000;
 *((volatile u8*)0x38) = 0b00000000;
 *((volatile u8*)0x35) = 0b00000000;
 *((volatile u8*)0x32) = 0b00000000;
 Local_enuErrorState = ES_OK;

 return Local_enuErrorState;
}
ES_T DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_u8PortID <= 3)
 {
  switch(Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3A) = Copy_u8Value;
   break;
  case 1:
   *((volatile u8*)0x37) = Copy_u8Value;
   break;
  case 2:
   *((volatile u8*)0x34) = Copy_u8Value;
   break;
  case 3:
   *((volatile u8*)0x31) = Copy_u8Value;
   break;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }
 return Local_enuErrorState;
}

ES_T DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_u8PortID <= 3)
 {
  switch(Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3B) = Copy_u8Value;
   break;
  case 1:
   *((volatile u8*)0x38) = Copy_u8Value;
   break;
  case 2:
   *((volatile u8*)0x35) = Copy_u8Value;
   break;
  case 3:
   *((volatile u8*)0x32) = Copy_u8Value;
   break;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }
 return Local_enuErrorState;
}

ES_T DIO_enuTogglePortValue(u8 Copy_u8PortID)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_u8PortID <= 3)
 {
  switch(Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3B) = ~*((volatile u8*)0x3B);
   break;
  case 1:
   *((volatile u8*)0x38) = ~*((volatile u8*)0x38);
   break;
  case 2:
   *((volatile u8*)0x35) = ~*((volatile u8*)0x35);
   break;
  case 3:
   *((volatile u8*)0x32) = ~*((volatile u8*)0x32);
   break;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }
 return Local_enuErrorState;
}

ES_T DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_Pu8Value)
{
 ES_T Local_enuErrorState = ES_NOK;

 if(Copy_Pu8Value != (void*)0)
 {
  if(Copy_u8PortID <= 3)
  {
   switch(Copy_u8PortID)
   {
   case 0:
    *Copy_Pu8Value = *((volatile u8*)0x39);
    break;
   case 1:
    *Copy_Pu8Value = *((volatile u8*)0x36);
    break;
   case 2:
    *Copy_Pu8Value = *((volatile u8*)0x33);
    break;
   case 3:
    *Copy_Pu8Value = *((volatile u8*)0x30);
    break;
   }
   Local_enuErrorState = ES_OK;
  }
  else
  {
   Local_enuErrorState = ES_OUTOFRANGE;
  }
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }
 return Local_enuErrorState;
}
ES_T DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_u8PortID <= 3 &&
   Copy_u8PinID <= 7 &&
   Copy_u8Value <= 1)
 {
  switch(Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3A) &= ~(1 << Copy_u8PinID);
   *((volatile u8*)0x3A) |= (Copy_u8Value<<Copy_u8PinID);
   break;
  case 1:
   *((volatile u8*)0x37) &= ~(1 << Copy_u8PinID);
   *((volatile u8*)0x37) |= (Copy_u8Value<<Copy_u8PinID);
   break;
  case 2:
   *((volatile u8*)0x34) &= ~(1 << Copy_u8PinID);
   *((volatile u8*)0x34) |= (Copy_u8Value<<Copy_u8PinID);
   break;
  case 3:
   *((volatile u8*)0x31) &= ~(1 << Copy_u8PinID);
   *((volatile u8*)0x31) |= (Copy_u8Value<<Copy_u8PinID);
   break;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }
 return Local_enuErrorState;
}
ES_T DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value)
{
 ES_T Local_enuErrorstate = ES_NOK;

 if (Copy_u8PortID <= 3 &&
   Copy_u8PinID <= 7 &&
   Copy_u8Value <= 1)
 {
  switch (Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3B) &= ~(1<<Copy_u8PinID);
   *((volatile u8*)0x3B) |= (Copy_u8Value << Copy_u8PinID);
   break;
  case 1:
   *((volatile u8*)0x38) &= ~(1<<Copy_u8PinID);
   *((volatile u8*)0x38) |= (Copy_u8Value << Copy_u8PinID);
   break;
  case 2:
   *((volatile u8*)0x35) &= ~(1<<Copy_u8PinID);
   *((volatile u8*)0x35) |= (Copy_u8Value << Copy_u8PinID);
   break;
  case 3:
   *((volatile u8*)0x32) &= ~(1<<Copy_u8PinID);
   *((volatile u8*)0x32) |= (Copy_u8Value << Copy_u8PinID);
   break;
  }
  Local_enuErrorstate = ES_OK;
 }
 else
 {
  Local_enuErrorstate = ES_OUTOFRANGE;
 }

 return Local_enuErrorstate;
}
ES_T DIO_enuToggelPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID)
{
 ES_T Local_enuErrorState = ES_NOK;
 if (Copy_u8PortID <= 3 &&
   Copy_u8PinID <= 7)
 {
  switch (Copy_u8PortID)
  {
  case 0:
   *((volatile u8*)0x3B) ^= (1<<Copy_u8PinID);
   break;
  case 1:
   *((volatile u8*)0x38) ^= (1<<Copy_u8PinID);
   break;
  case 2:
   *((volatile u8*)0x35) ^= (1<<Copy_u8PinID);
   break;
  case 3:
   *((volatile u8*)0x32) ^= (1<<Copy_u8PinID);
   break;
  }
  Local_enuErrorState = ES_OK;
 }
 else
 {
  Local_enuErrorState = ES_OUTOFRANGE;
 }
 return Local_enuErrorState;
}
ES_T DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 * Copy_Pu8Value)
{
 ES_T Local_enuErrorState = ES_NOK;
 if (Copy_Pu8Value != (void*)0)
 {
  if (Copy_u8PortID <= 3 &&
    Copy_u8PinID <= 7)
  {
   switch (Copy_u8PortID)
   {
   case 0:
    *Copy_Pu8Value = ((*((volatile u8*)0x39)>>Copy_u8PinID) &1);
    break;
   case 1:
    *Copy_Pu8Value = ((*((volatile u8*)0x36)>>Copy_u8PinID) &1);
    break;
   case 2:
    *Copy_Pu8Value = ((*((volatile u8*)0x33)>>Copy_u8PinID) &1);
    break;
   case 3:
    *Copy_Pu8Value = ((*((volatile u8*)0x30)>>Copy_u8PinID) &1);
    break;
   }
   Local_enuErrorState = ES_OK;
  }
  else
  {
   Local_enuErrorState = ES_OUTOFRANGE;
  }
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }

 return Local_enuErrorState;
}
