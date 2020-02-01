#include <pic16f88.h>
#include <stdint.h>

static __code uint16_t __at (_CONFIG1) configword1 =
_CP_OFF & _WDT_OFF & _INTRC_IO; //internal osc, rb6 and 7 i/o

void Intr(void) __interrupt 0
{
  INT0IF = 0;       //Was T0IF = 0, for f84
}

void wink()
{
  uint16_t i;
  for (i=0;i<30000;i++) continue;
}


void setup()
{
  TRISB = 0;
}

void loop()
{
  PORTB = 0xff;
  wink();
  PORTB = 0;
  wink();
}

void main()
{
  setup();

  for (;;) {
    loop();
  }
}
