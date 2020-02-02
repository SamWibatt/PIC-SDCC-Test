//OK! This works with the pickit 3, IPE, and an F628 wired up like this:
/*
External source +5V -> board high rail
External source gnd -> board low rail

Pickit Pin 1 rightmost viewed from front, with Pin 1 arrow triangle)
Pin 1 = VPP / ~MCLR, to F628 pin 4
Pin 2 = VDD target, to board High rail
Pin 3 = VSS / ground, to board low rail
Pin 4 = ICSPDAT/PGD, to F628 pin 13
Pin 5 = ICSPCLK/PGC, to F628 pin 12
Pin 6 = LVP = NC

F628
01 NC
02 NC
03 NC
04 10K pullup, also pickit pin 1
05 gnd
06 NC (LED can work here)
07 NC (LED can work here)
08 NC (LED can work here)
09 NC (LED can work here)
10 NC (LED SHOULD work here - tried LED here, didn't work for some reason, not the open drain pin)
11 (LED can work here) High leg of LED, low leg to ground
12 Pickit Pin 5 (LED can work here)
13 Pickit Pin 6 (LED can work here)
14 Vdd
15 NC
16 NC
17 NC
18 NC
*/

#include <pic16f628.h>
#include <stdint.h>

static __code uint16_t __at (_CONFIG) configword1 =
_CP_OFF & _WDT_OFF & _INTRC_OSC_NOCLKOUT; //internal osc, rb6 and 7 i/o

void Intr(void) __interrupt 0
{
  T0IF = 0;       //Was T0IF = 0, for f84, now again for f628
}

void wink()
{
  uint16_t i;
  //was for (i=0;i<30000;i++) continue;
  for (i=0;i<15000;i++) continue;
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
