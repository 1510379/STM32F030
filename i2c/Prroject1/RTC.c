#include "RTC.h"

/* Chuyen tu format BCD (Binary-Coded Decimal) sang Decimal */
uint8_t bcd2dec(uint8_t num)
{
        return ((num/16 * 10) + (num % 16));
}
/* Chuyen tu Decimal sang BCD */
uint8_t dec2bcd(uint8_t num)
{
        return ((num/10 * 16) + (num % 10));
}

void readtime(uint16_t *date)
{
  uint8_t i[10];
  
  
    date[0]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_sec,i,1)&0x7f);
    date[1]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_min,i,1));
    date[2]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_hour,i,1)&0x3f);
    date[3]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_wday,i,1));
    date[4]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_day,i,1));
    date[5]=(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_month,i,1));
    date[6]=2000+(uint16_t)bcd2dec(I2C_ReadReg(I2C1,addr_RTC,addr_year,i,1));               
}

void settime(uint8_t sec, uint8_t min, uint8_t hour, uint8_t wday, uint8_t day, uint8_t month, uint8_t year)
{
  
  sec=dec2bcd(sec);
  min=dec2bcd(min);
  hour=dec2bcd(hour);
  wday=dec2bcd(wday);
  day=dec2bcd(day);
  month=dec2bcd(month);
  year=dec2bcd(year);
  uint8_t dates[8]={0x00,sec,min,hour,wday,day,month,year};
  I2C_WriteByte(I2C1,addr_RTC,dates,8);
  
}