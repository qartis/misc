CC = sdcc
FLASH = stm8flash
OUT ?= main
CFLAGS += -I..
LDFLAGS :=
OBJS ?= main.rel
GARBAGE := $(foreach FILE,$(patsubst %.rel,%,$(OBJS)), \
    $(FILE).map $(FILE).rst $(FILE).cdb \
    $(FILE).asm $(FILE).sym $(FILE).lst)
F_CPU ?= 16000000UL

all: $(OUT).ihx

$(OBJS) : $(wildcard *.h) Makefile

%.rel: %.c
	$(CC) -lstm8 -mstm8 -DF_CPU=$(F_CPU) $(CFLAGS) -c -o $@ $<
	$(eval FILE := $(patsubst %.rel,%,$@))
	@rm -f $(FILE).cdb $(FILE).ihx $(FILE).map $(FILE).rst

%.ihx: $(OBJS)
	$(CC) -lstm8 -mstm8 $(CFLAGS) -o $@ $(OBJS)
	$(eval FILE := $(patsubst %.ihx,%,$@))
	@rm -f $(GARBAGE)

load: $(OUT).ihx
	$(FLASH) -c stlinkv2 -p stm8s103f3 -w $(OUT).ihx

factory_defaults:
	echo "00 00 ff 00 ff 00 ff 00 ff 00 ff" | xxd -r -p > factory_defaults.bin
	stm8flash -c stlinkv2 -p stm8s103f3 -s opt -w factory_defaults.bin

.PHONY: clean
clean:
	rm -f $(OBJS) $(GARBAGE) $(OUT).lk $(OUT).lst $(OUT).ihx
