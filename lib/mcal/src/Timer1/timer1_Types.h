#ifndef TIMER1_TYPES_H_
#define TIMER1_TYPES_H_

#include "std_types.h"

typedef enum
{
    /* TCCR1B/TCCR1A [WGM13, WGM12, WGM11, WGM10] */
    T1_MODE_NORMAL          = 0x00U,    /* WGM13:10 = 0000 */
    T1_MODE_CTC_OCR1A       = 0x04U,    /* WGM13:10 = 0100 */
    T1_MODE_FAST_PWM_ICR1   = 0x0EU,    /* WGM13:10 = 1110 */
    T1_MODE_FAST_PWM_OCR1A  = 0x0FU     /* WGM13:10 = 1111 */
} Timer1_Mode_t;

typedef enum
{
    /* TCCR1B [CS12, CS11, CS10] */
    T1_CLK_STOP         = 0x00U,    /* CS10:12 = 000 */
    T1_CLK_DIV_1        = 0x01U,    /* CS10:12 = 001 */
    T1_CLK_DIV_8        = 0x02U,    /* CS10:12 = 010 */
    T1_CLK_DIV_64       = 0x03U,    /* CS10:12 = 011 */
    T1_CLK_DIV_256      = 0x04U,    /* CS10:12 = 100 */
    T1_CLK_DIV_1024     = 0x05U,    /* CS10:12 = 101 */
    T1_CLK_EXT_FALLING  = 0x06U,    /* CS10:12 = 110 */
    T1_CLK_EXT_RISING   = 0x07U     /* CS10:12 = 111 */
} Timer1_Clock_t;

typedef enum
{
    T1_INT_OVERFLOW,
    T1_INT_COMPARE_A,
    T1_INT_COMPARE_B,
    T1_INT_CAPTURE
} Timer1_Interrupt_t;

#endif /* TIMER1_TYPES_H_ */