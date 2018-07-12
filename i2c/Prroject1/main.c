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
#include "i2c.h"
#include "MPU6050.h"
#include "RTC.h"
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

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
//uint8_t bcd2dec(uint8_t num);
//uint8_t dec2bcd(uint8_t num);
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
 // I2C_DeInit(I2C1);
  i2c_config();
//  uint8_t a[5];
//  static uint8_t b;
//  uint8_t f[2]={0x05,dec2bcd(8)};
//  uint8_t c=0xd0;
//  uint16_t addr=0x00;
//   I2C_WriteByte(I2C1,c,f,2);
//  while(1)
//  {
//   
//   b=bcd2dec( I2C_ReadReg(I2C1,c,0x05,a,1));
//   
   //if(addr==0x07) addr=0x00;
    //a=MPU6050_AccelerationZ();
   // for(uint16_t i=0;i<=1000000;i++)
    //{}
  //}
  uint16_t thoigian[7];
 // settime(1,03,12,5,12,7,18);
  while(1)
  {
    readtime(thoigian);
    
  }
  
} 
  
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
  