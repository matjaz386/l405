/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define __TP 130
#define __TL 36
#define __TH 94
#define __NWS 24
#define __RXLEN 128
#define __TXLEN 128
#define OTG_ID_Pin GPIO_PIN_13
#define OTG_ID_GPIO_Port GPIOC
#define LED_G_Pin GPIO_PIN_1
#define LED_G_GPIO_Port GPIOD
#define LED_R_Pin GPIO_PIN_0
#define LED_R_GPIO_Port GPIOD
#define sense45V_Pin GPIO_PIN_0
#define sense45V_GPIO_Port GPIOC
#define sense_5V_Pin GPIO_PIN_1
#define sense_5V_GPIO_Port GPIOC
#define TREF_Pin GPIO_PIN_8
#define TREF_GPIO_Port GPIOB
#define TEST_Pin GPIO_PIN_5
#define TEST_GPIO_Port GPIOA
#define LEDS_Pin GPIO_PIN_11
#define LEDS_GPIO_Port GPIOB
#define CAN_STB_Pin GPIO_PIN_14
#define CAN_STB_GPIO_Port GPIOB
#define CAN_TERM_Pin GPIO_PIN_15
#define CAN_TERM_GPIO_Port GPIOB
#define OTG_VBUS_Pin GPIO_PIN_12
#define OTG_VBUS_GPIO_Port GPIOC
/* USER CODE BEGIN Private defines */
#ifdef	__NUCLEO__
#define	__otgDeviceId	(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==GPIO_PIN_SET)
#define	__otgPwrOn		(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6)==GPIO_PIN_SET)
#define	__otgPwrOff		(HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_6)==GPIO_PIN_RESET)
#define	__otgPwrInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOG_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_6;\
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;\
    GPIO_InitStruct.Pull = GPIO_PULLDOWN;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;\
    HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);\
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_6, GPIO_PIN_RESET);\
	} while(0)
#define __ledInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOD_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_7|GPIO_PIN_14;\
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;\
    GPIO_InitStruct.Pull = GPIO_NOPULL;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;\
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);\
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_7|GPIO_PIN_14, GPIO_PIN_RESET);\
	} while(0)

#define	__otgIdInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOA_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_10;\
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;\
    GPIO_InitStruct.Pull = GPIO_PULLUP;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;\
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);\
	} while(0)
#else 
	#ifdef	__DISCO__
#define	serial	huart2
#define	__otgDeviceId	(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)==GPIO_PIN_SET)
#define	__otgPwrOn		(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)==GPIO_PIN_SET)
#define	__otgPwrOff		(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_0)==GPIO_PIN_RESET)
#define	__otgPwrInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOC_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_0;\
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;\
    GPIO_InitStruct.Pull = GPIO_NOPULL;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;\
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);\
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);\
	} while(0)
#define __ledInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOD_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;\
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;\
    GPIO_InitStruct.Pull = GPIO_NOPULL;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;\
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);\
		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);\
	} while(0)
#define	__otgIdInit do {\
	  GPIO_InitTypeDef GPIO_InitStruct = {0};\
		__HAL_RCC_GPIOA_CLK_ENABLE();\
    GPIO_InitStruct.Pin = GPIO_PIN_10;\
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;\
    GPIO_InitStruct.Pull = GPIO_PULLUP;\
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;\
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);\
	} while(0)
 #else
	#define	__otgDeviceId	(HAL_GPIO_ReadPin(OTG_ID_GPIO_Port, OTG_ID_Pin)==GPIO_PIN_SET)
	#define	__otgPwrOn		(HAL_GPIO_ReadPin(OTG_VBUS_GPIO_Port, OTG_VBUS_Pin)==GPIO_PIN_SET)
	#define	__otgPwrOff		(HAL_GPIO_ReadPin(OTG_VBUS_GPIO_Port, OTG_VBUS_Pin)==GPIO_PIN_RESET)
	#define	__otgPwrInit
	#define __ledInit
	#define	__otgIdInit
 #endif
#endif

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
