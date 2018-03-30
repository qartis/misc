#define I2C_READ        1
#define I2C_WRITE       0
void i2c_init(void);
void i2c_read(unsigned char *);
void i2c_set_nak(void);
void i2c_set_stop(void);
void i2c_send_reg(unsigned char);
void i2c_send_address(unsigned char, unsigned char);
void i2c_set_start_ack(void);
