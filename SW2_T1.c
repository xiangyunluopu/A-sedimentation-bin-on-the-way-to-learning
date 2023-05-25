#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

#define SW2 P0_1

unsigned char t1_flag = 0;
unsigned int t1_count = 0;
unsigned char t1__flag = 0;
unsigned int t1__count = 0;
//unsigned char t1__count_flag = 0;

void init_led(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_sw2(void)
{
  // 0000 0010
  P0SEL &= ~0x02;
  P0DIR &= ~0x02;
  // 因为默认上拉就不需要设置寄存器了
}

void delay(unsigned int time)
{
  unsigned int i = 0;
  unsigned char j = 0;
  while (i++ < time)
  {
    while (j++ < 240)
    {
      asm("NOP");
      asm("NOP");
      asm("NOP");
    }
  }
}

void led_running(void)
{
  if (t1_count < 30)
  {
    while (t1__count < 30 * 10)
    {
      switch (t1__count)
      {
      case 30:
        D4 = 1;
        break;
      case 30 * 2:
        D4 = 0;
        D3 = 1;
        break;
      case 30 * 3:
        D3 = 0;
        D6 = 1;
        break;
      case 30 * 4:
        D6 = 0;
        D5 = 1;
        break;
      case 30 * 5:
        D5 = 0;
        break;
      case 30 * 6:
        P1 |= 0x1b;
        break;
      case 30 * 7:
        P1 &= ~0x1b;
        break;
      case 30 * 8:
        P1 |= 0x1b;
        break;
      }
    }
    P1 &= ~0x1b;
  }
  else
  {
    while (t1__count < 30 * 10)
    {
      
      switch (t1__count)
      {
      case 30:
        D4 = 1; D6 = 1;
        break;
      case 30 * 2:
        D5 = 0; D3 = 0;
        break;
      case 30 * 3:
        D5 = 1; D3 = 1;
        break;
      case 30 * 4:
        D5 = 0; D3 = 0;
        break;
      case 30 * 5:
        D3 = ~D3; D4 = ~D4; D5 = ~D5; D6 = ~D6;
        break;
      case 30 * 6:
        D4 = 0; D6 = 0;
        break;
      case 30 * 7:
        D4 = 1; D6 = 1;
        break;
      case 30 * 8:
        D3 = ~D3; D4 = ~D4; D5 = ~D5; D6 = ~D6;
        break;
      }
    }
    
    //t1__count_flag = 0;
  }
}

void scan_key(void)
{
  if (!SW2)
  {
    delay(100);
    for (t1_flag = 1;!SW2;);
    t1_flag = 0;
    t1__flag = 1;
    led_running();
    t1__flag = 0;
    t1_count = 0;
    t1__count = 0;
  }
}

void init_t1(void)
{
  CLKCONCMD &= 0x80;
  T1CTL |= 0x05;
  T1IE = 1;
  EA = 1;
}

#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  // 0010 0000
  T1STAT &= ~0x20;
  if (1 == t1_flag)
  {
    t1_count += 1;
  }
  if (1 == t1__flag)
  {
    t1__count += 1;
  }
}

void main(void)
{
  init_led();
  init_sw2();
  init_t1();
  for (;;)
  {
    scan_key();
  }
}