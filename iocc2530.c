#include "ioCC2530.h"

#define LED1 P1_0
#define LED2 P1_5
#define LED3 P1_3
#define LED4 P1_4

#define SW1 P1_2

int count = 0;

void init() {
  // 0011 1001
  P1SEL &= ~0x39;
  P1DIR |= 0x39;
  P1 &= ~0x39;
  EA = 1;
  // 0001 0000
  IEN2 |= 0x10;
  P1IEN |= 0x04;
  PICTL |= 0x02;
}

#pragma vector = P1INT_VECTOR
__interrupt void A() {
  if (P1IFG & 0x04) {
    if (0 == LED1) {
      count += 1;
      if (3 == count) {
        LED1 = 1;
        count = 0;
      }
    }
    else if (1 == LED1) {
      count += 1;
      if (5 == count) {
        LED1 = 0;
        count = 0;
      }
    }
    P1IFG &= ~0x04;
  }
  P1IF = 0;
}
  
void main() {
  init();
  for (;;) {
    
  }
}