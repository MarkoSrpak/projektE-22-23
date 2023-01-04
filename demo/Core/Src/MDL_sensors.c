/*
 * MDL_sensors.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#include "MDL_sensors.h"

void MDL_sensors_handler(MDL_sensors_handle *sensorsHandle) {
	int i = 0;

	HAL_ADC_Start_DMA(sensorsHandle->adc_handle, (uint32_t *)sensorsHandle->buffer, NUMBER_OF_SENSORS);

	while (i == 0) {}


	if (buff[0] > 6) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	}

	if (buff[1] > 6) {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_SET);
	} else {
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_RESET);
	}

}



