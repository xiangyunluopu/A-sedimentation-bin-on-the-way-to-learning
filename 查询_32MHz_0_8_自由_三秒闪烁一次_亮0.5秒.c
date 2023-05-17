#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

void init_port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_timer1(void)
{
  CLKCONCMD &= 0x80;
  T1CTL = 0x05;
}

void main(void)
{
  unsigned int count = 0;
  init_port();
  init_timer1();
  for(;;)
  {
    if (1 == T1IF)
    {
      count = (count + 1) % 181;
      T1IF = 0;
      if (30 == count)
      {
        D4 = 1;
      }
      else if (60 == count)
      {
        D4 = 0;
      }
    }
  }
}