/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define A0_Pin GPIO_PIN_0
#define A0_GPIO_Port GPIOF
#define A1_Pin GPIO_PIN_1
#define A1_GPIO_Port GPIOF
#define A2_Pin GPIO_PIN_2
#define A2_GPIO_Port GPIOF
#define A3_Pin GPIO_PIN_3
#define A3_GPIO_Port GPIOF
#define A4_Pin GPIO_PIN_4
#define A4_GPIO_Port GPIOF
#define A5_Pin GPIO_PIN_5
#define A5_GPIO_Port GPIOF
#define SPI5_SCK_Pin GPIO_PIN_7
#define SPI5_SCK_GPIO_Port GPIOF
#define SPI5_MISO_Pin GPIO_PIN_8
#define SPI5_MISO_GPIO_Port GPIOF
#define SPI5_MOSI_Pin GPIO_PIN_9
#define SPI5_MOSI_GPIO_Port GPIOF
#define ENABLE_Pin GPIO_PIN_10
#define ENABLE_GPIO_Port GPIOF
#define SDNWE_Pin GPIO_PIN_0
#define SDNWE_GPIO_Port GPIOC
#define B5_Pin GPIO_PIN_3
#define B5_GPIO_Port GPIOA
#define VSYNC_Pin GPIO_PIN_4
#define VSYNC_GPIO_Port GPIOA
#define G2_Pin GPIO_PIN_6
#define G2_GPIO_Port GPIOA
#define R3_Pin GPIO_PIN_0
#define R3_GPIO_Port GPIOB
#define R6_Pin GPIO_PIN_1
#define R6_GPIO_Port GPIOB
#define SDNRAS_Pin GPIO_PIN_11
#define SDNRAS_GPIO_Port GPIOF
#define A6_Pin GPIO_PIN_12
#define A6_GPIO_Port GPIOF
#define A7_Pin GPIO_PIN_13
#define A7_GPIO_Port GPIOF
#define A8_Pin GPIO_PIN_14
#define A8_GPIO_Port GPIOF
#define A9_Pin GPIO_PIN_15
#define A9_GPIO_Port GPIOF
#define A10_Pin GPIO_PIN_0
#define A10_GPIO_Port GPIOG
#define D4_Pin GPIO_PIN_7
#define D4_GPIO_Port GPIOE
#define D5_Pin GPIO_PIN_8
#define D5_GPIO_Port GPIOE
#define D6_Pin GPIO_PIN_9
#define D6_GPIO_Port GPIOE
#define D7_Pin GPIO_PIN_10
#define D7_GPIO_Port GPIOE
#define G4_Pin GPIO_PIN_10
#define G4_GPIO_Port GPIOB
#define G5_Pin GPIO_PIN_11
#define G5_GPIO_Port GPIOB
#define D0_Pin GPIO_PIN_14
#define D0_GPIO_Port GPIOD
#define D1_Pin GPIO_PIN_15
#define D1_GPIO_Port GPIOD
#define BA0_Pin GPIO_PIN_4
#define BA0_GPIO_Port GPIOG
#define R7_Pin GPIO_PIN_6
#define R7_GPIO_Port GPIOG
#define DOTCLK_Pin GPIO_PIN_7
#define DOTCLK_GPIO_Port GPIOG
#define SDCLK_Pin GPIO_PIN_8
#define SDCLK_GPIO_Port GPIOG
#define HSYNC_Pin GPIO_PIN_6
#define HSYNC_GPIO_Port GPIOC
#define G6_Pin GPIO_PIN_7
#define G6_GPIO_Port GPIOC
#define I2C3_SDA_Pin GPIO_PIN_9
#define I2C3_SDA_GPIO_Port GPIOC
#define I2C3_SCL_Pin GPIO_PIN_8
#define I2C3_SCL_GPIO_Port GPIOA
#define STLINK_RX_Pin GPIO_PIN_9
#define STLINK_RX_GPIO_Port GPIOA
#define STLINK_TX_Pin GPIO_PIN_10
#define STLINK_TX_GPIO_Port GPIOA
#define R4_Pin GPIO_PIN_11
#define R4_GPIO_Port GPIOA
#define R5_Pin GPIO_PIN_12
#define R5_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define D2_Pin GPIO_PIN_0
#define D2_GPIO_Port GPIOD
#define D3_Pin GPIO_PIN_1
#define D3_GPIO_Port GPIOD
#define G7_Pin GPIO_PIN_3
#define G7_GPIO_Port GPIOD
#define G3_Pin GPIO_PIN_10
#define G3_GPIO_Port GPIOG
#define B3_Pin GPIO_PIN_11
#define B3_GPIO_Port GPIOG
#define B4_Pin GPIO_PIN_12
#define B4_GPIO_Port GPIOG
#define SDNCAS_Pin GPIO_PIN_15
#define SDNCAS_GPIO_Port GPIOG
#define SDCKE1_Pin GPIO_PIN_5
#define SDCKE1_GPIO_Port GPIOB
#define SDNE1_Pin GPIO_PIN_6
#define SDNE1_GPIO_Port GPIOB
#define B6_Pin GPIO_PIN_8
#define B6_GPIO_Port GPIOB
#define B7_Pin GPIO_PIN_9
#define B7_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
