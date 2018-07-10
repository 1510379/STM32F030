#ifndef __I2C_H
#define __I2C_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */


void i2c_config(void);
uint8_t I2C_ReadReg(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t RegAddr,uint8_t *Data,uint8_t Length);
uint8_t I2C_ReadByte(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t *Data,uint8_t Length);
int I2C_WriteReg(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t RegAddr,uint8_t *Data,uint8_t Length);
int I2C_WriteByte(I2C_TypeDef *I2Cx,uint8_t SlaveAddr,uint8_t *Data,uint8_t Length);
