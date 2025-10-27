#ifndef MCAL_STD_TYPES_H_
#define MCAL_STD_TYPES_H_

#include <stdint.h>  /* For uint8_t, uint16_t, etc. */
#include <stdbool.h> /* For bool, true, false */
#include <stddef.h>  /* For NULL */

/* Standard return type */
typedef uint8_t Std_ReturnType;

#define E_OK     (0U)
#define E_NOT_OK (1U)

typedef float     f32;
typedef double    f64;


#endif /* MCAL_STD_TYPES_H_ */