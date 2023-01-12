/*
 * my_buttons.c
 *
 *  Created on: Jan 5, 2023
 *      Author: Marko Srpak
 */

#include "main.h"
#include "beerpong.h"


struct MDL_buttons_handler buttons_handler;
GPIO_PinState state;

void MDL_buttons_init(){
	//init GPIO gatea
	for(int i = 0; i < NUM_OF_BUTTONS; i++){
		buttons_handler.buttons[i].gpio = GPIOE;
	}
	//init GPIO pinova
	buttons_handler.buttons[0].gpio_pin = GPIO_PIN_10;
	buttons_handler.buttons[1].gpio_pin = GPIO_PIN_11;
	buttons_handler.buttons[2].gpio_pin = GPIO_PIN_12;
	buttons_handler.buttons[3].gpio_pin = GPIO_PIN_13;

}

void BUTTON_CHECK(int i){

	buttons_handler.buttons[i].button_state = HAL_GPIO_ReadPin(buttons_handler.buttons[i].gpio, buttons_handler.buttons[i].gpio_pin);

	if(buttons_handler.buttons[i].prev_button_state == GPIO_PIN_SET && buttons_handler.buttons[i].button_state == GPIO_PIN_RESET){
		//detected falling edge

	}
	if(buttons_handler.buttons[i].prev_button_state == GPIO_PIN_RESET && buttons_handler.buttons[i].button_state == GPIO_PIN_SET){
		//detected rising edge
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, state); //TESTING
		state = !state; //TESTING
	}
	buttons_handler.buttons[i].prev_button_state = buttons_handler.buttons[i].button_state;
}


void MDL_Buttons_Handler(){
	for(int i = 0; i < NUM_OF_BUTTONS; i++){
		BUTTON_CHECK(i);
	}
}


