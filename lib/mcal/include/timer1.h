#ifndef TIMER1_H_
#define TIMER1_H_

#include "std_types.h"
#include "Timer1/timer1_Types.h"

/* --- Function Prototypes --- */

void Timer1_Init(Timer1_Mode_t mode);
void Timer1_Start(Timer1_Clock_t clock);
void Timer1_Stop(void);

void Timer1_SetValue(uint16_t value);
uint16_t Timer1_GetValue(void);

void Timer1_SetCompareA(uint16_t value);
void Timer1_SetCompareB(uint16_t value);
void Timer1_SetInputCapture(uint16_t value);

uint16_t Timer1_GetInputCapture(void);

void Timer1_EnableInterrupt(Timer1_Interrupt_t interrupt);
void Timer1_DisableInterrupt(Timer1_Interrupt_t interrupt);
void Timer1_SetCallback(Timer1_Interrupt_t interrupt, void (*callback)(void));

#endif /* TIMER1_H_ */