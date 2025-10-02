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
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
 /*
  //__HAL_RCC_GPIOD_CLK_ENABLE();
  //__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin = GPIO_PIN_All;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOD, &gpio_init);
	HAL_GPIO_Init(GPIOC, &gpio_init);

*/

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();
    __HAL_RCC_RNG_CLK_ENABLE();


    RNG_HandleTypeDef rng_handle;
    rng_handle
    HAL_RNG_Init();
    GPIO_InitTypeDef gpio_init;

	gpio_init.Pin = GPIO_PIN_13 | GPIO_PIN_12;
	gpio_init.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_init.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOD, &gpio_init);

	gpio_init.Pin = GPIO_PIN_0 | GPIO_PIN_1;
	gpio_init.Mode = GPIO_MODE_IT_RISING;
	gpio_init.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &gpio_init);

	EXTI_ConfigTypeDef exit_config_zero;
	EXTI_ConfigTypeDef exit_config_one;

	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);

	NVIC_SetPriority(EXTI0_IRQn, 0);
	NVIC_SetPriority(EXTI1_IRQn, 1);

	exit_config_zero.Line = EXTI_LINE_0 ;
	exit_config_zero.Mode = EXTI_MODE_INTERRUPT;
	exit_config_zero.Trigger = EXTI_TRIGGER_RISING;
	exit_config_zero.GPIOSel = EXTI_GPIOA;

	exit_config_one.Line = EXTI_LINE_1 ;
	exit_config_one.Mode = EXTI_MODE_INTERRUPT;
	exit_config_one.Trigger = EXTI_TRIGGER_RISING;
	exit_config_one.GPIOSel = EXTI_GPIOA;

	hexti0.Line =  EXTI_LINE_0;
	hexti1.Line = EXTI_LINE_1;


	HAL_EXTI_SetConfigLine(&hexti0, &exit_config_zero);
	HAL_EXTI_SetConfigLine(&hexti1, &exit_config_one);
	HAL_EXTI_RegisterCallback(&hexti0, HAL_EXTI_COMMON_CB_ID, EXTI_CALLBACK_ZERO);
	HAL_EXTI_RegisterCallback(&hexti1, HAL_EXTI_COMMON_CB_ID, EXTI_CALLBACK_ONE);

/*
	int seven_segment_display_count [ROW][COLUMN] ={
		  {0,0,0,0,0,0,1}, // 0
		  {1,0,0,1,1,1,1}, // 1
		  {0,0,1,0,0,1,0}, // 2
		  {0,0,0,0,1,1,0}, // 3
		  {1,0,0,1,1,0,0}, // 4
		  {0,1,0,0,1,0,0}, // 5
		  {0,1,0,0,0,0,0}, // 6
		  {0,0,0,1,1,1,1}, // 7
		  {0,0,0,0,0,0,0}, // 8
		  {0,0,0,0,1,0,0}, // 9
	};

	while(1){

	  for(int j=0;j<ROW;j++){
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_6, seven_segment_display_count[j][0]);
    	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, seven_segment_display_count[j][1]);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, seven_segment_display_count[j][2]);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, seven_segment_display_count[j][3]);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_10, seven_segment_display_count[j][4]);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_11, seven_segment_display_count[j][5]);
	    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_12, seven_segment_display_count[j][6]);

	    for(int i=0;i<ROW;i++){
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_6, seven_segment_display_count[i][0]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, seven_segment_display_count[i][1]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8, seven_segment_display_count[i][2]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9, seven_segment_display_count[i][3]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_10, seven_segment_display_count[i][4]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, seven_segment_display_count[i][5]);
		    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, seven_segment_display_count[i][6]);
		    HAL_Delay(60000);
		}
	  }

    }
*/

  // ARM core kısmı ile ilgili apiler var. sysmem.x
  //
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

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
