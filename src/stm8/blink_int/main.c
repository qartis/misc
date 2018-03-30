#include <stdint.h>
#include "stm8.h"

void tim1_int(void) __interrupt(TIM1_UPDATE_vector)
{
  PB_ODR ^= (1 << PB5);
	TIM1_SR1 = 0;
}

void main(void)
{
	CLK_CKDIVR = CKDIVR;

	// Configure timer1: 1000Hz
	TIM1_PSCRH = (uint8_t)(16000 >> 8);
	TIM1_PSCRL = (uint8_t)(16000 >> 0);

	TIM1_ARRH = (uint8_t)(1000 >> 8);
	TIM1_ARRL = (uint8_t)(1000 >> 0);

  TIM1_IER = TIM_IER_UIE;
	TIM1_CR1 = TIM_CR1_CEN;

	PB_DDR = (1 << PB5);
	PB_CR1 = (1 << PB5);

  __rim();

	for (;;) {};
}
