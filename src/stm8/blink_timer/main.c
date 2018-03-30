#include <stdint.h>
#include "stm8.h"

uint16_t clock(void)
{
	uint8_t h = TIM1_CNTRH;
	uint8_t l = TIM1_CNTRL;
	return (uint16_t)h << 8 | l;
}

void main(void)
{
	CLK_CKDIVR = 0;

	// Configure timer1: 1000Hz
	TIM1_PSCRH = 0x3e;
	TIM1_PSCRL = 0x80;

	// Enable timer1
	TIM1_CR1 = 0x01;

	PB_DDR = (1 << PB5);
	PB_CR1 = (1 << PB5);

	for (;;) {
		PB_ODR = (clock() % 1000 < 500) << PB5;
  }
}
