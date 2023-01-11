/*
 * MDL_sensors.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#include "main.h"
#include "MDL_sensors.h"
#include "adc.h"
#include "gpio.h"

//*********************************PRIVATE FUNCTIONS**********************************

void sensors_calculateCurrentData();
void sensors_determineIfSensorsDetectedObject();
void sensors_checkSensorState();

//************************************************************************************

//*******************************GLOBAL VARIABLES*************************************

struct MDL_sensors_handler sensors_handler;

//************************************************************************************

//*******************************PUBLIC FUNCTIONS*************************************

void MDL_sensors_init() {
	sensors_handler.state = GETTING_DATA;
	sensors_handler.ordinalNumOfMeasurment = 0;

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].currentState = GPIO_PIN_RESET;
		sensors_handler.sensors[i].wantedState = GPIO_PIN_RESET;
	}

	sensors_handler.sensors[0].gpio_pin = GPIO_PIN_13;
	sensors_handler.sensors[1].gpio_pin = GPIO_PIN_15;
	sensors_handler.sensors[2].gpio_pin = GPIO_PIN_13;
	sensors_handler.sensors[3].gpio_pin = GPIO_PIN_15;
	sensors_handler.sensors[4].gpio_pin = GPIO_PIN_13;
	sensors_handler.sensors[5].gpio_pin = GPIO_PIN_15;
}

void MDL_sensors_handler() {

	switch(sensors_handler.state) {
	case GETTING_DATA:
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)sensors_handler.buffer, NUM_OF_SENSORS);
		sensors_handler.state = WAITING_FOR_DATA;
		break;
	case WAITING_FOR_DATA:
//		__NOP();
		break;
	case CALCULATING_DATA:
		sensors_calculateCurrentData();
		break;
	case DETERMINING_SENSOR_STATE:
		sensors_determineIfSensorsDetectedObject();
		break;
	case CHECKING_SENSOR_STATE:
		sensors_checkSensorState();
		break;
	}
}

//************************************************************************************

//**********************PRIVATE FUNCTION DEFINITIONS**********************************

void sensors_determineIfSensorsDetectedObject() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		if (sensors_handler.sensors[i].sumOfDistances / NUM_OF_REQUIRED_MEASURMENTS < SENSOR_THRESHOLD) {
			sensors_handler.sensors[i].wantedState = GPIO_PIN_SET;
		} else {
			sensors_handler.sensors[i].wantedState = GPIO_PIN_RESET;
		}

		sensors_handler.sensors[i].sumOfDistances = 0;
	}

	sensors_handler.state = CHECKING_SENSOR_STATE;
}

void sensors_checkSensorState() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		if(sensors_handler.sensors[i].currentState != sensors_handler.sensors[i].wantedState) {
			HAL_GPIO_WritePin(GPIOG, sensors_handler.sensors[i].gpio_pin , sensors_handler.sensors[i].wantedState);
			sensors_handler.sensors[i].currentState = sensors_handler.sensors[i].wantedState;
		}
	}

	sensors_handler.state = GETTING_DATA;
	sensors_handler.ordinalNumOfMeasurment = 0;

}

void sensors_calculateCurrentData() {
	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].sumOfDistances += sensors_handler.buffer[i];
	}

	if (++sensors_handler.ordinalNumOfMeasurment == NUM_OF_REQUIRED_MEASURMENTS) {
		sensors_handler.state = DETERMINING_SENSOR_STATE;
	} else {
		sensors_handler.state = GETTING_DATA;
	}

}

//************************************************************************************

// when DMA finishes transferring data this function is called

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	sensors_handler.state = CALCULATING_DATA;
}

