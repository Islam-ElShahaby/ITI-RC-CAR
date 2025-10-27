#ifndef TIMER2_REG_H_
#define TIMER2_REG_H_

#include "std_types.h"

/* --- Timer 2 Registers --- */
#define TCCR2  (*(volatile uint8_t*)0x45)
#define TCNT2  (*(volatile uint8_t*)0x44)
#define OCR2   (*(volatile uint8_t*)0x43)
#define ASSR   (*(volatile uint8_t*)0x42)

/* --- Shared Timer Registers --- */
#define TIMSK  (*(volatile uint8_t*)0x59)
#define TIFR   (*(volatile uint8_t*)0x58)

/* --- TCCR2 Bits --- */
#define CS20   (0U)
#define CS21   (1U)
#define CS22   (2U)
#define WGM21  (3U)
#define COM20  (4U)
#define COM21  (5U)
#define WGM20  (6U)
#define FOC2   (7U)

/* --- TIMSK Bits --- */
#define TOIE2  (6U)
#define OCIE2  (7U)

/* --- TIFR Bits --- */
#define TOV2   (6U)
#define OCF2   (7U)

/* --- ASSR Bits --- */
#define AS2    (3U)

/* --- Bit Masks --- */
#define T2_CLK_MASK     (0xF8U) /* 0b11111000 */
#define T2_MODE_MASK    (0xB7U) /* 0b10110111 */
#define T2_COM_MASK     (0xCFU) /* 0b11001111 */

#endif /* TIMER2_REG_H_ */