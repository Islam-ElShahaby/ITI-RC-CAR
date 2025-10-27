#ifndef TIMER0_H_
#define TIMER0_H_

#include "std_types.h"
#include "../src/Timer0/timer0_TYPES.h"

/* --- Function Prototypes --- */

void Timer0_Init(Timer0_Mode_t mode);
void Timer0_Start(Timer0_Clock_t clock);
void Timer0_Stop(void);

void Timer0_SetValue(uint8_t value);
uint8_t Timer0_GetValue(void);

void Timer0_SetCompareValue(uint8_t value);

void Timer0_EnableInterrupt(Timer0_Interrupt_t interrupt);
void Timer0_DisableInterrupt(Timer0_Interrupt_t interrupt);
void Timer0_SetCallback(Timer0_Interrupt_t interrupt, void (*callback)(void));

#endif /* TIMER0_H_ */