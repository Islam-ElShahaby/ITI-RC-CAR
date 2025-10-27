#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#include "std_types.h"

/* --- Timer 1 Registers (16-bit) --- */
/* TCCR1A/B */
#define TCCR1A  (*(volatile uint8_t*)0x4F)
#define TCCR1B  (*(volatile uint8_t*)0x4E)
/* TCNT1 */
#define TCNT1L  (*(volatile uint8_t*)0x4C)
#define TCNT1H  (*(volatile uint8_t*)0x4D)
#define TCNT1   (*(volatile uint16_t*)0x4C) /* 16-bit access */
/* OCR1A */
#define OCR1AL  (*(volatile uint8_t*)0x4A)
#define OCR1AH  (*(volatile uint8_t*)0x4B)
#define OCR1A   (*(volatile uint16_t*)0x4A) /* 16-bit access */
/* OCR1B */
#define OCR1BL  (*(volatile uint8_t*)0x48)
#define OCR1BH  (*(volatile uint8_t*)0x49)
#define OCR1B   (*(volatile uint16_t*)0x48) /* 16-bit access */
/* ICR1 */
#define ICR1L   (*(volatile uint8_t*)0x46)
#define ICR1H   (*(volatile uint8_t*)0x47)
#define ICR1    (*(volatile uint16_t*)0x46) /* 16-bit access */

/* --- Shared Timer Registers --- */
#define TIMSK  (*(volatile uint8_t*)0x59)
#define TIFR   (*(volatile uint8_t*)0x58)

/* --- TCCR1A Bits --- */
#define WGM10  (0U)
#define WGM11  (1U)
#define FOC1B  (2U)
#define FOC1A  (3U)
#define COM1B0 (4U)
#define COM1B1 (5U)
#define COM1A0 (6U)
#define COM1A1 (7U)

/* --- TCCR1B Bits --- */
#define CS10   (0U)
#define CS11   (1U)
#define CS12   (2U)
#define WGM12  (3U)
#define WGM13  (4U)
#define ICES1  (6U)
#define ICNC1  (7U)

/* --- TIMSK Bits --- */
#define TOIE1  (2U)
#define OCIE1B (3U)
#define OCIE1A (4U)
#define TICIE1 (5U)

/* --- TIFR Bits --- */
#define TOV1   (2U)
#define OCF1B  (3U)
#define OCF1A  (4U)
#define ICF1   (5U)

/* --- Bit Masks --- */
#define T1_CLK_MASK (0xF8U) /* 0b11111000 */

#endif /* TIMER1_REG_H_ */