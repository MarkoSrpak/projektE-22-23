#include "main.h"

#define NUM_OF_LEDS 6

typedef enum MDL_leds_state {
	NEXT_ROUND,
	WAITING,
	SCORED,
	WIN
} MDL_leds_state;

typedef enum LED_sentStatus {
	TRANSFER_FINISHED,
	TRANSFER_NOT_FINISHED,

} LED_sentStatus;

typedef enum LED_number {
	LED_1 = 0,
	LED_2 = 1,
	LED_3 = 2,
	LED_4 = 3,
	LED_5 = 4,
	LED_6 = 5
} LED_number;

typedef struct LED_handler {
	LED_sentStatus datasentflag;
	uint8_t LED_Data[NUM_OF_LEDS][4];
	MDL_leds_state state;
	uint16_t pwmData[24 * NUM_OF_LEDS + 50];
	uint8_t led[NUM_OF_LEDS];
} LED_handler;

void MDL_leds_handler();
void MDL_leds_init();
void MDL_leds_scored(uint8_t sensorNum);
