void uart_tx_int(void) __interrupt(UART1_TXC_vector);
void uart_rx_int(void) __interrupt(UART1_RXC_vector);
void getline_block(uint8_t *buf, uint8_t n);
void uart1_init(uint16_t baud);

#define UART_BAUD(baud) (uint16_t)(F_CPU / baud)
