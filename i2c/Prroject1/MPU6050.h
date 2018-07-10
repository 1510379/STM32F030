
#define MPU6050_RA_ACCEL_XOUT_H     0x3B
#define MPU6050_RA_ACCEL_XOUT_L     0x3C
#define MPU6050_RA_ACCEL_YOUT_H     0x3D
#define MPU6050_RA_ACCEL_YOUT_L     0x3E
#define MPU6050_RA_ACCEL_ZOUT_H     0x3F
#define MPU6050_RA_ACCEL_ZOUT_L     0x40
#define MPU6050_RA_TEMP_OUT_H       0x41
#define MPU6050_RA_TEMP_OUT_L       0x42
#define MPU6050_RA_GYRO_XOUT_H      0x43
#define MPU6050_RA_GYRO_XOUT_L      0x44
#define MPU6050_RA_GYRO_YOUT_H      0x45
#define MPU6050_RA_GYRO_YOUT_L      0x46
#define MPU6050_RA_GYRO_ZOUT_H      0x47
#define MPU6050_RA_GYRO_ZOUT_L      0x48
#define MPU6050                     (0xD0)



typedef struct MPU6050_t
{
  uint8_t degAddr;
  uint8_t buffer[14];
} MPU6050_t;

int16_t MPU6050_AccelerationX(void);
int16_t MPU6050_AccelerationY(void);
int16_t MPU6050_AccelerationZ(void);
int16_t MPU6050_GyroX(void);
int16_t MPU6050_GyroY(void);
int16_t MPU6050_GyroZ(void);