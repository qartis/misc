#include <avr/io.h>

.org 0
;Interrupt vector table
;	rjmp reset			        ; All Resets	

reset:
; Setup I/O Port
  ldi r16, 0xd8

  ldi r17, 0x01
  out CCP, r16
  out CLKMSR, r17

  ldi r17, 0x08
  out CCP, r16
  out CLKPSR, r17

	sbi	DDRB, PORTB2       	; PB2 is Output

; main() code goes here
loop:
	inc r16
	brne loop
	sbi PINB, PORTB2        ; toggle LED
	rjmp loop
