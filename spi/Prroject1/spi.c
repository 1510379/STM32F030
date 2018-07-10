#include "spi.h"


void spi_config(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);

GPIO_PinAFConfig(GPIOA,GPIO_PinSource5,GPIO_AF_0);//SCK
GPIO_PinAFConfig(GPIOA,GPIO_PinSource6,GPIO_AF_0);//MISO
GPIO_PinAFConfig(GPIOA,GPIO_PinSource7,GPIO_AF_0);//MOSI


GPIO_InitTypeDef  GPIO_InitStruct;
SPI_InitTypeDef  SPI_InitStruct;

//config gpio
GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_DOWN;
GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
GPIO_Init(GPIOA,&GPIO_InitStruct);

//config CS
GPIO_InitStruct.GPIO_Pin=GPIO_Pin_4;
GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_UP;
GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
GPIO_Init(GPIOA,&GPIO_InitStruct);


//config spi
SPI_I2S_DeInit(SPI1);
SPI_InitStruct.SPI_Direction=SPI_Direction_2Lines_FullDuplex;
SPI_InitStruct.SPI_DataSize=SPI_DataSize_8b;
SPI_InitStruct.SPI_FirstBit=SPI_FirstBit_MSB;
SPI_InitStruct.SPI_BaudRatePrescaler=SPI_BaudRatePrescaler_4;
SPI_InitStruct.SPI_CRCPolynomial=7;
SPI_InitStruct.SPI_Mode=SPI_Mode_Master;
SPI_InitStruct.SPI_NSS=SPI_NSS_Soft;
SPI_InitStruct.SPI_CPHA=SPI_CPHA_1Edge;
SPI_InitStruct.SPI_CPOL=SPI_CPOL_High;
SPI_Init(SPI1,&SPI_InitStruct);
SPI_Cmd(SPI1,ENABLE);
}

void spi_senddata8(uint8_t data)
{
  while(SPI_I2S_GetFlagStatus(SPI1,SPI_I2S_FLAG_TXE)==RESET);
        SPI_SendData8(SPI1,data);
}
