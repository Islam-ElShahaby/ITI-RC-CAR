#ifndef TIMER0_REG_H_
#define TIMER0_REG_H_

#include "std_types.h"

/* --- Timer 0 Registers --- */
#define TCCR0  (*(volatile uint8_t*)0x53)
#define TCNT0  (*(volatile uint8_t*)0x52)
#define OCR0   (*(volatile uint8_t*)0x5C)

/* --- Shared Timer Registers --- */
#define TIMSK  (*(volatile uint8_t*)0x59)
#define TIFR   (*(volatile uint8_t*)0x58)

/* --- TCCR0 Bits --- */
#define CS00   (0U)
#define CS01   (1U)
#define CS02   (2U)
#define WGM01  (3U)
#define COM00  (4U)
#define COM01  (5U)
#define WGM00  (6U)
#define FOC0   (7U)

/* --- TIMSK Bits --- */
#define TOIE0  (0U)
#define OCIE0  (1U)

/* --- TIFR Bits --- */
#define TOV0   (0U)
#define OCF0   (1U)

/* --- Bit Masks --- */
#define T0_CLK_MASK     (0xF8U) /* 0b11111000 */
#define T0_MODE_MASK    (0xB7U) /* 0b10110111 */
#define T0_COM_MASK     (0xCFU) /* 0b11001111 */

#endif /* TIMER0_REG_H_ */