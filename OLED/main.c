#include "stm32f10x.h"                  // Device header
#include "clock.h"
#include "systick.h"
#include "gpio.h"
#include "i2c.h"
#include "sh1106.h"

int main(void)
{
	//Initializations
  Clock_HSI_8MHz_Init();
  SysTick_Init();
  GPIO_Reset();
  GPIO_OutputInit(GPIOB,
  				  GPIO_PORT_REG_LOW,
  				 (GPIO_PIN6_OUTPUT_MODE_2MHZ | GPIO_PIN7_OUTPUT_MODE_2MHZ),
  				 (GPIO_PIN6_ALT_FUNC_OPEN_DRAIN | GPIO_PIN7_ALT_FUNC_OPEN_DRAIN));
  I2C_Init(I2C1,I2C_PERIPH_FREQ_8MHZ,I2C_STANDARD_MODE_8MHZ_CCR,I2C_STANDARD_MODE_8MHZ_TRISE);

  SH1106_Init();
  SH1106_ClearScreen();
  SH1106_SetCursor(2,0);
  SH1106_WriteString("Good Day!!!", White);
  SH1106_UpdateScreen();
  SysTick_DelayMs(1000);

  SH1106_SetCursor(2,10);
  SH1106_WriteString("What's for dinner?", White);
  SH1106_UpdateScreen();
  SysTick_DelayMs(1000);

  SH1106_SetCursor(2,20);
  SH1106_WriteString("Let's play a game", White);
  SH1106_UpdateScreen();
	
	while(1)
	{
		
	}
}
