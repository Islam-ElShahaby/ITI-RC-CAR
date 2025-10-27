#include "timer1.h"
#include "timer1_reg.h"
#include "bit_math.h"
#include <avr/interrupt.h>
#include <util/atomic.h>

/* --- File-scope static callback pointers --- */
static volatile void (*g_timer1_ovf_callback)(void) = NULL;
static volatile void (*g_timer1_compa_callback)(void) = NULL;
static volatile void (*g_timer1_compb_callback)(void) = NULL;
static volatile void (*g_timer1_capt_callback)(void) = NULL;

void Timer1_Init(Timer1_Mode_t mode)
{
    /* Stop timer to configure */
    TCCR1A = 0x00U;
    TCCR1B = 0x00U;
    
    /* * Mode bits WGM13:10 are split across TCCR1A and TCCR1B.
     * TCCR1A holds WGM11:10
     * TCCR1B holds WGM13:12
     */
    
    uint8_t wgm_val = (uint8_t)mode;

    /* Set WGM11:10 in TCCR1A (bits 0 and 1) */
    if (CHECK_BIT(wgm_val, 0U) == 1U) { SET_BIT(TCCR1A, WGM10); }
    if (CHECK_BIT(wgm_val, 1U) == 1U) { SET_BIT(TCCR1A, WGM11); }
    
    /* Set WGM13:12 in TCCR1B (bits 3 and 4) */
    if (CHECK_BIT(wgm_val, 2U) == 1U) { SET_BIT(TCCR1B, WGM12); }
    if (CHECK_BIT(wgm_val, 3U) == 1U) { SET_BIT(TCCR1B, WGM13); }
    
    /* Reset counter (atomic 16-bit write) */
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        TCNT1 = 0x0000U;
    }
}

void Timer1_Start(Timer1_Clock_t clock)
{
    uint8_t tccr1b_val = TCCR1B;
    tccr1b_val &= T1_CLK_MASK; /* Clear CS bits */
    tccr1b_val |= (uint8_t)clock;
    TCCR1B = tccr1b_val;
}

void Timer1_Stop(void)
{
    TCCR1B &= T1_CLK_MASK; /* Clear CS bits */
}

void Timer1_SetValue(uint16_t value)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        TCNT1 = value;
    }
}

uint16_t Timer1_GetValue(void)
{
    uint16_t val;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        val = TCNT1;
    }
    return val;
}

void Timer1_SetCompareA(uint16_t value)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        OCR1A = value;
    }
}

void Timer1_SetCompareB(uint16_t value)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        OCR1B = value;
    }
}

void Timer1_SetInputCapture(uint16_t value)
{
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        ICR1 = value;
    }
}

uint16_t Timer1_GetInputCapture(void)
{
    uint16_t val;
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
    {
        val = ICR1;
    }
    return val;
}

void Timer1_EnableInterrupt(Timer1_Interrupt_t interrupt)
{
    switch (interrupt)
    {
        case T1_INT_OVERFLOW:
            SET_BIT(TIMSK, TOIE1);
            break;
        case T1_INT_COMPARE_A:
            SET_BIT(TIMSK, OCIE1A);
            break;
        case T1_INT_COMPARE_B:
            SET_BIT(TIMSK, OCIE1B);
            break;
        case T1_INT_CAPTURE:
            SET_BIT(TIMSK, TICIE1);
            break;
        default:
            /* Should not happen */
            break;
    }
}

void Timer1_DisableInterrupt(Timer1_Interrupt_t interrupt)
{
    switch (interrupt)
    {
        case T1_INT_OVERFLOW:
            CLEAR_BIT(TIMSK, TOIE1);
            break;
        case T1_INT_COMPARE_A:
            CLEAR_BIT(TIMSK, OCIE1A);
            break;
        case T1_INT_COMPARE_B:
            CLEAR_BIT(TIMSK, OCIE1B);
            break;
        case T1_INT_CAPTURE:
            CLEAR_BIT(TIMSK, TICIE1);
            break;
        default:
            /* Should not happen */
            break;
    }
}

void Timer1_SetCallback(Timer1_Interrupt_t interrupt, void (*callback)(void))
{
    switch (interrupt)
    {
        case T1_INT_OVERFLOW:
            g_timer1_ovf_callback = callback;
            break;
        case T1_INT_COMPARE_A:
            g_timer1_compa_callback = callback;
            break;
        case T1_INT_COMPARE_B:
            g_timer1_compb_callback = callback;
            break;
        case T1_INT_CAPTURE:
            g_timer1_capt_callback = callback;
            break;
        default:
            /* Should not happen */
            break;
    }
}

/* --- Interrupt Service Routines --- */

ISR(TIMER1_OVF_vect)
{
    if (g_timer1_ovf_callback != NULL)
    {
        g_timer1_ovf_callback();
    }
}

ISR(TIMER1_COMPA_vect)
{
    if (g_timer1_compa_callback != NULL)
    {
        g_timer1_compa_callback();
    }
}

ISR(TIMER1_COMPB_vect)
{
    if (g_timer1_compb_callback != NULL)
    {
        g_timer1_compb_callback();
    }
}

ISR(TIMER1_CAPT_vect)
{
    if (g_timer1_capt_callback != NULL)
    {
        g_timer1_capt_callback();
    }
}