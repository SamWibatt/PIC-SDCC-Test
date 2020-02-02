# PIC-SDCC-Test
Learning SDCC PIC tools to program PICs with C

I have a PICkit3 and a F628 already in a board so I used those and it worked!

Based on https://quozl.linux.org.au/pic16f84-sdcc-blink/ (note the source file there has the includes missing, but the C source code link leads to a correct version. Mine is hacked up for F628.)

Also I used MPLAB IPE / PICkit3, because those are what I have.

Procedure:
- run make
- use MPLAB IPE to send .hex file to target hardware

Pin connections are described in Blinky.c.
