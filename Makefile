.c.o:
	sdcc --use-non-free -mpic14 -p16f88 -c $<

Blinky.hex: Blinky.o
	gplink -r -w -m -o Blinky.hex Blinky.o /usr/local/share/sdcc/lib/pic14/libsdcc.lib /usr/local/share/sdcc/non-free/lib/pic14/pic16f88.lib

clean:
	rm *.o *.asm *.cod *.lst *.map *.hex

# I used MPLAB IPE and PICkit3; can't comment on
# whether this works, plus need to change hex file
# name.
#burn:
#	(cd prog84-2.3 && ./prog84 -T 1684 -x ~/a.hex)
