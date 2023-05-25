#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int t3_count1 = 0, t4_count1 = 0;

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
  T3CTL = 0xFD;
}
//unsigned int t3_count1 = 0;
#pragma vector = T3_VECTOR
__interrupt void SERVICE_T3(void)
{
  t3_count1 += 1;
  if (1000 == t3_count1)
  {
    D4 = ~D4;
    t3_count1 = 0;
  }
  T3CTL = 0xFD;
}

void init_timer4(void)
{
  T4CC0 = 0x7d;
  T4IE = 1;
  EA = 1;
  T4CCTL0 |= 0x04;
  T4CTL = 0xfe;  //1111 1110
}
//unsigned int t4_count1 = 0;
#pragma vector = T4_VECTOR
__interrupt void SERVICE_T4(void)
{
  t4_count1 += 1;
  if (4000 == t4_count1)
  {
    D6 = ~D6;
    t4_count1 = 0;;
  }
}

void main(void)
{
  init_port();
  init_timer3();
  init_timer4();
  for (;;)
  {
    
  }
}