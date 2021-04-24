#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "led.h"




//void Led_Con(void);
u8 state;
int main(void)
{
	SysTick_Config(72000);
	Led_Init();
	
	Led_Control(Led_All,OFF);

	
	while(1)
	{
		Led_Control(Led_All,state);
		Delay_ms(1000);
		state ^=1;
		
	}
}
