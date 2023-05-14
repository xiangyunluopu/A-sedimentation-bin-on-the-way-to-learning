#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

void delay(unsigned int time)
{
  unsigned int i = 0;
  unsigned char j = 0;
  for (i = 0; i < time; i += 1)
  {
    for (j = 0; j < 240; j += 1)
    {
      asm("NOP");
      asm("NOP");
      asm("NOP");
    }
  }
}

void init_port(void) 
{
  // 0001 1011
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void main(void)
{
  init_port();
  for(;;)
  {
    delay(2000);
    D4 = ~D4;
  }
}