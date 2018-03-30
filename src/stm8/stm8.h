#define PA_ODR *(volatile uint8_t*)0x5000
#define PA_IDR *(volatile uint8_t*)0x5001
#define PA_DDR *(volatile uint8_t*)0x5002
#define PA_CR1 *(volatile uint8_t*)0x5003
#define PA_CR2 *(volatile uint8_t*)0x5004
#define PB_ODR *(volatile uint8_t*)0x5005
#define PB_IDR *(volatile uint8_t*)0x5006
#define PB_DDR *(volatile uint8_t*)0x5007
#define PB_CR1 *(volatile uint8_t*)0x5008
#define PB_CR2 *(volatile uint8_t*)0x5009
#define PC_ODR *(volatile uint8_t*)0x500a
#define PC_IDR *(volatile uint8_t*)0x500b
#define PC_DDR *(volatile uint8_t*)0x500c
#define PC_CR1 *(volatile uint8_t*)0x500d
#define PC_CR2 *(volatile uint8_t*)0x500e
#define PD_ODR *(volatile uint8_t*)0x500f
#define PD_IDR *(volatile uint8_t*)0x5010
#define PD_DDR *(volatile uint8_t*)0x5011
#define PD_CR1 *(volatile uint8_t*)0x5012
#define PD_CR2 *(volatile uint8_t*)0x5013
#define PE_ODR *(volatile uint8_t*)0x5014
#define PE_IDR *(volatile uint8_t*)0x5015
#define PE_DDR *(volatile uint8_t*)0x5016
#define PE_CR1 *(volatile uint8_t*)0x5017
#define PE_CR2 *(volatile uint8_t*)0x5018
#define PF_ODR *(volatile uint8_t*)0x5019
#define PF_IDR *(volatile uint8_t*)0x501a
#define PF_DDR *(volatile uint8_t*)0x501b
#define PF_CR1 *(volatile uint8_t*)0x501c
#define PF_CR2 *(volatile uint8_t*)0x501d

#define HSIEN  (1 << 0)
#define HSIRDY (1 << 1)
#define SWEN   (1 << 2)
#define SWBSY  (1 << 3)

#define CLK_ICKR     *(volatile uint8_t*)0x50c0
#define CLK_ECKR     *(volatile uint8_t*)0x50c1
#define CLK_CMSR     *(volatile uint8_t*)0x50c3
#define CLK_SWR      *(volatile uint8_t*)0x50c4
#define CLK_SWCR     *(volatile uint8_t*)0x50c5
#define CLK_CKDIVR   *(volatile uint8_t*)0x50c6
#define CLK_PCKENR1  *(volatile uint8_t*)0x50c7
#define CLK_CSSR     *(volatile uint8_t*)0x50c8
#define CLK_CCOR     *(volatile uint8_t*)0x50c9
#define CLK_PCKENR2  *(volatile uint8_t*)0x50ca
#define CLK_HSITRIMR *(volatile uint8_t*)0x50cc
#define CLK_SWIMCCR  *(volatile uint8_t*)0x50cd

#define UART1_SR   *(volatile uint8_t*)0x5230
#define UART1_DR   *(volatile uint8_t*)0x5231
#define UART1_BRR1 *(volatile uint8_t*)0x5232
#define UART1_BRR2 *(volatile uint8_t*)0x5233
#define UART1_CR1  *(volatile uint8_t*)0x5234
#define UART1_CR2  *(volatile uint8_t*)0x5235
#define UART1_CR3  *(volatile uint8_t*)0x5236
#define UART1_CR4  *(volatile uint8_t*)0x5237
#define UART1_CR5  *(volatile uint8_t*)0x5238
#define UART1_GTR  *(volatile uint8_t*)0x5239
#define UART1_PSCR *(volatile uint8_t*)0x523a

#define UART_CR1_R8    (1 << 7)
#define UART_CR1_T8    (1 << 6)
#define UART_CR1_UARTD (1 << 5)
#define UART_CR1_M     (1 << 4)
#define UART_CR1_WAKE  (1 << 3)
#define UART_CR1_PCEN  (1 << 2)
#define UART_CR1_PS    (1 << 1)
#define UART_CR1_PIEN  (1 << 0)
#define UART_CR2_TIEN  (1 << 7)

