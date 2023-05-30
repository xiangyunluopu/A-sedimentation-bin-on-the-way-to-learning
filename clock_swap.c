#include "ioCC2530.h"

void Init_Port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
  
  // 0000 0010
  P0SEL &= ~0x02;
  P0DIR &= ~0x02;
  P0INP &= ~0x02;
  P2INP &= ~0x20;
}

void Delay(unsigned int time)
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

void Set_Clock(void)
{
  if (CLKCONSTA & 0x40)
  {
    CLKCONCMD &= ~0x40;
    while (CLKCONSTA & 0x40);
    CLKCONCMD &= ~0x07;
  }
  else
  {
    CLKCONCMD |= 0x40;
    while (!(CLKCONCMD & 0x40));
    CLKCONCMD |= 0x01;
  }
}

void Scan_Key(void)
{
  if (!P0_1)
  {
    Delay(100);
    if (!P0_1)
    {
      while(!P0_1);
      Set_Clock();
    }
  }
}

void main(void)
{
  Init_Port();
  for (;;)
  {
    P1_4 = 1;
    Delay(500);
    Scan_Key();
    Delay(500);
    Scan_Key();
    P1_4 = 0;
    Delay(500);
    Scan_Key();
    Delay(500);
    Scan_Key();
  }
}