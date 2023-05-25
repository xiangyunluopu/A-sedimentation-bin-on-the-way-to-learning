#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

void Init_Port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void Init_WDT(void)
{
  EA = 1;
  IEN2 |= 0x20;
  WDCTL = 0x0d;
  // 0000 1110
}
#pragma vector = WDT_VECTOR
__interrupt void Service_WDT(void)
{
  WDTIF = 0;
  D4 = ~D4;
}

void main(void)
{
  Init_Port();
  Init_WDT();
  for (;;)
  {
    
  }
}