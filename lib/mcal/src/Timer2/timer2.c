#include "timer2.h"
#include "timer2_reg.h"
#include "bit_math.h"
#include <avr/interrupt.h>

/* --- File-scope static callback pointers --- */
static volatile void (*g_timer2_ovf_callback)(void) = NULL;
static volatile void (*g_timer2_comp_callback)(void) = NULL;

void Timer2_Init(Timer2_Mode_t mode)
{
    /* Stop timer to configure */
    TCCR2 = 0x00U;
    
    uint8_t tccr2_val = TCCR2;
    tccr2_val &= T2_MODE_MASK; /* Clear WGM bits */
    tccr2_val |= (uint8_t)mode;
    TCCR2 = tccr2_val;
    
    /* Reset counter */
    TCNT2 = 0x00U;
}

void Timer2_Start(Timer2_Clock_t clock)
{
    uint8_t tccr2_val = TCCR2;
    tccr2_val &= T2_CLK_MASK; /* Clear clock bits */
    tccr2_val |= (uint8_t)clock;
    TCCR2 = tccr2_val;
}

void Timer2_Stop(void)
{
    TCCR2 &= T2_CLK_MASK; /* Clear clock bits */
}

void Timer2_SetValue(uint8_t value)
{
    TCNT2 = value;
}

uint8_t Timer2_GetValue(void)
{
    return TCNT2;
}

void Timer2_SetCompareValue(uint8_t value)
{
    OCR2 = value;
}

void Timer2_EnableInterrupt(Timer2_Interrupt_t interrupt)
{
    if (interrupt == T2_INT_OVERFLOW)
    {
        SET_BIT(TIMSK, TOIE2);
    }
    else /* T2_INT_COMPARE */
    {
        SET_BIT(TIMSK, OCIE2);
    }
}

void Timer2_DisableInterrupt(Timer2_Interrupt_t interrupt)
{
    if (interrupt == T2_INT_OVERFLOW)
    {
        CLEAR_BIT(TIMSK, TOIE2);
    }
    else /* T2_INT_COMPARE */
    {
        CLEAR_BIT(TIMSK, OCIE2);
    }
}

void Timer2_SetCallback(Timer2_Interrupt_t interrupt, void (*callback)(void))
{
    if (interrupt == T2_INT_OVERFLOW)
    {
        g_timer2_ovf_callback = callback;
    }
    else /* T2_INT_COMPARE */
    {
        g_timer2_comp_callback = callback;
    }
}

/* --- Interrupt Service Routines --- */

ISR(TIMER2_OVF_vect)
{
    if (g_timer2_ovf_callback != NULL)
    {
        g_timer2_ovf_callback();
    }
}

ISR(TIMER2_COMP_vect)
{
    if (g_timer2_comp_callback != NULL)
    {
        g_timer2_comp_callback();
    }
}