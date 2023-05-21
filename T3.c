#include "ioCC2530.h"

#define D3 P1_0
#define D4 P1_1
#define D5 P1_3
#define D6 P1_4

unsigned int count_t3 = 0;
//unsigned char count = 0;
void init(void)
{
  P1SEL &= ~0x1b;
  P1DIR |= 0x1b;
  P1 &= ~0x1b;
}


void initT3(void)
{
  // 1110 0000
  T3CTL |= 0xe0;
  EA = 1;
  T3IE = 1;
  T3CTL |= 0x10;
}
#pragma vector = T3_VECTOR
__interrupt void T3_SERVICE(void)
{
  count_t3 += 1;
  if (49 * 15 == count_t3)
  {
    D6 = 1;
  }
  else if (45 * 20 == count_t3)
  {
    D6 = 0;
    count_t3 = 0;
  }
}

void main(void)
{
  init();
  initT3();
  for(;;)
  {
    //delay(2000);
    //D3 = ~D3;
  }
}