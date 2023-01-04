/*
 * MDL_sensors.h
 *
 *  Created on: Dec 25, 2022
 *      Author: Petar
 */

#ifndef INC_MDL_SENSORS_H_
#define INC_MDL_SENSORS_H_

#define NUMBER_OF_SENSORS 2

#include"main.h"

typedef enum MDL_sensors_sensorState {
	GETTING_DATA,
	CALCULATING_DATA
} MDL_sensors_sensorState;

typedef struct MDL_sensor_handler {
	uint16_t gpio_pin;
	GPIO_PinState currentState;
	GPIO_PinState wantedState;
} MDL_sensor_handle;

typedef struct MDL_sensors_handler {
	MDL_sensors_sensorState sensorsState;
	ADC_HandleTypeDef *adc_handle;
	MDL_sensor_handle sensors[NUMBER_OF_SENSORS];
	volatile uint8_t buffer[NUMBER_OF_SENSORS];
	//trebalo bi definirati kontrolnu varijablu za
	//provjeru da li je dma zavrsio,
	//to bi trebalo s enumom MDL_sensors_sensorState
	//problem kada promijeniti state
	//zato jer je prvotno implementirano kao neka
	//globalna varijabla
	//to bi se moglo preko extern varijable
	//!!!!!!!!

	//jos jedna stvar, gdje definirati tu fju u koju se
	//ulazi prilikom prekida, ovdje ili u dma???

} MDL_sensors_handle;


void MDL_sensors_handler();


#endif /* INC_MDL_SENSORS_H_ */
