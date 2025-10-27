#ifndef DIO_H_
#define DIO_H_

#include "stdint.h"

/*PORT ID*/
#define PORTA_ID	(0)
#define PORTB_ID	(1)
#define PORTC_ID	(2)
#define PORTD_ID	(3)
#define PORT_ID_MAX (3)

/*PINs ID*/
#define PIN0_ID		(0)
#define PIN1_ID		(1)
#define PIN2_ID		(2)
#define PIN3_ID		(3)
#define PIN4_ID		(4)
#define PIN5_ID		(5)
#define PIN6_ID		(6)
#define PIN7_ID		(7)
#define PIN_ID_MAX  (7)

/*Data Direction*/
#define OUTPUT	        (1)
#define INPUT	        (0)
#define INPUT_PULLUP	(2)

/*Level*/
#define HIGH	(1)
#define LOW		(0)

/*Functions Prototype*/

/*Pin direction*/
void dio_setPinDirection(uint8_t portId, uint8_t pinId, uint8_t direction);
/*Write logic to pin*/
void dio_writeChannel(uint8_t portId, uint8_t pinId, uint8_t level);
/*Toggle pin logic*/
void dio_toggleChannel(uint8_t portId, uint8_t pinId);
/*Read logic of pin*/
uint8_t dio_readChannel(uint8_t portId, uint8_t pinId);

#endif /* DIO_H_ */