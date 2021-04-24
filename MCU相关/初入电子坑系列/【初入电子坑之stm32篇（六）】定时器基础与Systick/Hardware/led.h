#ifndef LED_H
#define LED_H
	#include "stm32f10x.h"
	#define ON	0
	#define OFF	1
	
	#define Led_1		GPIO_Pin_5 //R
	#define Led_2		GPIO_Pin_0 //G
	#define Led_3		GPIO_Pin_1 //B
	
	#define Led_All	Led_1|Led_2|Led_3
									
	void Led_Init(void);
	void Led_Control(u32 led,u8 state);
	
#endif
