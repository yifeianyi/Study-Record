#include "led.h"

void Led_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

  /* Configure PD0 and PD2 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = Led_All;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void Led_Control(u32 led,u8 state)
{
	if(state)
	{
		GPIO_SetBits(GPIOB, led);
	}
	else 
	{
		GPIO_ResetBits(GPIOB, led);
	}
}
