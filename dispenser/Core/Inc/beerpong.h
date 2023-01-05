#include "main.h"

// definicije GPIO pinova
extern GPIO_TypeDef *gpio_Dispenser;
extern GPIO_TypeDef *gpio_DispButton;
extern GPIO_TypeDef *gpio_Green;
extern GPIO_TypeDef *gpio_Red;
extern uint16_t pin_Dispenser;
extern uint16_t pin_DispButton;
extern uint16_t pin_Green;
extern uint16_t pin_Red;

//lokalne varijable
enum colorCode {
	RED,
	BLUE,
	GREEN
};

// prototipi funkcija
void Dispenser(uint8_t color);
