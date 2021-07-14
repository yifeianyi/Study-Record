#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "motor.h"
#include "infrared.h"
#include "stm32f10x_it.h"
#include "control.h"
//#include "stm32f10x_it.h"
/************************����������**************************/
int sensor[9]={0,0,0,0,0,0,0,0,0};
int stopconfig;
int KeyON;
/************************************************************/
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	 
	/*********************�����ʼ��***********************/
	//int i;
	SysTick_Config(72000);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART_Config();
	Motor_GPIO_Init();
	infrared_Init();
	TIM3_Time_Init(70,7199);//���ڵ�����������ʱ
	printf("hello world\n");
	//i=0;
	/*****************************************************/
	
	/**********************����ģ��***********************/
	while (1)
	{	
		infrared_Read();
		printf("%d %d %d %d\n",sensor[0],sensor[1],sensor[2],sensor[3]);
		delay_ms(300);
		//Motor_forward(FRONT);
		
		
		
		
		
//		TIM_SetCompare2(TIM4,4000);
//		TIM_SetCompare1(TIM4,4000);
		
//			if(stopconfig==0)
//			{
//				    //С�������ǰ
//			}	
//			else{
//				Motor_stop();
//				delay_ms(300);
//			}
		/**********************************Debug start***********************************************/
			//printf("hello world %d\n",i++);
			
//			//delay_ms(100);
//			infrared_Read();
//			printf("%d %d %d %d\n",sensor[0],sensor[1],sensor[2],sensor[3]);
//			delay_ms(150);
		

		//Motor_forward(FRONT);
		/*********************************Debug Ending************************************************/
	}
}

/*********************************************END OF FILE**********************/





















