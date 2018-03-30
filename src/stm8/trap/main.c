#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm8.h"
#include "uart.h"

void trap_int(void) __interrupt(TRAP_vector)
{
	uint8_t i;

	PB_DDR = (1 << PB5);
	PB_CR1 = (1 << PB5);

  for (i = 0; i < 10; i++) {
		PB_ODR ^= (1 << PB5);
		delay_ms(100);
  }

  __reset();
}

void main(void)
{
  uint8_t buf[32];

	CLK_CKDIVR = CKDIVR;
	CLK_PCKENR1 = PCKENR1_TIM1;
	uart1_init(UART_BAUD(115200));

  __rim();

  printf("uart_int init\n");

	for (;;) {
	  printf("> ");
	  getline_block(buf, sizeof(buf));
	  printf("got line: '%s'\r\n", buf);

	  if (strcmp(buf, "trap") == 0) {
	    printf("trapping\n");
	    delay_ms(500);
      __trap();
    }
  }
}
