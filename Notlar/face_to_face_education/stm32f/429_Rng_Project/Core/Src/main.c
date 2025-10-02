/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
RNG_HandleTypeDef hrng;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_RNG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */


EXTI_HandleTypeDef    hexti0;
EXTI_HandleTypeDef    hexti1;

int dizi[4] = {GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_8};

void EXTI_CALLBACK_SET(void){
	hrng.Instance = RNG;
	HAL_RNG_Init(&hrng);
	uint32_t random;
	HAL_RNG_GenerateRandomNumber(&hrng, &random);
	HAL_GPIO_WritePin(GPIOG, dizi[random%4], GPIO_PIN_SET);
}

void EXTI_CALLBACK_RESET(void){
	hrng.Instance = RNG;
	HAL_RNG_Init(&hrng);
	uint32_t random;
	HAL_RNG_GenerateRandomNumber(&hrng, &random);
	HAL_GPIO_WritePin(GPIOG, dizi[random%4], GPIO_PIN_RESET);
}

void EXTI0_IRQHandler(void){
	HAL_EXTI_IRQHandler(&hexti0);
}

void EXTI2_IRQHandler(void){
	HAL_EXTI_IRQHandler(&hexti1);
}



int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_RNG_CLK_ENABLE();
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  GPIO_InitTypeDef gpio_init;
  gpio_init.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_8;
  gpio_init.Mode = GPIO_MODE_OUTPUT_PP ;
  gpio_init.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOG, &gpio_init);

  GPIO_InitTypeDef gpioO_init;
  gpioO_init.Pin = GPIO_PIN_0 | GPIO_PIN_2;
  gpioO_init.Mode = GPIO_MODE_INPUT;
  gpioO_init.Pull =GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &gpioO_init);

  EXTI_ConfigTypeDef exti_config_one;
  EXTI_ConfigTypeDef exti_config_zero;

  NVIC_EnableIRQ(EXTI0_IRQn);
  NVIC_EnableIRQ(EXTI1_IRQn);

  NVIC_SetPriority(EXTI0_IRQn, 0);
  NVIC_SetPriority(EXTI1_IRQn, 1);

  exti_config_zero.Line = EXTI_LINE_0 ;
  exti_config_zero.Mode = EXTI_MODE_INTERRUPT;
  exti_config_zero.Trigger = EXTI_TRIGGER_RISING;
  exti_config_zero.GPIOSel = EXTI_GPIOA;

  exti_config_one.Line = EXTI_LINE_2 ;
  exti_config_one.Mode = EXTI_MODE_INTERRUPT;
  exti_config_one.Trigger = EXTI_TRIGGER_RISING;
  exti_config_one.GPIOSel = EXTI_GPIOA;

  hexti0.Line =  EXTI_LINE_0;
  hexti1.Line = EXTI_LINE_2;


  HAL_EXTI_SetConfigLine(&hexti0, &exti_config_zero);
  HAL_EXTI_SetConfigLine(&hexti1, &exti_config_one);
  HAL_EXTI_RegisterCallback(&hexti0, HAL_EXTI_COMMON_CB_ID, EXTI_CALLBACK_SET);
  HAL_EXTI_RegisterCallback(&hexti1, HAL_EXTI_COMMON_CB_ID, EXTI_CALLBACK_RESET);

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 192;
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
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
static void MX_RNG_Init(void)
{

  /* USER CODE BEGIN RNG_Init 0 */

  /* USER CODE END RNG_Init 0 */

  /* USER CODE BEGIN RNG_Init 1 */

  /* USER CODE END RNG_Init 1 */
  hrng.Instance = RNG;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RNG_Init 2 */

  /* USER CODE END RNG_Init 2 */

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
#ifdef USE_FULL_ASSERT
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
