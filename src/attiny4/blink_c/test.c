#include <avr/io.h>

void init(void) __attribute__ ( ( naked ) );

void init(void)
{
  CCP = 0xd8;
  CLKMSR = 1;
}
