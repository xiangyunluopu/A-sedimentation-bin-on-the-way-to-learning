#include "ioCC2530.h"

#define LED1 P1_0
#define LED2 P1_1
#define LED3 P1_3
#define LED4 P1_4

unsigned int count = 0;

void init_led(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}

void init_timer1(void)
{
  T1CTL |= 0x0c;
  T1IE = 1;
  EA = 1;
  T1CCTL0 |= 0x04;
  T1CC0L = 0x24;
  T1CC0H = 0xF4;
  T1CTL |= 0x02;
}

#pragma vector = T1_VECTOR
__interrupt void T1_SERVICE(void)
{
  count += 1;
  if (3 == count)
  {
    LED1 = 1;
    LED2 = 1;
  }
  else if (4 == count)
  {
    
    LED1 = 0;
    LED2 = 0;
    count = 0;
  }
}

void main(void)
{
  init_led();
  init_timer1();
  for (;;)
  {
  
  }
}