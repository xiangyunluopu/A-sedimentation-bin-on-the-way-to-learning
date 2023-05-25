#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1

unsigned int t3_count1 = 0;

void init_port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_timer3(void)
{
  T3CC0 = 0x7D;
  T3IE = 1;
  EA = 1;
  // 1111 1101
  T3CTL = 0xfd;
}

#pragma vector = T3_VECTOR
__interrupt void T3_service(void)
{
  t3_count1 += 1;
  if (1000 == t3_count1)
  {
    D4 = ~D4;
    t3_count1 = 0;
  }
  T3CTL = 0xfd;
}

void main(void)
{
  init_port();
  init_timer3();
  for (;;)
  {
    
  }
}