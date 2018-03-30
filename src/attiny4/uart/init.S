#include <avr/io.h>

.section .init0
.global _init
_init:
  eor     r17, r17
  out     SREG, r17
  ldi     r28, 0x5F
  ldi     r29, 0x00
  out     SPH, r29
  out     SPL, r28


.section .init0
.global __do_copy_data
__do_copy_data:
  ldi     r18, 0x00
  ldi     r26, 0x40
  ldi     r27, 0x00
  ldi     r30, 0xC8
  ldi     r31, 0x40
  rjmp    .+4
  ld      r19, Z+
  st      X+, r19
  cpi     r26, 0x46
  cpc     r27, r18
  brne    .-10
