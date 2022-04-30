/*
 * GIE_Program.c
 *
 *  Created on: Sep 9, 2021
 *      Author: Ahmed Maged
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/errorState.h"

#include"GIE_Private.h"

void GIE_enuInit(void)
{
	SREG |= (BIT_MASKING << BIT_7);
}

void GIE_enuEnable(void)
{
	SREG |= (BIT_MASKING << BIT_7);

}

void GIE_enuDisable(void)
{
	SREG &=~(BIT_MASKING << BIT_7);

}
