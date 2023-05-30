#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

#define SW1 P1_2

unsigned int count = 0;
unsigned int count_D3 = 0;
unsigned int count_D6 = 0;
unsigned char flag_t1 = 0;
unsigned char flag_D3 = 0;
unsigned char flag_D6 = 0;

void Init_Port(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
  // 0000 0100
  P1SEL &= ~0x04;
  P1DIR &= ~0x04;
  P1INP &= ~0x04;
  // 0100 0000
  P2INP &= ~0x40;
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

void Check_LED(void)
{
  P1 |= 0x1b;
  Delay(2000);
  P1 &= ~0x1b;
  Delay(2000);
  P1 |= 0x1b;
  Delay(2000);
  P1 &= ~0x1b;
  Delay(2000);
}

void Init_Timer1(void)
{
  // 0000 1100 
  T1CTL |= 0x0c;
  // 0100 0000
  T1CCTL0 |= 0x04;
  T1IE = 1;
  EA = 1;
  T1CC0L = 0xD4;
  T1CC0H = 0x30;
  T1CTL |= 0x02;
}

#pragma vector = T1_VECTOR
__interrupt void Service_T1(void)
{
  
  if (1 == flag_t1)
  {
    count += 1;
  }
  if (count != 0)
  {
    if (0 == flag_t1)
    {
      if (count < 5)
      {
        flag_D3 = ~flag_D3;
        count = 0;
      }
      else 
      {
        flag_D6 = ~flag_D6;
        count = 0;
      }
    }
  }

  if (flag_D3)
  {
    count_D3 += 1;
    if (5 == count_D3)
    {
      D3 = ~D3;
      count_D3 = 0;
    }
  }
  else
  {
    D3 = 0;
  }
  if (flag_D6)
  {
    count_D6 += 1;
    if (5 == count_D6)
    {
      D6 = ~D6;
      count_D6 = 0;
    }
  }
  else 
  {
    D6 = 0;
  }

}

void key_scan(void)
{
  if (0 == SW1)
  {
    Delay(200);
    if (0 == SW1)
    {
      flag_t1 = 1;
      while (0 == SW1);
      flag_t1 = 0;
    }
  }
}

void main(void)
{
  Init_Port();
  Check_LED();
  Init_Timer1();
  while (1)
  {
    key_scan();
  }
}