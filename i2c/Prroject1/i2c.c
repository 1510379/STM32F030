#include "stm32f0xx.h"
#include "i2c.h"
#include "MPU6050.h"

#define TIMEOUT(x,y)  timeout=y; \
while(x) {if(timeout--==0) return -1;}

void i2c_config(void)
{
  /* Enable peripheral clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1, ENABLE);
  
  /* Enable SDA, SCL GPIO clocks*/
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  
  /* Connect PXx to I2C_SCL*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_4);
  
  /* Connect PXx to I2C_SDA*/
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_4);
  
  /* GPIO configuration */
  GPIO_InitTypeDef  GPIO_InitStructure;
  /* Configure I2C pins */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  
  I2C_InitTypeDef I2C_InitStructure;
  /* I2C configuration */
  I2C_DeInit(I2C1);
  I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
  I2C_InitStructure.I2C_AnalogFilter = I2C_AnalogFilter_Enable;
  I2C_InitStructure.I2C_DigitalFilter = 0x00;
  I2C_InitStructure.I2C_OwnAddress1 = 0x00;
  I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
  I2C_InitStructure.I2C_Timing = 0x2000090E;
  
  /* Apply I2C configuration after enabling it */
  I2C_Init(I2C1, &I2C_InitStructure);
  
  /* I2C Peripheral Enable */
  I2C_Cmd(I2C1, ENABLE);
  //  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
  //  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  //  
  //  GPIO_PinAFConfig(GPIOB,GPIO_PinSource9,GPIO_AF_4);
  //  GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_4);
  
  //  //config gpio
  //  GPIO_InitTypeDef   GPIO_InitStruct;
  //  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF;
  //  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9|GPIO_Pin_10;
  //  GPIO_InitStruct.GPIO_OType=GPIO_OType_OD;
  //  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
  //  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
  //  GPIO_Init(GPIOB,&GPIO_InitStruct);
  //  
  //  I2C_InitTypeDef   I2C_InitStruct;
  //  I2C_InitStruct.I2C_Mode=I2C_Mode_I2C;
  //  I2C_InitStruct.I2C_OwnAddress1=0x00;
  //  I2C_InitStruct.I2C_Ack=I2C_Ack_Enable;
  //  I2C_InitStruct.I2C_AcknowledgedAddress=I2C_AcknowledgedAddress_7bit;
  //  I2C_InitStruct.I2C_AnalogFilter=I2C_AnalogFilter_Enable;
  //  I2C_InitStruct.I2C_DigitalFilter=0x00;
  //  I2C_InitStruct.I2C_Timing=0x2000090E;
  //  
  //  I2C_Init(I2C1,&I2C_InitStruct);
  //  I2C_Cmd(I2C1,ENABLE);
}

uint8_t I2C_ReadReg(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t RegAddr,uint8_t *Data,uint8_t Length)
{
  uint8_t i, SingleData=0;
  uint16_t timeout;
  TIMEOUT((I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY) != RESET),1000); //wait until bus is not busy
  I2C_TransferHandling(I2Cx,SlaveAddr,1,I2C_SoftEnd_Mode,I2C_Generate_Start_Write);// start to write
  TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_TXIS)==RESET,1000);// wait until transmit flag is set
  I2C_SendData(I2Cx,RegAddr);//write address of register
  TIMEOUT( (I2C_GetFlagStatus(I2Cx,I2C_FLAG_TC)==RESET),1000);//wait until transmit complete
  I2C_TransferHandling(I2Cx,SlaveAddr,Length,I2C_AutoEnd_Mode,I2C_Generate_Start_Read);//start to read
  for(i=0;i<Length;i++)
  {
    TIMEOUT( I2C_GetFlagStatus(I2Cx,I2C_FLAG_RXNE)==RESET,1000);//wait until receive flag is set
    if(Length>1) 
      Data[i]=I2C_ReceiveData(I2Cx);//receive data
     else SingleData=I2C_ReceiveData(I2Cx);
  }
  TIMEOUT((I2C_GetFlagStatus(I2Cx,I2C_FLAG_STOPF)==RESET),1000);//wait until stop flag is set
  I2C_ClearFlag(I2Cx,I2C_FLAG_STOPF);
  return SingleData;     
}

uint8_t I2C_ReadByte(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t *Data,uint8_t Length)
{
  uint8_t i,SingleData=0;
  uint16_t timeout;
  TIMEOUT((I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY)!=RESET),1000);
  I2C_TransferHandling(I2Cx,SlaveAddr,Length,I2C_AutoEnd_Mode,I2C_Generate_Start_Read);
  for(i=0;i<Length;i++)
  {
    TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_RXNE)==RESET,1000);
    if(Length>1) Data[i]=I2C_ReceiveData(I2Cx);
    else SingleData=I2C_ReceiveData(I2Cx);
  }
  TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_STOPF)==RESET,1000);
  I2C_ClearFlag(I2Cx,I2C_FLAG_STOPF);
  return SingleData;
}

int I2C_WriteReg(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t RegAddr,uint8_t *Data,uint8_t Length)
{
   uint8_t i;
   uint16_t timeout;
   TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY)!=RESET,1000);
   I2C_TransferHandling(I2Cx,SlaveAddr,1,I2C_AutoEnd_Mode,I2C_Generate_Start_Write);
   TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_TXIS)==RESET,1000);
   I2C_SendData(I2Cx,RegAddr);
   TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_TC)==RESET,1000);
   I2C_TransferHandling(I2Cx,SlaveAddr,Length,I2C_AutoEnd_Mode,I2C_Generate_Start_Write);
   for(i=0;i<Length;i++)
   {
   TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_TXIS)==RESET,1000);
   I2C_SendData(I2Cx,Data[i]);
   }
   TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_STOPF)==RESET,1000);
   I2C_ClearFlag(I2Cx,I2C_FLAG_STOPF);
   return 0;
}

int I2C_WriteByte(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t *Data,uint8_t Length)
{
uint8_t i;
uint16_t timeout;
TIMEOUT((I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY)!=RESET),1000);
I2C_TransferHandling(I2Cx,SlaveAddr,Length,I2C_AutoEnd_Mode,I2C_Generate_Start_Write);
for(i=0;i<Length;i++)
{
TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_TXIS)==RESET,1000);
I2C_SendData(I2Cx,Data[i]);
}
TIMEOUT(I2C_GetFlagStatus(I2Cx,I2C_FLAG_STOPF)==RESET,1000);
I2C_ClearFlag(I2Cx,I2C_FLAG_STOPF);
return 0;
}