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
#include "spi.h"
#include "led7seg.h"
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
  SystemInit();
  SystemCoreClockUpdate();
  spi_config();

 // while(1)
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
//  while(1)
//  {
//    for(uint16_t j=0;j<10000;j++)
//    
//   spi_senddata8(0xf9);
//   spi_senddata8(0x08);
//   GPIO_ResetBits(GPIOA,GPIO_Pin_4);
//   GPIO_SetBits(GPIOA,GPIO_Pin_4);
//  }
    for(uint32_t i=0;i<=9999;i++)
    {
      for(uint16_t j=0;j<10000;j++)
      hienthi(i);
      if(i==9999) i=0;
    }
}

//static void Timer_setup(void)
//{
//  TIM_TimeBaseInitTypeDef   TIM_TimeBase;
//  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//mo timer 2
//  
//  //cai dat timer
//  uint16_t Prescaler=(uint16_t)(SystemCoreClock/1000000)-1;
//  TIM_TimeBase.TIM_Period=999;
//  TIM_TimeBase.TIM_Prescaler=Prescaler;
//  TIM_TimeBase.TIM_CounterMode=TIM_CounterMode_Up;
//  TIM_TimeBase.TIM_ClockDivision=0;
//  TIM_TimeBaseInit(TIM3,&TIM_TimeBase);
//  
//  TIM_ClearFlag(TIM3,TIM_FLAG_Update);
//  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
//  TIM_Cmd(TIM3,ENABLE);
//  //cau hinh ngat
//  NVIC_InitTypeDef  NVIC_InitStruct;
//  NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
//  NVIC_InitStruct.NVIC_IRQChannelPriority=1;
//  NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//  NVIC_Init(&NVIC_InitStruct);
//}
//void GPIO_setup(void)
//{
//  GPIO_InitTypeDef  GPIO_InitStruct;
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
//  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1;
//  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
//  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
//  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
//  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
//  GPIO_Init(GPIOA,&GPIO_InitStruct);
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
