#include "motor.h"
/****************************************************************
	���������¼
		1����ʼ��TIM4��ʱ�Ӻ���ѡ�񲻶�
		2����Ҫ����3��ʱ�ӣ���ʱ��ʱ�ӡ�ͨ���˿�ʱ�ӡ��˿ڸ���ʱ��
		
*****************************************************************/

void TIM3_Time_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;  //�ж����ȼ��Ľṹ�嶨��

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //TIM3��ʱ��ʹ��

	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ 
	TIM_TimeBaseStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx����Ӧ��ģʽ����
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);  //ʹ��TIM3�ж�
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3�жϷ�����������
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority =0;  //�����ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;  //�����ȼ�2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //ʹ��IRQ�ж�ͨ��
	NVIC_Init(&NVIC_InitStructure);  //����NVIC_InitStruct��ָ���Ĳ�����ʼ��NVIC�Ĵ���

	TIM_Cmd(TIM3, ENABLE);  //����TIM3
}

//arr���Զ���װֵ
//psc��ʱ��Ԥ��Ƶ��
void TIM4_PWM_Init(u16 arr,u16 psc)//��������main�д���arr��psc����ֵ
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

    TIM_TimeBaseStructure.TIM_Period = arr;    		//�����Զ���װ��               
    TIM_TimeBaseStructure.TIM_Prescaler =psc;   	//Ԥ��Ƶϵ��
    TIM_TimeBaseStructure.TIM_ClockDivision = 0;    //��Ƶ���ӣ�һ�����˲����ã�����Ӱ����ʱֵ
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 	//ѡ�����ģʽ
    TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);       


    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;      //����PWMģʽ��ģʽ1��CNT < CCRʱ�����Ч��ƽ
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //���ʹ�ܣ�������ʱ���ⲿ���
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;     //���ü���
    TIM_OC1Init(TIM4, &TIM_OCInitStructure);               //??TIM_OCInitStruct???????????TIMx
    TIM_OC2Init(TIM4, &TIM_OCInitStructure);               //??TIM_OCInitStruct???????????TIMx

    TIM_CtrlPWMOutputs(TIM4,ENABLE);                      //MOE ?????   

		/****************************ʹ��ͨ����Ԥװ�ؼĴ���*****************************/
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
	
	/***********************************pwm����**********************************************************/
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

