#include "led7.h"

#define SCLK  GPIO_Pin_1
#define RCLK  GPIO_Pin_2
#define DATA  GPIO_Pin_3

void led_donvi(void)
{
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g3
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g2
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g1
  GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g0
}

void led_chuc(void)
{
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g3
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g2
  GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g1
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g0
}

void led_tram(void)
{
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g3
  GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g2
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g1
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g0
}

void led_nghin(void)
{
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//0
  GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g3
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g2
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g1
  GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g0
}

void so(uint8_t num)
{
  switch(num)
  {
  case 0:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 1:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 2:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 3:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 4:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 5:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 6:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 7:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 8:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
  case 9:
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
    case 10:
    GPIO_ResetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//dp
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//g
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//f
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//e
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//d
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//c
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//b
    GPIO_SetBits(GPIOA,DATA);GPIO_ResetBits(GPIOA,SCLK);GPIO_SetBits(GPIOA,SCLK);//a
    break;
      
  }

}

void GPIO_setup(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  GPIO_InitStruct.GPIO_Pin=SCLK|RCLK|DATA;
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void write_led()
{
  GPIO_ResetBits(GPIOA,RCLK);GPIO_SetBits(GPIOA,RCLK);//write
  
}

void hienso(uint16_t num)
{
  uint8_t nghin;
  uint8_t tram;
  uint8_t chuc;
  uint8_t donvi;
  nghin=num/1000;
  tram=(num%1000)/100;
  chuc=(num%100)/10;
  donvi=num%10;
  so(nghin);
  led_nghin();
  write_led();
  so(tram);
  led_tram();
  write_led();
  so(chuc);
  led_chuc();
  write_led();
  so(donvi);
  led_donvi();
  write_led();
}