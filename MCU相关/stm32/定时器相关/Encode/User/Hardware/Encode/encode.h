#ifndef __ENCODE_H__
#define __ENCODE_H__
	#include "stm32f10x.h"
	#include "delay.h"
	
	#define EncoderA_Port					GPIOA
	#define EncoderA_GPIO_CLK 		RCC_APB2Periph_GPIOA	
	#define EncoderA_TIM_CLK			RCC_APB1Periph_TIM3
	#define EncoderA_TIM					TIM3
	#define EncoderA_PINA					GPIO_Pin_6
	#define EncoderA_PINB					GPIO_Pin_7
	
	
	void Encoder_Init(void);
	void Encoder_GPIO_Init(void);
	void Encoder_TIM_Init(void);
	
	
#endif
