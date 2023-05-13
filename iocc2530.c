#include "ioCC2530.h"

#define D5 (P1_3)
#define D6 (P1_4)
#define D3 (P1_0)
#define D4 (P1_1)

#define SW2 (P0_1)

unsigned int count = 0;
unsigned char F_time = 0;
unsigned char F_key = 0;

//void init_port(void) {
  // init_LED
  //P1SEL &= ~0x1B;
  //P1DIR |= 0x1B;
  //P1 &= ~0x1B;
  // init_SW2 0000 0010
  //P0SEL &= ~0x02;
  //P0DIR &= ~0x02;
  //P0INP &= ~0x02;
//  P2INP &= ~0x20;// 0010 0000
//}



#pragma vector = T1_VECTOR
__interrupt void T(void) {
  if (F_time == 1) {
    count += 1;
  }
}


void delay(unsigned int time) {
  unsigned int i = 0;
  unsigned char j = 0;
  for (i = 0; i < time; i += 1) {
    for (j = 0; j < 240; j += 1) {
      asm("NOP");
      asm("NOP");
      asm("NOP");
  }
  }
}


void init_timer(void) {
  
  T1CC0L = 0xd4;
  T1CC0H = 0x30;
  T1CCTL0 |= 0x04; // 0000 0100
  EA = 1;
  T1IE = 1;
  T1CTL = 0x0e;
}


void init_Port(void) {
  P1SEL &= ~0x1b; // 0001 1011
  P1DIR |= 0x1b;
  P1 &= 0x1b;
  P0SEL &= ~0x02;
  P0DIR &= ~0x02;
  P0INP &= ~0x02;
  P2INP &= ~0x20;
}


void key_scan(void) {
  if (0 == SW2) {
    delay(50);
    if (0 == SW2) {
      for(;0 == SW2;);
      if (0 == F_key) {
        F_time = 1;
        D4 = 1;
        F_key = 1;
      }
      else if (F_key) {
        F_time = 1;
        D5 = 1;
        F_key = 0;
      }
    }
  }
}


void led_runing(void) {
  if (0 == F_key) {
    switch (count) {
    case 5:
      D3 = 1;
      break;
    case 10:
      D6 = 1;
      break;
    case 15:
      D5 = 1;
      break;
    case 20:
      P1 &= ~0x1b;
      count = 0;
      F_time = 0;
      break;
    }
  }
  else if (1 == F_key) {
    switch (count) {
    case 5:
      D6 = 1;
      break;
    case 10:
      D3 = 1;
      break;
    case 15:
      D4 = 1;
      break;
    case 20:
      P1 &= ~0x1b;
      count = 0;
      F_time = 0;
      break;
    }
  }
  }



void main(void) {
  init_Port();
  init_timer();
  for (;;) {
    key_scan();
    led_runing();
  }
}