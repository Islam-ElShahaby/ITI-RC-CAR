#ifndef HCSR04_MUX_H_
#define HCSR04_MUX_H_

#include "std_types.h"
#include "dio.h"


/* Define the single interrupt pin for the Mux's output */
#define HCSR04_ECHO_PORT_ID  PORTD_ID
#define HCSR04_ECHO_INT_PIN_ID   PIN2_ID   
#define HCSR04_ECHO_INT_VECT INT0_vect

/* Define the Mux select pins (S0, S1, S2 for up to 8 sensors) */
#define HCSR04_MUX_PORT_ID   PORTC_ID
#define HCSR04_MUX_S0_PIN_ID PIN0_ID
#define HCSR04_MUX_S1_PIN_ID PIN1_ID
#define HCSR04_MUX_S2_PIN_ID PIN2_ID


/* --- PUBLIC TYPES --- */

/* The "object" struct for a single HC-SR04 sensor instance. */
typedef struct Hcsr04Sensor_t
{
    /* --- Configuration (set by InitObject) --- */
    uint8_t trig_port_id;
    uint8_t trig_pin_id;
    uint8_t mux_select_value; /* The value (0-7) for the mux select lines */
    
    /* --- State (managed by driver) --- */
    volatile uint16_t last_distance_cm;
    volatile bool is_data_ready;
    
} Hcsr04Sensor_t;


/* --- PUBLIC FUNCTION PROTOTYPES ---  */

/* Initializes the shared hardware (Timer0, Mux pins, and single Interrupt). */
void HCSR04_GlobalInit(void);

/* Initializes a specific sensor "object". */
void HCSR04_InitObject(Hcsr04Sensor_t* sensor,
                       uint8_t trig_port_id,
                       uint8_t trig_pin_id,
                       uint8_t mux_select_value);

/* Starts a new distance measurement on a specific sensor. */
bool HCSR04_StartMeasurement(Hcsr04Sensor_t* sensor);

/* @brief Checks if a new measurement is complete for a specific sensor. */
bool HCSR04_IsDataReady(Hcsr04Sensor_t* sensor);

/* Gets the last measured distance in centimeters for a specific sensor. */
uint16_t HCSR04_GetDistanceCm(Hcsr04Sensor_t* sensor);

#endif /* HCSR04_MUX_H_ */