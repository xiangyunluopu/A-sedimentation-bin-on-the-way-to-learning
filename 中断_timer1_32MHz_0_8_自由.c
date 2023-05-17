#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int count_timer1 = 0;

void init_port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_timer1(void)
{
  CLKCONCMD &= 0x80;
  EA = 1;
  T1IE = 1;
  T1CTL = 0X05;
}
#pragma vector = T1_VECTOR
__interrupt void t1_sre(void)
{
  count_timer1 += 1;
  if (30 == count_timer1)
  {
    D4 = 1;
  }
  else if (60 == count_timer1)
  {
    D4 = 0;
  }
  else if (120 == count_timer1)
  {
    count_timer1 = 0;
  }
}

void main(void)
{
  init_port();
  init_timer1();
  for(;;);
}