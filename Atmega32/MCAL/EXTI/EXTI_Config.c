/*
 * EXTI_Config.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */
#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include "EXTI_Private.h"
#include "EXTI_Config.h"
/*
* ==============================================================================================
* 								External interrupt Pin Configuration.
* ==============================================================================================
*/
EXTI_T EXTI_AstrEXTIconfig[3]=
{
		{INT_DEAVTIVE},          	 //INT0
		{INT_ACTIVE,FALLING_EDGE},            			     //INT1
		{INT_DEAVTIVE},            	             //INT2

};


