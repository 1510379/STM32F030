#include "stm32f0xx.h"
#include "i2c.h"

#define addr_RTC  0xd0
#define addr_sec  0x00
#define addr_min  0x01
#define addr_hour  0x02
#define addr_wday  0x03
#define addr_day   0x04
#define addr_month  0x05
#define addr_year  0x06


uint8_t bcd2dec(uint8_t num);
uint8_t dec2bcd(uint8_t num);
void readtime(uint16_t *date);
void settime(uint8_t sec, uint8_t min, uint8_t hour, uint8_t wday, uint8_t day, uint8_t month, uint8_t year);
