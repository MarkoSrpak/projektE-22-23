/*
 * MDL_sensors.c
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#include "MDL_sensors.h"
#include "adc.h"

//*********************************PRIVATE FUNCTIONS**********************************

void sensors_calculateCurrentData();
void sensors_determineIfSensorsDetectedObject();
void sensors_sensorIsActivated();

//************************************************************************************

//*******************************GLOBAL VARIABLES*************************************

struct MDL_sensors_handler sensors_handler;

//************************************************************************************

//*******************************PUBLIC FUNCTIONS*************************************

void MDL_sensors_init() {
	sensors_handler.state = GETTING_DATA;
	sensors_handler.ordinalNumOfMeasurment = 0;

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].currentState = PASIVE;
	}

}

void MDL_sensors_handler() {

	switch(sensors_handler.state) {
	case GETTING_DATA:
		HAL_ADC_Start_DMA(&hadc1, (uint32_t *)sensors_handler.buffer, NUM_OF_SENSORS);
		break;
	case CALCULATING_DATA:
		sensors_calculateCurrentData();
		break;
	case DETERMINING_SENSOR_STATE:
		sensors_determineIfSensorsDetectedObject();
		break;

	}
}

//************************************************************************************

//**********************PRIVATE FUNCTION DEFINITIONS**********************************

void sensors_determineIfSensorsDetectedObject() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		if (sensors_handler.sensors[i].sumOfDistances / NUM_OF_REQUIRED_MEASURMENTS > 6) {
			sensors_sensorIsActivated();

		}
	}

}

void sensors_sensorIsActivated() {



}

void sensors_calculateCurrentData() {
	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].sumOfDistances += sensors_handler.buffer[i];
	}

	if (++sensors_handler.ordinalNumOfMeasurment == NUM_OF_REQUIRED_MEASURMENTS) {
		sensors_handler.state = DETERMINING_SENSOR_STATE;
	}
}

//************************************************************************************


// when DMA finishes transferring data this function is called

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
	sensors_handler.state = CALCULATING_DATA;
}

