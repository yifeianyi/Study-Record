#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_usart.h"
#include "stm32f10x_it.h"
#include "delay.h"
#include "encoder.h"
/************************����������**************************/

/************************************************************/
/**
  * @brief  ������
  * @param  ��  
  * @retval ��
  */
int main(void)
{	 
	/*********************�����ʼ��***********************/
	SysTick_Config(72000);
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	USART_Config();
	TIM4_Mode_Config();
	
	/*****************************************************/
	
	/**********************����ģ��***********************/
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





















