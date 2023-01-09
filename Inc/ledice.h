#include "main.h"

#define NUM_OF_LEDS 6

typedef enum MDL_leds_state {
	NEXT_ROUND,
	WAITING,
	SCORED,
	WIN
} MDL_leds_state;

typedef enum LED_number {
	LED_1 = 0,
	LED_2 = 1,
	LED_3 = 2,
	LED_4 = 3,
	LED_5 = 4,
	LED_6 = 5
} LED_number;

void MDL_leds_handler();
