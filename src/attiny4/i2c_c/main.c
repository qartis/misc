#include <avr/io.h>
#include <stdint.h>

#include "delay.h"

#define SDA      (1 << PORTB0)
#define SCL      (1 << PORTB2)
#define I2C_PORT PORTB
#define I2C_PIN  PINB
#define I2C_DDR  DDRB

#define SCL_HI I2C_DDR &= ~SCL
#define SCL_LO I2C_DDR |= SCL
#define SDA_HI I2C_DDR &= ~SDA
#define SDA_LO I2C_DDR |= SDA

#define ACK 0
#define NACK 1

void i2c_init(void)
{
  I2C_PORT &= ~(SDA | SCL);
}

void i2c_start(void)
{
  SCL_HI;
  SDA_HI;
  _delay_ms(1);

  SDA_LO;
  _delay_ms(1);
  SCL_LO;
  _delay_ms(1);
}

void i2c_stop(void)
{
  SDA_LO;
  _delay_ms(1);
  SCL_HI;
  _delay_ms(1);
  SDA_HI;
  _delay_ms(1);
}

void i2c_writebit(uint8_t c)
{
  if (c == ACK)
    SDA_LO;
  else
    SDA_HI;

  SCL_HI;
  _delay_ms(1);
  SCL_LO;
  _delay_ms(1);

  SDA_HI;
}

uint8_t i2c_readbit(void)
{
  uint8_t c;

  SCL_HI;
  _delay_ms(1);

  /* read ack */
  c = !!(I2C_PIN & SDA);

  SCL_LO;
  _delay_ms(1);

  return c;
}

uint8_t i2c_write(uint8_t c)
{
  i2c_writebit(c & 0x80);
  i2c_writebit(c & 0x40);
  i2c_writebit(c & 0x20);
  i2c_writebit(c & 0x10);
  i2c_writebit(c & 0x08);
  i2c_writebit(c & 0x04);
  i2c_writebit(c & 0x02);
  i2c_writebit(c & 0x01);
  return !i2c_readbit(); /* ack */
}

uint8_t i2c_read(uint8_t ack)
{
  uint8_t c;
  uint8_t i;

  c = 0;
  for (i = 0; i < 8; i++) {
    c <<= 1;
    c |= i2c_readbit();
  }

  i2c_writebit(ack);

  return c;
}

uint16_t temp_read(void)
{
  uint16_t temp = 0;

  i2c_start();
  if (!i2c_write(0x80)) {
    i2c_stop();
    return temp;
  }

  i2c_write(0xf3);
  i2c_stop();

  _delay_ms(255);

  i2c_start();
  if (!i2c_write(0x81)) {
    i2c_stop();
    return temp;
  }
  temp = i2c_read(ACK);
  temp <<= 8;
  temp |= i2c_read(NACK);
  i2c_stop();

  return temp;
}

void main(void) __attribute__((section(".init1")));
void main(void)
{
  CCP = 0xd8;
  CLKPSR = 0x00;

  for (;;) {
    uint16_t temp = temp_read();
    if (temp != 0) {
      i2c_start();
      i2c_write(temp >> 8);
      i2c_write(temp);
      i2c_stop();
    }
    _delay_ms(255);
    _delay_ms(255);
    _delay_ms(255);
    _delay_ms(255);
  }
}
