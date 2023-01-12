/*
 * buttons.h
 *
 *  Created on: Jan 5, 2023
 *      Author: Marko Srpak
 */

#ifndef INC_MDL_BUTTONS_H_
#define INC_MDL_BUTTONS_H_
#endif /* INC_MDL_BUTTONS_H_ */


#define NUM_OF_BUTTONS 4
#define HALT_TIME 5

#include "main.h"



extern struct MDL_buttons_handler buttons_handler;


typedef struct MDL_button_handler{
	uint16_t gpio_pin;
	GPIO_TypeDef *gpio;
	GPIO_PinState button_state;
	GPIO_PinState prev_button_state;
}MDL_button_handler;


typedef struct MDL_buttons_handler{
	MDL_button_handler buttons[NUM_OF_BUTTONS];
}MDL_buttons_handler;



// User function prototypes
void MDL_buttons_init();
void BUTTON_CHECK(int i);
void MDL_Buttons_Handler();

