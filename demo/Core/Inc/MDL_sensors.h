/*
 * MDL_sensors.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#ifndef INC_MDL_SENSORS_H_
#define INC_MDL_SENSORS_H_

#define NUM_OF_SENSORS 2
#define NUM_OF_REQUIRED_MEASURMENTS 5

#include"main.h"

extern struct MDL_sensors_handler sensors_handler;

typedef enum MDL_sensors_sensorsState {
	GETTING_DATA,
	CALCULATING_DATA,
	DETERMINING_SENSOR_STATE,
	CHECKING_SENSOR_STATE
} MDL_sensors_sensorsState;

typedef enum MDL_sensors_sensorState {
	ACTIVE,
	PASIVE
} MDL_sensors_sensorState;

typedef struct MDL_sensor_handler {
	uint16_t gpio_pin;
	GPIO_PinState currentState;
	GPIO_PinState wantedState;
	uint8_t sumOfDistances;
} MDL_sensor_handle;

typedef struct MDL_sensors_handler {
	MDL_sensors_sensorsState state;
	MDL_sensor_handle sensors[NUM_OF_SENSORS];
	volatile uint16_t buffer[NUM_OF_SENSORS];
	uint8_t ordinalNumOfMeasurment;

} MDL_sensors_handle;

void MDL_sensors_init();
void MDL_sensors_handler();


#endif /* INC_MDL_SENSORS_H_ */
