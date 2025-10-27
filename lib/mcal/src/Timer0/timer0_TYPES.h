#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_
#include "timer0_REG.h"
typedef enum
{
    T0_MODE_NORMAL     = 0x00U,
    T0_MODE_PWM_PHASE  = (1U << WGM00),
    T0_MODE_CTC        = (1U << WGM01),
    T0_MODE_PWM_FAST   = (1U << WGM00) | (1U << WGM01)
} Timer0_Mode_t;

typedef enum
{
    T0_CLK_STOP        = 0x00U,
    T0_CLK_DIV_1       = (1U << CS00),
    T0_CLK_DIV_8       = (1U << CS01),
    T0_CLK_DIV_64      = (1U << CS00) | (1U << CS01),
    T0_CLK_DIV_256     = (1U << CS02),
    T0_CLK_DIV_1024    = (1U << CS02) | (1U << CS00),
    T0_CLK_EXT_FALLING = (1U << CS02) | (1U << CS01),
    T0_CLK_EXT_RISING  = (1U << CS02) | (1U << CS01) | (1U << CS00)
} Timer0_Clock_t;

typedef enum
{
    T0_INT_OVERFLOW,
    T0_INT_COMPARE
} Timer0_Interrupt_t;
#endif