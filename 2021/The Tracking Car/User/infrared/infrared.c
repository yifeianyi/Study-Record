#include "infrared.h"
#include "bsp_usart.h"

extern int sensor[9];//引用主函数main定义的数组，才能在本文件内使用sensor[x]该变量
extern int error;	//引用主函数control.c定义的误差值
void infrared_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO管脚模式配置为浮空输入，这样就能获取传感器传回来的数字信号(高低电平)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);  
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO管脚模式配置为浮空输入，这样就能获取传感器传回来的数字信号(高低电平)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}

void infrared_Read(void)
{
//	printf("%d\n",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13));
	
	sensor[0]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14);//最左的传感器
	sensor[1]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	sensor[2]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10);
	sensor[3]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15);//最右的传感器
	
	
	/****************************偏差计算********************************/
//	if( (sensor[0]==0)&&(sensor[1]&&sensor[2])&&(sensor[3]==0) ){//正中
//		error=0;
//		//Base = 0;
//	}
//	//左正，右负
//	else if((sensor[0]==0)&&(sensor[1]==0 && sensor[2])&&(sensor[3]==0)){
//		//左小偏
//		error = 1;
//		//Base = 0;
//	}
//	else if((sensor[0]==0)&&(sensor[1] && sensor[2]==0 )&&(sensor[3]==0)){
//		//右小偏
//		error = -1;
//		//Base = 0;
//	}
//	else if((sensor[0])&&(sensor[1]&&sensor[2]==0)&&(sensor[3]==0)){
//		//左偏
//		error = 5;
//		//a = 2;
//	}
//	else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2])&&(sensor[3])){
//		//右偏
//		error = -5;
//	}
//	else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3])){
//		//右大偏
//		error =  -7;
//	}
//	else if((sensor[0])&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3]==0)){
//		//左大偏
//		error = 7;
	}
//}
