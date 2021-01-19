#include"stm32f10x.h"
//typedef unsigned int uint;
unsigned int State[2]={LED_B,0xffffffff};
void delay(){
	int i=1000,j;
	while(i--){
		j=500;
		while(j--);
	}
	
	return;
}

int main(void){
	
	char flag = 0;
	/***********初始化*************/
	//启动PA 、PB的时钟
	RCC_APB2ENR |= (1<<3);
	RCC_APB2ENR |= (1<<2);
	
	/************配置PA PB相关端口***********/
	//清零控制PB 0、1、5的端口位
	GPIOB_CRL &= ~( 0x00f000ff );
	
	//清零控制PA 0 的端口位
	GPIOA_CRL &= ~( 0x0000000f );
	
	//配置PB 0、1、5 为通用推挽输出，速度为10M
	GPIOB_CRL |= (0x00200022);
	//配置PB0为浮空输入
	GPIOA_CRL |= (0x4);
	
	/*********控制引脚电平输出*********/
	GPIOB_ODR	=	LED_B;
	while(1){
		
		//按键控制
		if(GPIOA_IDR & 0x1 ==1){
			while(GPIOA_IDR & 0x1 ==0x1);
			flag = (++flag)%2;
			GPIOB_ODR = State[flag];
		}
	}

}
