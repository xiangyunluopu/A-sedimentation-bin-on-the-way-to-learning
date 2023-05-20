#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int count_t1 = 0;

void init(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
  
  T1CTL |= 0x0c;
  T1CC0L = 0x12;
  T1CC0H = 0x7a;
  EA = 1;
  T1IE = 1;
  T1CTL |= 0x03;
}

#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  T1STAT &= ~0x20;
  count_t1 += 1;
  if (3 == count_t1)
  {
    D5 = 1;
  }
  else if (4 == count_t1)
  {
    D5 = 0;
    count_t1 = 0;
  }
}

void main(void)
{
  init();
  for (;;)
  {
    
  }
}