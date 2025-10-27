#include "dio.h"
#include "bit_math.h"
#include "dio_reg.h"

static volatile uint8_t* const g_portRegisters[] = {&PORTA, &PORTB, &PORTC, &PORTD};
static volatile uint8_t* const g_ddrRegisters[]  = {&DDRA, &DDRB, &DDRC, &DDRD};
static volatile uint8_t* const g_pinRegisters[]  = {&PINA, &PINB, &PINC, &PIND};


void dio_setPinDirection(uint8_t portId, uint8_t pinId, uint8_t direction)
{
	/* Input Validation return when out of range*/
	if (portId > PORT_ID_MAX || pinId > PIN_ID_MAX) {
		return;
	}

	if (direction == OUTPUT) {
		SET_BIT( *(g_ddrRegisters[portId]), pinId );
	}
	else if (direction == INPUT) {
		CLEAR_BIT( *(g_ddrRegisters[portId]), pinId );
		CLEAR_BIT( *(g_portRegisters[portId]), pinId ); // Disable pull-up
	}
	else if (direction == INPUT_PULLUP) {
		CLEAR_BIT( *(g_ddrRegisters[portId]), pinId ); // Set as INPUT
		SET_BIT( *(g_portRegisters[portId]), pinId );   // Enable pull-up
	}
}

void dio_writeChannel(uint8_t portId, uint8_t pinId, uint8_t level)
{
	/* Input Validation return when out of range*/
	if (portId > PORT_ID_MAX || pinId > PIN_ID_MAX) {
		return;
	}

	if (level == HIGH) {
		SET_BIT( *(g_portRegisters[portId]), pinId );
	} else {
		CLEAR_BIT( *(g_portRegisters[portId]), pinId );
	}
}

void dio_toggleChannel(uint8_t portId, uint8_t pinId)
{
	/* Input Validation return when out of range*/
	if (portId > PORT_ID_MAX || pinId > PIN_ID_MAX) {
		return;
	}

	TOGGLE_BIT( *(g_portRegisters[portId]), pinId );
}

uint8_t dio_readChannel(uint8_t portId, uint8_t pinId)
{
	/* Input Validation return when out of range*/
	if (portId > PORT_ID_MAX || pinId > PIN_ID_MAX) {
		return LOW; // Return safe default
	}

	return CHECK_BIT( *(g_pinRegisters[portId]), pinId );
}