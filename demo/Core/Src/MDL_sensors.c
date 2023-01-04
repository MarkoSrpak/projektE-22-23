/*
 * MDL_sensors.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#include "MDL_sensors.h"
#include "adc.h"

struct MDL_sensors_handler sensors_handler;


void MDL_sensors_init() {
	sensors_handler.sensorsState = GETTING_DATA;

	for (int i = 0; i < NUMBER_OF_SENSORS; i++) {
		sensors_handler.sensors[i].currentState = PASIVE;
//		sensors_handler.sensors[i].gpio_pin
	}

}

void MDL_sensors_handler() {

	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)sensors_handler.buffer, NUMBER_OF_SENSORS);





}


// when DMA finishes transferring data this function is called

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

}

