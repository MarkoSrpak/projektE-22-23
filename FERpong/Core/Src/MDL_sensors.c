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
#include "MDL_led.h"
//*********************************PRIVATE FUNCTIONS**********************************

void sensors_calculateCurrentData();
void sensors_determineIfSensorsDetectedObject();
void sensors_checkSensorState();
void sensors_calculateCurrentDataForCalibration();
void sensors_calibrateSensors();

//************************************************************************************

//*******************************GLOBAL VARIABLES*************************************

struct MDL_sensors_handler sensors_handler;

//************************************************************************************

//*******************************PUBLIC FUNCTIONS*************************************

void MDL_sensors_init() {
	sensors_handler.state = START_CALIBRATION;
	sensors_handler.ordinalNumOfMeasurement = 0;
	sensors_handler.ordinalNumOfMeasurementForCalibration = 0;

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].currentState = PASIVE;
	}

}

void MDL_sensors_handler() {

	switch (sensors_handler.state) {
	case GETTING_DATA:
		if(sensors_handler.timer == 0) {
			HAL_ADC_Start_DMA(&hadc1, (uint32_t*) sensors_handler.buffer,
			NUM_OF_SENSORS);
			sensors_handler.state = WAITING_FOR_DATA;
		} else {
			sensors_handler.timer--;
		}
		break;
	case WAITING_FOR_DATA:
		__NOP();
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
	case START_CALIBRATION:
		HAL_ADC_Stop(&hadc1);
		HAL_ADC_Start_DMA(&hadc1, (uint32_t*) sensors_handler.buffer,
				NUM_OF_SENSORS);
		sensors_handler.state = WAITING_FOR_CALIBRATION_DATA;
		break;
	case WAITING_FOR_CALIBRATION_DATA:
		__NOP();
		break;
	case CALCULATING_DATA_FOR_CALIBRATION:
		sensors_calculateCurrentDataForCalibration();
		break;
	case CALIBRATING:
		sensors_calibrateSensors();
		break;
	}
}

void MDL_sensors_startSensorCalibration() {
	sensors_handler.state = START_CALIBRATION;
}

//************************************************************************************

//**********************PRIVATE FUNCTION DEFINITIONS**********************************

void sensors_calibrateSensors() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].sensor_threshold =
				sensors_handler.sensors[i].sumOfDistances
						/ NUM_OF_REQUIRED_MEASURMENTS_FOR_CALIBRATION
						- THRESHOLD_REDUCER;
		sensors_handler.sensors[i].sumOfDistances = 0;
	}

	sensors_handler.state = GETTING_DATA;
}

void sensors_calculateCurrentDataForCalibration() {
	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].sumOfDistances += sensors_handler.buffer[i];
	}

	if (++sensors_handler.ordinalNumOfMeasurementForCalibration
			== NUM_OF_REQUIRED_MEASURMENTS_FOR_CALIBRATION) {
		sensors_handler.state = CALIBRATING;
	} else {
		sensors_handler.state = START_CALIBRATION;
	}

}

void sensors_determineIfSensorsDetectedObject() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		if (sensors_handler.sensors[i].sumOfDistances
				/ (NUM_OF_REQUIRED_MEASURMENTS)
				< sensors_handler.sensors[i].sensor_threshold) {
			sensors_handler.sensors[i].currentState = ACTIVE;
		} else {
			sensors_handler.sensors[i].currentState = PASIVE;
		}

		sensors_handler.sensors[i].sumOfDistances = 0;
	}

	sensors_handler.state = CHECKING_SENSOR_STATE;
}

void sensors_checkSensorState() {

	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		if (sensors_handler.sensors[i].currentState == ACTIVE) {

			MDL_leds_scored(i);
			sensors_handler.timer = SENSOR_TIMER;
		}
	}

	sensors_handler.state = GETTING_DATA;
	sensors_handler.ordinalNumOfMeasurement = 0;

}

void sensors_calculateCurrentData() {
	for (int i = 0; i < NUM_OF_SENSORS; i++) {
		sensors_handler.sensors[i].sumOfDistances += sensors_handler.buffer[i];
	}

	if (++sensors_handler.ordinalNumOfMeasurement == NUM_OF_REQUIRED_MEASURMENTS) {
		sensors_handler.state = DETERMINING_SENSOR_STATE;
	} else {
		sensors_handler.state = GETTING_DATA;
	}

}

//************************************************************************************

// when DMA finishes transferring data this function is called

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {

	if (sensors_handler.state == WAITING_FOR_CALIBRATION_DATA) {
		sensors_handler.state = CALCULATING_DATA_FOR_CALIBRATION;
	} else {
		sensors_handler.state = CALCULATING_DATA;
	}
}

