#ifndef _infrared_H
#define _infrared_H
	#include "stm32f10x.h"
	#define Infrared_PORT1	GPIOB
	#define Infrared_PORT2	GPIOC
	#define Infrared_CLK1	GPIOB
	#define Infrared_CLK2	GPIOC
	
	void infrared_Init(void);
	void infrared_Read(void);

#endif
