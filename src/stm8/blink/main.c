#include <stdint.h>
#include "stm8.h"

void main(void)
{
  CLK_CKDIVR = CKDIVR;

	PB_DDR = (1 << PB5);
	PB_CR1 = (1 << PB5);

	for (;;) {
		PB_ODR ^= (1 << PB5);
		delay_ms(500);
  }
}
