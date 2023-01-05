#include "beerpong.h"

void Dispenser(uint8_t color) {
	 if (HAL_GPIO_ReadPin(gpio_DispButton, pin_DispButton)) {
		 if (color == RED) {
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_SET);
			 HAL_Delay(1492); // 100 mL
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_RESET);
//			 red = 0;
		 } else if (color == BLUE) {
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_SET);
			 HAL_Delay(746); // 50 mL
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_RESET);
//			 blue = 0;
		 } else if (color == GREEN) {
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_SET);
			 HAL_Delay(373); // 25 mL
			 HAL_GPIO_WritePin(gpio_Dispenser, pin_Dispenser, GPIO_PIN_RESET);
//			 green = 0;
		 } else {
			 // ispiši na LCD "Nije pogođena rupa, ne točim pivo" i onda clear screen
		 }
	 }
}
