#include "ioCC2530.h"

#define D6 P1_4
void Delay(unsigned int time)
{
  unsigned char j = 0;
  unsigned int i = 0;
  for (i = 0; i < time; i += 1)
  {
    for (j = 0; j < 240; j += 1)
    {
      asm("NOP");asm("NOP");asm("NOP");
    }
  }
}

void main()
{
  P1SEL &= ~0x10;
  P1DIR |= 0x10;
  D6 = 0;
  for (;;)
  {
    D6 = ~D6;
    Delay(1000);
  }
}