#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int count_timer1 = 0;

void init_led(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_timer1(void)
{
  CLKCONCMD &= 0x80;
  T1CTL |= 0x05;
  EA = 1;
  T1IE = 1;
}

#pragma vector = T1_VECTOR
__interrupt void t1_service(void)
{
  count_timer1 += 1;
  if (30 * 2 == count_timer1)
  {
    P1 |= 0x1b;
  }
  else if (30 * 4 == count_timer1)
  {
    P1 &= ~0x1b;
    count_timer1 = 0;
  }
}

void main(void)
{
  init_led();
  init_timer1();
  for (;;)
  {
  
  }
}