#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int count_t3 = 0;
unsigned int count_t4 = 0;

void init_port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_t3_t4(void)
{
  //CLKCONCMD |= 0X80;
  T3CTL |= 0xe0;
  T4CTL |= 0xe0;
  T3IE = 1;
  T4IE = 1;
  EA = 1;
  T3CTL |= 0x10;
  T4CTL |= 0X10;
}
// t3 _ t4
#pragma vector = T3_VECTOR
__interrupt void T3_SERVICE(void)
{
  count_t3 += 1;
  if (49 * 30 == count_t3)
  {
    D5 = 1;
  }
  else if (49 * 40 == count_t3)
  {
    D5 = 0;
    count_t3 = 0;
  }
}

#pragma vector = T4_VECTOR
__interrupt void T4_SERVICE(void)
{
  count_t4 += 1;
  if (49 * 0 + 1 == count_t3)
  {
    D6 = 1;
  }
  else if (49 * 30 == count_t3)
  {
    D6 = 0;
    count_t4 = 0;
  }
}

void main(void)
{
  init_port();
  init_t3_t4();
  
  for (;;)
  {
    
  }
}