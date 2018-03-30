#include <avr/io.h>

void main(void) __attribute__((naked));
void main(void)
{
  CCP = 0xd8;
  CLKPSR = 0x00;

  DDRB |= (1 << PORTB2);

  for (;;) {
    PINB |= (1 << PORTB2);
  }
}
