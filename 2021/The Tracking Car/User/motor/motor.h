#ifndef _MOTOR_H
#define _MOTOR_H
	#include "stm32f10x.h"
	#define MOTOR_GPIO GPIOB
	#define MOTOR_CLK		RCC_APB2Periph_GPIOB
	
	
	
	#define MOTOR_AIN1	GPIO_Pin_9
	#define MOTOR_AIN2	GPIO_Pin_8
	#define MOTOR_PWMA	GPIO_Pin_7
	
	#define MOTOR_PWMB	GPIO_Pin_6
	#define MOTOR_BIN1	GPIO_Pin_4
	#define MOTOR_BIN2	GPIO_Pin_5
	#define FRONT 1
	#define BACK 0
	
	void Motor_GPIO_Init(void);
	void Motor_forward(char flag);
	void Motor_stop(void);
	void TIM3_Time_Init(u16 arr,u16 psc);
	void TIM4_PWM_Init(u16 arr,u16 psc);

#endif
