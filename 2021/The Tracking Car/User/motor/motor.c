#include "motor.h"
/****************************************************************
	犯错纠正记录
		1、初始化TIM4的时钟函数选择不对
		2、需要开启3个时钟：定时器时钟、通道端口时钟、端口复用时钟
		
*****************************************************************/

void TIM3_Time_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;  //中断优先级的结构体定义

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //TIM3的时钟使能

	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的相应的模式配置
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);  //使能TIM3中断
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断服务函数的配置
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;  //主优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //从优先级2级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能IRQ中断通道
	NVIC_Init(&NVIC_InitStructure);  //根据NVIC_InitStruct中指定的参数初始化NVIC寄存器

	TIM_Cmd(TIM3, ENABLE);  //开启TIM3
}

//arr：自动重装值
//psc：时钟预分频数
void TIM4_PWM_Init(u16 arr,u16 psc)//在主函数main中传入arr和psc的数值
{         
    GPIO_InitTypeDef GPIO_InitStructure;
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);    // 
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);  //
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO , ENABLE); 
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7;   //TIM_CH1 //TIM_CH4
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;         //??????
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    TIM_TimeBaseStructure.TIM_Period = arr;    		//设置自动重装载               
    TIM_TimeBaseStructure.TIM_Prescaler =psc;   	//预分频系数
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;    //分频因子，一般起到滤波作用，不会影响延时值
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//选择计数模式
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);       


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;      //设置PWM模式，模式1：CNT < CCR时输出有效电平
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //输出使能，开启定时器外部输出
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //设置极性
    TIM_OC1Init(TIM4, &TIM_OCInitStructure);               //??TIM_OCInitStruct???????????TIMx
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);               //??TIM_OCInitStruct???????????TIMx

    TIM_CtrlPWMOutputs(TIM4,ENABLE);                      //MOE ?????   

		/****************************使能通道的预装载寄存器*****************************/
    TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);     //CH1?????     
    TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);     //CH4?????     

    TIM_ARRPreloadConfig(TIM4, ENABLE);                   //??TIMx?ARR????????

    TIM_Cmd(TIM4, ENABLE);                                //??TIM1
}




void Motor_GPIO_Init(){
		GPIO_InitTypeDef GPIO_InitStructure;
	
		RCC_APB2PeriphClockCmd(MOTOR_CLK|RCC_APB2Periph_AFIO, ENABLE);
		//RCC_APB2PeriphClockCmd(MOTOR_CLK, ENABLE);
		GPIO_InitStructure.GPIO_Pin = MOTOR_AIN1;	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	
		//AIN1
		GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);	
	
		//AIN2
		GPIO_InitStructure.GPIO_Pin = MOTOR_AIN2;	
		GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
	
	//BIN1
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	//RCC_APB2PeriphClockCmd(MOTOR_CLK, ENABLE);
	GPIO_InitStructure.GPIO_Pin = MOTOR_BIN1;	
		GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
	
	//BIN2
	GPIO_InitStructure.GPIO_Pin = MOTOR_BIN2;	
	GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
	
	/***********************************pwm配置**********************************************************/
		TIM4_PWM_Init(7199,0);
//		
//		GPIO_InitStructure.GPIO_Pin = MOTOR_PWMA;	
//		GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
//		GPIO_InitStructure.GPIO_Pin = MOTOR_PWMB;	
//		GPIO_Init(MOTOR_GPIO, &GPIO_InitStructure);
		
}


void Motor_forward(char flag){
	if(!flag){
		GPIO_SetBits( MOTOR_GPIO, MOTOR_AIN1);
		GPIO_ResetBits( MOTOR_GPIO, MOTOR_AIN2);
		//GPIO_SetBits( MOTOR_GPIO, MOTOR_PWMA);
		
		GPIO_SetBits( MOTOR_GPIO, MOTOR_BIN1);
		//GPIO_SetBits( MOTOR_GPIO, MOTOR_PWMB);
		GPIO_ResetBits( MOTOR_GPIO, MOTOR_BIN2);
	}
	else{
		GPIO_SetBits( MOTOR_GPIO, MOTOR_AIN2);
		GPIO_ResetBits( MOTOR_GPIO, MOTOR_AIN1);
		GPIO_SetBits( MOTOR_GPIO, MOTOR_PWMA);
		
		GPIO_SetBits( MOTOR_GPIO, MOTOR_BIN2);
		GPIO_SetBits( MOTOR_GPIO, MOTOR_PWMB);
		GPIO_ResetBits( MOTOR_GPIO, MOTOR_BIN1);
	}
}
void Motor_stop(){
	
}

