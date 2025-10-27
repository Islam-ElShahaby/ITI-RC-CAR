#ifndef EXT_INT_REG_H_
#define EXT_INT_REG_H_

#include "inttypes.h"

#define	EXT_INT_GICR_REG		(*(volatile uint8_t*)0x5B)
#define	EXT_INT_MCUCR_REG		(*(volatile uint8_t*)0x55)
#define	EXT_INT_MCUCSR_REG		(*(volatile uint8_t*)0x54)

#endif /* EXT_INT_REG_H_ */