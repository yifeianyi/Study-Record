#include "infrared.h"
#include "bsp_usart.h"

extern int sensor[9];//����������main��������飬�����ڱ��ļ���ʹ��sensor[x]�ñ���
extern int error;	//����������control.c��������ֵ
void infrared_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO�ܽ�ģʽ����Ϊ�������룬�������ܻ�ȡ�������������������ź�(�ߵ͵�ƽ)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);  
	
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//IO�ܽ�ģʽ����Ϊ�������룬�������ܻ�ȡ�������������������ź�(�ߵ͵�ƽ)
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
}

void infrared_Read(void)
{
//	printf("%d\n",GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13));
	
	sensor[0]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14);//����Ĵ�����
	sensor[1]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);
	sensor[2]=GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10);
	sensor[3]=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15);//���ҵĴ�����
	
	
	/****************************ƫ�����********************************/
//	if( (sensor[0]==0)&&(sensor[1]&&sensor[2])&&(sensor[3]==0) ){//����
//		error=0;
//		//Base = 0;
//	}
//	//�������Ҹ�
//	else if((sensor[0]==0)&&(sensor[1]==0 && sensor[2])&&(sensor[3]==0)){
//		//��Сƫ
//		error = 1;
//		//Base = 0;
//	}
//	else if((sensor[0]==0)&&(sensor[1] && sensor[2]==0 )&&(sensor[3]==0)){
//		//��Сƫ
//		error = -1;
//		//Base = 0;
//	}
//	else if((sensor[0])&&(sensor[1]&&sensor[2]==0)&&(sensor[3]==0)){
//		//��ƫ
//		error = 5;
//		//a = 2;
//	}
//	else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2])&&(sensor[3])){
//		//��ƫ
//		error = -5;
//	}
//	else if((sensor[0]==0)&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3])){
//		//�Ҵ�ƫ
//		error =  -7;
//	}
//	else if((sensor[0])&&(sensor[1]==0&&sensor[2]==0)&&(sensor[3]==0)){
//		//���ƫ
//		error = 7;
	}
//}
