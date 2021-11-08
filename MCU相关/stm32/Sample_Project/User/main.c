#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "stm32f10x_it.h"
#include "delay.h"
#include "encoder.h"
/************************变量定义区**************************/

/************************************************************/
/**
  * @brief  主函数
  * @param  无  
  * @retval 无
  */
int main(void)
{	 
	/*********************外设初始化***********************/
	SysTick_Config(72000);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART_Config();
	TIM4_Mode_Config();
	
	/*****************************************************/
	
	/**********************功能模块***********************/
	while (1)
	{	
		//windows();
//		printf("hello world\n");
//		delay_ms(400);
		
	//	Servo_Angle(45);
		delay_ms(500);
		//printf("hello world\n");
		printf("%d\n",TIM4->CNT);
		/**********************************Debug start***********************************************/

		/*********************************Debug Ending************************************************/
	}
}

/*********************************************END OF FILE**********************/





















