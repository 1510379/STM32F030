/**
******************************************************************************
* @file    Project/STM32F0xx_StdPeriph_Templates/main.c 
* @author  MCD Application Team
* @version V1.5.0
* @date    05-December-2014
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
#include "main.h"
#include "stm32f0xx.h"
#include "stdio.h"
#include "usart.h"
/** @addtogroup STM32F0xx_StdPeriph_Templates
* @{
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else 
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
//void usart_Config(void);
/* Private functions ---------------------------------------------------------*/
//void USART1_IRQHandler(void);


/**
* @brief  Main program.
* @param  None
* @retval None
*/
//uint16_t value[1000];

int main(void)
{
  
  /*!< At this stage the microcontroller clock setting is already configured, 
  this is done through SystemInit() function which is called from startup
  file (startup_stm32f0xx.s) before to branch to application main.
  To reconfigure the default setting of SystemInit() function, refer to
  system_stm32f0xx.c file
  */ 
  
  /* Add your application code here
  */
//  usart_Config();
//    
//  uint16_t a=0;
//  printf("\n");
//  /* Infinite loop */
//  while (1)
//  {
//   
//    while(a!=i)
//    {
////    USART_SendData(USART1,value[a]);
//      printf("%c",value[a]);
//    a++;}
//  
//  }
//  
  
  usart_config();
  uint16_t buff[1000];

  while(1)
  {
   usart_read(buff);
    // printf("ok");
  }
}
//
//void usart_Config(void)
//{
//  USART_InitTypeDef    USART_InitStruct;
//  
//  USART_InitStruct.USART_BaudRate=9600;
//  USART_InitStruct.USART_WordLength=USART_WordLength_8b;
//  USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
//  USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//  USART_InitStruct.USART_Parity=USART_Parity_No;
//  USART_InitStruct.USART_StopBits=USART_StopBits_1;
//  
//  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
//  
//  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
//  
//  GPIO_InitTypeDef  GPIO_InitStruct;
//  
//  GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_1);//Tx
//  GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_1);//Rx
//  //config tx
//  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;
//  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
//  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
//  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
//  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
//  GPIO_Init(GPIOA,&GPIO_InitStruct);
//  
//  USART_Init(USART1,&USART_InitStruct);
//  
//  
//  NVIC_InitTypeDef NVIC_InitStruct;
//  
//  NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
//  NVIC_InitStruct.NVIC_IRQChannelPriority=0;
//  NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
//  NVIC_Init(&NVIC_InitStruct);
//  
//  USART_Cmd(USART1,ENABLE);
//// USART_ClearFlag(USART1,USART_IT_RXNE);
//  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
//}

//void USART1_IRQHandler(void)
//{
//  uint16_t data;
//  if(USART_GetFlagStatus(USART1,USART_IT_RXNE)==RESET)
//  {
//    data=USART_ReceiveData(USART1);
//    //if(USART_GetFlagStatus(USART1,USART_IT_TXE)==RESET)
//      //USART_SendData(USART1,*data);
//      value[i]=data;
//    i++;
//  }
//}
//
//PUTCHAR_PROTOTYPE
//{
//  USART_SendData(USART1, (uint8_t) ch);
//  while (USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET)
//  {}
//  return ch;
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


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
