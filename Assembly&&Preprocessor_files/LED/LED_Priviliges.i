# 1 "LED_Priviliges.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "LED_Priviliges.c"






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
# 8 "LED_Priviliges.c" 2
# 1 "../../LIB/errorState.h" 1
# 10 "../../LIB/errorState.h"
typedef enum
{
 ES_NOK,
 ES_OK,
 ES_NULL_POINTER,
 ES_OUTOFRANGE
}ES_T;
# 9 "LED_Priviliges.c" 2

# 1 "LED_Config.h" 1
# 12 "LED_Config.h"
typedef struct
{
 u8 LED_u8PortID ;
 u8 LED_u8PinID ;
 u8 LED_u8Connection ;
 u8 LED_u8InitState;
}LED_T;
# 11 "LED_Priviliges.c" 2
# 1 "LED_Private.h" 1
# 12 "LED_Priviliges.c" 2

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
# 14 "LED_Priviliges.c" 2

ES_T LED_enuInit(LED_T *Copy_AstrLedConfig)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_AstrLedConfig != (void*)0)
 {
  u8 Local_u8Iterator=0;
  for(Local_u8Iterator=0 ; Local_u8Iterator < 3 ; Local_u8Iterator++)
  {
   Local_enuErrorState = DIO_enuSetPinDirection(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,1);
   if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8Connection == 0)
   {
    if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == 1)
    {
     Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,0);
    }
    else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == 0)
    {
     Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,1);
    }
    else
    {
     Local_enuErrorState = ES_OUTOFRANGE;
    }
   }
   else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8Connection == 1)
   {
    if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == 1)
    {
     Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,1);
    }
    else if(Copy_AstrLedConfig[Local_u8Iterator].LED_u8InitState == 0)
    {
     Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Local_u8Iterator].LED_u8PortID ,Copy_AstrLedConfig[Local_u8Iterator].LED_u8PinID,0);
    }
    else
    {
     Local_enuErrorState = ES_OUTOFRANGE;
    }
   }
   else
   {
    Local_enuErrorState = ES_OUTOFRANGE;
   }

  }
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }

 return Local_enuErrorState;
}

ES_T LED_enuTurnOn(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_AstrLedConfig != (void*)0)
 {
  if(Copy_u8LedNum < 3)
  {
   if(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == 0)
   {
    Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,0);
   }
   else if (Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == 1)
   {
    Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,1);
   }
   else
   {
    Local_enuErrorState = ES_OUTOFRANGE;
   }
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

ES_T LED_enuTurnOff(LED_T *Copy_AstrLedConfig , u8 Copy_u8LedNum)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_AstrLedConfig != (void*)0)
 {
  if(Copy_u8LedNum < 3)
  {
   if(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == 0)
   {
    Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,1);
   }
   else if (Copy_AstrLedConfig[Copy_u8LedNum].LED_u8Connection == 1)
   {
    Local_enuErrorState = DIO_enuSetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID ,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,0);
   }
   else
   {
    Local_enuErrorState = ES_OUTOFRANGE;
   }
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

ES_T LED_enuGetState(LED_T *Copy_AstrLedConfig ,u8 Copy_u8LedNum, u8 *Copy_u8LedState)
{
 ES_T Local_enuErrorState = ES_NOK;
    if(Copy_AstrLedConfig != (void*)0 && Copy_u8LedState != (void*)0)
    {
     if(Copy_u8LedNum < 3)
     {
     Local_enuErrorState = DIO_enuGetPinValue(Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PortID,Copy_AstrLedConfig[Copy_u8LedNum].LED_u8PinID,Copy_u8LedState);
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
