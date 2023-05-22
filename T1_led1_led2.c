#include "ioCC2530.h"

#define LED1 P1_0
#define LED2 P1_5
#define LED3 P1_3
#define LED4 P1_4

unsigned char count_t1 = 0;

void init_port(void)
{
  // 0011 1001
  P1SEL &= ~0x39;
  P1DIR |= 0x39;
  P1 &= ~0x39;
}

void init_timer(void)
{
  // 0b0000 1100
  T1CC0L = 0xd4;
  T1CC0H = 0x30;
  T1CCTL0 |= 0x04;
  T1IE = 1;
  EA = 0;
  T1CTL |= 0x0e;
}
#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  //T1STAT = 0;
  count_t1 += 1;
  if (15 == count_t1)
  {
    LED1 = 1;
    LED2 = 1;
  }
  else if (20 == count_t1)
  {
    LED1 = 0;
    LED2 = 0;
    count_t1 = 0;
  }
}

void main(void)
{
  init_port();
  init_timer();
  for (;;)
  {
    
  }
}