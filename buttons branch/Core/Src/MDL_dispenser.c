#include "FERpong.h"

uint16_t ml_total = ML_DEFAULT;

GPIO_TypeDef *gpio_Dispenser;
uint16_t pin_Dispenser;

void MDL_dispenser_init(){
	gpio_Dispenser = GPIOG;
	pin_Dispenser = GPIO_PIN_2;
}

void Dispenser(uint8_t ml_total) {
	HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_SET);
	HAL_Delay(ml_total/0.067); //ukupna militraza kroz protok pumpe + t za paljenje pumpe
	HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_RESET);
}

void sumator(uint8_t ml){
	ml_total += ml;
}

void TociPressed(){
	Dispenser(ml_total);
	ml_total = ML_DEFAULT;
}