#define UART_CR2_TCIEN (1 << 6)
#define UART_CR2_RIEN  (1 << 5)
#define UART_CR2_ILIEN (1 << 4)
#define UART_CR2_TEN   (1 << 3)
#define UART_CR2_REN   (1 << 2)
#define UART_CR2_RWU   (1 << 1)
#define UART_CR2_SBK   (1 << 0)

#define UART_CR3_LINEN (1 << 6)
#define UART_CR3_STOP2 (1 << 5)
#define UART_CR3_STOP1 (1 << 4)
#define UART_CR3_CLKEN (1 << 3)
#define UART_CR3_CPOL  (1 << 2)
#define UART_CR3_CPHA  (1 << 1)
#define UART_CR3_LBCL  (1 << 0)

#define UART_SR_TXE    (1 << 7)
#define UART_SR_TC     (1 << 6)
#define UART_SR_RXNE   (1 << 5)
#define UART_SR_IDLE   (1 << 4)
#define UART_SR_OR     (1 << 3)
#define UART_SR_NF     (1 << 2)
#define UART_SR_FE     (1 << 1)
#define UART_SR_PE     (1 << 0)

#define TIM1_CR1   *(volatile uint8_t*)0x5250
#define TIM1_CR2   *(volatile uint8_t*)0x5251
#define TIM1_SMCR  *(volatile uint8_t*)0x5252
#define TIM1_ETR   *(volatile uint8_t*)0x5253
#define TIM1_IER   *(volatile uint8_t*)0x5254
#define TIM1_SR1   *(volatile uint8_t*)0x5255
#define TIM1_SR2   *(volatile uint8_t*)0x5256
#define TIM1_EGR   *(volatile uint8_t*)0x5257
#define TIM1_CCMR1 *(volatile uint8_t*)0x5258
#define TIM1_CCMR2 *(volatile uint8_t*)0x5259
#define TIM1_CCMR3 *(volatile uint8_t*)0x525a
#define TIM1_CCMR4 *(volatile uint8_t*)0x525b
#define TIM1_CCER1 *(volatile uint8_t*)0x525c
#define TIM1_CCER2 *(volatile uint8_t*)0x525d
#define TIM1_CNTRH *(volatile uint8_t*)0x525e
#define TIM1_CNTRL *(volatile uint8_t*)0x525f
#define TIM1_PSCRH *(volatile uint8_t*)0x5260
#define TIM1_PSCRL *(volatile uint8_t*)0x5261
#define TIM1_ARRH  *(volatile uint8_t*)0x5262
#define TIM1_ARRL  *(volatile uint8_t*)0x5263
#define TIM1_RCR   *(volatile uint8_t*)0x5264
#define TIM1_CCR1H *(volatile uint8_t*)0x5265
#define TIM1_CCR1L *(volatile uint8_t*)0x5266
#define TIM1_CCR2H *(volatile uint8_t*)0x5267
#define TIM1_CCR2L *(volatile uint8_t*)0x5268
#define TIM1_CCR3H *(volatile uint8_t*)0x5269
#define TIM1_CCR3L *(volatile uint8_t*)0x526a
#define TIM1_CCR4H *(volatile uint8_t*)0x526b
#define TIM1_CCR4L *(volatile uint8_t*)0x526c
#define TIM1_BKR   *(volatile uint8_t*)0x526d
#define TIM1_DTR   *(volatile uint8_t*)0x526e
#define TIM1_OISR  *(volatile uint8_t*)0x526f


#define TIM_IER_BIE   (1 << 7)
#define TIM_IER_TIE   (1 << 6)
#define TIM_IER_COMIE (1 << 5)
#define TIM_IER_CC4IE (1 << 4)
#define TIM_IER_CC3IE (1 << 3)
#define TIM_IER_CC2IE (1 << 2)
#define TIM_IER_CC1IE (1 << 1)
#define TIM_IER_UIE   (1 << 0)

#define TIM_CR1_ARPE (1 << 7)
#define TIM_CR1_CMSH (1 << 6)
#define TIM_CR1_CMSL (1 << 5)
#define TIM_CR1_DIR  (1 << 4)
#define TIM_CR1_OPM  (1 << 3)
#define TIM_CR1_URS  (1 << 2)
#define TIM_CR1_UDIS (1 << 1)
#define TIM_CR1_CEN  (1 << 0)

#define TIM_CR2_MMS2 (1 << 6)
#define TIM_CR2_MMS1 (1 << 5)
#define TIM_CR2_MMS0 (1 << 4)
#define TIM_CR2_COMS (1 << 2)
#define TIM_CR2_CCPC (1 << 0)

