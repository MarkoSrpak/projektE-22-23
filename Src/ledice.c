#include "main.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"
#include "ledice.h"

void Set_LED(uint8_t LEDnum, uint8_t Red, uint8_t Green, uint_8 Blue);
void Send();
void Next_round(void);
void Scored(uint8_t Sensor_num);
void Win(void);


uint8_t LED_Data[NUM_OF_LEDS][4];
uint8_t datasentflag = 0;
uint8_t led[NUM_OF_LEDS] = {0, 1, 2, 3, 4, 5};
uint16_t pwmData[24 * NUM_OF_LEDS + 50];

void MDL_leds_handler() {

	switch(MDL_led_state) {
	case NEXT_ROUND:
		// if pritisnut start, pritisnut next player ili nakon tri pogotka
		Next_round();
		MDL_leds_state = WAITING;
	case WAITING:
		break;
	case SCORED:
		// if pogodena rupa
		SCORED(Sensor_num);
		MDL_leds_state = WAITING;
	case WIN:
		// if netko pobijedio
		Win();
		MDL_leds_state = WAITING;
	}
}

void Set_LED(uint8_t LEDnum, uint8_t Red, uint8_t Green, uint_8 Blue) {
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Red;
	LED_Data[LEDnum][2] = Green;
	LED_Data[LEDnum][3] = Blue;
}

void Send(void) {
	uint32_t index = 0;
	uint32_t color;

	for (uint8_t i = 0; i < NUM_OF_LEDS; i++) {
		color = ((LED_Data[i][1] << 16) | (LED_Data[i][2] << 8) | (LED_Data[i][3]));

		for (uint8_t i = 23; i >= 0; i--) {
			if (color & (1 << i))
				pwmData[index] = 60;
			else
				pwmData[index] = 30;
			index++;
		}
	}

	for (uint8_t i = 0; i < 50; i++) {
		pwmData[index] = 0;
		index++;
	}

	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t*) pwmData, index);
	while (!datasentflag) {
	};
	datasentflag = 0;
}

void Next_round(void) {

	for (uint8_t i = 0; i < NUM_OF_LEDS - 1; i++) {
		uint8_t n = i + rand() / (RAND_MAX / (NUM_OF_LEDS - i) + 1);
		uint8_t pom = led[n];
		led[n] = led[i];
		led[i] = pom;
	}

	Set_LED(LED_1, 0, 0, 0);
	Set_LED(LED_2, 0, 0, 0);
	Set_LED(LED_3, 0, 0, 0);
	Set_LED(LED_4, 0, 0, 0);
	Set_LED(LED_5, 0, 0, 0);
	Set_LED(LED_6, 0, 0, 0);
	Send();
	timer2_wait_millisec(1000);

	Set_LED(led[0], 255, 0, 0);
	Set_LED(led[1], 0, 255, 0);
	Set_LED(led[2], 0, 255, 0);
	Set_LED(led[3], 0, 0, 255);
	Set_LED(led[4], 0, 0, 255);
	Set_LED(led[5], 0, 0, 255);
	Send();

}

void Scored(uint8_t Sensor_num) {
	uint8_t index;
	for (uint8_t i = 0; i < NUM_OF_LEDS; i++) {
		if (led[i] == Sensor_num) index = i;
	}

	for (uint8_t j = 0; j < 3; j++) {
		Set_LED(br, 0, 0, 0);
		Send();
		timer2_wait_millisec(100);
		if (index == 0) Set_LED(Sensor_num, 255, 0, 0);
		else if (index == 1 || index == 2) Set_LED(Sensor_num, 0, 255, 0);
		else Set_LED(Sensor_num, 0, 0, 255);
		Send();
		timer2_wait_millisec(100);
	}

}


void Win(void) {

	Set_LED(LED_1, 0, 0, 0);
	Set_LED(LED_2, 0, 0, 0);
	Set_LED(LED_3, 0, 0, 0);
	Set_LED(LED_4, 0, 0, 0);
	Set_LED(LED_5, 0, 0, 0);
	Set_LED(LED_6, 0, 0, 0);
	Send();
	timer2_wait_millisec(500);

	for (uint8_t i = 0; i < 4*NUM_OF_LEDS; i++) {
		Set_LED(i % NUM_OF_LEDS, 142, 0, 142);  //ljubicasta
		Set_LED((i + 1) % NUM_OF_LEDS, 0, 0, 255);  //plava
		Set_LED((i + 2) % NUM_OF_LEDS, 0, 255, 180);  //zelena
		Set_LED((i + 3) % NUM_OF_LEDS, 255, 255, 0);  //zuta
		Set_LED((i + 4) % NUM_OF_LEDS, 255, 173, 51);  //narancasta
		Set_LED((i + 5) % NUM_OF_LEDS, 255, 0, 0);  //crvena
		Send();
		timer2_wait_millisec(100);
		Set_LED(i % NUM_OF_LEDS, 102, 0, 255);
		Set_LED((i + 1) % NUM_OF_LEDS, 0, 153, 255);
		Set_LED((i + 2) % NUM_OF_LEDS, 191, 255, 128);
		Set_LED((i + 3) % NUM_OF_LEDS, 255, 197, 20);
		Set_LED((i + 4) % NUM_OF_LEDS, 255, 102, 0);
		Set_LED((i + 5) % NUM_OF_LEDS, 153, 0, 51);
		Send();
		timer2_wait_millisec(100);
	}

}



void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
	datasentflag = 1;
}
