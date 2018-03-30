#include <avr/io.h>

/*
.global _delay_us
_delay_us:
  nop
  nop
  nop
  nop
  nop
  subi r24, 0x01
  brne _delay_us
  ret
  */

.global _delay_ms
_delay_ms:
  push r19
  push r18
L0:
  ldi  r18, 11
  ldi  r19, 1 /* 99 */
L1:
  dec  r19
  brne L1
  dec  r18
  brne L1
  subi r24, 0x01
  brne L0

  pop r18
  pop r19
  ret
