#include "led7seg.h"
uint8_t so[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void hienthi(uint32_t num)
{
  uint8_t nghin;
  uint8_t tram;
  uint8_t chuc;
  uint8_t donvi;
  nghin=num/1000;
  tram=(num%1000)/100;
  chuc=(num%100)/10;
  donvi=num%10;
  
  spi_senddata8(so[nghin]);
  spi_senddata8(NGHIN);
  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);
  
  
  spi_senddata8(so[tram]);
  spi_senddata8(TRAM);
  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);
  
  
  spi_senddata8(so[chuc]);
  spi_senddata8(CHUC);
  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);
  
  
  spi_senddata8(so[donvi]);
  spi_senddata8(DONVI);
  GPIO_ResetBits(GPIOA,GPIO_Pin_4);
  GPIO_SetBits(GPIOA,GPIO_Pin_4);
               
}