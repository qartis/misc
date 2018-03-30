#include <avr/io.h>
#include <util/delay.h>

#define HI PORTB |= (1 << PORTB2)
#define LO PORTB &= ~(1 << PORTB2)

void putch(char c)
{
  uint8_t i;

restart:
  HI;
  _delay_us(97);
  LO;
  _delay_us(97);
  for (i = 0; i < 8; i++) {
    if (c & (1 << i))
      HI;
    else
      LO;
    _delay_us(97);
  }
  HI;
  _delay_us(97);

  if (c == '\n') {
    c = '\r';
    goto restart;
  }
}

void putstr(const char *s)
{
  while (*s) {
    putch(*s);
    s++;
  }
  putch('\n');
}

/*void main(void) __attribute__((section(".init1"))); */
void main(void)
{
  CCP = 0xd8;
  CLKPSR = 0x00;

  DDRB |= (1 << PORTB2);

  for (;;) {
    putstr("hello");
    _delay_ms(1000);
  }
}
