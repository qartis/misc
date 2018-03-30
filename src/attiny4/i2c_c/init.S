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
