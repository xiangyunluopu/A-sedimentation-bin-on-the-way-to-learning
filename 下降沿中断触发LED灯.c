#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

#define SW1 P1_2

void init_port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
  // 0000 0100
  P1SEL &= ~0x04;
  P1DIR &= ~0x04;
  
  EA = 1;
  IEN2 |= 0x10;
  P1IEN |= 0x04;
  PICTL |= 0x02;
}

#pragma vector = P1INT_VECTOR
__interrupt void P1INT_SERVISE(void)
{
  if (P1IFG & 0x04)
  {
    D4 = ~D4;
    P1IFG &= ~0x04;
  }
  P1IF = 0;
}

void main(void)
{
  init_port();
  //init_
  for (;;)
  {
  
  }
}