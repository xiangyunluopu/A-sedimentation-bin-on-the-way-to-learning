#include "ioCC2530.h"

#define D5 P1_3

void Init_clk(void)
{
  CLKCONCMD &= ~0x40;
  while (CLKCONSTA & 0x40);
  CLKCONCMD &= ~0x07;
}

void Init_Prot(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void Init_UART0(void)
{
  // 映射端口
  PERCFG &= ~0x01; // P0_2,P0_3 0000 1100
  P0SEL |= 0x0c;
  // 波特率 9600 32M
  U0BAUD = 59;
  U0GCR = 8;
  // UART控制
  U0UCR |= 0x80;
  // 控制与状态寄存器
  U0CSR |= 0xc0;
}

void Init_dg(void)
{
  WDCTL = 0x0c;
}

void Seed(unsigned char ch)
{
  U0DBUF = ch;
  while (!UTX0IF);
  UTX0IF = 0;
}

void Uart_Seed_Str(unsigned char* str)
{
  while (*str != '\0')
  {
    Seed(*str++);
  }
}

void main(void)
{
  Init_clk();
  Init_Prot();
  Init_UART0();
  Init_dg();
  for (;;)
  {
    while(0 == WDTIF);
    WDTIF = 0;
    D5 = 1;
    Uart_Seed_Str("hello,world!\n");
    D5 = 0;
  }
}