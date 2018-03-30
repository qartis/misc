BINPATH = ../avr8-gnu-toolchain-linux_x86/bin
CC = $(BINPATH)/avr-gcc
OBJCOPY = $(BINPATH)/avr-objcopy
SIZE = $(BINPATH)/avr-size
OUT = main
CFLAGS = -mmcu=attiny4 -nostartfiles

OBJS = blink.o

all: $(OUT).hex

%.o: %.S
	$(CC) -mmcu=attiny4 -c -o $@ $<

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@
	$(SIZE) -C --mcu=attiny4 $<

main.elf: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT).elf $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(OUT).elf $(OUT).hex
