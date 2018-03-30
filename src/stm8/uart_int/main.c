#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "stm8.h"
#include "i2c.h"

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
    putchar('\r');
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

void main(void)
{
  uint8_t buf[32];
  uint8_t reg;

	CLK_CKDIVR = 0; /* 16MHz */
	CLK_PCKENR1 = PCKENR1_TIM1 | PCKENR1_UART1;

	UART1_CR2 = UART_CR2_TEN | UART_CR2_REN | UART_CR2_RIEN;
	UART1_BRR2 = 0x03;
	UART1_BRR1 = 0x68; // 9600 baud

  __rim();

  printf("uart_int init\n");

  i2c_init();

	for (;;) {
	  printf("> ");
	  i2c_set_start_ack();
	  i2c_send_address(0x1e, I2C_WRITE);
	  i2c_send_reg(0x0f);
	  i2c_set_start_ack();
	  i2c_send_address(0x1e, I2C_READ);
	  reg = I2C_SR1;
	  reg = I2C_SR3;
	  i2c_set_nak();
	  i2c_set_stop();
	  i2c_read(&reg);

	  printf("got byte '%x'\n", reg);

	  /*
	  getline_block(buf, sizeof(buf));

	  printf("got line: '%s'\r\n", buf);
	  if (strncmp(buf, "on", strlen("on")) == 0) {
	    printf("turning on\r\n");
    }
    */
  }
}
