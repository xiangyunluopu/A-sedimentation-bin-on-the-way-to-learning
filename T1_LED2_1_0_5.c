#include "ioCC2530.h"

#define LED1 P1_0
#define LED2 P1_5
#define LED3 P1_3
#define LED4 P1_4

#define SW1 P1_2

unsigned int count = 0;
unsigned char flag = 0;

void init_all(void)
{
  P1SEL &= 0x39;
  P1DIR |= 0x39;
  P1 &= ~0x39;
  P1SEL &= ~0x04;
  P1DIR &= ~0x04;
  P1INP &= ~0x04;
  P2INP &= ~0x40;
  
  T1CTL |= 0x0c;
  T1IE = 1;
  EA = 1;
  T1CCTL0 |= 0x04;
  T1CC0L = 0x24;
  T1CC0H = 0xF4;
  //T1CTL |= 0x02;
}
#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  if (1 == flag)
  {
    count += 1;
    if (3 == count)
    {
      LED1 = 1;
    }
    else if (4 == count)
    {
      LED1 = 0;
      count = 0;
    }
  }
}

void delay(unsigned int t)
{
  unsigned int i = 0;
  unsigned char j = 0;
  for (i = 0; i < t; i += 1)
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
  if (0 == SW1)
  {
    delay(100);
    if (0 == SW1)
    {
      for (;!SW1;);
      flag = 1;
      T1CTL |= 0x02;
    }
  }
}

void main(void)
{
  init_all();
  for (;;)
  {
    scan_key();
  }
}
// 0010 0000