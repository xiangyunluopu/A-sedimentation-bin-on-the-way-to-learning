#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned char count_t1 = 0; 

void init_led(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_T1(void)
{
  CLKCONCMD &= 0x80;
  // 0b00001100
  T1CTL |= 0x0c;
  T1CC0L = 0xa8;
  T1CC0H = 0x61;
  // 0000 0100
  T1CCTL0 |= 0x04;
  T1IE = 1;
  EA = 1;
  T1CTL |= 0x02;
}

#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  count_t1 += 1;
    if (15 == count_t1)
    {
      D5 = 1;
    }
    else if (20 == count_t1)
    {
      D5 = 0;
      count_t1 = 0;
    }
}

void main(void)
{
  init_led();
  init_T1();
  for (;;)
  {
    
  }
}