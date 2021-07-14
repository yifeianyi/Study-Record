#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "motor.h"
#include "infrared.h"
#include "stm32f10x_it.h"
#include "control.h"
//#include "stm32f10x_it.h"
/************************变量定义区**************************/
int sensor[9]={0,0,0,0,0,0,0,0,0};
int stopconfig;
int KeyON;
/************************************************************/
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	 
	/*********************外设初始化***********************/
	//int i;
	SysTick_Config(72000);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART_Config();
	Motor_GPIO_Init();
	infrared_Init();
	TIM3_Time_Init(70,7199);//用于电机方向调整定时
	printf("hello world\n");
	//i=0;
	/*****************************************************/
	
	/**********************功能模块***********************/
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
//				    //小车电机向前
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





















