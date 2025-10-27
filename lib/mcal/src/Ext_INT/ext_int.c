#include "ext_int.h"
#include "bit_math.h"

static volatile void (*int0ClbkPtr)(void) = NULL;
static volatile void (*int1ClbkPtr)(void) = NULL;
static volatile void (*int2ClbkPtr)(void) = NULL;

void extINT_enable(uint8_t interruptId)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT0_EN_BIT);
		break;
		
		case EXT_INT1_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT1_EN_BIT);
		break;
		
		case EXT_INT2_ID:
			SET_BIT(EXT_INT_GICR_REG,GICR_EXT_INT2_EN_BIT);
		break;

		default:
		break;
	}
}

void extINT_disable(uint8_t interruptId)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT0_EN_BIT);
		break;
		
		case EXT_INT1_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT1_EN_BIT);
		break;
		
		case EXT_INT2_ID:
			CLEAR_BIT(EXT_INT_GICR_REG,GICR_EXT_INT2_EN_BIT);
		break;
	}
}

void extINT_setSenseControl(uint8_t interruptId, uint8_t senseControl)
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			// 1. Clear the two ISC0 bits (bits 0 and 1)
			EXT_INT_MCUCR_REG &= ~((1 << MCUCR_ISC00_BIT_NO) | (1 << MCUCR_ISC01_BIT_NO));
			
			// 2. Set the new sense control bits
			EXT_INT_MCUCR_REG |= (senseControl << MCUCR_ISC00_BIT_NO);	

			break;

		case EXT_INT1_ID:
			// 1. Clear the two ISC1 bits (bits 2 and 3)
			EXT_INT_MCUCR_REG &= ~((1 << MCUCR_ISC10_BIT_NO) | (1 << MCUCR_ISC11_BIT_NO));

			// 2. Set the new sense control bits
			EXT_INT_MCUCR_REG |= (senseControl << MCUCR_ISC10_BIT_NO);
		break;
		
		case EXT_INT2_ID:
			if (senseControl == FALLING_EDGE)
			{
				CLEAR_BIT(EXT_INT_MCUCSR_REG,MCUCSR_ISC2_BIT_NO);
			}
			else if (senseControl == RISING_EDGE)
			{
				SET_BIT(EXT_INT_MCUCSR_REG,MCUCSR_ISC2_BIT_NO);
			}
			else
			{
				/*Do Nothing*/
			}
		break;
		default:
		break;
	}
}

void extINT_setCallBack(uint8_t interruptId, void(*fptr)(void))
{
	switch (interruptId)
	{
		case EXT_INT0_ID:
			int0ClbkPtr = fptr;
		break;
		
		case EXT_INT1_ID:
			int1ClbkPtr = fptr;
		break;
		
		case EXT_INT2_ID:
			int2ClbkPtr = fptr;
		break;
	}
}

ISR(INT0_vect)
{
	if (int0ClbkPtr != NULL)
	{
		int0ClbkPtr();
	}
}

ISR(INT1_vect)
{
	if (int1ClbkPtr != NULL)
	{
		int1ClbkPtr();
	}
}

ISR(INT2_vect)
{
	if (int2ClbkPtr != NULL)
	{
		int2ClbkPtr();
	}
}