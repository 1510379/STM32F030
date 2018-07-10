#include "usart.h"
uint16_t value[1000];

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else 
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif

uint16_t i=0;

void usart_config(void)
{
  USART_InitTypeDef  USART_InitStruct;
  
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  
  //config usart
  USART_InitStruct.USART_BaudRate=9600;
  USART_InitStruct.USART_WordLength=USART_WordLength_8b;
  USART_InitStruct.USART_Mode=USART_Mode_Tx|USART_Mode_Rx;
  USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
  USART_InitStruct.USART_Parity=USART_Parity_No;
  USART_InitStruct.USART_StopBits=USART_StopBits_1;
  USART_Init(USART1,&USART_InitStruct);
  USART_Cmd(USART1,ENABLE);
  
  //config gpio
  GPIO_InitTypeDef   GPIO_InitStruct;
  
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource9,GPIO_AF_1); //Tx
  GPIO_PinAFConfig(GPIOA,GPIO_PinSource10,GPIO_AF_1);//Rx
  
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
  GPIO_Init(GPIOA,&GPIO_InitStruct);
  
  //config interupt
  NVIC_InitTypeDef  NVIC_InitStruct;
  NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
  NVIC_InitStruct.NVIC_IRQChannelPriority=0;
  NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
  NVIC_Init(&NVIC_InitStruct);
  
  USART_ClearFlag(USART1,USART_IT_RXNE);
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
  
}
uint16_t a;
int usart_read(uint16_t *buf)//read data
{

  
    while(a!=i)
    {
        USART_SendData(USART1,value[a]);
        buf[a]=value[a];
    a++;}
  return 0;
}


void USART1_IRQHandler(void)//interupt
{
  uint16_t data;
  if(USART_GetFlagStatus(USART1,USART_IT_RXNE)==RESET)
  {
  data=USART_ReceiveData(USART1);
  //   if(USART_GetFlagStatus(USART1,USART_IT_TXE)==RESET)
     // USART_SendData(USART1,data);

  value[i]=data;
 // printf("ok");
  i++;
}
}

PUTCHAR_PROTOTYPE
{
  USART_SendData(USART1,(uint8_t) ch);
  while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
  return ch;
}