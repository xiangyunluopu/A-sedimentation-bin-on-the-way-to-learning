#include "ioCC2530.h"

#define D3 (P1_0)
#define D4 (P1_1)
#define D5 (P1_3)
#define D6 (P1_4)

#define SW1 (P1_2)

//unsigned char flag_time = 0;
unsigned int count = 0;

void initial(void) 
{
  // 0001 1011
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
  // 0000 0100
  P1SEL &= ~0x04;
  P1DIR &= ~0x04;
  P1INP &= ~0x04;
  P2INP &= ~0x40;
  // 
  EA = 1;
  T1IE = 1;
  CLKCONCMD &= 0x80;
  
}
#pragma vector = T1_VECTOR
__interrupt void T1_SER(void)
{
  count = (count + 1) % 31;
  if (count > 0)
  {
    if (30 == count)
    {
      D4 = ~D4;
    }
  }
  T1IF = 0;
}

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

void key_scan(void)
{
  if (0 == SW1)
  {
    delay(100);
    if (0 == SW1)
    {
      T1CTL = 0x05;
    }
  }
}

void running(void)
{
  
}

void main(void)
{
  initial();
  for(;;)
  {
    key_scan();
    //running();
  }
}