/**
******************************************************************************
* @file    TIM/TIM_OnePulse/main.c  
* @author  MCD Application Team
* @version V1.4.0
* @date    24-July-2014
* @brief   Main program body
******************************************************************************
* @attention

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
#include "led7.h"
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
//static void Timer_setup(void);
//void GPIO_setup(void);
//void TIM3_IRQHandler(void);
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
  //  /* TIM Configuration */
  //  Timer_setup();
  GPIO_setup();
  uint16_t  dem;
  //  
  //  /* Infinite loop */
  //  while (1)
  //{
  //    if(dem==1000)
  //    {
  //      GPIO_SetBits(GPIOA,GPIO_Pin_1);
  //    }
  //    else if(dem==2000)
  //    {
  //      GPIO_ResetBits(GPIOA,GPIO_Pin_1);
  //      dem=0;
  //    }
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  //    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g3
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g2
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g1
  //    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g0
  //    GPIO_ResetBits(GPIOA,RCLK);GPIO_SetBits(GPIOA,RCLK);//write
  //    for(uint16_t i=0;i<666;i++)
  //    {
  //      so(1);
  //      led_nghin();
  //      write_led();
  //     so(2);
  //      led_tram();
  //      write_led();
  //      so(3);
  //      led_chuc();
  //      write_led();
  //      so(4);
  //      led_donvi();
  //      write_led();
  //    }
  for(dem=0;dem<9999;dem++)
  {
    for(uint32_t j=0;j<15000;j++)
    {
      hienso(dem);
      so(10);
      led_tram();
      write_led();
    }
    
  }
}



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