#define TIM_SR1_BIF   (1 << 7)
#define TIM_SR1_TIF   (1 << 6)
#define TIM_SR1_COMIF (1 << 5)
#define TIM_SR1_CC4IF (1 << 4)
#define TIM_SR1_CC3IF (1 << 3)
#define TIM_SR1_CC2IF (1 << 2)
#define TIM_SR1_CC1IF (1 << 1)
#define TIM_SR1_UIF   (1 << 0)

/* port bits */
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7
#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7
#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7
#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

#define TRAP_vector        255
#define TIM1_UPDATE_vector 11
#define UART1_TXC_vector   17
#define UART1_RXC_vector   18

#define PCKENR1_TIM1  (1 << 7)
#define PCKENR1_TIM2  (1 << 5)
#define PCKENR1_TIM4  (1 << 4)
#define PCKENR1_UART1 (1 << 3)
#define PCKENR1_SPI   (1 << 1)
#define PCKENR1_I2C   (1 << 0)

#define PCKENR2_ADC   (1 << 3)
#define PCKENR2_AWU   (1 << 2)

#define I2C_CR1			*(unsigned char*)0x005210 // I2C control register 1   
#define I2C_CR2			*(unsigned char*)0x005211 // I2C control register 2   
#define I2C_FREQR		*(unsigned char*)0x005212 // I2C frequency register    
#define I2C_OARL		*(unsigned char*)0x005213 // I2C Own address register low  
#define I2C_OARH		*(unsigned char*)0x005214 // I2C Own address register high  
#define I2C_DR			*(unsigned char*)0x005216 // I2C data register    
#define I2C_SR1			*(unsigned char*)0x005217 // I2C status register 1   
#define I2C_SR2			*(unsigned char*)0x005218 // I2C status register 2   
#define I2C_SR3			*(unsigned char*)0x005219 // I2C status register 3   
#define I2C_ITR			*(unsigned char*)0x00521A // I2C interrupt control register   
#define I2C_CCRL		*(unsigned char*)0x00521B // I2C Clock control register low  
#define I2C_CCRH		*(unsigned char*)0x00521C // I2C Clock control register high  
#define I2C_TRISER		*(unsigned char*)0x00521D // I2C TRISE register    
#define I2C_PECR		*(unsigned char*)0x00521E // I2C packet error checking register 
// I2C_CR1
#define I2C_NOSTRETCH	(1 << 7)
#define I2C_ENGC	(1 << 6)
#define I2C_PE		(1 << 0)

// I2C_CR2
#define I2C_SWRST	(1 << 7)
#define I2C_POS		(1 << 3)
#define I2C_ACK		(1 << 2)
#define I2C_STOP	(1 << 1)
#define I2C_START	(1 << 0)

// I2C_OARH
#define I2C_ADDMODE	(1 << 7)
#define I2C_ADDCONF	(1 << 6)

// I2C_CCRH
#define I2C_FS		(1 << 7)
#define I2C_DUTY	(1 << 6)

// I2C_ITR
#define I2C_ITBUFEN	(1 << 2)
#define I2C_ITEVTEN	(1 << 1)
#define I2C_ITERREN	(1 << 0)

// I2C_SR1
#define I2C_TXE		(1 << 7)
#define I2C_RXNE	(1 << 6)
#define I2C_STOPF	(1 << 4)
#define I2C_ADD10	(1 << 3)
#define I2C_BTF		(1 << 2)
#define I2C_ADDR	(1 << 1)
#define I2C_SB		(1 << 0)

#define WWDG_CR *(volatile uint8_t *)0x50d1

#define __rim()   {__asm rim __endasm;}  /* enable interrupts */
#define __sim()   {__asm sim __endasm;}  /* disable interrupts */
#define __nop()   {__asm nop __endasm;}  /* No Operation */
#define __trap()  {__asm trap __endasm;} /* Trap (soft IT) */
#define __wfi()   {__asm wfi __endasm;}  /* Wait For Interrupt */
#define __halt()  {__asm halt __endasm;} /* Halt */
#define __reset() {WWDG_CR = 0x80;}      /* Software reset */

#if F_CPU == 16000000
#define CKDIVR 0
#else
#error Unknown CPU freq, please edit stm8.h
#endif

inline void delay_ms(uint16_t ms)
{
  uint16_t i;

  while (ms--) {
		for (i = 0; i < 1587; i++) {};
  }
}
