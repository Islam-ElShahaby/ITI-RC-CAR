#ifndef TIMER2_TYPES_H_
#define TIMER2_TYPES_H_

#include "std_types.h"

typedef enum
{
    /* TCCR2 [WGM21, WGM20] */
    T2_MODE_NORMAL     = 0x00U,  /* WGM21=0, WGM20=0 */
    T2_MODE_CTC        = 0x08U,  /* WGM21=1, WGM20=0 (Value is 1<<WGM21) */
    T2_MODE_PWM_PHASE  = 0x40U,  /* WGM21=0, WGM20=1 (Value is 1<<WGM20) */
    T2_MODE_PWM_FAST   = 0x48U   /* WGM21=1, WGM20=1 (Values are 1<<WGM21 | 1<<WGM20) */
} Timer2_Mode_t;

typedef enum
{
    /* TCCR2 [CS22, CS21, CS20] */
    T2_CLK_STOP        = 0x00U,  /* CS22=0, CS21=0, CS20=0 */
    T2_CLK_DIV_1       = 0x01U,  /* CS22=0, CS21=0, CS20=1 */
    T2_CLK_DIV_8       = 0x02U,  /* CS22=0, CS21=1, CS20=0 */
    T2_CLK_DIV_32      = 0x03U,  /* CS22=0, CS21=1, CS20=1 */
    T2_CLK_DIV_64      = 0x04U,  /* CS22=1, CS21=0, CS20=0 */
    T2_CLK_DIV_128     = 0x05U,  /* CS22=1, CS21=0, CS20=1 */
    T2_CLK_DIV_256     = 0x06U,  /* CS22=1, CS21=1, CS20=0 */
    T2_CLK_DIV_1024    = 0x07U   /* CS22=1, CS21=1, CS20=1 */
} Timer2_Clock_t;

typedef enum
{
    T2_INT_OVERFLOW,
    T2_INT_COMPARE
} Timer2_Interrupt_t;

#endif /* TIMER2_TYPES_H_ */