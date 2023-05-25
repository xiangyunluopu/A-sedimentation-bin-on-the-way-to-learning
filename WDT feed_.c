#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

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

void LED_Check(void)
{
  P1 |= 0x1b;
  Delay(2000);
  P1 &= ~0x1b;
  Delay(2000);
}

void Init_Port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= 0x1b;
  LED_Check();
}

void Init_WDT(void)
{
  WDCTL = 0x08;
  // 0000 1000
}

void feed_dog(void)
{
  WDCTL |= 0xa0;
  WDCTL |= 0x50;
}

void D4_shang_feed(void)
{
  Delay(1000);
  D4 = 1;
  Delay(1000);
  D4 = 0;
  feed_dog();
}

void D6_shang(void)
{
  Delay(1000);
  D6 = 1;
  Delay(1000);
  D6 = 0;
}

void main(void)
{
  unsigned char i = 0;
  Init_Port();
  Init_WDT();
  while (1)
  {
    for (i = 0; i < 8; i += 1)
    {
      D4_shang_feed();
    }
    for (i = 0; i < 8; i += 1)
    {
      D6_shang();
    }
  }
}