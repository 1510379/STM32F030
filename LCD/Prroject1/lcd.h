#include <stm32f0xx.h>

#define RS GPIO_Pin_1
#define RW GPIO_Pin_2
#define EN GPIO_Pin_3
#define DB4 GPIO_Pin_4
#define DB5 GPIO_Pin_5
#define DB6 GPIO_Pin_6
#define DB7 GPIO_Pin_7

void GPIO_setup(void);
void delay_us(uint32_t time);
void Enable(void);
void send4bits(uint8_t data);
void send_command(uint8_t command);
void lcd_init();
void gotoXY(unsigned char row, unsigned char column);
void lcd_putchar(unsigned char data);
void lcd_putstring(char *s);


