# 1 "Switch_Program.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "Switch_Program.c"







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
# 9 "Switch_Program.c" 2
# 1 "../../LIB/errorState.h" 1
# 10 "../../LIB/errorState.h"
typedef enum
{
 ES_NOK,
 ES_OK,
 ES_NULL_POINTER,
 ES_OUTOFRANGE
}ES_T;
# 10 "Switch_Program.c" 2

# 1 "Switch_Private.h" 1
# 12 "Switch_Program.c" 2
# 1 "Switch_Config.h" 1
# 12 "Switch_Config.h"
typedef struct
{
 u8 SW_PortID;
 u8 SW_PinID;
 u8 SW_Status;
}SW_T;
# 13 "Switch_Program.c" 2

# 1 "../../MCAL/DIO/DIO_Interface.h" 1
# 34 "../../MCAL/DIO/DIO_Interface.h"
 ES_T DIO_enuInit(void);

 ES_T DIO_enuSetPortDirection(u8 Copy_u8PortID , u8 Copy_u8Value);

 ES_T DIO_enuSetPortValue(u8 Copy_u8PortID , u8 Copy_u8Value);

 ES_T DIO_enuTogglePortValue(u8 Copy_u8PortID);

 ES_T DIO_enuGetPortValue(u8 Copy_u8PortID , u8 * Copy_Pu8Value);

 ES_T DIO_enuSetPinDirection(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

 ES_T DIO_enuSetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 Copy_u8Value);

 ES_T DIO_enuToggelPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID);

 ES_T DIO_enuGetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID ,u8 * Copy_Pu8Value);
# 15 "Switch_Program.c" 2

ES_T SW_enuInit(SW_T * Copy_PstrSwState)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_PstrSwState != (void*)0)
 {
  u8 Local_u8Iterator = 0;
  for(Local_u8Iterator = 0 ; Local_u8Iterator < 3 ; Local_u8Iterator++)
  {
   Local_enuErrorState = DIO_enuSetPinDirection(Copy_PstrSwState[Local_u8Iterator].SW_PortID ,Copy_PstrSwState[Local_u8Iterator].SW_PinID,0);
   Local_enuErrorState = DIO_enuSetPinValue(Copy_PstrSwState[Local_u8Iterator].SW_PortID ,Copy_PstrSwState[Local_u8Iterator].SW_PinID,Copy_PstrSwState[Local_u8Iterator].SW_Status);

  }
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }

 return Local_enuErrorState;
}

ES_T SW_enuGetState(SW_T * Copy_PstrSwState , u8 * Copy_Pu8SwState)
{
 ES_T Local_enuErrorState = ES_NOK;
 if(Copy_PstrSwState != (void*)0 && Copy_Pu8SwState != (void*)0)
 {
   Local_enuErrorState = DIO_enuGetPinValue(Copy_PstrSwState->SW_PortID ,Copy_PstrSwState->SW_PinID , Copy_Pu8SwState);
 }
 else
 {
  Local_enuErrorState = ES_NULL_POINTER;
 }

 return Local_enuErrorState;
}
