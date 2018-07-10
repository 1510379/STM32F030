/**
******************************************************************************
* @file    TIM/TIM_OnePulse/main.c  
* @author  MCD Application Team
* @version V1.4.0
* @date    24-July-2014
* @brief   Main program body
******************************************************************************
* @attention
*
* <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
*
* Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
* You may not use this file except in compliance with the License.
* You may obtain a copy of the License at:
*
*        http://www.st.com/software_license_agreement_liberty_v2
*
* Unless required by applicable law or agreed to in writing, software 
* distributed under the License is distributed on an "AS IS" BASIS, 
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/** @addtogroup STM32F0xx_StdPeriph_Examples
* @{
*/

/** @addtogroup TIM_OnePulse
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
//uint16_t dem;

/* Private function prototypes -----------------------------------------------*/
/*static void Timer_setup(void);
static void GPIO_setup(void);
void TIM3_IRQHandler(void);*/
/* Private functions ---------------------------------------------------------*/
uint16_t TimerPeriod=0;
uint16_t Pulse=0;
  TIM_OCInitTypeDef  TIM_OCInitStruct;

void pwm_config(void);
/**
* @brief  Main program.
* @param  None
* @retval None
*/


int main(void)
{
//  /*!< At this stage the microcontroller clock setting is already configured, 
//  this is done through SystemInit() function which is called from startup
//  file (startup_stm32f0xx.s) before to branch to application main.
//  To reconfigure the default setting of SystemInit() function, refer to
//  system_stm32f0xx.c file
//  */ 
//  SystemInit();
//  SystemCoreClockUpdate();
//  /* TIM Configuration */
//  Timer_setup();
//  GPIO_setup();
//  dem=0;
//  
//  /* Infinite loop */
//  while (1)
//  {
//    if(dem==1000)
//    {
//      GPIO_SetBits(GPIOA,GPIO_Pin_1);
//    }
//    else if(dem==2000)
//    {
//      GPIO_ResetBits(GPIOA,GPIO_Pin_1);
//      dem=0;
//    }
//  }
  pwm_config();
  while(1)
  {
    for(uint16_t i=0;i<=100;i++)
    { 
      for(uint32_t j=0;j<1000;j++);
    Pulse = (uint16_t) (((uint32_t) i * (TimerPeriod - 1)) / 100);
    TIM_OCInitStruct.TIM_Pulse = Pulse;
    TIM_OC1Init(TIM1, &TIM_OCInitStruct);
    if(i==100) i=0;
    }
  }
}

void pwm_config(void)
{
   TIM_TimeBaseInitTypeDef  TIM_TimeBaseStruct;
  GPIO_InitTypeDef GPIO_InitStruct;
  
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_7;
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
  GPIO_Init(GPIOA,&GPIO_InitStruct);
  
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_2);
  
  TimerPeriod=(SystemCoreClock/20000)-1;
  //Pulse = (uint16_t) (((uint32_t) 1 * (TimerPeriod - 1)) / 100);
  
  //config timer
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1 , ENABLE);
    TIM_TimeBaseStruct.TIM_Prescaler=0;
    TIM_TimeBaseStruct.TIM_CounterMode=TIM_CounterMode_Up;
    TIM_TimeBaseStruct.TIM_Period=TimerPeriod;
    TIM_TimeBaseStruct.TIM_ClockDivision=0;
    TIM_TimeBaseStruct.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM1,&TIM_TimeBaseStruct);

    //config pwm
   TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM2;
  TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStruct.TIM_OutputNState = TIM_OutputNState_Enable;
 // TIM_OCInitStruct.TIM_Pulse = Pulse;
  TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low;
  TIM_OCInitStruct.TIM_OCNPolarity = TIM_OCNPolarity_High;
  TIM_OCInitStruct.TIM_OCIdleState = TIM_OCIdleState_Set;
  TIM_OCInitStruct.TIM_OCNIdleState = TIM_OCIdleState_Reset;

  //TIM_OC1Init(TIM1, &TIM_OCInitStruct);        
  
   /* TIM1 counter enable */
  TIM_Cmd(TIM1, ENABLE);

  /* TIM1 Main Output Enable */
  TIM_CtrlPWMOutputs(TIM1, ENABLE);
}
//}
//void TIM3_IRQHandler(void)
//{
//  if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
//  {
//    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
//    dem++;
//  }
//}


#ifdef  USE_FULL_ASSERT

/**
* @brief  Reports the name of the source file and the source line number
*         where the assert_param error has occurred.
* @param  file: pointer to the source file name
* @param  line: assert_param error line source number
* @retval None
*/
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  
  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
* @}
*/

/**
* @}
*/

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
