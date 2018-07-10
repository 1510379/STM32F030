#include <lcd.h>

void GPIO_setup(void)//set gpio
{
  GPIO_InitTypeDef  GPIO_InitStruct;
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA,ENABLE);
  GPIO_InitStruct.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
  GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
  GPIO_Init(GPIOA,&GPIO_InitStruct);
}

void delay_us(uint32_t time)//delay
{
  for(uint32_t i=0;i<=(7*time);i++);
}

void Enable(void)
{
  GPIO_WriteBit(GPIOA,EN,Bit_SET);
  delay_us(3);
  GPIO_WriteBit(GPIOA,EN,Bit_RESET);
  delay_us(50);
}

void send4bits(uint8_t data)
{
  GPIO_WriteBit(GPIOA,DB4,data&1);
  GPIO_WriteBit(GPIOA,DB5,(data>>1)&1);
  GPIO_WriteBit(GPIOA,DB6,(data>>2)&1);
  GPIO_WriteBit(GPIOA,DB7,(data>>3)&1);
}

void send_command(uint8_t command)
{
  send4bits(command>>4);
  Enable();
  send4bits(command);
  Enable();
}

void lcd_init()// initial lcd
{
  send4bits(0);                 //turn on power
  delay_us(20000);
  GPIO_ResetBits(GPIOA,RS);
  GPIO_ResetBits(GPIOA,RW);
  send4bits(0x03);                      //
  Enable();
  delay_us(5000);                       //cau hinh bat buoc cua nha san xuat
  Enable();
  delay_us(100);                        //
  Enable();
  send4bits(0x02);
  Enable();
  send_command(0x28);// 4bit, 2hang, 5x8
  send_command(0x0e);//hien man hinh,hien con tro,khong nhap nhay
  send_command(0x06);//ID tang, noi dung khong dich
  send_command(0x01);//xoa man hinh
}

void gotoXY(unsigned char row, unsigned char column)// move to a position
{
  unsigned char addr;
  if(row==1) addr=0x7F+column;
  else addr=0xBF+column;
  delay_us(1000);
  send_command(addr);
  delay_us(50);
}

void lcd_putchar(unsigned char data)//send a char
{
  GPIO_SetBits(GPIOA,RS);
  send_command(data);
  GPIO_ResetBits(GPIOA,RS);
}

void lcd_putstring(char *s)// send string
{
  while(*s)
  {
    lcd_putchar(*s);
    s++;
  }
}