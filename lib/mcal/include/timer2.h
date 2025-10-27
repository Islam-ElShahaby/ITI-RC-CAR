#ifndef TIMER2_H_
#define TIMER2_H_

#include "std_types.h"
#include "Timer2/timer2_Types.h"

/* --- Function Prototypes --- */

void Timer2_Init(Timer2_Mode_t mode);
void Timer2_Start(Timer2_Clock_t clock);
void Timer2_Stop(void);

void Timer2_SetValue(uint8_t value);
uint8_t Timer2_GetValue(void);

void Timer2_SetCompareValue(uint8_t value);

void Timer2_EnableInterrupt(Timer2_Interrupt_t interrupt);
void Timer2_DisableInterrupt(Timer2_Interrupt_t interrupt);
void Timer2_SetCallback(Timer2_Interrupt_t interrupt, void (*callback)(void));

#endif /* TIMER2_H_ */