#include <stdint.h>
#include "stm8.h"
#include "uart.h"

volatile uint8_t txbuffer[32];
volatile uint8_t txbuffer_out;
volatile uint8_t txbuffer_in;

volatile uint8_t rxbuffer[32];
volatile uint8_t rxbuffer_out;
volatile uint8_t rxbuffer_in;

void putchar(const char c)
{
  txbuffer[txbuffer_in++] = c;
  txbuffer_in %= sizeof(txbuffer);

  if (c == '\n') {
    txbuffer[txbuffer_in++] = '\r';
    txbuffer_in %= sizeof(txbuffer);
  }

  UART1_CR2 |= UART_CR2_TIEN;
}

void uart_tx_int(void) __interrupt(UART1_TXC_vector)
{
  UART1_DR = txbuffer[txbuffer_out++];
  txbuffer_out %= sizeof(txbuffer);

  if (txbuffer_out == txbuffer_in)
    UART1_CR2 &= ~UART_CR2_TIEN;
}

void uart_rx_int(void) __interrupt(UART1_RXC_vector)
{
  uint8_t c;

  c = UART1_DR;
  if (c == '\r')
    c = '\n';

  rxbuffer[rxbuffer_in++] = c;
  rxbuffer_in %= sizeof(rxbuffer);

  putchar(c);
}

void getline_block(uint8_t *buf, uint8_t n)
{
  uint8_t c;
  uint8_t i;

  i = 0;
  while (i < n - 1) {
    while (rxbuffer_in == rxbuffer_out) {};

    c = rxbuffer[rxbuffer_out++];
    rxbuffer_out %= sizeof(rxbuffer);

    if (c == '\r' || c == '\n')
      break;

    buf[i] = c;
    i++;
  }

  buf[i] = '\0';
}

void uart1_init(uint16_t baud)
{
	CLK_PCKENR1 |= PCKENR1_UART1;
	UART1_CR2 = UART_CR2_TEN | UART_CR2_REN | UART_CR2_RIEN;
	UART1_BRR2 = (baud >> 8) & 0xf0 | (baud >> 0) & 0x0f;
	UART1_BRR1 = (baud >> 4) & 0xff;
}
