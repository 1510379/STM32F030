#include "i2c.h"
#include "MPU6050.h"
MPU6050_t mpu6050;

int16_t MPU6050_AccelerationX(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_ACCEL_XOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}

int16_t MPU6050_AccelerationY(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_ACCEL_YOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}

int16_t MPU6050_AccelerationZ(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_ACCEL_ZOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}

int16_t MPU6050_GyroX(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_GYRO_XOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}

int16_t MPU6050_GyroY(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_GYRO_YOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}

int16_t MPU6050_GyroZ(void)
{
  I2C_ReadReg(I2C1,MPU6050 ,MPU6050_RA_GYRO_ZOUT_L,mpu6050.buffer,2);
  return (((uint16_t)mpu6050.buffer[0]<<8)|mpu6050.buffer[1]);
}
