/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define NUM_OF_LEDS 2

uint8_t LED_Data[NUM_OF_LEDS][4];
int datasentflag = 0;
int led[NUM_OF_LEDS] = {0, 1}; // 2, 3, 4, 5};

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
	datasentflag = 1;
}

void Set_LED(int LEDnum, int Red, int Green, int Blue) {
	LED_Data[LEDnum][0] = LEDnum;
	LED_Data[LEDnum][1] = Red;
	LED_Data[LEDnum][2] = Green;
	LED_Data[LEDnum][3] = Blue;
}

uint16_t pwmData[24*NUM_OF_LEDS + 50];

void Send(void) {
	uint32_t index = 0;
	uint32_t color;

	for (int i = 0; i < NUM_OF_LEDS; i++) {
		color = ((LED_Data[i][1]<<16) | (LED_Data[i][2]<<8) | (LED_Data[i][3]));

		for (int i = 23; i >= 0; i--) {
			if (color&(1<<i)) pwmData[index] = 60;
			else pwmData[index] = 30;
			index++;
		}
	}

	for (int i = 0; i < 50; i++) {
		pwmData[index] = 0;
		index++;
	}

	HAL_TIM_PWM_Start_DMA(&htim1, TIM_CHANNEL_1, (uint32_t *)pwmData, index);
	while (!datasentflag) {};
	datasentflag = 0;
}




void runda(void) {

	for (int i = 0; i < NUM_OF_LEDS - 1; i++) {
		int n = i + rand() / (RAND_MAX / (NUM_OF_LEDS - i) + 1);
	    int pom = led[n];
	    led[n] = led[i];
	    led[i] = pom;
	}

	Set_LED(led[0], 255, 0, 0);
	Set_LED(led[1], 0, 255, 0);
//	Set_LED(led[2], 0, 255, 0);
//	Set_LED(led[3], 0, 0, 255);
//	Set_LED(led[4], 0, 0, 255);
//	Set_LED(led[5], 0, 0, 255);
	Send();

}

void pobjeda(void) {
	for (int i = 0; i < 4; i ++) {
		Set_LED(i%NUM_OF_LEDS, 76, 0, 153);  //ljubicasta
		Set_LED((i+1)%NUM_OF_LEDS, 0, 0, 255);  //plava
		Set_LED((i+2)%NUM_OF_LEDS, 0, 204, 102);  //zelena
		Set_LED((i+3)%NUM_OF_LEDS, 255, 255, 51);  //zuta
		Set_LED((i+4)%NUM_OF_LEDS, 255, 128, 0);  //narancasta
		Set_LED((i+5)%NUM_OF_LEDS, 255, 0, 0);  //crvena
		Send();
	}

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE BEGIN 2 */

  Set_LED(0, 76, 0, 153);
  Set_LED(1, 0, 0, 255);
  Send();
  timer2_wait_millisec(1000);
  Set_LED(0, 0, 0, 255);
  Set_LED(1, 0, 204, 102);
  Send();
  timer2_wait_millisec(1000);
  Set_LED(0, 0, 204, 102);
  Set_LED(1, 255, 255, 51);
  Send();
  timer2_wait_millisec(1000);
  Set_LED(0, 255, 255, 51);
  Set_LED(1, 255, 128, 0);
  Send();
  timer2_wait_millisec(1000);
  Set_LED(0, 255, 128, 0);
  Set_LED(1, 255, 0, 0);
  Send();
  timer2_wait_millisec(1000);
  Set_LED(0, 255, 0, 0);
  Set_LED(1, 76, 0, 153);
  Send();
  timer2_wait_millisec(1000);

//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1000);
//  runda();
//
//  timer2_wait_millisec(1500);
//  pobjeda();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 72;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
