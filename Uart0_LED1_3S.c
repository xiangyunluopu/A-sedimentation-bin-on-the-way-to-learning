#include "ioCC2530.h"

#define LED1 P1_0

unsigned char count = 0;

void Init_Prot(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void Set_Clk_32Mhz(void)
{
  CLKCONCMD &= ~0x40;
  while (CLKCONCMD & 0x40);
  CLKCONCMD &= ~0x07;
}

void Init_Uart0(void)
{
  //映射端口
  PERCFG &= ~0x01; //P0_2, P0_3 0000 1100
  P0SEL |= 0x0c; 
  //波特率
  U0BAUD = 59;
  U0GCR = 8;
  //Uart控制
  U0UCR |= 0x80;
  //控制与状态寄存器
  U0CSR |= 0xc0;
}

void Init_WD(void)
{
  WDCTL = 0x0c;
}

void Seed_dat(unsigned char dat)
{
  U0DBUF = dat;
  while (!UTX0IF);
  UTX0IF = 0;
}

void Uart_Seed_String(unsigned char* str)
{
  while (*str != '\0')
  {
    Seed_dat(*str++);
  }
}

void main(void)
{
  Set_Clk_32Mhz();
  Init_Prot();
  Init_Uart0();
  Init_WD();
  while (1)
  {
    LED1 = 1;
    Uart_Seed_String("Hello! I am CC2530.\n");
    LED1 = 0;
    for (count = 0; count < 3; count +=1)
    {
      while (!WDTIF);
      WDTIF = 0;
    }
  }
}