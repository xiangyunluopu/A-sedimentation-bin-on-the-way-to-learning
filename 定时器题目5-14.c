#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

#define SW2 P0_1

unsigned int count = 0;
unsigned char flag_time = 0;
unsigned char flag_key = 0;

void init_port(void) 
{
  // 0001 1011 // led
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 = ~0x1b;
  // SW2 // 0000 0010
  P0SEL &= ~0x02;
  P0DIR &= ~0x02;
  P0INP &= ~0x02;
  P2INP &= ~0x20;
}

void init_timer1(void) 
{
  EA = 1;
  T1IE = 1;
  // 设置定时频数
  T1CC0L = 0xd4;
  T1CC0H = 0x30;
  // 打开通道0的比较模式
  T1CCTL0 |= 0x04;
  // 打开定时器1的模模式，且配置128分频
  T1CTL = 0x0e;
}
#pragma vector = T1_VECTOR
__interrupt void T1_SER(void)
{
  if (1 == flag_time) 
  {
    count += 1;
  }
}

void delay(unsigned int time)
{
  unsigned int i = 0;
  unsigned char j = 0;
  for (i = 0; i < time; i += 1)
  {
    for (j = 0; j < 240; j += 1)
    {
      asm("NOP");
      asm("NOP");
      asm("NOP");
    }
  }
}

void scan_key(void)
{
  if (0 == SW2) 
  {
    delay(50);
    if (0 == SW2)
    {
      for (;0 == SW2;);
      if (0 == flag_key)
      {
        flag_key = 1;
        flag_time = 1;
      }
      else if (1 == flag_key)
      {
        flag_key = 0;
        flag_time = 1;
      }
    }
  }
}

void LED_runing(void)
{
  if (1 == flag_key)
  {
    switch (count)
    {
    case 5:
      D4 = 1;
      break;
    case 10:
      D3 = 1;
      break;
    case 15:
      D6 = 1;
      break;
    case 20:
      D5 = 1;
      break;
    case 25:
      P1 &= ~0x1b;
      flag_time = 0;
      count = 0;
      break;
    }
  }
  else if (0 == flag_key)
  {
    switch (count)
    {
    case 5:
      D5 = 1;
      break;
    case 10:
      D6 = 1;
      break;
    case 15:
      D3 = 1;
      break;
    case 20:
      D4 = 1;
      break;
    case 25:
      P1 &= ~0x1b;
      flag_time = 0;
      count = 0;
      break;
    }
  }
}

void main(void) 
{
  // init_port
  init_port();
  // init_timer
  init_timer1();
  for(;;) 
  {
    scan_key();
    // 按键扫描与LEDruning
    LED_runing();
  }
}