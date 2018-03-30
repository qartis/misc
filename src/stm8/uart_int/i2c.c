#include <stdint.h>
#include "stm8.h"
#include "i2c.h"

void i2c_init(void) {
   I2C_CR1 = 0;   //  Disable I2C before configuration starts. PE bit is bit 0
   //
   //  Setup the clock information.
   //
   I2C_FREQR = 16;                     //  Set the internal clock frequency (MHz).
   I2C_CCRH &= ~I2C_FS;           //  I2C running is standard mode.
   I2C_CCRL = 0x10;                    //  SCL clock speed is 500 kHz.
   I2C_CCRH &= 0xf0;	// Clears lower 4 bits "CCR"
   //
   //  Set the address of this device.
   //
   I2C_OARH &= ~I2C_ADDMODE;      //  7 bit address mode.
   I2C_OARH |= I2C_ADDCONF;       //  Docs say this must always be 1.
   //
   //  Setup the bus characteristics.
   //
   I2C_TRISER = 17;
   //
   //  Turn on the interrupts.
   //
   //I2C_ITR = I2C_ITBUFEN | I2C_ITEVTEN | I2C_ITERREN; //  Buffer, event and error interrupts enabled
   //
   //  Configuration complete so turn the peripheral on.
   //
   I2C_CR1 = I2C_PE;	// Enables port
   //
   //  Enter master mode.
   //
}

void i2c_read (unsigned char *x) {
   while ((I2C_SR1 & I2C_RXNE) == 0);
   *x = I2C_DR;
}
void i2c_set_nak (void) {
   I2C_CR2 &= ~I2C_ACK;
}
void i2c_set_stop (void) {
   I2C_CR2 |= I2C_STOP;
}
void i2c_send_reg (unsigned char addr) {
   volatile int reg;
   reg = I2C_SR1;
   reg = I2C_SR3;
   I2C_DR = addr;
   while ((I2C_SR1 & I2C_TXE) == 0);
}
void i2c_send_address (unsigned char addr, unsigned char mode) {
   volatile int reg;
   reg = I2C_SR1;
   I2C_DR = (addr << 1) | mode;
   if (mode == I2C_READ) {
      I2C_OARL = 0;
      I2C_OARH = 0;
   }
   while ((I2C_SR1 & I2C_ADDR) == 0);
   if (mode == I2C_READ)
      I2C_SR1 &= ~I2C_ADDR;
}
void i2c_set_start_ack (void) {
   I2C_CR2 = I2C_ACK | I2C_START;
   while ((I2C_SR1 & I2C_SB) == 0);
}
