#ifndef TIMER0_TYPES_H_
#define TIMER0_TYPES_H_
#include "timer0_REG.h"

typedef enum
{
    /* TCCR0 [WGM01, WGM00] */
    T0_MODE_NORMAL     = 0x00U,  /* WGM01=0, WGM00=0 */
    T0_MODE_CTC        = 0x08U,  /* WGM01=1, WGM00=0 (Value is 1<<WGM01) */
    T0_MODE_PWM_PHASE  = 0x40U,  /* WGM01=0, WGM00=1 (Value is 1<<WGM00) */
    T0_MODE_PWM_FAST   = 0x48U   /* WGM01=1, WGM00=1 (Values are 1<<WGM01 | 1<<WGM00) */
} Timer0_Mode_t;

typedef enum
{
    /* TCCR0 [CS02, CS01, CS00] */
    T0_CLK_STOP        = 0x00U,  /* CS02=0, CS01=0, CS00=0 */
    T0_CLK_DIV_1       = 0x01U,  /* CS02=0, CS01=0, CS00=1 */
    T0_CLK_DIV_8       = 0x02U,  /* CS02=0, CS01=1, CS00=0 */
    T0_CLK_DIV_64      = 0x03U,  /* CS02=0, CS01=1, CS00=1 */
    T0_CLK_DIV_256     = 0x04U,  /* CS02=1, CS01=0, CS00=0 */
    T0_CLK_DIV_1024    = 0x05U,  /* CS02=1, CS01=0, CS00=1 */
    T0_CLK_EXT_FALLING = 0x06U,  /* CS02=1, CS01=1, CS00=0 */
    T0_CLK_EXT_RISING  = 0x07U   /* CS02=1, CS01=1, CS00=1 */
} Timer0_Clock_t;

typedef enum
{
    T0_INT_OVERFLOW,
    T0_INT_COMPARE
} Timer0_Interrupt_t;
#endif