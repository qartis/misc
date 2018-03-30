BINPATH = ../avr8-gnu-toolchain-linux_x86/bin
CC = $(BINPATH)/avr-gcc
OBJCOPY = $(BINPATH)/avr-objcopy
SIZE = $(BINPATH)/avr-size
OUT = main
CFLAGS = -mmcu=attiny9 -Os -I..
LDFLAGS = -mmcu=attiny9 -nostartfiles -Wl,-u,main -Wl,--gc-sections 

OBJS = main.o ../delay.o init.o

all: $(OUT).hex

%.o: %.S
	$(CC) $(CFLAGS) -c -o $@ $<

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@
	$(SIZE) -C --mcu=attiny9 $<

main.elf: $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(OUT).elf

main.map: $(OBJS)
	$(CC) -Wl,-Map,main.map $(LDFLAGS) $(OBJS) -o /dev/null

.PHONY: clean
clean:
	rm -f $(OBJS) $(OUT).elf $(OUT).hex

.PHONY: dump
dump:
	avr-objdump -d $(OUT).elf

.PHONY: load
load:
	echo "P" | sudo tee SERIAL
	cat main.hex | tr -d '\r\n' | sudo tee SERIAL
