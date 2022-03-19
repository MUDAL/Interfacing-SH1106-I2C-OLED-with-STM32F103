#include "stm32f10x.h"                  // Device header
#include "clock.h"

void Clock_HSI_8MHz_Init(void)
{
	while((RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY); //wait for internal oscillator to be stable
	RCC->CFGR = 0; //Reset CFGR
	RCC->CR &= ~(RCC_CR_PLLON | RCC_CR_HSEON);	//disable PLL and external oscillator
	//enable clock access for GPIOB
	RCC->APB2ENR |= (RCC_APB2ENR_IOPBEN);
	//enable clock for I2C1
	RCC->APB1ENR |= (RCC_APB1ENR_I2C1EN);
}
