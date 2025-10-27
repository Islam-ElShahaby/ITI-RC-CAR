#include "timer0.h"
#include "timer0_TYPES.h"
#include <avr/interrupt.h>


/* --- File-scope static callback pointers --- */
static volatile void (*g_timer0_ovf_callback)(void) = NULL;
static volatile void (*g_timer0_comp_callback)(void) = NULL;

void Timer0_Init(Timer0_Mode_t mode)
{
    /* Stop timer to configure */
    TCCR0 = 0x00U;
    
    /* Set mode */
    uint8_t tccr0_val = TCCR0;
    tccr0_val &= T0_MODE_MASK; /* Clear WGM bits */
    tccr0_val |= (uint8_t)mode;
    TCCR0 = tccr0_val;
    
    /* Reset counter */
    TCNT0 = 0x00U;
}

void Timer0_Start(Timer0_Clock_t clock)
{
    uint8_t tccr0_val = TCCR0;
    tccr0_val &= T0_CLK_MASK; /* Clear clock bits */
    tccr0_val |= (uint8_t)clock;
    TCCR0 = tccr0_val;
}

void Timer0_Stop(void)
{
    TCCR0 &= T0_CLK_MASK; /* Clear clock bits */
}

void Timer0_SetValue(uint8_t value)
{
    TCNT0 = value;
}

uint8_t Timer0_GetValue(void)
{
    return TCNT0;
}

void Timer0_SetCompareValue(uint8_t value)
{
    OCR0 = value;
}

void Timer0_EnableInterrupt(Timer0_Interrupt_t interrupt)
{
    if (interrupt == T0_INT_OVERFLOW)
    {
        TIMSK |= (1U << TOIE0);
    }
    else /* T0_INT_COMPARE */
    {
        TIMSK |= (1U << OCIE0);
    }
}

void Timer0_DisableInterrupt(Timer0_Interrupt_t interrupt)
{
    if (interrupt == T0_INT_OVERFLOW)
    {
        TIMSK &= ~(1U << TOIE0);
    }
    else /* T0_INT_COMPARE */
    {
        TIMSK &= ~(1U << OCIE0);
    }
}

void Timer0_SetCallback(Timer0_Interrupt_t interrupt, void (*callback)(void))
{
    if (interrupt == T0_INT_OVERFLOW)
    {
        g_timer0_ovf_callback = callback;
    }
    else /* T0_INT_COMPARE */
    {
        g_timer0_comp_callback = callback;
    }
}

/* --- Interrupt Service Routines --- */

ISR(TIMER0_OVF_vect)
{
    if (g_timer0_ovf_callback != NULL)
    {
        g_timer0_ovf_callback();
    }
}

ISR(TIMER0_COMP_vect)
{
    if (g_timer0_comp_callback != NULL)
    {
        g_timer0_comp_callback();
    }
}